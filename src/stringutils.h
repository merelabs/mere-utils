#ifndef MERE_UTILS_STRINGUTILS_H
#define MERE_UTILS_STRINGUTILS_H

#include "global.h"

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIB_SPEC StringUtils
{
    StringUtils() = default;
public:
    static bool isBoolean(const QString &value);
    static bool isBoolean(const std::string &value);

    static bool isTrue(const QString &value);
    static bool isTrue(const std::string &value);

    static bool isFalse(const QString &value);
    static bool isFalse(const std::string &value);

    static bool isInteger(const QString &str, int base = 10);
    static int toInt(const QString &value);

    static bool isInteger(const std::string &value);
    static int toInt(const std::string &value);

    static bool isInt(const std::string &value);
    static bool isUInt(const std::string &value);

    /**
     * @brief isBlank
     *
     * <pre>
     * QString()     = true
     * QString("")   = true
     * QString("  ") = true
     * QString("abc")= false
     * </pre>
     *
     * @param str
     * @return
     */
    static bool isBlank(const QString& str);

    static bool isBlank(const std::string &str);

    /**
     * @brief isBlank
     * @param c_str - Pointer to a null terminated c-style string
     * @return
     */
    static bool isBlank(const char *c_str);

    static bool isNotBlank(const QString& str);
    static bool isNotBlank(const std::string &str);

    /**
     * @brief isEmpty
     *
     * <pre>
     * QString()     = true
     * QString("")   = true
     * QString("  ") = false
     * </pre>
     *
     * @param str
     * @return
     */
    static bool isEmpty(const QString& str);
    static bool isNotEmpty(const QString& str);
    static QString trim(const QString& str);
    static std::string &trim(std::string &str);

    static QString& upper(QString& str);
    static QString upper(const QString& str);

    static QString& lower(QString& str);
    static QString lower(const QString& str);

    static bool isStartsWidth(const std::string &str, const std::string &sub);
    static bool isEndsWidth(const std::string &str, const std::string &sub);

    static int indexOf(const QString& str, const QString &sub, uint occurrence = 1);

    static std::vector<std::string> split(const std::string &str, char delim = ' ');
    static std::string format(const std::string &format, ...);
};

}
}
#endif // MERE_UTILS_STRINGUTILS_H
