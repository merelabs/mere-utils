#ifndef MERE_UTILS_PATHUTILS_H
#define MERE_UTILS_PATHUTILS_H

#include "global.h"

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIB_SPEC  PathUtils
{
    PathUtils() = default;
public:
    static bool exists(const std::string &path);
    static bool remove(const std::string &path);
    static bool create(const std::string &path, int mode = 0755);
    static bool create_if_none(const std::string &path, int mode = 0755);
};

}
}
#endif // MERE_UTILS_PATHUTILS_H
