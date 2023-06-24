#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QPushButton>
#include <QGridLayout>
#include <QFormLayout>
#include <QApplication>
#include "caixa1.h"
//=========================================================================================
#include <QtWidgets/QApplication>


//----------------Header para campos editaveis------
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMainWindow>
//-----End------------------------------------------
#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include <QtDataVisualization/QValue3DAxis>
//header para criação de box na interface
#include <QtWidgets/QGroupBox>
//=========================================================================================

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

//============Implementação do widget do grafico de superfície==============
    //Criação do widget do gráfico 3D
    Q3DSurface *graph = new Q3DSurface();
    QWidget    *container = QWidget::createWindowContainer(graph);

    //criaçao de um layout para o gráfico de superficie
    QVBoxLayout *layout1=new QVBoxLayout;

    // Criação da série de dados
    QSurfaceDataProxy *dataProxy = new QSurfaceDataProxy();
    QSurface3DSeries *series = new QSurface3DSeries(dataProxy);

    // Adição dos pontos do plano ao gráfico
    QSurfaceDataArray *dataArray = new QSurfaceDataArray();
    QSurfaceDataRow   *dataRow;


//==========================================================================



    //O layout
    QHBoxLayout *layout= new QHBoxLayout;

     // QGridLayout *layout= new QGridLayout;
    //crio um objeto grupo box, para dentro colocar itens
    QGroupBox *Box1= new QGroupBox("Calc");
    //usado para plotar o grafico
    QGroupBox *Box2= new QGroupBox("Graph");
    Box2->setFixedSize(600, 600);

   // Criação do layout do QGroupBox
    //QVBoxLayout *layoutParaBox1= new QVBoxLayout;
    QFormLayout *layoutParaBox1= new QFormLayout;

    //Criação da linha editavel
    QLineEdit *linha=new QLineEdit;
    layoutParaBox1->addRow("Z=", linha);

    //este botao vai para um layout BOX1 que em seguida para dentro de uma caixa
    QPushButton *buttonparaBox1=new QPushButton("Enter");
    buttonparaBox1->setFixedSize(100, 20);
    layoutParaBox1->addWidget(buttonparaBox1);

    //layoutParaBox2->addWidget(linha1);//posso adicionar a funcao _Graph


    //defino o layout criado como o layout do groupbox-grupo da caixa tal ou itens da caixa tal
    Box1->setLayout(layoutParaBox1);



//=========================================================================================


//=========================================================================================
    layout->addWidget(Box1);
    layout->setContentsMargins(0, 10, 800, 10);

    w.setLayout(layout);



    w.show();
    return a.exec();
}
