QT = core

TARGET = mere-utils
VERSION = 0.0.1b
TEMPLATE = lib

CONFIG += shared
CONFIG += C++11

DEFINES += QT_DEPRECATED_WARNINGS MERE_UTILS_LIB

DEFINES += LIB_CODE=\\\"$$TARGET\\\"
DEFINES += LIB_NAME=\\\"$$TARGET\\\"
DEFINES += LIB_VERSION=\\\"$$VERSION\\\"

SOURCES += \
    src/apputils.cpp \
    src/envutils.cpp \
    src/fileutils.cpp \
    src/i18nutils.cpp \
    src/processutils.cpp \
    src/signalutils.cpp \
    src/stringutils.cpp

HEADERS += \
    src/apputils.h \
    src/envutils.h \
    src/fileutils.h \
    src/i18nutils.h \
    src/processutils.h \
    src/signalutils.h \
    src/stringutils.h \
    src/utilsglobal.h

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

