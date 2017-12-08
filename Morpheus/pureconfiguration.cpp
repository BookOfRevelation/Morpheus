#include "PureConfiguration.h"
#include <QFile>
#include <QDebug>

QSettings* PureConfiguration::settings;
QString PureConfiguration::srcDir;
QString PureConfiguration::destDir;
QString PureConfiguration::targetDir;

PureConfiguration::PureConfiguration()
{

}


void PureConfiguration::loadConf()
{
    QFile f("./conf.ini");

    f.open(QIODevice::ReadWrite);
    f.close();

    settings = new QSettings("./conf.ini", QSettings::IniFormat);

    srcDir = settings->value("global/srcDir").toString();
    destDir = settings->value("global/destDir").toString();
    targetDir = settings->value("global/targetDir").toString();



}

void PureConfiguration::saveConf()
{
    settings->setValue("global/srcDir", srcDir);
    settings->setValue("global/destDir", destDir);
    settings->setValue("global/targetDir", targetDir);



    delete settings;

}
