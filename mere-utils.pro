TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS = \
        mere-utils-lib     \  # mere-utils-lib
        mere-utils-app     \  # mere-utils-app
        mere-utils-test    \  # mere-utils-test

mere-utils-app.depends   = mere-utils-lib
mere-utils-tests.depends = mere-utils-lib
