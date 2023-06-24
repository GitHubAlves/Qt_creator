#include "surfacegraph.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SurfaceGraph w;
    w.show();
    return a.exec();
}
