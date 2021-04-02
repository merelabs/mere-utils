#ifndef MERE_UTILS_ICONUTILS_H
#define MERE_UTILS_ICONUTILS_H

#include "global.h"
#include <map>

namespace Mere
{
namespace Utils
{

class MERE_UTILS_LIB_SPEC IconUtils
{
    IconUtils() = default;
public:
    static std::string fromMime(const std::string &mime);

private:
    static std::map<std::string, std::string> MIMETYPES;
};

}
}
#endif // MERE_UTILS_ICONUTILS_H
