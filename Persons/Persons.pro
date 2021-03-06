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
    person.cpp \
    dbmanager.cpp \
    computer.cpp \
    computerService.cpp \
    PersonService.cpp \
    generalService.cpp \
    connection.cpp \
    connectionservice.cpp

HEADERS += \
    consoleui.h \
    person.h \
    dbmanager.h \
    computer.h \
    computerService.h \
    PersonService.h \
    generalService.h \
    connection.h \
    connectionservice.h
