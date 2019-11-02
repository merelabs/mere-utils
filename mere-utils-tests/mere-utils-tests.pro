QT -= gui

TARGET = mere-utils-tests
TEMPLATE = app
CONFIG += console

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
