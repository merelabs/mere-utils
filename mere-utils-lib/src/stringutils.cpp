#include "stringutils.h"

bool Mere::Utils::StringUtils::isInteger(const QString& str, int base)
{
    bool ok;

    str.toInt(&ok, base);

    return ok;
}

bool Mere::Utils::StringUtils::isBlank(const QString& str)
{
    return str.isNull() || str.isEmpty();
}

bool Mere::Utils::StringUtils::isNotBlank(const QString& str)
{
    return !isBlank(str);
}

bool Mere::Utils::StringUtils::isEmpty(const QString& str)
{
    return str.isEmpty();
}

bool Mere::Utils::StringUtils::isNotEmpty(const QString& str)
{
    return !isEmpty(str);
}

QString Mere::Utils::StringUtils::trim(const QString& str)
{
    return str.trimmed();
}

QString Mere::Utils::StringUtils::upper(const QString& str)
{
    return str.toUpper();
}

QString Mere::Utils::StringUtils::lower(const QString& str)
{
    return str.toLower();
}
