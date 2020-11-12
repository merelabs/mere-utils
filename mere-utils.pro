TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS = \
        mere-utils-lib     \  # mere-utils-lib
        mere-utils-tests   \  # mere-utils-tests

mere-utils-tests.depends = mere-utils-lib
