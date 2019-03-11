#-------------------------------------------------
#
# Project created by QtCreator 2019-03-10T15:00:40
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = ui3280player
TEMPLATE    = app

SOURCES     += main.cpp \
    edit_form.cpp \
    ui3280player.cpp \
    videoplayer.cpp
SOURCES     += iconhelper.cpp
SOURCES     += flatui.cpp
SOURCES     += appinit.cpp
SOURCES     +=

HEADERS     += \
    edit_form.h \
    edit_form.h \
    ui3280player.h \
    videoplayer.h
HEADERS     += iconhelper.h
HEADERS     += flatui.h
HEADERS     += appinit.h
HEADERS     +=

FORMS       += \
    edit_form.ui \
    ui3280player.ui \
    videoplayer.ui

RESOURCES   += main.qrc \
    main.qrc
CONFIG      += qt warn_off

DISTFILES +=
