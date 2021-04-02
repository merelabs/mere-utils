#include "binutils.h"
#include "stringutils.h"

#include <QProcess>
#include <QStringList>

//static
std::string Mere::Utils::BinUtils::find(const std::string &binary)
{
    QProcess process;
    process.start("/usr/bin/which", QStringList() << binary.c_str());
    process.waitForFinished();

    QString path = process.readAllStandardOutput();
    if(StringUtils::isNotBlank(path))
        path = path.trimmed();

    return path.toStdString();
}
