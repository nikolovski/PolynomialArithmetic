#include <iostream>
#include <fstream>
#include <sstream>
#include "Term.h"
#include "Polynomial.h"
using namespace std;
int countLines(string file);

int main() {
    string filename= "/Users/d4k1d23/ClionProjects/PolynomialArithmetic/input.txt";
    int poly_count=countLines(filename);

    Polynomial *polynomials = new Polynomial[poly_count];
    ifstream infile;
    infile.open(filename);
    string current_polynomial;
    int poly_iterator=0;

    //building the polynomials
    while(getline(infile,current_polynomial)){
        stringstream ss(current_polynomial);
        int current_coefficient, current_power;
        Term *temp;
        while(ss>>current_coefficient>>current_power){
             temp= new Term (current_coefficient,current_power);
            polynomials[poly_iterator].insertTerm(*temp);
        }
        poly_iterator++;
    }
    //printing the polynomials
    for (int i = 0; i < poly_count; ++i) {
        polynomials[i].printPoly();
        cout<<endl;
    }

    Polynomial polynomial = polynomials[0]-polynomials[1];
    polynomial.printPoly();
    delete [] polynomials;
    infile.close();
    return 0;
}

int countLines(string file){
    int count=0;
    ifstream infile;
    infile.open(file);
    string line;
    while(getline(infile,line)){
        count++;
    }
    infile.close();
    return count;
}