QT       -= gui

TARGET = mere-utils
TEMPLATE = app 

SOURCES += \
        src/main.cpp \

#HEADERS += \



#
# Install
#
unix {
    target.path = /usr/local/bin
    INSTALLS += target
}
