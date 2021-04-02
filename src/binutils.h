#ifndef MERE_UTILS_BINUTILS_H
#define MERE_UTILS_BINUTILS_H

#include "global.h"

namespace Mere
{
namespace Utils
{

class MERE_UTILS_LIB_SPEC BinUtils final
{
    BinUtils() = default;
public:
    static std::string find(const std::string &binary);
};

}
}
#endif // MERE_UTILS_BINUTILS_H
