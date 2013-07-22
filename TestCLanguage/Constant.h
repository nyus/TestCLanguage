//
//  Constant.h
//  TestCLanguage
//
//  Created by Jason Huang on 6/8/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//

#ifndef TestCLanguage_Constant_h
#define TestCLanguage_Constant_h
#define NOT_EXIST -9999999
typedef int boolean;
enum boolean {NO, YES};
typedef int Element_Type;
struct Node {
    Element_Type value;
    struct Node *next;
};
struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    Element_Type value;
};
#endif
