#include "pathutils.h"

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

//static
bool Mere::Utils::PathUtils::exists(const std::string &path)
{
    struct stat s;
    return stat(path.c_str(), &s) == 0;
}

//static
bool Mere::Utils::PathUtils::remove(const std::string &path)
{
    if(exists(path)) return false;

    int err = rmdir(path.c_str());

    return !err;
}

//static
bool Mere::Utils::PathUtils::create(const std::string &path, int mode)
{
    if(exists(path)) return false;

    int err = mkdir(path.c_str(), mode);

    return !err;
}

//static
bool Mere::Utils::PathUtils::create_if_none(const std::string &path, int mode)
{
    return create(path, mode);
}
