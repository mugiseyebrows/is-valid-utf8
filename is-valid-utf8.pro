QT -= gui

QT += core core-private

CONFIG += c++11 console
CONFIG -= app_bundle

qt_src = "C:/Qt/5.15.1/Src"

SOURCES += \
        main.cpp \
        $$qt_src/qtbase/src/corelib/codecs/qutfcodec.cpp
