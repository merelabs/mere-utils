#ifndef MERE_UTILS_APPUTILS_H
#define MERE_UTILS_APPUTILS_H

#include "global.h"

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIB_SPEC AppUtils
{
    AppUtils() = default;
public:
    static QString appCode();
    static void setAppCode(const QString &code);

};

}
}
#endif // MERE_UTILS_APPUTILS_H
