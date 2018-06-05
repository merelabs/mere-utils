QT       -= gui

TARGET = mere-utils
TEMPLATE = app 

SOURCES += \
        src/main.cpp \

HEADERS += \


DEPENDPATH += . ../lib
INCLUDEPATH += ../include

LIBS += -L$$PWD/../lib -lmere-utils
LIBS += -lX11

#
# Install
#
unix {
    target.path = /usr/local/bin
    INSTALLS += target
}
