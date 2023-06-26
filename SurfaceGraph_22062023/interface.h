//Este arquivo gera a interface usuário, par ainserir
//a expressão f(x,y);
#include "surfacegraph.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

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
    QFormLayout   *_layoutParaBox2;
    QLineEdit     *_linha;
    QPushButton   *_ButtonParaBox1;
    SurfaceGraph_ *_surfaGraph;



};

#endif // INTERFACE_H
