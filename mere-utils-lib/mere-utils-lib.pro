QT = core

TARGET = mere-utils
VERSION = 0.0.1b
TEMPLATE = lib

CONFIG += shared

DEFINES += QT_DEPRECATED_WARNINGS MERE_UTILS_LIB

DEFINES += LIB_CODE=\\\"$$TARGET\\\"
DEFINES += LIB_NAME=\\\"$$TARGET\\\"
DEFINES += LIB_VERSION=\\\"$$VERSION\\\"

#CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += \
    src/mereapputils.cpp \
    src/merei18nutils.cpp \
    src/mereutils.cpp \
    src/meresignal.cpp \
    src/merestringutils.cpp \
    src/mereprocessutils.cpp \
    src/merefileutils.cpp

HEADERS += \
    src/mereapputils.h \
    src/merei18nutils.h \
    src/mereutils.h \
    src/mereutilsglobal.h \
    src/meresignal.h \
    src/merestringutils.h \
    src/mereprocessutils.h \
    src/merefileutils.h

DESTDIR = $$PWD/../lib

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

