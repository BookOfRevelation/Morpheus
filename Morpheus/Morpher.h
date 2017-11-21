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

    void start();

signals:
    void newFrame(const QImage& f);

protected:


    virtual void morph() = 0 ;

    QImage currentImage;
    QImage goalImage;

    int iterations;
};

#endif // MORPHER_H
