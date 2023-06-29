#include "interface.h"
#include "parsing.h"
#include "surfacegraph.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

Interface::Interface(QWidget *parent) : QWidget(parent)
{
    Parsing Exec_Expr;

     //O layout
    _layout         =new QHBoxLayout;

      //Box para inserir a expressão
    _Box1           =new QGroupBox("Calc");

    //Box para apresentar o gráfico de superfície
    _Box2           =new QGroupBox("Graph");
    _Box2->setMinimumSize(600,600);

    //Criação do layout para a o box 1 e box 2
    _layoutParaBox1 =new QFormLayout;
    _layoutParaBox2 =new QVBoxLayout;

    //Criação de linha editavel
    _linha          =new QLineEdit;
    _layoutParaBox1->addRow("Z=", _linha);
    //pega a expressao digitada na linha
    _text =  _linha->text();

    _ButtonParaBox1 =new QPushButton("Enter");
    _ButtonParaBox1->setFixedSize(100, 20);
    _layoutParaBox1->addWidget(_ButtonParaBox1);


    _Box1->setLayout(_layoutParaBox1);

    _graph =  new SurfaceGraph();
    _layoutParaBox2->addWidget(_graph);
    _Box2->setLayout(_layoutParaBox2);

    _layout->addWidget(_Box1);
    _layout->addWidget(_Box2);

    //QObject::connect(_ButtonParaBox1, &QPushButton::clicked, Exec_Expr.getExpressao());
    this->setLayout(_layout);
}


Interface::~Interface()
{

}

