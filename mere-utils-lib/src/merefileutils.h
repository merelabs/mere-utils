#ifndef MEREFILEUTILS_H
#define MEREFILEUTILS_H

#include "mereutilsglobal.h"

class MERE_UTILS_LIBSPEC MereFileUtils
{
private:
    MereFileUtils();

public:
    static bool isExist(const QString &path);
    static bool isNotExist(const QString &path);
    static bool isBinary(const QString &path);
    static bool isExecutable(const QString &path);
};

#endif // MEREFILEUTILS_H
