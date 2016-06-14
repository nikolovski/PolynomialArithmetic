//
// Created by Martino Nikolovski on 6/9/16.
//

#ifndef POLYNOMIALARITHMETIC_POLYNOMIAL_H
#define POLYNOMIALARITHMETIC_POLYNOMIAL_H

#include "Term.h"

class Polynomial{
private:
    Term *first;
public:
    Polynomial();
    void insertTerm(Term &term);
    Polynomial operator+(const Polynomial& poly);
    Polynomial operator-(const Polynomial& poly);
    Polynomial operator*(const Polynomial& poly);
    void printPoly();

    ~Polynomial();


    Term *getFirst() const;

    void setFirst(Term *first);
};

#endif //POLYNOMIALARITHMETIC_POLYNOMIAL_H
