#include "mereutils.h"

#include <QProcessEnvironment>
#include <QString>
#include <QStringList>
#include <QDebug>

MereUtils::MereUtils()
{

}

void MereUtils::expandEnvVar(QString &str)
{
    QProcessEnvironment processEnvironment = QProcessEnvironment::systemEnvironment();

    QStringList keys = processEnvironment.keys();
    foreach (QString key, keys)
    {
        QString env = "$" + key;
        if(str.contains(env))
        {
            QString val = processEnvironment.value(key);
            str = str.replace(env, val);
        }
    }
}
