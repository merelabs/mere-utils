#include "pathutils.h"

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

//static
bool Mere::Utils::PathUtils::exists(const std::string &path)
{
    struct stat s;
    stat(path.c_str(), &s);

    //S_ISDIR(s.st_mode) || S_ISREG(s.st_mode) || S_ISFIFO(s.st_mode) || S_ISLNK(s.st_mode) || S_ISSOCK(s.st_mode);

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

    auto pos = path.find("/", 0);
    while (pos != std::string::npos)
    {
        std::string part = path.substr(0, pos + 1);
        if (!exists(part) && mkdir(part.c_str(), mode))
            return false;

        pos = path.find("/", pos + 1);
    }

    int err = mkdir(path.c_str(), mode);

    return !err;
}

//static
bool Mere::Utils::PathUtils::create_if_none(const std::string &path, int mode)
{
    return create(path, mode);
}

//static
std::string Mere::Utils::PathUtils::resolve(const std::string &path, int *resolved)
{
    char buffer[PATH_MAX];
    if(realpath(path.c_str(), buffer))
    {
        if (resolved) *resolved = 1;
        return std::string(buffer);
    }

    if (resolved) *resolved = 0;

    return path;
}
