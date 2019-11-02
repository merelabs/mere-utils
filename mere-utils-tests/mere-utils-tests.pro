QT -= gui 

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
