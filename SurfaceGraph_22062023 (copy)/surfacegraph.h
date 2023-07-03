#ifndef SURFACEGRAPH_H
#define SURFACEGRAPH_H

#include <QtWidgets>
#include <Q3DSurface>
#include <QSurfaceDataProxy>
#include <QSurface3DSeries>
#include <QValue3DAxis>
#include <QString>
#include <string>
using std::string;

class SurfaceGraph : public QWidget
{
    Q_OBJECT

public:
    SurfaceGraph(QWidget *parent = nullptr);

    ~SurfaceGraph();
    float calc(float x, float y, int choice);
    void clearing();
    int op_Expr;
private:
    Q3DSurface        *graph;
    QSurfaceDataProxy *dataProxy;
    QSurface3DSeries  *series;
    QSurfaceDataArray *dataArray;
    QValue3DAxis      *axisX;
    QValue3DAxis      *axisY;
    QValue3DAxis      *axisZ;
    QHBoxLayout       *layoutSurface;
    QSurfaceDataRow   *dataRow;
//    QString           _letter;



};

#endif // SURFACEGRAPH_H
