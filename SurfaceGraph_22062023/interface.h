//Este arquivo gera a interface usuário, par ainserir
//a expressão f(x,y);
#ifndef INTERFACE_H
#define INTERFACE_H

#include "surfacegraph.h"
#include "parsing.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QString>


class Interface : public QWidget
{
    Q_OBJECT
public:
    Interface(QWidget *parent=nullptr);   
    ~Interface();

private:
    QHBoxLayout   *_layout;
    QGroupBox     *_Box1;
    QGroupBox     *_Box2;
    QFormLayout   *_layoutParaBox1;
    QVBoxLayout   *_layoutParaBox2;
    QLineEdit     *_linha;
    QPushButton   *_ButtonParaBox1;
    QString       *_text;
    SurfaceGraph  *_graph;

};

#endif // INTERFACE_H
