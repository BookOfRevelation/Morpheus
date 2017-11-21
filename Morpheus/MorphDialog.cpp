#include "MorphDialog.h"

MorphDialog::MorphDialog()
    : QDialog()
{

    srcLoader = new InlineLoader("Source", InlineLoader::IMAGE);
    desLoader = new InlineLoader("Destination", InlineLoader::IMAGE);
    dirLoader = new InlineLoader("Target directory", InlineLoader::DIR);

    validButton = new QPushButton("Ok");

    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    this->setLayout(mainLayout);

    mainLayout->addWidget(srcLoader);
    mainLayout->addWidget(desLoader);
    mainLayout->addWidget(dirLoader);
    mainLayout->addWidget(validButton);

    connect(validButton, &QPushButton::pressed, this, &MorphDialog::checkValidation);

}


void MorphDialog::checkValidation()
{
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
