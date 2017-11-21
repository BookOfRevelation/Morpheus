#include "MainWindow.h"
#include <QApplication>
#include "PureCore.h"
int main(int argc, char *argv[])
{
    PureCore::initRNG();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
