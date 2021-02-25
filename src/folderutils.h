#ifndef FOLDERUTILS_H
#define FOLDERUTILS_H

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

};

}
}
#endif // FOLDERUTILS_H
