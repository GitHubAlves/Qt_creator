#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QPushButton>
#include <QGridLayout>
#include <QFormLayout>
#include <QApplication>
//=========================================================================================
#include <QtWidgets/QApplication>


//----------------Header para campos editaveis------
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMainWindow>
//-----End------------------------------------------
#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include <QtDataVisualization/QValue3DAxis>
//header para criação de box na interface
#include <QtWidgets/QGroupBox>
//=========================================================================================

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;


    //=========================================================================================

    //=========================================================================================

    //O layout
    QHBoxLayout *layout= new QHBoxLayout;

    // QGridLayout *layout= new QGridLayout;
    //crio um objeto grupo box, para dentro colocar itens
    QGroupBox *Box1= new QGroupBox("Calc");
    //usado para plotar o grafico
    QGroupBox *Box2= new QGroupBox("Graph");
    Box2->setFixedSize(600, 600);

    // Criação do layout do QGroupBox
    //QVBoxLayout *layoutParaBox1= new QVBoxLayout;
    QFormLayout *layoutParaBox1= new QFormLayout;
    QFormLayout *layoutParaBox2= new QFormLayout;

    //Criação da linha editavel
    QLineEdit *linha=new QLineEdit;
    QLineEdit *linha1=new QLineEdit;
    layoutParaBox1->addRow("Z=", linha);

    //este botao vai para um layout BOX1 que em seguida para dentro de uma caixa
    QPushButton *buttonparaBox1=new QPushButton("Enter");
    buttonparaBox1->setFixedSize(100, 20);
    layoutParaBox1->addWidget(buttonparaBox1);

    //layoutParaBox2->addWidget(linha1);//posso adicionar a funcao _Graph


    //defino o layout criado como o layout do groupbox-grupo da caixa tal ou itens da caixa tal
    Box1->setLayout(layoutParaBox1);
    Box2->setLayout(layoutParaBox2);



    //=========================================================================================

    //=========================================================================================
    layout->addWidget(Box1);
    layout->addWidget(Box2);
    layout->setContentsMargins(10, 10, 10, 10);

    w.setLayout(layout);



    w.show();
    return a.exec();
}
