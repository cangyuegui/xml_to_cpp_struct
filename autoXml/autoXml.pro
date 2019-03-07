#-------------------------------------------------
#
# Project created by QtCreator 2019-01-06T12:06:47
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = autoXml
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/x2struct-master
include (../ShareTools/ShareTools.pri)

SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h \
        OTHER.h
FORMS += \
        widget.ui

CONFIG += c++14

DEFINES += XTOSTRUCT_XML

DISTFILES += \
    x2struct-master/README.md \
    x2struct-master/README.zh-cn.md

RESOURCES += \
    res.qrc
