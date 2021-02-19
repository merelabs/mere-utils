#ifndef MERE_UTILS_FILEUTILS_H
#define MERE_UTILS_FILEUTILS_H

#include "global.h"

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIBSPEC FileUtils
{
    FileUtils() = default;
public:
    static bool touch(const std::string &path);

    static bool isExist(const std::string &path);
    static bool isExist(const QString &path);
    static bool isNotExist(const QString &path);
    static bool isBinary(const QString &path);
    static bool isNotBinary(const QString &path);
    static bool isExecutable(const QString &path);
    static bool isNotExecutable(const QString &path);
};

} }
#endif // MERE_UTILS_FILEUTILS_H
