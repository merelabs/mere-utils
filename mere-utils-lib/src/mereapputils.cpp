#include "mereapputils.h"

#include <QVariant>
#include <QCoreApplication>

MereAppUtils::MereAppUtils()
{

}

//static
QString MereAppUtils::AppCode()
{
    QVariant code = qApp->property("AppCode");

    return (code.isValid() && !code.isNull()) ? code .toString() : "";
}

