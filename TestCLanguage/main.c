//
//  main.c
//  TestCLanguage
//
//  Created by Jason Huang on 6/2/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Polynomial.h"
#include <time.h>
#include "BinarySearchTree.h"
#include "Stack.h"
int main(int argc, const char * argv[])
{

//    struct List *list = createList();
//    if(list != NULL){
//        if (list->head == NULL) {
//            printf("head is null\n");
//        }else{
//            printf("head is not null\n");
//        }
//    }else{
//        printf("List allocation failed\n");
//    }
    
//    insertNode(list->head, 1);
//    insertNode(list->head, 2);
//    insertNode(list->head, 3);
//    insertNode(list->head, 4);
    
//    struct List *list2 = createList();
//    if(list2 != NULL){
//        if (list2->head == NULL) {
//            printf("head is null\n");
//        }else{
//            printf("head is not null\n");
//        }
//    }else{
//        printf("List allocation failed\n");
//    }
//    
//    insertNode(list2->head, 1);
//    insertNode(list2->head, 2);
//    insertNode(list2->head, 8);
//    insertNode(list2->head, 9);
    
//    struct List *list3 = intersectionOfLists(list, list2);
//    traverseList(list3->head);
//    struct List *list3 = unionOfLists(list, list2);
//    traverseList(list3->head);
//    int coef[] = {1,2,3,4,5};
//    int degree[] = {2,3,4,5,7};
//    
//    createPolynomials(coef, degree);
//    reverseListWithConstantExSpace(list);
//    traverseList(list->head);
//    for (int i = 0; i<1000; i ++) {
//        insertNode(list->head, i);
//    }
//    clock_t begin, end;
//    double time_spent;
//    
//    begin = clock();
//    /* here, do your time-consuming job */
//    struct Node *nodeFound = findNodeRecursive(list->head, 999);
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    printf("time spent on recursive is %f \n",time_spent);
//    
//    
//    begin = clock();
//    /* here, do your time-consuming job */
//    nodeFound = findNode(list->head, 99);
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    printf("time spent on non-recursive is %f",time_spent);    

//    struct Stack *stack = createStack();
//    push(stack, 1);
//    push(stack, 2);
//    push(stack, 3);
//    push(stack, 4);
//    push(stack, 5);
//    pop(stack);
//    pop(stack);
    
    struct BinarySearchTree *tree = createBinarySearchTree();
    insert(tree, 15);
    insert(tree, 8);
    insert(tree, 21);
    insert(tree, 6);
    insert(tree, 13);
    insert(tree, 17);
    insert(tree, 50);
//    struct TreeNode *max = findMax(tree);
//    struct TreeNode *min = findMin(tree);
//    boolean isFind = find(tree->root, 99);
    traverseBinarySearchTree(tree);

    struct Node **nodeList = (struct Node **)malloc(sizeof(struct Node*) * 10);
    nodeList[0] = (struct Node *)malloc(sizeof(struct Node));
    
    return 0;
}

