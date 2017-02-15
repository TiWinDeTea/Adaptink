TEMPLATE = app
TARGET = Adaptink
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    adaptink.cpp

HEADERS += \
    adaptink.hpp

FORMS += \
    adaptink.ui
