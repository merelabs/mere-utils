include(../mere-utils-lib/mere-utils-lib.pri)

QT       -= gui

TARGET = mere-utils
TEMPLATE = app 

SOURCES += \
        src/main.cpp \

HEADERS += \

#INCLUDEPATH += src
#INCLUDEPATH += ../include
#INCLUDEPATH += /usr/local/include

#LIBS += -L$$PWD/../lib -lmere-utils

#
# Install
#
unix {
    target.path = /usr/local/bin
    INSTALLS += target
}
