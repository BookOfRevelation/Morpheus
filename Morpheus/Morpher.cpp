#include "Morpher.h"
#include <thread>
#include <QDebug>
#include <cmath>

Morpher::Morpher()
    : currentIteration(0), iterations(1)
{
}

void Morpher::setRange(const QImage &src, const QImage &dest)    
{
    currentImage = src.scaled(dest.size());
    goalImage = dest;
}

void Morpher::setIterations(int it)
{
    iterations = it;
}

void Morpher::setTargetDir(const QString &dir)
{
    targetDir = dir;
}

void Morpher::start()
{
    auto work = [&]()
    {
        currentIteration = 0;
        for(int i = 0 ; i < iterations ; ++i)
        {
            emit newFrame(currentImage);            
            saveCurrentImage();
            this->morph();
        }
    };
    std::thread th(work);
    th.detach();
}

void Morpher::saveCurrentImage()
{
    auto work = [&]()
    {
        ++currentIteration;
        QString name = QString("morphing%1").arg(currentIteration, std::log10(iterations)+1, 10, QChar('0'));
        currentImage.save(QString("%1/%2%3").arg(targetDir).arg(name).arg(".png"));
    };
    std::thread th(work);
    th.detach();
}
