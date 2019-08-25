#-------------------------------------------------
#
# Project created by QtCreator 2018-06-05T19:35:50
#
#-------------------------------------------------

QT       += core gui concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mere-widgets
TEMPLATE = lib

DEFINES += QT_DEPRECATED_WARNINGS MERE_WIDGETS_LIB

SOURCES += \
    src/merewidgetresizer.cpp \
    src/merepushmenu.cpp \
    src/mereballonwidget.cpp \
    src/merelabel.cpp \
    src/mereclickdetector.cpp \
    src/mereshadowwidget.cpp \

HEADERS += \
    src/merewidgetresizer.h \
    src/merepushmenu.h \
    src/mereballonwidget.h \
    src/merelabel.h \
    src/merepopupmenu.h \
    src/mereclickdetector.h \
    src/mereshadowwidget.h \


LIBS += -lX11

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
