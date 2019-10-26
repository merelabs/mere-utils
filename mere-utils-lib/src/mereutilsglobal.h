#ifndef MEREUTILSGLOBAL_H
#define MEREUTILSGLOBAL_H

#include <QtCore/qglobal.h>
#include <QDebug>

#if defined(MERE_UTILS_LIB)
#  define MERE_UTILS_LIBSPEC Q_DECL_EXPORT
#else
#  define MERE_UTILS_LIBSPEC Q_DECL_IMPORT
#endif

#endif // MEREUTILSGLOBAL_H
