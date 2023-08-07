#include "apputils.h"
#include "qvariant.h"

#include <QCoreApplication>

//static
std::string Mere::Utils::AppUtils::appCode()
{
    return qApp->property("appCode").toString().toStdString();
}

//static
void Mere::Utils::AppUtils::setAppCode(const std::string &code)
{
    qApp->setProperty("appCode", QString::fromStdString(code));
}

