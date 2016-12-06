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
    dataaccess.cpp \
    person.cpp \
    dbmanager.cpp \
    computer.cpp \
    computerservice.cpp \
    PersonService.cpp

HEADERS += \
    consoleui.h \
    dataaccess.h \
    person.h \
    dbmanager.h \
    computer.h \
    computerservice.h \
    PersonService.h
