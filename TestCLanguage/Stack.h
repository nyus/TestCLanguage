//
//  Stack.h
//  TestCLanguage
//
//  Created by Jason Huang on 6/8/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//
#include "Constant.h"
#include "List.h"
#ifndef TestCLanguage_Stack_h
#define TestCLanguage_Stack_h

struct Stack {
    struct Node *head;
    struct Node *first;
    struct Node *last;
};

struct Stack *createStack();
void push(struct Stack *stack, Element_Type value);
Element_Type pop(struct Stack *stack);
struct Node *findPreviousOfLastNodeInStack(struct Node *last, struct Stack *stack);
#endif
