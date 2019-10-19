#-------------------------------------------------
#
# Project created by QtCreator 2018-06-05T19:35:50
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mere-widgets
TEMPLATE = lib

DEFINES += QT_DEPRECATED_WARNINGS MERE_WIDGETS_LIB

SOURCES += \
    src/merestatusbar.cpp \
    src/merewidgetresizer.cpp \
    src/merepushmenu.cpp \
    src/mereballonwidget.cpp \
    src/merelabel.cpp \
    src/mereclickdetector.cpp \
    src/mereshadowwidget.cpp \
    src/merewinheader.cpp

HEADERS += \
    src/merestatusbar.h \
    src/merewidgetresizer.h \
    src/merepushmenu.h \
    src/mereballonwidget.h \
    src/merelabel.h \
    src/merepopupmenu.h \
    src/mereclickdetector.h \
    src/mereshadowwidget.h \
    src/merewinheader.h


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

    INSTALL_PREFIX = /usr/local/include/mere/widgets
    for(header, HEADERS) {
        sdir = $${dirname(header)}
        sdir = $$replace(sdir, "src", "")
        path = $${INSTALL_PREFIX}$${sdir}

        eval(headers_$${path}.files += $$header)
        eval(headers_$${path}.path = $$path)
        eval(INSTALLS *= headers_$${path})
    }
}
