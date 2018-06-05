#-------------------------------------------------
#
# Project created by QtCreator 2018-06-05T19:35:50
#
#-------------------------------------------------

QT       -= gui

TARGET = mere-utils
TEMPLATE = lib

DEFINES += MEREUTILS_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS MERE_UTILS_LIB

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/mereutils.cpp

HEADERS += \
        src/mereutils.h \
        src/mereutilsglobal.h \


LIBS += -lX11

#DISTFILES +=

#DEPENDPATH  +=. ../../mere-window/lib
#INCLUDEPATH += ../../mere-window/include
#LIBS += -L../../mere-window/lib  -lmere-window-utils

LIBDIR = $$PWD/../lib
INCDIR = $$PWD/../include
DESTDIR = \"$$LIBDIR\"

QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$PWD/$$HEADERS) $$quote($$INCDIR) $$escape_expand(\\n\\t)

#
# Install
#
unix {
    target.path = /usr/local/lib
    INSTALLS += target
}
