//#include "widget.h"

//--------------------------------------------------
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
//---------Header Local
#include "caixa1.h"

Caixa1::Caixa1(QObject *parent)
    : QObject{parent}
{

}


void Caixa1::_Graph()
{
    QMainWindow window;

    Q3DSurface *graph = new Q3DSurface;
    QWidget    *container = QWidget::createWindowContainer(graph);

    // Criação da série de dados
    QSurfaceDataProxy *dataProxy = new QSurfaceDataProxy();
    QSurface3DSeries *series = new QSurface3DSeries(dataProxy);

    // Adição dos pontos do plano ao gráfico
    QSurfaceDataArray *dataArray = new QSurfaceDataArray();
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
    QValue3DAxis *axisX = new QValue3DAxis();
    QValue3DAxis *axisY = new QValue3DAxis();
    QValue3DAxis *axisZ = new QValue3DAxis();



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



    window.setCentralWidget(container);
    window.resize(900, 900);
    window.show();



}
