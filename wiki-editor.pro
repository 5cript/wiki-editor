#-------------------------------------------------
#
# Project created by QtCreator 2016-01-31T16:20:34
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wiki-editor
TEMPLATE = app


SOURCES += main.cpp\
        editor.cpp \
    component_builder.cpp

HEADERS  += editor.h \
    component_builder.h

FORMS    += editor.ui
