#ifndef MERE_UTILS_ENVUTILS_H
#define MERE_UTILS_ENVUTILS_H

#include "global.h"

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIBSPEC EnvUtils
{
private:
    EnvUtils(){}

public:
    static void expandEnvVar(QString &str);
};

}
}
#endif // MERE_UTILS_ENVUTILS_H
