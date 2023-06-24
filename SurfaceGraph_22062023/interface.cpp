#include "interface.h"
#include "surfacegraph.h"

#include <QVBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

Interface::Interface(QWidget *parent)
    : QWidget{parent}
{
     //O layout
    _layout         =new QVBoxLayout;

      //Box para inserir a expressão
    _Box1           =new QGroupBox("Calc");

    //Box para apresentar o gráfico de superfície
    _Box2           =new QGroupBox("Graph");
    _Box2->setFixedSize(600, 600);

    //Craição do layout para a o box 1 e box 2
    _layoutParaBox1 =new QFormLayout;
    _layoutParaBox2 =new QFormLayout;

    //Criação de linha editavel
    _linha          =new QLineEdit;
    _layoutParaBox1->addRow("Z=", _linha);


    _ButtonParaBox1 =new QPushButton;
    _ButtonParaBox1->setFixedSize(100, 20);
    _layoutParaBox1->addWidget(_ButtonParaBox1);


    _Box1->setLayout(_layoutParaBox1);
    _Box2->setLayout(_layoutParaBox2);


    _layout->addWidget(_Box1);
    _layout->addWidget(_Box2);

    this->setLayout(_layout);
}

Interface::~Interface()
{

}

