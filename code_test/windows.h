#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QWidget>
#include <QGroupBox>
//#include <QGridLayout>
//#include <QLineEdit>

class Window : public QWidget
{
    Q_OBJECT
public:
    Window(QWidget *parents=NULL);
private:
    QGroupBox *CampoForFunction();
    QGroupBox *CampoForGraph();
    QGroupBox *GroupButtons();

};

#endif // WINDOWS_H

