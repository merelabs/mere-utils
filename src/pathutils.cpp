#include "pathutils.h"

#include <sys/stat.h>
#include <unistd.h>

//static
bool Mere::Utils::PathUtils::exists(const std::string &path)
{
    struct stat st = {0};
    return stat(path.c_str(), &st) == 0;
}

//static
bool remove(const std::string &path)
{
    if(Mere::Utils::PathUtils::exists(path))
        return false;

    int err = rmdir(path.c_str());

    return !err;
}

//static
bool create(const std::string &path, int mode)
{
    if(Mere::Utils::PathUtils::exists(path))
        return false;

    int err = mkdir(path.c_str(), mode);

    return !err;
}

//static
bool create_if_none(const std::string &path, int mode)
{
    return Mere::Utils::PathUtils::create(path, mode);
}
