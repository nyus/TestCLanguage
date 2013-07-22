//
//  Polynomial.c
//  TestCLanguage
//
//  Created by Jason Huang on 6/22/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Polynomial.h"

void traversePolynomial(struct Polynomial *poly){
    struct PolyNode *node = poly->head->next;
    
    while (node!=NULL) {
        printf("%dx^%d ",node->coef,node->degree);
        node = node->next;
    }
}

struct Polynomial *createPolynomials(int *coef , int *degree){
    
    struct Polynomial *poly = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    poly->head = (struct PolyNode *)malloc(sizeof(struct PolyNode));
    struct PolyNode *tempHead = poly->head;
    
    for (int i = 0; i < sizeof(coef)/sizeof(int); i++) {
        struct PolyNode *newNode = (struct PolyNode *)malloc(sizeof(struct PolyNode));
        newNode->next = NULL;
        newNode->coef = coef[i];
        newNode->degree = degree[i];
        tempHead->next = newNode;
        tempHead=tempHead->next;
    }
    
    traversePolynomial(poly);
    return poly;
}

struct Polynomial *addTwoPolynomials(struct Polynomial *aPoly, struct Polynomial *bPoly){
    
}

struct Polynomial *multiplyTwoPolynomials(struct Polynomial *aPoly, struct Polynomial *bPoly){}