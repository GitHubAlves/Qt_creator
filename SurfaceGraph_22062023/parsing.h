
#ifndef PARSING_H
#define PARSING_H

#include <iostream>
#include <string>
using namespace std;

class Parsing
{
public:
    Parsing(string Expr);
    void  setExpressao(string Expr);
    string getExpressao() { return expressao; }
    int calcula(int x, int y);
    void show();


private:
    int _tamanhoString=0;
    int _x=0;
    int _y=0;
    string expressao="";
    //=========================
    int _calcInParenteses=0;
    int _calcOutParenteses=0;
    int _vetAuxiliar[2];
    int _B=0;
};

#endif // PARSING_H
