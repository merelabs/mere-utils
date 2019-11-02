LIBTARGET = mere-utils
BASEDIR   = $${PWD}
INCLUDEPATH *= $${BASEDIR}/include
LIBS += -L$${DESTDIR} -L../lib -lmere-utils
