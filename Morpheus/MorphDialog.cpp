#include "MorphDialog.h"
#include <QSpinBox>
#include "PureConfiguration.h"

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

MorphDialog::MorphDialog()
    : QDialog()
{

    srcLoader = new InlineLoader("Source", InlineLoader::IMAGE);
    srcLoader->setBaseDirectory(PureConfiguration::srcDir);
    desLoader = new InlineLoader("Destination", InlineLoader::IMAGE);
    desLoader->setBaseDirectory(PureConfiguration::destDir);
    dirLoader = new InlineLoader("Target directory", InlineLoader::DIR);
    dirLoader->setBaseDirectory(PureConfiguration::targetDir);

    iterationSlider = new QSlider(Qt::Horizontal);
    iterationSlider->setRange(1,10000);
    iterationSlider->setValue(100);

    QSpinBox* iterationSpinBox = new QSpinBox();
    iterationSpinBox->setRange(1,10000);
    iterationSpinBox->setValue(100);
    connect(iterationSlider, &QSlider::valueChanged, iterationSpinBox, &QSpinBox::setValue);
    connect(iterationSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), iterationSlider, &QSlider::setValue);



    QHBoxLayout* iterationLayout = new QHBoxLayout();
    iterationLayout->addWidget(new QLabel("Iterations : "));
    iterationLayout->addWidget(iterationSlider);
    iterationLayout->addWidget(iterationSpinBox);

    validButton = new QPushButton("Ok");

    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    this->setLayout(mainLayout);

    mainLayout->addWidget(srcLoader);
    mainLayout->addWidget(desLoader);
    mainLayout->addWidget(dirLoader);
    mainLayout->addLayout(iterationLayout);
    mainLayout->addWidget(validButton);

    connect(validButton, &QPushButton::pressed, this, &MorphDialog::checkValidation);

}


void MorphDialog::checkValidation()
{
    QFileInfo srcfi(QFile(srcLoader->getFilePath()));
    PureConfiguration::srcDir = srcfi.absoluteDir().absolutePath();

    QFileInfo destfi(QFile(desLoader->getFilePath()));
    PureConfiguration::destDir = destfi.absoluteDir().absolutePath();

    PureConfiguration::targetDir = dirLoader->getFilePath();


    if(
            srcLoader->getFilePath() != "" &&
            desLoader->getFilePath() != "" &&
            dirLoader->getFilePath() != ""
    )
    {

        this->accept();
    }
    else
    {
        this->reject();
    }
}
