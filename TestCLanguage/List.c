//
//  Node.c
//  TestCLanguage
//
//  Created by Jason Huang on 6/2/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct List *createList(){
    struct List *list = (struct List *)malloc(sizeof(struct List));
    if(list != NULL){
        list->head = (struct Node *)malloc(sizeof(struct Node));
        return list;
    }else{
        printf("List allocation failed");
        return NULL;
    }
}

void traverseList(struct Node *head){
    struct Node *node = head->next;
    while (node!= NULL) {
        printf("%d -> ",node->value);
        node = node ->next;
    }
    printf("\n");
}

struct Node *findPrevious(struct Node *head, Element_Type value){
    
    if (head == NULL) {
        return NULL;
    }
    
    struct Node *p = head;
    
    while (p->next != NULL && p->next->value != value) {
        p = p->next;
    }
    
    //if head->next == null, then p = head, and p->next == null
    //if value doesnt exist in the list, then p would be the last node and p->next == null
    //if value is found, then p->next->value == value
    if(p->next != NULL){
        return p;
    }else{
        return NULL;
    }
}

struct Node *findNode(struct Node *head, Element_Type value){
    struct Node *node = head->next;
    
    while (node!=NULL && node->value != value) {
        node = node->next;
    }
    
    if (node !=NULL) {
        return node;
    }else{
        return NULL;
    }
}

//return head or the last node
struct Node *findLastNode(struct Node *head){
    
    if (head == NULL) {
        return NULL;
    }
    
    //find the last node
    struct Node *node = head;
    while (node-> next != NULL) {
        node = node->next;
    }
    
    return node;
}

boolean insertNode(struct Node *head, Element_Type valueToInsert){
    
    //find the last node
    struct Node *node = findLastNode(head);
    //create new node
    struct Node *newLastNode = (struct Node *)malloc(sizeof(struct Node));
    newLastNode->next = NULL;
    newLastNode->value = valueToInsert;
    //insert 
    node->next = newLastNode;
    
//    printf("insert node %d\n", valueToInsert);
//    traverseList(head);
    
    return YES;
}

boolean insertNodeAtIndex(struct Node *head, Element_Type valueToInsert, int index){
    return NO;
}

boolean deleteNode(struct Node *head, Element_Type valueToDelete){
    
    struct Node *previous = findPrevious(head, valueToDelete);
    if (previous!=NULL) {
        
        struct Node *nodeToDelete = previous->next;
        previous->next = previous->next->next;
        free(nodeToDelete);
        printf("delete node %d\n",valueToDelete);
        traverseList(head);
        return YES;
        
    }else{
        
        return NO;
        
    }
}

boolean isEmptyList(struct List *list){
    if (list->head->next == NULL) {
        return YES;
    }else{
        return NO;
    }
}

struct List *intersectionOfLists(struct List *aList, struct List *bList){
    
    //intersection of am empty list is null
    if (isEmptyList(aList) || isEmptyList(bList)) {
        return NULL;
    }
    
    struct Node *a = aList->head->next;
    struct Node *b = bList->head->next;
    struct List *list = createList();
    
    while (a!=NULL) {
        while (b!=NULL && a->value != b->value) {
            b = b->next;
        }
        //
        if (b!=NULL) {
            insertNode(list->head, b->value);
        }
        a = a->next;
    }
    
    return list;
}

struct List *unionOfLists(struct List *aList, struct List *bList){
    
    //empty union non-empty = empty
    //empty union empty = empty
    if (isEmptyList(aList) || isEmptyList(bList)) {
        return isEmptyList(aList)?bList:aList;
    }
    
    struct Node *a = aList->head->next;
    struct Node *b = bList->head->next;
    struct List *tempList = createList();
    
    //compare each node in a with every node in b, if a doesnt exist in b, then a needs to be in the union. Add a into tempList. And finally combine list b with tempList, that's the union.
    while (a!=NULL) {
        while (b!=NULL && a->value != b->value) {
            b = b->next;
        }
        //
        if (b==NULL) {
            insertNode(tempList->head, a->value);
        }
        a = a->next;
    }
    
    b = bList->head->next;
    while (b!=NULL) {
        insertNode(tempList->head, b->value);
        b = b->next;
    }
    
    return tempList;
}

struct List *reverseListWithConstantExSpace(struct List *list){
    struct Node *pre = list->head->next;
    struct Node *now = pre->next;
    struct Node *after = now->next;
    
    //seperate pre == first node case
    pre->next = NULL;
    now->next = pre;
    pre = now;
    now = after;
    after = after->next;
    
    while (after != NULL) {
        now->next = pre;
        pre = now;
        now = after;
        after = after->next;
    }
    
    //when while loops ends, now is pointing to the last node
    now->next = pre;
    
    //correct head
    list->head->next = now;
    
    return list;
}

struct Node *findNodeRecursive(struct Node *node, Element_Type value){
    if (node->value != value) {
        return findNodeRecursive(node->next, value);
    }else{
        return node;
    }
}

