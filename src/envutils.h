#ifndef MERE_UTILS_ENVUTILS_H
#define MERE_UTILS_ENVUTILS_H

#include "global.h"

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIBSPEC EnvUtils
{
    EnvUtils() = default;
public:
    static void expandEnvVar(std::string &str);
};

}
}
#endif // MERE_UTILS_ENVUTILS_H
