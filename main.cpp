#include <iostream>
#include <fstream>
#include <sstream>
#include "Term.h"
#include "Polynomial.h"
using namespace std;

int countLines(string file);
void printHeader();

int main(int argc,char *argv[]) {
    printHeader();
    if(argc!=2) {
        cout<<"Please enter file as an input parameter containing polynomials. It is recommended that the full directory"
                "+ filename + extension is entered."<<endl;
        exit(1);
    }
    string filename= argv[1];

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
        cout<<"Polynomial "<<(i+1)<<":"<<endl;
        polynomials[i].printPoly();
        cout<<endl<<endl;
    }

    //Polynomial operations
    for (int j = 0; j < poly_count; j+=2) {
        //addition
        cout<<"Polynomial "<<(j+1)<<" + Polynomial "<<(j+2)<<":"<<endl;
        (polynomials[j]+polynomials[j+1]).printPoly();
        cout<<endl<<endl;
        //subtraction
        cout<<"Polynomial "<<(j+1)<<" - Polynomial "<<(j+2)<<":"<<endl;
        (polynomials[j]-polynomials[j+1]).printPoly();
        cout<<endl<<endl;
        //multiplication
        cout<<"Polynomial "<<(j+1)<<" * Polynomial "<<(j+2)<<":"<<endl;
        (polynomials[j]*polynomials[j+1]).printPoly();
        cout<<endl<<endl;
    }
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

void printHeader(){
    cout<<"Polynomial Arithmetic provided by\n"
                  "          .--.  ,---.  _______ ,-..-. .-. .---.\n"
                  "|\\    /| / /\\ \\ | .-.\\|__   __||(||  \\| |/ .-. )\n"
                  "|(\\  / |/ /__\\ \\| `-'/  )| |   (_)|   | || | |(_)\n"
                  "(_)\\/  ||  __  ||   (  (_) |   | || |\\  || | | |\n"
                  "| \\  / || |  |)|| |\\ \\   | |   | || | |)|\\ `-' /\n"
                  "| |\\/| ||_|  (_)|_| \\)\\  `-'   `-'/(  (_) )---'\n"
                  "'-'  '-'            (__)         (__)    (_)"<<endl<<endl;
}