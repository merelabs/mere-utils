QT = core

CONFIG += c++11
CONFIG += console

TARGET = mere-utils-tests
TEMPLATE = app

SOURCES += \
        src/main.cpp \

HEADERS += \

#
# Install
#
unix {
    target.path = /usr/local/bin
    INSTALLS += target
}
