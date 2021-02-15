#ifndef BINUTILS_H
#define BINUTILS_H

#include "global.h"

namespace Mere
{
namespace Utils
{

class MERE_UTILS_LIBSPEC BinUtils final
{
private:
    BinUtils() = default;

public:
    static QString find(const QString &binary);
};

}
}
#endif // BINUTILS_H
