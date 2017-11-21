#ifndef PURECORE_H
#define PURECORE_H

#include <QString>
#include <QWidget>

class PureCore
{
public:
    PureCore();
    static void initRNG();

    static int getRandom(int min, int max);
};

#endif // PURECORE_H
