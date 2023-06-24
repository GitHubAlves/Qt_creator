#ifndef SURFACEGRAPH_H
#define SURFACEGRAPH_H

#include <QtWidgets>

#include <Q3DSurface>
#include <QSurfaceDataProxy>
#include <QSurface3DSeries>
#include <QValue3DAxis>

class SurfaceGraph : public QWidget
{
    Q_OBJECT

public:
    SurfaceGraph(QWidget *parent = nullptr);
    ~SurfaceGraph();

private:
    Q3DSurface *graph;
    QSurfaceDataProxy *dataProxy;
    QSurface3DSeries *series;
    QSurfaceDataArray *dataArray;
    QValue3DAxis *axisX;
    QValue3DAxis *axisY;
    QValue3DAxis *axisZ;

    QHBoxLayout * layout;
};
#endif // SURFACEGRAPH_H
