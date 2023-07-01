#include "parsing.h"

#include <iostream>
using namespace std;
#include <string>

Parsing::Parsing(string Expr)
{
    _tamanhoString=Expr.size();
     _x=0;
     _y=0;
     expressao=Expr;
    //=========================
     _calcInParenteses=0;
     _calcOutParenteses=0;
     _vetAuxiliar[2];
     _B=0;
    //=========================

}

void Parsing::setExpressao(string  Expr){

     _tamanhoString=Expr.size();
     _x=0;
     _y=0;
     expressao=Expr;
     //=========================
     _calcInParenteses=0;
     _calcOutParenteses=0;
     _vetAuxiliar[0] = 0;
     _vetAuxiliar[1] = 0;
     _B=0;
     //=========================
     //("2+2+(x*x+y*y)");
}

int Parsing::calcula(int x, int y)
{
     //============Percorre a expressão======================
     return -4+(x*x+y*y);
}





//void Parsing::show()
//{
//    cout<<"O Resultado eh: "<<_calcOutParenteses<<endl;

//}
