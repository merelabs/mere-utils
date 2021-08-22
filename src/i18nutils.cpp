#include "i18nutils.h"
#include "apputils.h"
#include "stringutils.h"

#include <iostream>
#include <QTranslator>
#include <QCoreApplication>

bool Mere::Utils::I18nUtils::apply()
{
    QLocale fallback("en");
    bool ok = apply(fallback, true);
    if(!ok)
        std::cout << "WARN:: Could not find fallback translator resource for  " << fallback.bcp47Name().toStdString() << std::endl;

    QLocale locale = QLocale::system();

    return apply(locale, ok);
}

bool Mere::Utils::I18nUtils::apply(QTranslator &translator)
{
    QLocale fallback("en");
    bool ok = apply(fallback, true);
    if(!ok)
        std::cout << "WARN:: Could not find fallback translator resource for  " << fallback.bcp47Name().toStdString() << std::endl;

    QLocale locale = QLocale::system();

    return apply(translator, locale, ok);
}

//static
bool Mere::Utils::I18nUtils::apply(const QLocale &locale, bool fallback)
{
    QTranslator *translator = new QTranslator();

    return apply(*translator, locale, fallback);
}

bool Mere::Utils::I18nUtils::apply(QTranslator &translator, const QLocale &locale, bool fallback)
{
    QCoreApplication::removeTranslator(&translator);

    std::string app = AppUtils::appCode();

    bool ok = translator.load(locale, app.c_str(), "_", QString::fromStdString(i18nPath()));
    if (!ok) return false;

    if (!fallback && i18nPath().append(app.c_str()).append("_en.qm") == translator.filePath().toStdString())
        return false;

    std::cout << "Applying following translator resource: " << translator.filePath().toStdString() << std::endl;
    QCoreApplication::installTranslator(&translator);

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
