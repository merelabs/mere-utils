#include "merestringutils.h"

bool MereStringUtils::isBlank(const QString& str)
{
    return str.isNull() || isEmpty(trim(str));
}

bool MereStringUtils::isNotBlank(const QString& str)
{
    return !isBlank(str);
}

bool MereStringUtils::isEmpty(const QString& str)
{
    return str.isEmpty();
}

bool MereStringUtils::isNotEmpty(const QString& str)
{
    return !isEmpty(str);
}

bool MereStringUtils::isInteger(const QString& str, const int &base)
{
    bool ok;

    str.toInt(&ok, base);

    return ok;
}

QString MereStringUtils::trim(const QString& str)
{
    return str.trimmed();
}

QString MereStringUtils::upper(const QString& str)
{
    return str.toUpper();
}

QString MereStringUtils::lower(const QString& str)
{
    return str.toLower();
}

