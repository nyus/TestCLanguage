//
//  Stack.c
//  TestCLanguage
//
//  Created by Jason Huang on 6/8/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct Stack *createStack(){
    
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->head = (struct Node *)malloc(sizeof(struct Node));
    return stack;
}

void push(struct Stack *stack, Element_Type value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    
    //push first element
    if (stack->head->next == NULL) {
        stack->head->next = newNode;
        stack->first = newNode;
        stack->last = newNode;
    }else{
        stack->last->next = newNode;
        stack->last = newNode;
    }
    
    traverseList(stack->head);
}

struct Node *findPreviousOfLastNodeInStack(struct Node *last, struct Stack *stack){
    
    if (last == NULL) {
        return NULL;
    }else{
        
        struct Node *temp = stack->head;
        while (temp->next!=NULL) {
            if(temp->next == last){
                break;
            }else{
                temp = temp->next;
            }
        }
        return temp;
    }
    
}

Element_Type pop(struct Stack *stack){
    
    struct Node *preToLast = findPreviousOfLastNodeInStack(stack->last, stack);
    Element_Type valueToReturn = stack->last->value;
    //if empty stack
    if (preToLast==NULL) {
        return NOT_EXIST;
    }else{
        //if there is only one item left in the stack
        if (preToLast == stack->head) {
            free(stack->last);
            stack->head->next=stack->first=stack->last=NULL;
        }else{
            free(stack->last);
            stack->last = preToLast;
            stack->last->next = NULL;
        }
        
        return valueToReturn;
    }
}
