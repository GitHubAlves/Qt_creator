#include "parsing.h"
#include <iostream>
using namespace std;
#include <string>

Parsing::Parsing(string Expr)
{
    _tamanhoString=Expr.size();
     _x=0;
     _y=0;
     Expressao="\0";
    //=========================
     _calcInParenteses=0;
     _calcOutParenteses=0;
     _vetAuxiliar[2]=0, 0;
     _B=0;
    //=========================

}

void Parsing::setExpressao(int value_x, int value_y, string expressao)
{
    _x=value_x;
    _y=value_y;
    _tamanhoString=expressao.size();
    Expressao=expressao;
    //============Percorre a expressão======================
    for(int i=0; i<_tamanhoString; i++)
    {
        if(expressao[i]==40) // se caso encontrar o inicio do parenteses
        {
            int a=i+1;
            int A=a;
            //percorre dentro dos parenteses procurando a precendência multiplicação
            while(expressao[A]!=41)//encotnrou o fim dos parenteses
            {
                if(expressao[A]==94)//se o indice for o acento circunflexo representando a potencia.
                {
                    if( (expressao[A+1]-'0')== 2 )//se o que vem depois do circunflexo é dois, então faz ao quadrado
                        _vetAuxiliar[0]= _x * _x;
                }
                if(expressao[A]==94)
                {
                    if( (expressao[A+1]-'0')== 2 )//se o que vem depois do circunflexo é dois, então faz ao quadrado
                    _vetAuxiliar[1]= _y * _y;
                }
                A++;
            }
            _calcInParenteses = _vetAuxiliar[0]+ _vetAuxiliar[1];
        }

    }

    for(int i=0; i<5; i++)
    {

        if(expressao[i]=='+' && expressao[i+1] != 40)
        {
            _calcOutParenteses=(expressao[i-1]-'0') + (expressao[i+1]-'0');
//            printf("\ncalcInParenteses=%d..", _calcInParenteses);
//            printf("\n+calcOutParenteses=%d..", _calcOutParenteses);
        }
        if(expressao[i]=='-' && expressao[i+1] != 40)
        {
            _calcOutParenteses=(expressao[i-1]-'0') - (expressao[i+1]-'0');
            //printf("\ncalcInParenteses=%d...", calcInParenteses);
            //printf("\n-calcOutParenteses=%d...", calcOutParenteses);
        }

        if(expressao[i]=='+' && expressao[i+1] == 40)
        {
            _calcOutParenteses=_calcOutParenteses + _calcInParenteses;//6+41
//            printf("\ncalcInParenteses=%d....", _calcInParenteses);
//            printf("\n++calcOutParenteses=%d....", _calcOutParenteses);
        }
        if(expressao[i]=='-' && expressao[i+1] == 40)
        {
            _calcOutParenteses=_calcOutParenteses - _calcInParenteses;//6-41
            //printf("\ncalcInParenteses=%d.....", _calcInParenteses);
            //printf("\n--calcOutParenteses=%d.....", _calcOutParenteses);
        }
    }

}

float Parsing::getExpressao()
{
    return _calcOutParenteses;
}

void Parsing::show()
{
    cout<<"O Resultado eh: "<<getExpressao()<<endl;
}
