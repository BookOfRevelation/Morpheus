#ifndef MORPHDIALOG_H
#define MORPHDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QComboBox>
#include <QPushButton>
#include "InlineLoader.h"

class MorphDialog : public QDialog
{
    Q_OBJECT
public:
    MorphDialog();


    InlineLoader* srcLoader;
    InlineLoader* desLoader;
    InlineLoader* dirLoader;

private:


    QBoxLayout* mainLayout;
    QPushButton* validButton;

    void checkValidation();

};

#endif // MORPHDIALOG_H
