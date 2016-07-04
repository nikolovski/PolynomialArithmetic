//
// Created by Martino Nikolovski on 6/9/16.
//

#ifndef POLYNOMIALARITHMETIC_TERM_H
#define POLYNOMIALARITHMETIC_TERM_H

class Term{
private:
    int coeficient;
    int power;
    Term* next_term;

public:
    //default constructor
    Term();
    //constructor with 2 parameters
    Term(int c, int p);

    //GETTERS AND SETTERS

    int getCoeficient() const;


    void setCoeficient(int coeficient);

    int getPower() const;

    void setPower(int power);

    Term * getNext_term() ;

    void setNext_term(Term *next_term);

//printing term
    void print_term();
};
#endif //POLYNOMIALARITHMETIC_TERM_H
