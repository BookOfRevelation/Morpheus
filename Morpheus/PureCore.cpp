#include "PureCore.h"
#include <QTime>

PureCore::PureCore()
{

}

void PureCore::initRNG()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

int PureCore::getRandom(int min, int max)
{
    int coef = (max+1) - min;
    if(coef <= 0)
    {
        coef = 1;
    }
    int rd = qrand() % coef + min;

    return rd;
}
