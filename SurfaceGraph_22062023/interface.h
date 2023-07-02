//Este arquivo gera a interface usuário, par ainserir
//a expressão f(x,y);
#ifndef INTERFACE_H
#define INTERFACE_H

#include "surfacegraph.h"


#include <QVBoxLayout>
#include <QSurfaceDataProxy>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <QSurfaceDataArray>


class Interface : public QWidget
{
    Q_OBJECT
public:
    Interface(QWidget *parent=nullptr);   
    ~Interface();

public slots:
    //void _ButtonParaBox1_clicked();
      void _plotButton_clicked();

private:
    QHBoxLayout     *_layout;
    QGroupBox       *_Box1;
    QGroupBox       *_Box2;
    QFormLayout     *_layoutParaBox1;
    QVBoxLayout     *_layoutParaBox2;
    QLineEdit       *_linha;
    QPushButton     *_ButtonParaBox1;
    QPushButton     *_plotButton;
    QString         *_text;
    SurfaceGraph    *_graph;
    QSurfaceDataRow *dataRow;
    QSurfaceDataArray *dataArray;
    QSurfaceDataProxy  *dataProxy;
    SurfaceGraph      *geratorGraph;
};

#endif // INTERFACE_H
