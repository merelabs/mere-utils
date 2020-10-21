#include "envutils.h"

#include <QProcessEnvironment>

void Mere::Utils::EnvUtils::expandEnvVar(QString &str)
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
