#ifndef MEREI18NUTILS_H
#define MEREI18NUTILS_H

#include "mereutilsglobal.h"

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

class MERE_UTILS_LIBSPEC MereI18nUtils
{
public:
    static bool apply();
    static bool apply(QLocale locale);
    static bool apply(QTranslator *translator);
    static bool apply(QTranslator *translator, QLocale locale);

private:
    MereI18nUtils();

    static bool exist(QLocale locale);
    static QString i18nFile(QLocale locale);
    static QString i18nPath();
    static QString i18nMerePath();
    static QString i18nBasePath();

    static QString i18nPattern();

    static QString fallback(QLocale locale);

};

#endif // MEREI18NUTILS_H
