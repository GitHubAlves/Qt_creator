//Este arquivo gera a interface usuário, par ainserir
//a expressão f(x,y);

#include <QVBoxLayout>
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
    QVBoxLayout *_layout;
    QGroupBox   *_Box1;
    QGroupBox   *_Box2;
    QFormLayout *_layoutParaBox1;
    QFormLayout *_layoutParaBox2;
    QLineEdit   *_linha;
    QPushButton *_ButtonParaBox1;




};

#endif // INTERFACE_H
