#ifndef MERE_UTILS_APPUTILS_H
#define MERE_UTILS_APPUTILS_H

#include "global.h"

#include <QObject>

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIBSPEC AppUtils : public QObject
{
    Q_OBJECT
public:
    static QString appCode();
    static void setAppCode(const QString &code);

private:
    AppUtils(){}
    explicit AppUtils(QObject *parent = nullptr){}
};

}
}
#endif // MERE_UTILS_APPUTILS_H
