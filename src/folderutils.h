#ifndef MERE_UTILS_FOLDERUTILS_H
#define MERE_UTILS_FOLDERUTILS_H

#include "global.h"

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIB_SPEC FolderUtils final
{
    FolderUtils() = default;
public:
    static int copy(const std::string &source, const std::string &target, const bool &recursive = true);

private:
    static bool isValidSource(const std::string &source);
    static bool isValidTarget(const std::string &target);
};

}
}
#endif // MERE_UTILS_FOLDERUTILS_H
