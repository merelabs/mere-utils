#include "binutils.h"
#include "stringutils.h"

#include <QProcess>
#include <QStringList>

//static
QString Mere::Utils::BinUtils::find(const QString &binary)
{
    QProcess process;
    process.start("/usr/bin/which", QStringList() << binary);
    process.waitForFinished();

    QString path = process.readAllStandardOutput();
    if(StringUtils::isNotBlank(path))
        path = path.trimmed();

    return path;
}
