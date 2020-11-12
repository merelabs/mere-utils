#include "apputils.h"

#include <QCoreApplication>

//static
QString Mere::Utils::AppUtils::appCode()
{
    return qApp->property("appCode").toString();
}

//static
void Mere::Utils::AppUtils::setAppCode(const QString &code)
{
    qApp->setProperty("appCode", code);
}

