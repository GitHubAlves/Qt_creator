
#include "Surface.h"

#include <QtDataVisualization/QValue3DAxis>
#include <QtDataVisualization/Q3DTheme>
#include <QtGui/QImage>
#include <QtCore/qmath.h>

float sampleCountX = 50.0;
float sampleCountZ = 50.0;
const int heightMapGridStepX = 12;
const int heightMapGridStepZ = 12;
const float sampleMin = 0.0f;
const float sampleMax = 12.0f;

SurfaceGraph::SurfaceGraph(Q3DSurface *surface) : m_graph(surface)//construtor é responsável por gerenciar o gráfico
{
//Ele recebe um objeto Q3DSurface como parâmetro e inicializa as configurações básicas do gráfico
    m_graph->setAxisX(new QValue3DAxis);
    m_graph->setAxisY(new QValue3DAxis);
    m_graph->setAxisZ(new QValue3DAxis);

    //! [0]
    m_sqrtSinProxy = new QSurfaceDataProxy();//é criado como uma instância de QSurfaceDataProxy.
    m_sqrtSinSeries = new QSurface3DSeries(m_sqrtSinProxy);//é criado como uma instância de QSurface3DSeries utilizando o m_sqrtSinProxy criado anteriormente.
    //! [0]
    fillSqrtSinProxy();//A função fillSqrtSinProxy() é chamada para preencher os dados do proxy m_sqrtSinProxy

    //! [2]
    QImage heightMapImage(" ");
    m_heightMapProxy = new QHeightMapSurfaceDataProxy();
    m_heightMapSeries = new QSurface3DSeries(m_heightMapProxy);
    m_heightMapSeries->setItemLabelFormat(QStringLiteral("(@xLabel, @zLabel): @yLabel"));//ormatação do rótulo do item da série m_heightMapSeries é definida como "(@xLabel, @zLabel): @yLabel".
    m_heightMapProxy->setValueRanges(120.0f, 120.0f, 120.0f, 120.0f);//Os intervalos de valores do proxy m_heightMapProxy são definidos como 34.0f a 40.0f para o eixo X e 18.0f a 24.0f para o eixo Z
    //! [2]
//---As dimensões da imagem heightMapImage são armazenadas nas variáveis m_heightMapWidth e m_heightMapHeight.
    m_heightMapWidth = heightMapImage.width();
    m_heightMapHeight = heightMapImage.height();
}

SurfaceGraph::~SurfaceGraph()
{
    delete m_graph;
}

//! [1] 
//A função fillSqrtSinProxy() é definida. Ela preenche o proxy m_sqrtSinProxy com dados de superfície calculados com base em equações matemáticas.
//O laço principal itera sobre os valores de Z e X e calcula os valores de Y para cada ponto da superfície.
void SurfaceGraph::fillSqrtSinProxy()
{
    float stepX = (sampleMax - sampleMin) / float(sampleCountX - 1);
    float stepZ = (sampleMax - sampleMin) / float(sampleCountZ - 1);

    QSurfaceDataArray *dataArray = new QSurfaceDataArray;
    dataArray->reserve(sampleCountZ);
    for (int i = 0 ; i < sampleCountZ ; i++) {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(sampleCountX);//Os valores de X, Y e Z são armazenados em um objeto QSurfaceDataRow e adicionados ao dataArray

        float z = qMin(sampleMax, (i * stepZ + sampleMin));
        int index = 0;
        for (int j = 0; j < sampleCountX; j++) {
            float x = qMin(sampleMax, (j * stepX + sampleMin));
            float R = qSqrt(z * z + x * x) + 0.01f;
            float y = (qSin(R) / R + 0.24f) * 1.61f;
            (*newRow)[index++].setPosition(QVector3D(x, y, z));//Os valores de X, Y e Z são armazenados em um objeto QSurfaceDataRow e adicionados ao dataArray
        }
        *dataArray << newRow;//Os valores de X, Y e Z são armazenados em um objeto QSurfaceDataRow e adicionados ao dataArray
        }



    m_sqrtSinProxy->resetArray(dataArray);
}
//! [1]
//A função enableSqrtSinModel() é definida. Ela habilita o modelo de função sqrt(sin()) para o gráfico de superfície
//Se enable for verdadeiro, algumas configurações são ajustadas para exibir corretamente o modelo sqrt(sin()) no gráfico.
void SurfaceGraph::enableSqrtSinModel(bool enable)
{
    if (enable) {
        //! [3]
        m_sqrtSinSeries->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
        m_sqrtSinSeries->setFlatShadingEnabled(true);

        m_graph->axisX()->setLabelFormat("%.2f");
        m_graph->axisZ()->setLabelFormat("%.2f");
        m_graph->axisX()->setRange(sampleMin, sampleMax);
        m_graph->axisY()->setRange(0.0f, 2.0f);
        m_graph->axisZ()->setRange(sampleMin, sampleMax);
        m_graph->axisX()->setLabelAutoRotation(30);
        m_graph->axisY()->setLabelAutoRotation(90);
        m_graph->axisZ()->setLabelAutoRotation(30);

        m_graph->removeSeries(m_heightMapSeries);
        m_graph->addSeries(m_sqrtSinSeries);
        //! [3]

        //! [8]
        // Reset range sliders for Sqrt&Sin
        m_rangeMinX = sampleMin;
        m_rangeMinZ = sampleMin;
        m_stepX = (sampleMax - sampleMin) / float(sampleCountX - 1);
        m_stepZ = (sampleMax - sampleMin) / float(sampleCountZ - 1);
        m_axisMinSliderX->setMaximum(sampleCountX - 2);
        m_axisMinSliderX->setValue(0);
        m_axisMaxSliderX->setMaximum(sampleCountX - 1);
        m_axisMaxSliderX->setValue(sampleCountX - 1);
        m_axisMinSliderZ->setMaximum(sampleCountZ - 2);
        m_axisMinSliderZ->setValue(0);
        m_axisMaxSliderZ->setMaximum(sampleCountZ - 1);
        m_axisMaxSliderZ->setValue(sampleCountZ - 1);
        //! [8]
    }
}

void SurfaceGraph::enableHeightMapModel(bool enable)
{
    if (enable) {
        //! [4]
        m_heightMapSeries->setDrawMode(QSurface3DSeries::DrawSurface);
        m_heightMapSeries->setFlatShadingEnabled(false);

        m_graph->axisX()->setLabelFormat("%.1f N");
        m_graph->axisZ()->setLabelFormat("%.1f E");
        m_graph->axisX()->setRange(34.0f, 40.0f);
        m_graph->axisY()->setAutoAdjustRange(true);
        m_graph->axisZ()->setRange(18.0f, 24.0f);

        m_graph->axisX()->setTitle(QStringLiteral("Latitude"));
        m_graph->axisY()->setTitle(QStringLiteral("Height"));
        m_graph->axisZ()->setTitle(QStringLiteral("Longitude"));

        m_graph->removeSeries(m_sqrtSinSeries);
        m_graph->addSeries(m_heightMapSeries);
        //! [4]

        // Reset range sliders for height map
        int mapGridCountX = m_heightMapWidth / heightMapGridStepX;
        int mapGridCountZ = m_heightMapHeight / heightMapGridStepZ;
        m_rangeMinX = 34.0f;
        m_rangeMinZ = 18.0f;
        m_stepX = 6.0f / float(mapGridCountX - 1);
        m_stepZ = 6.0f / float(mapGridCountZ - 1);
        m_axisMinSliderX->setMaximum(mapGridCountX - 2);
        m_axisMinSliderX->setValue(0);
        m_axisMaxSliderX->setMaximum(mapGridCountX - 1);
        m_axisMaxSliderX->setValue(mapGridCountX - 1);
        m_axisMinSliderZ->setMaximum(mapGridCountZ - 2);
        m_axisMinSliderZ->setValue(0);
        m_axisMaxSliderZ->setMaximum(mapGridCountZ - 1);
        m_axisMaxSliderZ->setValue(mapGridCountZ - 1);
    }
}

void SurfaceGraph::adjustXMin(int min)
{
    float minX = m_stepX * float(min) + m_rangeMinX;

    int max = m_axisMaxSliderX->value();
    if (min >= max) {
        max = min + 1;
        m_axisMaxSliderX->setValue(max);
    }
    float maxX = m_stepX * max + m_rangeMinX;

    setAxisXRange(minX, maxX);
}

void SurfaceGraph::adjustXMax(int max)
{
    float maxX = m_stepX * float(max) + m_rangeMinX;

    int min = m_axisMinSliderX->value();
    if (max <= min) {
        min = max - 1;
        m_axisMinSliderX->setValue(min);
    }
    float minX = m_stepX * min + m_rangeMinX;

    setAxisXRange(minX, maxX);
}

void SurfaceGraph::adjustZMin(int min)
{
    float minZ = m_stepZ * float(min) + m_rangeMinZ;

    int max = m_axisMaxSliderZ->value();
    if (min >= max) {
        max = min + 1;
        m_axisMaxSliderZ->setValue(max);
    }
    float maxZ = m_stepZ * max + m_rangeMinZ;

    setAxisZRange(minZ, maxZ);
}

void SurfaceGraph::adjustZMax(int max)
{
    float maxX = m_stepZ * float(max) + m_rangeMinZ;

    int min = m_axisMinSliderZ->value();
    if (max <= min) {
        min = max - 1;
        m_axisMinSliderZ->setValue(min);
    }
    float minX = m_stepZ * min + m_rangeMinZ;

    setAxisZRange(minX, maxX);
}

//! [5]
void SurfaceGraph::setAxisXRange(float min, float max)
{
    m_graph->axisX()->setRange(min, max);
}

void SurfaceGraph::setAxisZRange(float min, float max)
{
    m_graph->axisZ()->setRange(min, max);
}
//! [5]

//! [6]
void SurfaceGraph::changeTheme(int theme)
{
    m_graph->activeTheme()->setType(Q3DTheme::Theme(theme));
}
//! [6]

void SurfaceGraph::setBlackToYellowGradient()
{
    //! [7]
    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::black);
    gr.setColorAt(0.33, Qt::blue);
    gr.setColorAt(0.67, Qt::red);
    gr.setColorAt(1.0, Qt::yellow);

    m_graph->seriesList().at(0)->setBaseGradient(gr);
    m_graph->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
    //! [7]
}

void SurfaceGraph::setGreenToRedGradient()
{
    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::darkGreen);
    gr.setColorAt(0.5, Qt::yellow);
    gr.setColorAt(0.8, Qt::red);
    gr.setColorAt(1.0, Qt::darkRed);

    m_graph->seriesList().at(0)->setBaseGradient(gr);
    m_graph->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
}

float SurfaceGraph::calculate(float x , float y)
{

    return x*x+y*y;

}
