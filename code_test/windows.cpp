#include "windows.h"
#include <QGroupBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>

Window::Window(QWidget *parents) : QWidget(parents)
{
    QGridLayout *grid = new QGridLayout;

    grid->addWidget(CampoForFunction(), 0, 0);
    grid->addWidget(CampoForGraph(), 0, 1);
    setLayout(grid);

    setWindowTitle(tr("Caixa de exemplos"));
    resize(700, 700);
}


QGroupBox *Window::CampoForGraph()
{
    QGroupBox   *grupoCaixa= new QGroupBox(tr("funcao"));
    QPushButton *botao=new QPushButton;
    QLineEdit   *linEdit= new QLineEdit(linEdit);

    QVBoxLayout *Vbox=new QVBoxLayout;   
    Vbox->addWidget(linEdit);
     Vbox->addWidget(botao);

    Vbox->addStretch(1);
    grupoCaixa->setLayout(Vbox);
    return grupoCaixa;

}

QGroupBox *Window::CampoForFunction()
{
    QGroupBox *grupoBoxBotao=new QGroupBox(tr("botao numero 1"));
    grupoBoxBotao->setCheckable(true);
    grupoBoxBotao->setChecked(true);

    QPushButton *Botao1=new QPushButton(tr("Botao Normal"));

    QVBoxLayout *verticalBox=new QVBoxLayout;

    verticalBox->addWidget(Botao1);
    verticalBox->addStretch(1);
    grupoBoxBotao->setLayout(verticalBox);

    return grupoBoxBotao;
}


















