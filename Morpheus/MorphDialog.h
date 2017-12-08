#ifndef MORPHDIALOG_H
#define MORPHDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QComboBox>
#include <QPushButton>
#include <QSlider>
#include "InlineLoader.h"

class MorphDialog : public QDialog
{
    Q_OBJECT
public:
    MorphDialog();


    InlineLoader* srcLoader;
    InlineLoader* desLoader;
    InlineLoader* dirLoader;

    QSlider* iterationSlider;

private:


    QBoxLayout* mainLayout;
    QPushButton* validButton;

    void checkValidation();

};

#endif // MORPHDIALOG_H
