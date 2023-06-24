#include <string.h>
using namespace std;

#ifndef PARSING_H
#define PARSING_H

#include <QWidget>

class Parsing
{

public:
    Parsing(int, int, string);
    void  setparsingEpr(int, int, string);
    float getParsingEpr();


private:
    int _x;
    int _y;
    int _calcOutParenteses;
    string _Expr;

};

#endif // PARSING_H
