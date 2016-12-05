QT += core
QT -= gui
QT += sql

CONFIG += c++11

TARGET = Persons
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    service.cpp \
    dataaccess.cpp \
    person.cpp

HEADERS += \
    consoleui.h \
    service.h \
    dataaccess.h \
    person.h
