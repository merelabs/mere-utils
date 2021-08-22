#include "fileutils.h"
#include "stringutils.h"

#include <fstream>
#include <QFileInfo>
#include <QMimeDatabase>

bool Mere::Utils::FileUtils::touch(const std::string &path)
{
    return std::ofstream(path).good();
}

bool Mere::Utils::FileUtils::remove(const std::string &path)
{
    return std::remove(path.c_str()) == 0;
}

bool Mere::Utils::FileUtils::isExist(const std::string &path)
{
    return std::ifstream(path).good();
}

bool Mere::Utils::FileUtils::isExist(const QString &path)
{
    if (Mere::Utils::StringUtils::isBlank(path))
    {
        qDebug() << "Path cant be emoty or null!";
        return false;
    }

    return isExist(path.toStdString());
}

bool Mere::Utils::FileUtils::isNotExist(const QString &path)
{
    return !isExist(path);
}

bool Mere::Utils::FileUtils::isNotExist(const std::string &path)
{
    return !isExist(path);
}

bool Mere::Utils::FileUtils::isBinary(const QString &path)
{
    if (!FileUtils::isExist(path))
        return false;

    QMimeDatabase mimeDatabase;
    QMimeType mimeType = mimeDatabase.mimeTypeForFile(path);

    if (mimeType.name().contains("application/x-executable"))
        return true;

    return false;
}

bool Mere::Utils::FileUtils::isNotBinary(const QString &path)
{
    return !isBinary(path);
}

bool Mere::Utils::FileUtils::isExecutable(const QString &path)
{
    if (!FileUtils::isExist(path))
        return false;

    QFileInfo info(path);
    return info.isExecutable();
}

bool Mere::Utils::FileUtils::isNotExecutable(const QString &path)
{
    return !isExecutable(path);
}
