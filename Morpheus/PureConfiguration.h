#ifndef PURECONFIGURATION_H
#define PURECONFIGURATION_H

#include <QSettings>

class PureConfiguration
{
public:
    PureConfiguration();

    static void loadConf();
    static void saveConf();


//SETTINGS
    static QString srcDir;
    static QString destDir;
    static QString targetDir;

private:

    static QSettings* settings;


};

#endif // PURECONFIGURATION_H
