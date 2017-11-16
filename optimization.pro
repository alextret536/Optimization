TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    area.cpp \
    const.cpp \
    function.cpp \
    optimization.cpp \
    stopcriterion.cpp \
    stdafx.cpp

HEADERS += \
    const.h \
    function.h \
    optimization.h \
    stopcriterion.h \
    area.h \
    stdafx.h \
    targetver.h
