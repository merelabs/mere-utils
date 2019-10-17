#-------------------------------------------------
#
# Project created by QtCreator 2018-06-05T19:35:50
#
#-------------------------------------------------

QT       -= gui

TARGET = mere-utils
TEMPLATE = lib

DEFINES += QT_DEPRECATED_WARNINGS MERE_UTILS_LIB

SOURCES += \
        src/mereutils.cpp \
    src/meresignal.cpp \
    src/merestringutils.cpp \
    src/mereprocessutils.cpp \
    src/merefileutils.cpp

HEADERS += \
        src/mereutils.h \
        src/mereutilsglobal.h \
    src/meresignal.h \
    src/merestringutils.h \
    src/mereprocessutils.h \
    src/merefileutils.h


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

    INSTALL_PREFIX = /usr/local/include/mere/utils
    for(header, HEADERS) {
        sdir = $${dirname(header)}
        sdir = $$replace(sdir, "src", "")
        path = $${INSTALL_PREFIX}$${sdir}

        eval(headers_$${path}.files += $$header)
        eval(headers_$${path}.path = $$path)
        eval(INSTALLS *= headers_$${path})
    }
}

