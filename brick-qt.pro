#-------------------------------------------------
#
# Project created by QtCreator 2012-02-06T19:55:10
#
#-------------------------------------------------

QT       += core gui opengl
CONFIG   += console

TARGET = brick-qt
TEMPLATE = app


SOURCES += main.cpp \
           glwidget.cpp

HEADERS  += glwidget.h

LIBS += -lglut \
        -lGLU
