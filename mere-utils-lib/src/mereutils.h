#ifndef MEREUTILS_H
#define MEREUTILS_H

#include "mereutilsglobal.h"

class MERE_UTILS_LIBSPEC MereUtils
{
private:
    MereUtils();

public:
    static void expandEnvVar(QString &str);
};

#endif // MEREUTILS_H
