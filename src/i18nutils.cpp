#include "i18nutils.h"
#include "apputils.h"
#include "stringutils.h"

#include <iostream>
#include <QTranslator>
#include <QCoreApplication>

bool Mere::Utils::I18nUtils::apply()
{
    QLocale fallback("en");
    bool ok = apply(fallback);
    if(!ok)
        std::cout << "WARN:: Could not find fallback translator resource for  " << fallback.bcp47Name().toStdString() << std::endl;

    QLocale locale = QLocale::system();

    return apply(locale);
}

//static
bool Mere::Utils::I18nUtils::apply(const QLocale &locale)
{
    QTranslator *translator = new QTranslator();

    bool ok = translator->load(locale, "lock", "_", QString::fromStdString(i18nPath()));
    if (!ok) return false;

    std::cout << "Applying following translator resource: " << translator->filePath().toStdString() << std::endl;
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
