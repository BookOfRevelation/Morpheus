#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    centralImage = new AspectRatioPixmapLabel;

    this->setCentralWidget(centralImage);
    toolBar = new QToolBar(this);
    morphAction = toolBar->addAction("Morphing");
}

MainWindow::~MainWindow()
{

}
