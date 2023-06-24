#ifndef SURFACE_H
#define SURFACE_H

#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include <QtWidgets/QSlider>

class SurfaceGraph : public QObject//Declaração da classe SurfaceGraph, que é uma subclasse de QObject e representa o gerenciador do gráfico de superfície.
{
    Q_OBJECT //Macro necessária para permitir o uso de recursos de meta-objeto do Qt, como sinais e slots.
public:
    explicit SurfaceGraph(Q3DSurface *surface);//Construtor da classe. SurfaceGraph, que recebe um ponteiro para um objeto Q3DSurface
    ~SurfaceGraph();//Destrutor

    void enableHeightMapModel(bool enable);//Habilita ou desabilita o modelo de mapa de altura no gráfico.
    void enableSqrtSinModel(bool enable);//Habilita ou desabilita o modelo de raiz quadrada do seno no gráfico.

    //! [0]
 //---------Funções para alternar entre os modos de seleção do gráfico.-----------------
    void toggleModeNone() { m_graph->setSelectionMode(QAbstract3DGraph::SelectionNone); }
    void toggleModeItem() { m_graph->setSelectionMode(QAbstract3DGraph::SelectionItem); }
    void toggleModeSliceRow() { m_graph->setSelectionMode(QAbstract3DGraph::SelectionItemAndRow
                                                          | QAbstract3DGraph::SelectionSlice); }
    void toggleModeSliceColumn() { m_graph->setSelectionMode(QAbstract3DGraph::SelectionItemAndColumn
                                                             | QAbstract3DGraph::SelectionSlice); }
    //! [0]
//---------Configura gradientes de cores para o gráfico.---------------------------------------------------------
    void setBlackToYellowGradient();
    void setGreenToRedGradient();
//-----End Configura gradientes de cores para o gráfico.---------------------------------------------------------

//--------Configura os controles deslizantes dos limites dos eixos X e Z do gráfico.----------------------------
    void setAxisMinSliderX(QSlider *slider) { m_axisMinSliderX = slider; }
    void setAxisMaxSliderX(QSlider *slider) { m_axisMaxSliderX = slider; }
    void setAxisMinSliderZ(QSlider *slider) { m_axisMinSliderZ = slider; }
    void setAxisMaxSliderZ(QSlider *slider) { m_axisMaxSliderZ = slider; }
//----End Configura os controles deslizantes dos limites dos eixos X e Z do gráfico.-----------------------------

//--------Ajusta os limites dos eixos X e Z do gráfico com base nos valores dos controles deslizantes------------
    void adjustXMin(int min);
    void adjustXMax(int max);
    void adjustZMin(int min);
    void adjustZMax(int max);
    float calculate(float, float);
//----End Ajusta os limites dos eixos X e Z do gráfico com base nos valores dos controles deslizantes------------


//--------Slot para alterar o tema do gráfico.-------------------------------------------------------------------
public Q_SLOTS:
    void changeTheme(int theme);
//----End Slot para alterar o tema do gráfico.-------------------------------------------------------------------

private:
    Q3DSurface *m_graph;//Ponteiro para um objeto da classe Q3DSurface
    QHeightMapSurfaceDataProxy *m_heightMapProxy;//Ponteiro para um objeto da classe ...
    //QHeightMapSurfaceDataProxy, usado para o modelo de mapa de altura
    QSurfaceDataProxy *m_sqrtSinProxy;//Ponteiro para um objeto da classe ...
    //QSurfaceDataProxy, usado para o modelo de raiz quadrada do seno
    QSurface3DSeries *m_heightMapSeries;//Ponteiro para um objeto da classe ...
    //QSurface3DSeries, usado para a série de dados do mapa de altura.
    QSurface3DSeries *m_sqrtSinSeries;//Ponteiro para um objeto da classe ...
    //QSurface3DSeries, usado para a série de dados da raiz quadrada do seno.

//--------Ponteiros para os controles deslizantes dos limites dos eixos X e Z.---------------------------------------
    QSlider *m_axisMinSliderX;//Ponteiro para um objeto da classe ...
    QSlider *m_axisMaxSliderX;//Ponteiro para um objeto da classe ...
    QSlider *m_axisMinSliderZ;//Ponteiro para um objeto da classe ...
    QSlider *m_axisMaxSliderZ;//Ponteiro para um objeto da classe ...
//----End Ponteiros para os controles deslizantes dos limites dos eixos X e Z.---------------------------------------

//--------Valores mínimos para os eixos X e Z------------------------------------------------------------------------

    float m_rangeMinX;
    float m_rangeMinZ;
//----End Valores mínimos para os eixos X e Z------------------------------------------------------------------------

//--------Valores de passo para os eixos X e Z------------------------------------------------------------------------
    float m_stepX;
    float m_stepZ;
    int m_heightMapWidth;
    int m_heightMapHeight;
//----End Valores de passo para os eixos X e Z------------------------------------------------------------------------


//--------Define o intervalo dos valores do eixo X.-------------------------------------------------------------------
    void setAxisXRange(float min, float max);
//--------Define o intervalo dos valores do eixo Z.-------------------------------------------------------------------
    void setAxisZRange(float min, float max);
//-------Preenche o objeto QSurfaceDataProxy com dados calculados usando a função fillSqrtSinProxy().-----------------
    void fillSqrtSinProxy();
};


#endif // SURFACE_H
