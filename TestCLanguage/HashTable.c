//
//  HashTable.c
//  TestCLanguage
//
//  Created by Jason Huang on 7/23/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "HashTable.h"

struct HashTable *createHashTable(int size){
    
    if (size<=0) {
        printf("size is illegal");
        return NULL;
    }
    
    struct HashTable *table = (struct HashTable *)malloc(sizeof(struct HashTable));
    if (table == NULL) {
        printf("error");
        return NULL;
    }

    table->size = nextPrime(size);
    table->list = (List)malloc(sizeof(List)*size);
    if (table->list == NULL) {
        printf("error");
        return NULL;
    }
    for (int i=0; i<table->size; i++) {
        table->list[i] = (struct Node*)malloc(sizeof(struct Node));
        table->list[i]->next = NULL;
    }
    return table;
}

int nextPrime(int num){
//Bertrand's postulate (actually a theorem) states that if n > 3 is an integer, then there always exists at least one prime number p with n < p < 2n − 2. A weaker but more elegant formulation is: for every n > 1 there is always at least one prime p such that n < p < 2n.
//A simple but slow method of verifying the primality of a given number n is known as trial division. It consists of testing whether n is a multiple of any integer between 2 and \sqrt{n}.
    if (num == 1) {
        return 1;
    }else if (num <= 3){
        return 3;
    }else{
        // when n = 0, square(n) < 2n -2
        // when n = 1, square(n) > 2n -2
        // when n >= 2, square(n) < 2n -2
        for (int i = num+1; i < sqrtf(num); i++) {
            int k = i;
            while (num % k ==0 && k < sqrtf(num)) {
                k++;
            }
            if (k > sqrt(num)) {
                return num;
            }
        }
    }
    
    return 0;
}

int hash(int key, int table_size){
    return 0;
}

boolean insertHashTable_Closed(int value, struct HashTable*table){
    
    int index = hash(value, table->size);
    if (table->list[index] == NULL) {
        printf("something went wrong");
        return NO;
    }else{
        struct Node *temp = table->list[index];
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->value = value;
        newNode->next = NULL;
        
        temp->next = newNode;
        
        return YES;
    }
}

