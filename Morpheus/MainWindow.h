#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include "QImage"
#include "AspectRationPixmapLabel.h"
#include "MorphDialog.h"


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



};

#endif // MAINWINDOW_H
