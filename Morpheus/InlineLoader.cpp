#include "InlineLoader.h"
#include <QFileDialog>

InlineLoader::InlineLoader(const QString& ttl, LoadType lt)
    : QWidget(), loadType(lt), baseDir("./")
{
    mainLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    title = new QLabel(ttl);
    lineEdit = new QLineEdit("");
    button = new QPushButton("Load...");

    mainLayout->addWidget(title);
    mainLayout->addWidget(lineEdit);
    mainLayout->addWidget(button);

    this->setLayout(mainLayout);

    connect(button, &QPushButton::pressed, this, &InlineLoader::loadRessource);

}


QString InlineLoader::getFilePath()
{
    return lineEdit->text();
}

void InlineLoader::loadRessource()
{
    QString res = "";

    switch (loadType)
    {
    case DIR:
        res = QFileDialog::getExistingDirectory(
                    nullptr,
                    "Folder",
                    baseDir
                    );
        break;
    case IMAGE:
        res = QFileDialog::getOpenFileName(
                    this,
                    tr("Open Image"),
                    baseDir,
                    tr("Image Files (*.png *.jpg *.bmp)")
                    );
    default:
        break;
    }

    lineEdit->setText(res);

    if(res != "")
    {
        emit ressourceLoaded(res);
    }

}

void InlineLoader::setBaseDirectory(const QString &dir)
{
    baseDir = dir;
}
