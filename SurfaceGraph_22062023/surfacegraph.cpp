#include "surfacegraph.h"
#include "interface.h"
#include <QtWidgets>
#include <string>
using std::string;





SurfaceGraph::SurfaceGraph(QWidget *parent): QWidget(parent)
{    
    //Criação do widget do gráfico 3D
    graph = new Q3DSurface();

    // Criação da série de dados
    dataProxy = new QSurfaceDataProxy();
    series = new QSurface3DSeries(dataProxy);

    // Adição dos pontos do plano ao gráfico
    dataArray = new QSurfaceDataArray();


    //     Adicionando os pontos do plano
    for (int i = -10; i <= 10; i++)
    {
        dataRow = new QSurfaceDataRow();
        for (int j = -10; j <= 10; j++) {
            float x = i*0.5;
            float y = j*0.5;
           float z =calc(x, y, op_Expr);
            qDebug()<<"for"<<op_Expr;
            *dataRow << QVector3D(x, y, z);
        }
        dataArray->append(dataRow);
    }

    dataProxy->resetArray(dataArray);


    // Configuração dos eixos X, Y e Z
    axisX = new QValue3DAxis();
    axisY = new QValue3DAxis();
    axisZ = new QValue3DAxis();

    axisX->setRange(-100, 100);
    axisX->setLabelAutoRotation(360);
    axisY->setRange(-100, 100);
    axisY->setLabelAutoRotation(360);
    axisZ->setRange(-100, 100);
    axisZ->setLabelAutoRotation(360);

    //    // Adição da série e dos eixos ao gráfico
    graph->addSeries(series);
    graph->setAxisX(axisX);
    graph->setAxisY(axisY);
    graph->setAxisZ(axisZ);

    //    //criaçao de um layout
    layoutSurface = new QHBoxLayout;
    layoutSurface->addWidget(QWidget::createWindowContainer(graph));

    this->setLayout(layoutSurface);
        //this->resize(300, 300);
}

void SurfaceGraph::clearing()
{
    dataArray->clear();
    SurfaceGraph::~SurfaceGraph();

}

float SurfaceGraph::calc(float x, float y, int op)
{
    int i=0;
    op_Expr=op;
 qDebug()<<"cl-"<<op;

    if(op_Expr==1)
    {
        return x+y;
    }
    if(op_Expr==7)
    {
        return x*x+y*y;    
    }
    else
        qDebug()<<"nothing "<<i++;

}


SurfaceGraph::~SurfaceGraph(){ }

