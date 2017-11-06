#-------------------------------------------------
#
# Project created by QtCreator 2017-10-09T19:14:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
    bcm2835_stub.cpp \
    blink.c \
    pin.cpp \
    pwm.cpp

HEADERS  += \
    bcm2835.h \
    pin.h \
    pwm.h

FORMS    += mainwindow.ui
