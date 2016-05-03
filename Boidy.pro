#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T20:50:20
#
#-------------------------------------------------

QT       += core gui opengl
LIBS += -LC:/Qt/Qt5.5.1/5.5/mingw492_32/lib/libQt5OpenGL.a -lopengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Boidy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    environment.cpp \
    creature.cpp \
    boid.cpp \
    predator.cpp \
    obstacle.cpp

HEADERS  += mainwindow.h \
    environment.h \
    creature.h \
    typedefs.h \
    boid.h \
    predator.h \
    obstacle.h

FORMS    += mainwindow.ui
