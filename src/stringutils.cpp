#include "stringutils.h"

#include <iostream>
#include <sstream>

bool Mere::Utils::StringUtils::isBoolean(const QString &value)
{
    return isBoolean(value.toStdString());
}

bool Mere::Utils::StringUtils::isBoolean(const std::string &value)
{
    return isTrue(value) || isFalse(value);
}

bool Mere::Utils::StringUtils::isTrue(const QString &value)
{
    return isTrue(value.toStdString());
}

bool Mere::Utils::StringUtils::isTrue(const std::string &value)
{
    return value == "true" || value == "yes" || value == "1";
}

bool Mere::Utils::StringUtils::isFalse(const QString &value)
{
    return isFalse(value.toStdString());
}

bool Mere::Utils::StringUtils::isFalse(const std::string &value)
{
    return value == "false" || value == "no" || value == "0";
}

bool Mere::Utils::StringUtils::isInteger(const QString& str, int base)
{
    return isInteger(str.toStdString());
}

int Mere::Utils::StringUtils::toInt(const QString &value)
{
    return toInt(value.toStdString());
}

bool Mere::Utils::StringUtils::isInteger(const std::string &value)
{
    try
    {
        std::stoi(value);
    }
    catch (const std::exception &_)
    {
        return false;
    }

    return true;
}

int Mere::Utils::StringUtils::toInt(const std::string &value)
{
    return std::stoi(value);
}

bool Mere::Utils::StringUtils::isInt(const std::string &value)
{
    return isInteger(value);
}

bool Mere::Utils::StringUtils::isUInt(const std::string &value)
{
    if(!isInt(value)) return false;

    return toInt(value) >= 0;
}

bool Mere::Utils::StringUtils::isBlank(const QString &str)
{
    return str.isNull() || str.isEmpty() || str.trimmed().isEmpty();
}

bool Mere::Utils::StringUtils::isBlank(const std::string &str)
{
    if (str.length() == 0)
        return true;

    for(auto ch : str)
    {
        if(!std::isspace(ch))
            return false;
    }

    return true;
}

bool Mere::Utils::StringUtils::isBlank(const char *c_str)
{
    if (c_str == nullptr) return true;

    return std::char_traits<char>::length(c_str) == 0;
}

bool Mere::Utils::StringUtils::isNotBlank(const QString& str)
{
    return !isBlank(str);
}

bool Mere::Utils::StringUtils::isNotBlank(const std::string &str)
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

std::string& Mere::Utils::StringUtils::trim(std::string &str)
{
    if (str.empty()) return str;

    // from left
    auto pos = str.find_first_not_of(" ");
    if (pos != std::string::npos)
    {
        if (pos != 0)
            str = str.erase(0, pos);

        // from right
        pos = str.find_last_not_of(" ");
        if (pos != std::string::npos && pos != str.length() - 1)
            str = str.erase(pos + 1);
    }
    else
    {
        str.clear();
    }

    return str;
}

//static
bool Mere::Utils::StringUtils::isStartsWidth(const std::string &str, const std::string &sub)
{
    std::size_t found = str.find(sub);
    if (found == 0)
        return true;

    return false;
}

//static
bool Mere::Utils::StringUtils::isEndsWidth(const std::string &str, const std::string &sub)
{
    std::size_t found = str.find(sub);
    if (found == str.length() - sub.length())
        return true;

    return false;
}

QString& Mere::Utils::StringUtils::upper(QString& str)
{
    if (isBlank(str))
        return str;

    if (str.isUpper())
        return str;

    for(int i = 0; i < str.length(); i++)
    {
        QChar ch(str.at(i));

        if (ch.isUpper()) continue;

        str.replace(i, 1, QChar(str.at(i)).toUpper());
    }

    return str;
}

QString Mere::Utils::StringUtils::upper(const QString& str)
{
    if (str.isUpper())
        return str;

    return str.toUpper();
}

QString& Mere::Utils::StringUtils::lower(QString& str)
{
    if (isBlank(str))
        return str;

    if (str.isLower())
        return str;

    for(int i = 0; i < str.length(); i++)
    {
        QChar ch(str.at(i));

        if (ch.isLower()) continue;

        str.replace(i, 1, QChar(str.at(i)).toLower());
    }

    return str;
}

QString Mere::Utils::StringUtils::lower(const QString& str)
{
    if (str.isLower())
        return str;

    return str.toLower();
}

int Mere::Utils::StringUtils::indexOf(const QString& str, const QString &sub, uint occurrence)
{
    if (occurrence == 0) return -1;

    int pos = str.indexOf(sub);
    if (pos == -1) return -1;

    int len = sub.length();
    while (--occurrence)
    {
        pos = str.indexOf(sub, pos + len + 1);
        if (pos == -1) break;
    }

    return pos;
}

//static
std::vector<std::string> Mere::Utils::StringUtils::split(const std::string &str, char del)
{
    std::vector<std::string> parts;

    std::string part;
    std::stringstream stream (str);
    while(std::getline(stream , part, del))
        parts.push_back(part);

    return parts;
}

//static
std::string Mere::Utils::StringUtils::format(const std::string &format, ...)
{

}
