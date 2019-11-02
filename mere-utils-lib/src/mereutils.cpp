#include "mereutils.h"

#include <QProcessEnvironment>

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
