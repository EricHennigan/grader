
QT       += core gui

TARGET = grader
TEMPLATE = app

FORMS    += \
    src/mainwindow.ui

HEADERS += \
    src/mainwindow.h \
    src/qxtglobal.h \
    src/qxtcsvmodel.h

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/qxtcsvmodel.cpp

