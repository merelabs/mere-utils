#include "merestringutils.h"

bool isInteger(const QString& str, int base)
{
    bool ok;

    str.toInt(&ok, base);

    return ok;
}

bool MereStringUtils::isBlank(const QString& str)
{
    return str.isNull() || str.isEmpty();
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

