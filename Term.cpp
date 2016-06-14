//
// Created by Martino Nikolovski on 6/9/16.
//

#include <iostream>
#include "Term.h"

Term::Term() {
    coeficient = 1;
    power =0;
    next_term=NULL;
}

Term::Term(int c, int p) {
    if(p<0){
        std::cout<<"Invalid term. The power has to be positive!"<<std::endl;
        exit(1);
    }
    coeficient = c;
    power = p;
    next_term=NULL;
}

int Term::getCoeficient() const {
    return coeficient;
}

void Term::setCoeficient(int coeficient) {
    this->coeficient=coeficient;
}

int Term::getPower() const {
    return power;
}

void Term::setPower(int power) {
    this->power=power;
}

Term * Term::getNext_term() {
    return next_term;
}

void Term::setNext_term(Term *next_term) {
    this->next_term=next_term;
}

void Term::print_term() {
    if(coeficient>0) std::cout<<"+";
    if(coeficient==0) return;
    else if(power==0) std::cout<<coeficient<<" ";
    else std::cout<<coeficient<<"x^"<<power<<" ";
}
