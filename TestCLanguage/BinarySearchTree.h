//
//  BinarySearchTree.h
//  TestCLanguage
//
//  Created by Jason Huang on 7/4/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//
#include "Constant.h"
#ifndef TestCLanguage_BinarySearchTree_h
#define TestCLanguage_BinarySearchTree_h

struct BinarySearchTree {
    struct TreeNode *root;
};

struct BinarySearchTree *createBinarySearchTree();
boolean insert(struct BinarySearchTree *tree, Element_Type value);
boolean deleteTreeNode(struct BinarySearchTree *tree, Element_Type value);
struct TreeNode *findMin(struct BinarySearchTree *tree);
struct TreeNode *findMax(struct BinarySearchTree *tree);
boolean find(struct TreeNode *root, Element_Type value);
void traverseBinarySearchTree(struct BinarySearchTree *tree);
#endif
