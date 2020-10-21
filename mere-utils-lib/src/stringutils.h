#ifndef MERE_UTILS_STRINGUTILS_H
#define MERE_UTILS_STRINGUTILS_H

#include "utilsglobal.h"

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIBSPEC StringUtils
{
private:
    StringUtils(){}

public:
    static bool isInteger(const QString& str, int base = 10);
    static bool isBlank(const QString& str);
    static bool isNotBlank(const QString& str);
    static bool isEmpty(const QString& str);
    static bool isNotEmpty(const QString& str);
    static QString trim(const QString& str);
    static QString upper(const QString& str);
    static QString lower(const QString& str);
};

}
}
#endif // MERE_UTILS_STRINGUTILS_H
