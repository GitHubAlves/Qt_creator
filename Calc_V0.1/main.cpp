#include <QtWidgets/QApplication>
#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QSurfaceDataItem>
#include <QtDataVisualization/QCustom3DItem>
#include <QtDataVisualization/QCustom3DLabel>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QSurfaceDataItem>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QCustom3DItem>
#include <QtDataVisualization/QCustom3DLabel>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QSurfaceDataItem>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QCustom3DItem>
#include <QtDataVisualization/QCustom3DLabel>
#include <QtGui/QMouseEvent>
#include <QtGui/QScreen>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *mainWindow = new QWidget();
    mainWindow->setWindowTitle("Gráfico de Superfície 3D");

    // Criação da visualização de gráfico de superfície
    QtDataVisualization::Q3DSurface *graph = new QtDataVisualization::Q3DSurface();
    QWidget *container = QWidget::createWindowContainer(graph);
    container->setMinimumSize(800, 600);

    // Configuração dos eixos do gráfico
    QtDataVisualization::QValue3DAxis *axisX = new QtDataVisualization::QValue3DAxis();
    QtDataVisualization::QValue3DAxis *axisY = new QtDataVisualization::QValue3DAxis();
    QtDataVisualization::QValue3DAxis *axisZ = new QtDataVisualization::QValue3DAxis();
    graph->setAxisX(axisX);
    graph->setAxisY(axisY);
    graph->setAxisZ(axisZ);

    // Configuração dos dados do gráfico
    QtDataVisualization::QSurfaceDataProxy *dataProxy = new QtDataVisualization::QSurfaceDataProxy();
    QtDataVisualization::QSurface3DSeries *series = new QtDataVisualization::QSurface3DSeries(dataProxy);

    // Criação dos dados de mapa de altura
    int rowCount = 100; // Número de linhas
    int columnCount = 100; // Número de colunas
    QSurfaceDataArray *dataArray = new QSurfaceDataArray;
    dataArray->reserve(rowCount * columnCount);

    // Preenchimento dos dados do mapa de altura
    for (int i = 0; i < rowCount; ++i) {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(columnCount);
        qreal z = qSin(M_PI * i / rowCount);
        for (int j = 0; j < columnCount; ++j) {
            qreal x = (j / qreal(columnCount - 1)) - 0.5;
            qreal y = qSin(M_PI * j / columnCount + M_PI * i / rowCount);
            (*newRow)[j].setPosition(QVector3D(x, y, z));
        }
        *dataArray << newRow;
    }

    // Define o array de dados no proxy do gráfico
    dataProxy->resetArray(dataArray);

    // Adiciona a série ao gráfico
    graph->addSeries(series);

    // Configurações adicionais do gráfico
    graph->activeTheme()->setType(QtDataVisualization::Q3DTheme::ThemeEbony);

    // Configuração da janela principal
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWindow);
    mainLayout->addWidget(container);

    mainWindow->show();

    return app.exec();
}
