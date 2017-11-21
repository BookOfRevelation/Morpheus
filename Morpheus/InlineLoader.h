#ifndef INLINELOADER_H
#define INLINELOADER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>
#include <QString>

class InlineLoader : public QWidget
{    
    Q_OBJECT

public:

    enum LoadType
    {
        DIR, IMAGE
    };

    InlineLoader(const QString& ttl, LoadType lt);

    QString getFilePath();

signals:

    void ressourceLoaded(const QString& res);

private:

    LoadType loadType;

    QBoxLayout* mainLayout;
    QLabel* title;
    QLineEdit* lineEdit;
    QPushButton* button;

    void loadRessource();



};

#endif // INLINELOADER_H
