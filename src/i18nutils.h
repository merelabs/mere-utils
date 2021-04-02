#ifndef MERE_UTILS_I18NUTILS_H
#define MERE_UTILS_I18NUTILS_H

#include "global.h"
#include <QTranslator>
#include <QLocale>

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

class MERE_UTILS_LIB_SPEC I18nUtils
{
private:
    I18nUtils() = default;

public:
    static bool apply();
    static bool apply(QLocale locale);
    static bool apply(QTranslator *translator);
    static bool apply(QTranslator *translator, QLocale locale);

private:
    static bool exist(QLocale locale);
    static std::string i18nFile(QLocale locale);
    static std::string i18nPath();
    static std::string i18nMerePath();
    static std::string i18nBasePath();

    static std::string i18nPattern();
    static std::string fallback(QLocale locale);
};
}
}
#endif // MERE_UTILS_I18NUTILS_H
