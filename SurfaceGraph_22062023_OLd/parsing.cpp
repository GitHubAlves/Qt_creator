//#include "parsing.h"
//#include <string.h>
//using namespace std;

//Parsing::Parsing(int x, int y, string Expr)
//{
//    _x=x;
//    _y=y;
//    _Expr=Expr;
//    _calcOutParenteses=0;
//}

//void Parsing::setparsingEpr(int x, int y, string expressao)
//{
//    int calcInParenteses=0;
//    //int calcOutParenteses=0;
//    int vetAuxiliar[2];
//    int B=0;

//    int TamanhoExpressao=strlen(expressao);
//    char vetorDeArmazenamento[TamanhoExpressao];

////2+4+(x^2+y^2); para x=2, y=3
////===============Percorre a função======================================================
//    for(int i=0; i<TamanhoExpressao; i++)
//    {
//        if(expressao[i]==40) //'('
//        {
//            int a=i+1;
//            int A=a;
//            //percorre dentro dos parenteses procurando a precedencia Multiplicação
//            while(expressao[A]!=41)//encotnrou o inicio dos parenteses
//            {
//                if(expressao[A]==94)//se o indice for o acento circunflexo representando a potencia.
//                {
//                    if( (expressao[A+1]-'0')== 2 )//se o que vem depois do acento circunflexo é 2, então faz ao quadrado
//                    {
//                        vetAuxiliar[0]= x * x;
//                    }
//                }
//                if(expressao[A]==94)
//                {
//                    if( (expressao[A+1]-'0')== 2 )//se o que vem depois do acento circunflexo é 2, então faz ao quadrado
//                    {
//                        vetAuxiliar[1]= y * y;
//                    }
//                }
//                A++;
//            }
//            calcInParenteses = vetAuxiliar[0]+vetAuxiliar[1];
//            //printf("\nSoma=%.2f", (float)calcInParenteses);
//        }
//    }

//    for(int i=0; i<5; i++)
//    {

//     if(expressao[i]=='+' && expressao[i+1] != 40)
//        {
//            _calcOutParenteses=(expressao[i-1]-'0') + (expressao[i+1]-'0');
//            //printf("\ncalcInParenteses=%d..", calcInParenteses);
//            //printf("\n+calcOutParenteses=%d..", calcOutParenteses);
//        }
//        if(expressao[i]=='-' && expressao[i+1] != 40)
//        {
//            _calcOutParenteses=(expressao[i-1]-'0') - (expressao[i+1]-'0');
//            //printf("\ncalcInParenteses=%d...", calcInParenteses);
//            /qprintf("\n-calcOutParenteses=%d...", _calcOutParenteses);
//        }

//        if(expressao[i]=='+' && expressao[i+1] == 40)
//        {
//            _calcOutParenteses=_calcOutParenteses + calcInParenteses;//6+41
//            //printf("\ncalcInParenteses=%d....", calcInParenteses);
//            //printf("\n++calcOutParenteses=%d....", calcOutParenteses);
//        }
//        if(expressao[i]=='-' && expressao[i+1] == 40)
//        {
//            _calcOutParenteses=_calcOutParenteses - calcInParenteses;//6-41
//            //printf("\ncalcInParenteses=%d.....", calcInParenteses);
//            //printf("\n--calcOutParenteses=%d.....", calcOutParenteses);
//        }

//    }
//    //printf("\nResultado final= %.2f.", (float)calcOutParenteses);//2+4+(x^2+y^2); para x=2, y=3


//}

//float Parsing::getParsingEpr()
//{
//    return (float)_calcOutParenteses;
//}
