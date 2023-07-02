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
    _expr = new Parsing("(x*x+y*y)/10");

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

    _ButtonParaBox1 =new QPushButton("Enter");
    _ButtonParaBox1->setFixedSize(100, 20);
    _layoutParaBox1->addWidget(_ButtonParaBox1);

    _plotButton =new QPushButton("Plot");
    _layoutParaBox1->addWidget(_plotButton);

    _Box1->setLayout(_layoutParaBox1);

    _graph =  new SurfaceGraph();
    _layoutParaBox2->addWidget(_graph);
    _Box2->setLayout(_layoutParaBox2);

    _layout->addWidget(_Box1);
    _layout->addWidget(_Box2);

    QObject::connect(_ButtonParaBox1, SIGNAL(clicked(bool)),
                     this, SLOT(_ButtonParaBox1_clicked()));

    QObject::connect(_plotButton, SIGNAL(clicked(bool)),
                     this, SLOT(_plotButton_clicked()));

    this->setLayout(_layout);
}

void Interface::_ButtonParaBox1_clicked(){
    _expr->setExpressao(_linha->text().toStdString());
};

void Interface::_plotButton_clicked(){
    //geracao dos pontos
    float result;
    for (int i = -10; i <= 10; i++) {
        for (int j = -10; j <= 10; j++) {
            result = _expr->calcula(i*0.5, j*0.5);
            qDebug() << "x,y,z = "  << i <<  "," << j <<  "," << result <<  "\n";
        }
    }
};

Interface::~Interface()
{

}

