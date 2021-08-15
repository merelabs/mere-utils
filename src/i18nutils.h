#ifndef MERE_UTILS_I18NUTILS_H
#define MERE_UTILS_I18NUTILS_H

#include "global.h"
#include <QLocale>

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
    static bool apply(const QLocale &locale, bool fallback = false);

private:
    static std::string i18nPath();
    static std::string i18nMerePath();
    static std::string i18nBasePath();
};

}
}
#endif // MERE_UTILS_I18NUTILS_H
