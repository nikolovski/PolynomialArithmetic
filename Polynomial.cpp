//
// Created by Martino Nikolovski on 6/9/16.
//
#include <iostream>
#include "Polynomial.h"
Polynomial::Polynomial() {
    first=NULL;
}
void Polynomial::insertTerm(Term &term) {
    if(first==NULL){
        first = new Term();
        first->setNext_term(&term);
    }
    else{
        Term *temp =first;
        while (temp->getNext_term()){
            if(temp->getNext_term()->getPower()<term.getPower()){
                term.setNext_term(temp->getNext_term());
                temp->setNext_term(&term);
                break;
            }
            else if(temp->getNext_term()->getPower()==term.getPower()) {
                int coefficient = temp->getNext_term()->getCoeficient();
                temp->getNext_term()->setCoeficient(coefficient + term.getCoeficient());
                break;
            }
            else temp=temp->getNext_term();
        }
        if(temp->getNext_term()==NULL) temp->setNext_term(&term);
    }
}

Polynomial Polynomial::operator+(const Polynomial& poly){
    Polynomial polynomial;
    Term * temp1 = first->getNext_term();
    Term * temp2 = poly.first->getNext_term();
    Term * current;
    while (temp1!=NULL) {
        while(temp2!=NULL){
            if(temp1->getPower()==temp2->getPower()){
                current=new Term(temp1->getCoeficient()+temp2->getCoeficient(),temp2->getPower());
                polynomial.insertTerm(*current);
                break;
            }
            temp2=temp2->getNext_term();
        }
        temp1=temp1->getNext_term();
    }
    delete current;
    return polynomial;
}
Polynomial Polynomial::operator-(const Polynomial& poly){
    Polynomial polynomial;
    Term * temp1 = first->getNext_term();
    Term * temp2 = poly.first->getNext_term();
    Term * current;
    while (temp1!=NULL) {
        while(temp2!=NULL){
            if(temp1->getPower()==temp2->getPower()){
                current=new Term(temp1->getCoeficient()-temp2->getCoeficient(),temp2->getPower());
                polynomial.insertTerm(*current);
                break;
            }
            temp2=temp2->getNext_term();
        }
        temp1=temp1->getNext_term();
    }
    delete current;
    return polynomial;
}

void Polynomial::printPoly() {
    Term *temp = first->getNext_term();
    while(temp!=NULL){
        temp->print_term();
        temp=temp->getNext_term();
    }
}
Term* Polynomial::getFirst() const {
    return first;
}

void Polynomial::setFirst(Term *first) {
    first = first;
}


Polynomial::~Polynomial() {
    delete first;
}