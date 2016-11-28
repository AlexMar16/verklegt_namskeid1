QT += core
QT -= gui

CONFIG += c++11

TARGET = Persons
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    service.cpp \
    dataaccess.cpp

HEADERS += \
    consoleui.h \
    service.h \
    dataaccess.h
