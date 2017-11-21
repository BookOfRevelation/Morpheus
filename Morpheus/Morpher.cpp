#include "Morpher.h"
#include <thread>

Morpher::Morpher()
{
    iterations = 1;
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

void Morpher::start()
{
    auto work = [&]()
    {
        for(int i = 0 ; i < iterations ; ++i)
        {
            emit newFrame(currentImage);
            this->morph();
        }
    };
    std::thread th(work);
    th.detach();
}
