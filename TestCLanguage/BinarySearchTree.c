//
//  BinarySearchTree.c
//  TestCLanguage
//
//  Created by Jason Huang on 7/4/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
struct BinarySearchTree *createBinarySearchTree(){
    struct BinarySearchTree *tree = (struct BinarySearchTree *)malloc(sizeof(struct BinarySearchTree));
    return tree;
}

boolean insert(struct BinarySearchTree *tree, Element_Type value){
    
    if(tree->root == NULL){
        tree->root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        tree->root->value = value;
        return YES;
    }else{
        struct TreeNode *temp = tree->root;
        while (temp!=NULL) {
            if(temp->value > value){
                if (temp->left == NULL) {
                    //insert;
                    temp->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                    temp->left->value = value;
                    break;
                }else{
                    temp = temp->left;
                }
            }else if(temp->value < value){
                if (temp->right == NULL) {
                    //insert
                    temp->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                    temp->right->value = value;
                    break;
                }else{
                    temp = temp->right;
                }
            }
        }
        
        if (temp==NULL) {
            return NO;
        }else{
            return YES;
        }
    }
}

boolean deleteTreeNode(struct BinarySearchTree *tree, Element_Type value);

struct TreeNode *findMin(struct BinarySearchTree *tree){
    struct TreeNode *temp = tree->root;
    while (temp!=NULL) {
        if (temp->left!=NULL) {
            temp = temp->left;
        }else{
            break;
        }
    }
    if (temp == NULL) {
        return NULL;
    }else{
        return temp;
    }
}
struct TreeNode *findMax(struct BinarySearchTree *tree){
    struct TreeNode *temp = tree->root;
    while (temp!=NULL) {
        if (temp->right!=NULL) {
            temp = temp->right;
        }else{
            break;
        }
    }
    if (temp == NULL) {
        return NULL;
    }else{
        return temp;
    }
}

boolean find(struct TreeNode *root, Element_Type value){
    struct TreeNode *temp = root;
    if (temp == NULL) {
        return NO;
    }else if(temp->value == value){
        return YES;
    }else if(temp->value > value){
        return find(temp->left, value);
    }else{
        return find(temp->right, value);
    }
}

void traverse(struct TreeNode *treeNode){
    
    if (treeNode == NULL) {
        return;
    }
    
    if (treeNode->left != NULL) {
        traverse(treeNode->left);
    }
    
    printf("%d ",treeNode->value);
    
    if (treeNode->right != NULL) {
        traverse(treeNode->right);
    }
}

void traverseBinarySearchTree(struct BinarySearchTree *tree){

    struct TreeNode *root = tree->root;
    
    traverse(root);
    
}


