#include "folderutils.h"

#include <iostream>

#include <QFileInfo>
#include <QDir>
#include <QDirIterator>

//static
int Mere::Utils::FolderUtils::copy(const std::string &source, const std::string &target, const bool &recursive)
{
    if (!isValidSource(source))
        return 1;

    QFileInfo sourceDir(source.c_str());

    if (!isValidTarget(target))
        return 2;

    QFileInfo targetDir(target.c_str());
    if (targetDir.fileName().isEmpty())
        targetDir.setFile(targetDir.absoluteFilePath() + sourceDir.fileName());

    if (!targetDir.exists())
    {
        QDir dir(target.c_str());
        if (!dir.exists())
            dir.mkpath(target.c_str());
    }

    QDirIterator it(source.c_str(), QDir::AllEntries | QDir::NoDotAndDotDot, recursive ? QDirIterator::Subdirectories : QDirIterator::NoIteratorFlags);
    while (it.hasNext())
    {
        QString sourceFile = it.next();

        QString targetFile(sourceFile);
        targetFile.replace(source.c_str(), targetDir.absoluteFilePath());

        QFileInfo info(sourceFile);
        std::cout << "copy " << sourceFile.toStdString() << " => " << targetFile.toStdString() << std::endl;

        if(info.isFile())
        {
            QFile::copy(sourceFile, targetFile);
        }
        else if(info.isDir())
        {
            QDir dir(targetFile);
            if (!dir.exists())
                dir.mkpath(targetFile);
        }
    }

    return 0;
}

//static
bool Mere::Utils::FolderUtils::isValidSource(const std::string &source)
{
    QFileInfo sourceDir(source.c_str());

    if (!sourceDir.exists())
    {
        std::cout << "source does not exists." << std::endl;
        return false;
    }

    if (!sourceDir.isDir())
    {
        std::cout << "source is not a directory." << std::endl;
        return false;
    }

    if (!sourceDir.isReadable())
    {
        std::cout << "source is not readble." << std::endl;
        return false;
    }

    return true;
}

//static
bool Mere::Utils::FolderUtils::isValidTarget(const std::string &target)
{
    QFileInfo targetDir(target.c_str());

    if (!targetDir.isWritable())
    {
        std::cout << "target is not writeable." << std::endl;
        return false;
    }

    return true;
}
