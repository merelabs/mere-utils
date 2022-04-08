#include "binutils.h"
#include "fileutils.h"

#include <fstream>
#include <sstream>

//static
std::string Mere::Utils::BinUtils::find(const std::string &binary)
{
    char *pathenv = getenv("PATH");
    if (!pathenv) return "";

    std::string path;

    std::istringstream iss(pathenv);
    while (std::getline(iss, path, ':'))
    {
        if (path.empty())
            continue;

        if(path.back() != '/')
            path.append("/");

        path.append(binary);

        if (FileUtils::isExist(path))
            return path;
    }

    return "";
}
