#include "folderutils.h"

#include <QFileInfo>
#include <QDir>
#include <QDirIterator>

//static
int Mere::Utils::FolderUtils::copy(const std::string &source, const std::string &target, const bool &recursive)
{
    QFileInfo sourceDir(source.c_str());

    if (!sourceDir.exists()) return 1;
    if (!sourceDir.isDir()) return 2;
    if (!sourceDir.isReadable()) return 3;

    QFileInfo targetDir(target.c_str());
    if (!targetDir.exists())
    {
        QDir dir(target.c_str());
        if (!dir.exists())
            dir.mkpath(target.c_str());
    }
    if (!targetDir.isWritable()) return 4;

    QDirIterator it(source.c_str(), QDir::AllEntries, recursive ? QDirIterator::Subdirectories : QDirIterator::NoIteratorFlags);
    while (it.hasNext())
    {
        QString sourceFile = it.next();

        QString targetFile(sourceFile);
        targetFile.replace(source.c_str(), target.c_str());

        QFileInfo info(sourceFile);
        //qDebug() << "COPY " << sourceFile << "AS:" << targetFile;

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
