//
//  Header.h
//  TestCLanguage
//
//  Created by Jason Huang on 6/2/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//

#include "Constant.h"
#ifndef TestCLanguage_Header_h
#define TestCLanguage_Header_h

struct List {
    struct Node *head;
};

struct List *createList();
void traverseList(struct Node *head);
struct Node *findNode(struct Node *header, Element_Type value);
struct Node *findPrevious(struct Node *head, Element_Type value);
boolean insertNode(struct Node *header, Element_Type valueToInsert);
boolean insertNodeAtIndex(struct Node *header, Element_Type valueToInsert, int index);
boolean deleteNode(struct Node *header, Element_Type valueToDelete);
struct List *intersectionOfLists(struct List *aList, struct List *bList);
struct List *unionOfLists(struct List *aList, struct List *bList);
struct List *reverseListWithConstantExSpace(struct List *list);
struct Node *findNodeRecursive(struct Node *node, Element_Type value);
#endif
