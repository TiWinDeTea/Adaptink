TEMPLATE = app
TARGET = Adaptink
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11 -Wdisabled-optimization -Wvector-operation-performance -Winvalid-pch    \
	-Wunused -Wconversion -Wlogical-op -Wuninitialized -Wsuggest-final-types -Wdouble-promotion      \
	-Wmissing-include-dirs -Wall -pedantic -Wmain -Wswitch-default -Wunreachable-code -Winline       \
	-Wfloat-equal -Wundef -Wcast-align -Wredundant-decls -Winit-self -Wshadow -Wnon-virtual-dtor     \
	-Weffc++ -Wswitch-enum -Wmissing-declarations -Wzero-as-null-pointer-constant -fmessage-length=0 \
	-W -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Wmissing-noreturn

SOURCES += main.cpp \
    adaptink.cpp \
    canvas.cpp

HEADERS += \
    adaptink.hpp \
    canvas.hpp

FORMS += \
    adaptink.ui
