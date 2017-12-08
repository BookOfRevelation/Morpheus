#-------------------------------------------------
#
# Project created by QtCreator 2017-11-20T10:17:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Morpheus
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    AspectRationPixmapLabel.cpp \
    MorphDialog.cpp \
    InlineLoader.cpp \
    Morpher.cpp \
    AdaptativeGaussianMorpher.cpp \
    PureCore.cpp \
    PureConfiguration.cpp

HEADERS  += MainWindow.h \
    AspectRationPixmapLabel.h \
    MorphDialog.h \
    InlineLoader.h \
    Morpher.h \
    AdaptativeGaussianMorpher.h \
    PureCore.h \
    PureConfiguration.h
