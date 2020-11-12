#ifndef MERE_UTILS_I18NUTILS_H
#define MERE_UTILS_I18NUTILS_H

#include "global.h"

#include <QTranslator>
#include <QLocale>
#include <QDebug>

namespace Mere
{
    namespace Utils
    {
//        const QString i18nPathPattern = "/usr/local/share/mere/mere-about/i18n/mere-about_%1.qm";
    }
}

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIBSPEC I18nUtils
{
private:
    I18nUtils(){}

public:
    static bool apply();
    static bool apply(QLocale locale);
    static bool apply(QTranslator *translator);
    static bool apply(QTranslator *translator, QLocale locale);

private:
    static bool exist(QLocale locale);
    static QString i18nFile(QLocale locale);
    static QString i18nPath();
    static QString i18nMerePath();
    static QString i18nBasePath();

    static QString i18nPattern();

    static QString fallback(QLocale locale);

};
}
}
#endif // MERE_UTILS_I18NUTILS_H
