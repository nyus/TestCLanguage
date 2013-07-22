//
//  Polynomial.h
//  TestCLanguage
//
//  Created by Jason Huang on 6/22/13.
//  Copyright (c) 2013 Jason Huang. All rights reserved.
//
#include "Constant.h"

#ifndef TestCLanguage_Polynomial_h
#define TestCLanguage_Polynomial_h

struct PolyNode {
    struct PolyNode *next;
    Element_Type coef;
    Element_Type degree;
};

struct Polynomial {
    struct PolyNode *head;
};


struct Polynomial *createPolynomials(int coef[] , int degree[]);
struct Polynomial *addTwoPolynomials(struct Polynomial *aPoly, struct Polynomial *bPoly);
struct Polynomial *multiplyTwoPolynomials(struct Polynomial *aPoly, struct Polynomial *bPoly);
#endif
