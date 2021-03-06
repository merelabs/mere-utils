#include "merefileutils.h"
#include "merestringutils.h"

#include <QFileInfo>
#include <QMimeDatabase>

bool MereFileUtils::isExist(const QString &path)
{
    if (MereStringUtils::isBlank(path))
    {
        qDebug() << "Path cant be emoty or null!";
        return false;
    }

    QFileInfo info(path);

    return info.exists();
}

bool MereFileUtils::isNotExist(const QString &path)
{
    return !isExist(path);
}

bool MereFileUtils::isBinary(const QString &path)
{
    if (MereFileUtils::isExist(path))
    {
        QMimeDatabase mimeDatabase;
        QMimeType mimeType = mimeDatabase.mimeTypeForFile(path);

        if (mimeType.name().contains("application/x-executable"))
            return true;
    }

    return false;
}

bool MereFileUtils::isNotBinary(const QString &path)
{
    return !isBinary(path);
}

bool MereFileUtils::isExecutable(const QString &path)
{
    if (MereFileUtils::isExist(path))
    {
        QFileInfo info(path);
        return info.isExecutable();
    }

    return false;
}

bool MereFileUtils::isNotExecutable(const QString &path)
{
    return !isExecutable(path);
}
