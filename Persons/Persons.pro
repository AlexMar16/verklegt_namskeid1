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
    computerService.cpp \
    PersonService.cpp \
    generalService.cpp

HEADERS += \
    consoleui.h \
    dataaccess.h \
    person.h \
    dbmanager.h \
    computer.h \
    computerService.h \
    PersonService.h \
    generalService.h
