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

CONFIG(release, debug|release) {
    DESTDIR = release
    OBJECTS_DIR = release/
}
CONFIG(debug, debug|release) {
    DESTDIR = debug
    OBJECTS_DIR = debug/
}

shaders.path = $$OUT_PWD/$$DESTDIR
shaders.files += $$PWD/brick.vert \
                 $$PWD/brick.frag
INSTALLS += shaders
