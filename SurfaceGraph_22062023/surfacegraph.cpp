#include "surfacegraph.h"
#include "interface.h"

SurfaceGraph_::SurfaceGraph_(QWidget *parent): QWidget(parent)
{
    //Criação do widget do gráfico 3D
    graph = new Q3DSurface();

    // Criação da série de dados
    dataProxy = new QSurfaceDataProxy();
    series = new QSurface3DSeries(dataProxy);

    // Adição dos pontos do plano ao gráfico
    dataArray = new QSurfaceDataArray();

    QSurfaceDataRow   *dataRow;
    // Adicionando os pontos do plano
    for (int i = -10; i <= 10; i++) {
        dataRow = new QSurfaceDataRow();
        for (int j = -10; j <= 10; j++) {
            float x = i*0.5;
            float y = j*0.5;
            float z =2*(x+y)/10; // Equação do plano

            *dataRow << QVector3D(x, y, z);
        }
        dataArray->append(dataRow);
    }

    dataProxy->resetArray(dataArray);

    // Configuração dos eixos X, Y e Z
    axisX = new QValue3DAxis();
    axisY = new QValue3DAxis();
    axisZ = new QValue3DAxis();

    axisX->setRange(-5, 5);
    axisX->setLabelAutoRotation(360);
    axisY->setRange(-5, 5);
    axisY->setLabelAutoRotation(360);
    axisZ->setRange(-5, 5);
    axisZ->setLabelAutoRotation(360);

    // Adição da série e dos eixos ao gráfico
    graph->addSeries(series);
    graph->setAxisX(axisX);
    graph->setAxisY(axisY);
    graph->setAxisZ(axisZ);

    //criaçao de um layout
    layoutSurface = new QHBoxLayout;
    layoutSurface->addWidget(QWidget::createWindowContainer(graph));


    //this->setLayout(layoutSurface);
    this->resize(900, 900);

}

SurfaceGraph_::~SurfaceGraph_()
{
}

