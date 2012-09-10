QT += phonon

TEMPLATE = app
TARGET = displayDemo
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += mainwindow.h \
           mapScene.h \
           mThread.h \
           mysym.h \
           mytext.h \
           targetScene.h \
           videoScene.h
SOURCES += main.cpp \
           mainwindow.cpp \
           mapScene.cpp \
           mThread.cpp \
           mysym.cpp \
           mytext.cpp \
           targetScene.cpp \
           videoScene.cpp
RESOURCES += displayDemo.qrc
