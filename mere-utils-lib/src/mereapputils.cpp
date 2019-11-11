#include "mereapputils.h"

#include <QCoreApplication>

QString MereAppUtils::appCode() const
{
    return qApp->property("appCode").toString();
}

void MereAppUtils::setAppCode(const QString &code)
{
    qApp->setProperty("appCode", code);
}

