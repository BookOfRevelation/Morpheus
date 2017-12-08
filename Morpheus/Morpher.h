#ifndef MORPHER_H
#define MORPHER_H

#include <QObject>
#include <QImage>

class Morpher : public QObject
{
    Q_OBJECT
public:
    Morpher();

    void setRange(const QImage& src, const QImage& dest);
    void setIterations(int it);
    void setTargetDir(const QString& dir);

    void start();

    void saveCurrentImage();

signals:
    void newFrame(const QImage& f);

protected:

    virtual void morph() = 0 ;

    int currentIteration;
    int iterations;

    QImage currentImage;
    QImage goalImage;

    QString targetDir;

};

#endif // MORPHER_H
