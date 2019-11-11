#include "mereapputils.h"

#include <QCoreApplication>

//static
QString MereAppUtils::appCode()
{
    return qApp->property("appCode").toString();
}

//static
void MereAppUtils::setAppCode(const QString &code)
{
    qApp->setProperty("appCode", code);
}

