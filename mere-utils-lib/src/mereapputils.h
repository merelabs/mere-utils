#ifndef MEREAPPUTILS_H
#define MEREAPPUTILS_H

#include "mereutilsglobal.h"

#include <QObject>

class MERE_UTILS_LIBSPEC MereAppUtils : public QObject
{
    Q_OBJECT
public:
    QString appCode() const;
    void setAppCode(const QString &code);

private:
    MereAppUtils(){}
    explicit MereAppUtils(QObject *parent = nullptr){}
};

#endif // MEREAPPUTILS_H
