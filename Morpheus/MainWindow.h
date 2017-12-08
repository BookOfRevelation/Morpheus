#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QProgressBar>
#include "QImage"
#include "AspectRationPixmapLabel.h"
#include "MorphDialog.h"
#include "AdaptativeGaussianMorpher.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setImage(QImage img);

private:
    AspectRatioPixmapLabel* centralImage;
    QToolBar* toolBar;
    QAction* morphAction;
    QProgressBar* progressBar;

    MorphDialog* morphDialog;

    void setMorphParameters();

    AdaptativeGaussianMorpher* morpher;

    void updateFrame(const QImage& f);



};

#endif // MAINWINDOW_H
