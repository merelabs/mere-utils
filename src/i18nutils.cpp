#include "i18nutils.h"
#include "apputils.h"

#include <iostream>
#include <QTranslator>
#include <QCoreApplication>

//static
bool Mere::Utils::I18nUtils::apply()
{
    QLocale fallback("en");
    bool ok = apply(fallback);
    if(!ok) std::cout << "WARN:: Could not find fallback translator resource for  " << fallback.bcp47Name().toStdString() << std::endl;

    QLocale locale = QLocale::system();
    return apply(locale, ok);
}

//static
bool Mere::Utils::I18nUtils::apply(const QLocale &locale, bool fallback)
{
    QTranslator *translator = new QTranslator();

    bool ok = translator->load(locale, AppUtils::appCode().c_str(), "_", QString::fromStdString(i18nPath()));
    if (!ok)
    {
        translator->deleteLater();
        return false;
    }

    if (fallback && i18nFallbackPath() == translator->filePath().toStdString())
    {
        translator->deleteLater();
        return false;
    }

    std::cout << "Applying the following translator resource: " << translator->filePath().toStdString() << std::endl;
    QCoreApplication::installTranslator(translator);

    return ok;
}

std::string Mere::Utils::I18nUtils::i18nPath()
{
    return i18nMerePath().append(Mere::Utils::AppUtils::appCode().c_str()).append("/").append("i18n/");
}

std::string Mere::Utils::I18nUtils::i18nMerePath()
{
    return i18nBasePath().append("mere/");
}

std::string Mere::Utils::I18nUtils::i18nBasePath()
{
    return "/usr/local/share/";
}

std::string Mere::Utils::I18nUtils::i18nFallbackPath()
{
    return i18nPath().append(AppUtils::appCode().c_str()).append("_en.qm");
}
