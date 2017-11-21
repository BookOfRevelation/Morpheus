#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    centralImage = new AspectRatioPixmapLabel;

    this->setCentralWidget(centralImage);
    toolBar = new QToolBar(this);
    morphAction = toolBar->addAction("Morphing");

    morphDialog = new MorphDialog();
    morpher = new AdaptativeGaussianMorpher();
    connect(morphAction, &QAction::triggered, this, &MainWindow::setMorphParameters);
    connect(morpher, &AdaptativeGaussianMorpher::newFrame, this, &MainWindow::updateFrame);



}

MainWindow::~MainWindow()
{
    delete morphDialog;
    delete morpher;
}


void MainWindow::setMorphParameters()
{
    if(morphDialog->exec() == QDialog::Accepted)
    {
        QImage src(morphDialog->srcLoader->getFilePath());
        QImage dst(morphDialog->desLoader->getFilePath());
        morpher->setRange(src, dst);
        morpher->setIterations(10000);
        morpher->start();
    }
}

void MainWindow::updateFrame(const QImage &f)
{
    centralImage->setPixmap(QPixmap::fromImage(f));
}
