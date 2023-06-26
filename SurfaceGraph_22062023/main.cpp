//#include "surfacegraph.h"
#include "interface.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //SurfaceGraph w;
    Interface w;
    w.show();
    return a.exec();
}
