//
//  HashTable.h
//  TestCLanguage
//
//  Created by Jason Huang on 7/23/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//
#include "Constant.h"
#ifndef TestCLanguage_HashTable_h
#define TestCLanguage_HashTable_h

typedef struct Node **List;
struct HashTable {
    int size;
    List list;
};

struct HashTable *createHashTable(int size);
int nextPrime(int num);
boolean insertHashTable_Closed(int value, struct HashTable*table);
#endif
