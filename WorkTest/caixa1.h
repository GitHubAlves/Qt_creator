#ifndef CAIXA1_H
#define CAIXA1_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Caixa1 : public QObject
{
    Q_OBJECT
public:
    explicit Caixa1(QObject *parent = nullptr);

    void _Graph();

signals:

};

#endif // CAIXA1_H
