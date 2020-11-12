QT += testlib

TARGET = mere-utils-tests
TEMPLATE = app 

SOURCES += \
    src/main.cpp \
    src/teststring.cpp

HEADERS += \
    src/teststring.h

INCLUDEPATH += ../mere-utils-lib/src

LIBS += -lmere-utils
LIBS += -lX11


#
# Install
#
unix {
    target.path = /usr/local/bin
    INSTALLS += target
}
