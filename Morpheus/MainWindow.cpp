#include "MainWindow.h"
#include <QDebug>
#include <QStatusBar>
#include "PureConfiguration.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    PureConfiguration::loadConf();

    centralImage = new AspectRatioPixmapLabel;

    this->setCentralWidget(centralImage);
    toolBar = new QToolBar(this);
    morphAction = toolBar->addAction("Morphing");

    progressBar = new QProgressBar();
    this->statusBar()->addPermanentWidget(progressBar);

    morphDialog = new MorphDialog();
    morpher = new AdaptativeGaussianMorpher();
    connect(morphAction, &QAction::triggered, this, &MainWindow::setMorphParameters);
    connect(morpher, &AdaptativeGaussianMorpher::newFrame, this, &MainWindow::updateFrame);



}

MainWindow::~MainWindow()
{
    delete morphDialog;
    delete morpher;


    PureConfiguration::saveConf();
}


void MainWindow::setMorphParameters()
{
    if(morphDialog->exec() == QDialog::Accepted)
    {
        QImage src(morphDialog->srcLoader->getFilePath());
        QImage dst(morphDialog->desLoader->getFilePath());
        morpher->setTargetDir(morphDialog->dirLoader->getFilePath());
        morpher->setRange(src, dst);

        morpher->setIterations(morphDialog->iterationSlider->value());
        progressBar->setRange(0, morphDialog->iterationSlider->value()-1);
        progressBar->setValue(0);
        morpher->start();
    }
}

void MainWindow::updateFrame(const QImage &f)
{
    centralImage->setPixmap(QPixmap::fromImage(f));
    progressBar->setValue(progressBar->value() + 1);
    this->statusBar()->showMessage(QString("Iteration %1 of %2").arg(progressBar->value()+1).arg(progressBar->maximum()+1), 100);

}
