#ifndef MERE_UTILS_STRINGUTILS_H
#define MERE_UTILS_STRINGUTILS_H

#include "global.h"
#include <QDebug>

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIBSPEC StringUtils
{
private:
    StringUtils(){}

public:
    static bool isInteger(const QString& str, int base = 10);

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
    static bool isNotBlank(const QString& str);

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

    static QString& upper(QString& str);
    static QString upper(const QString& str);

    static QString& lower(QString& str);
    static QString lower(const QString& str);

    static int indexOf(const QString& str, const QString &sub, uint occurrence = 1);
};

}
}
#endif // MERE_UTILS_STRINGUTILS_H
