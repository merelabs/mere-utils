#ifndef MERESTRINGUTILS_H
#define MERESTRINGUTILS_H

#include "mereutilsglobal.h"

class MERE_UTILS_LIBSPEC MereStringUtils
{
private:
    MereStringUtils(){}

public:
    static bool isBlank(const QString& str);
    static bool isNotBlank(const QString& str);
    static bool isEmpty(const QString& str);
    static bool isNotEmpty(const QString& str);
    static QString trim(const QString& str);
    static QString upper(const QString& str);
    static QString lower(const QString& str);
};

#endif // MERESTRINGUTILS_H
