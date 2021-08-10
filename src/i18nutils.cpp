#include "apputils.h"
#include "i18nutils.h"
#include "stringutils.h"
#include "fileutils.h"

#include <iostream>

#include <QCoreApplication>

//static
bool Mere::Utils::I18nUtils::apply()
{
    QLocale locale = QLocale::system();
    return apply(locale);
}

//static
bool Mere::Utils::I18nUtils::apply(QLocale locale)
{
    QTranslator *translator = new QTranslator();
    return apply(translator, locale);
}

//static
bool Mere::Utils::I18nUtils::apply(QTranslator *translator)
{
    QLocale locale = QLocale::system();
    return apply(translator, locale);
}

//static
bool Mere::Utils::I18nUtils::apply(QTranslator *translator, QLocale locale)
{
    QCoreApplication::removeTranslator(translator);

    std::string path = i18nFile(locale);
    if (Mere::Utils::StringUtils::isBlank(path))
        return false;

    bool ok = translator->load(path.c_str());
    if (!ok) return false;

    QCoreApplication::installTranslator(translator);

    return true;
}

//static
bool Mere::Utils::I18nUtils::exist(QLocale locale)
{
    QString name = locale.name();

    std::string pattern = i18nPattern();
    QString path = QString(pattern.c_str()).arg(name);

    return FileUtils::isExist(path);
}

//static
std::string Mere::Utils::I18nUtils::i18nFile(QLocale locale)
{
    QString name = locale.name();

    std::string pattern = i18nPattern();
    QString path = QString(pattern.c_str()).arg(name);

    return FileUtils::isExist(path) ? path.toStdString() : fallback(locale);
}

//static
std::string Mere::Utils::I18nUtils::i18nPattern()
{
    std::string path = i18nPath();
    return path.append(Mere::Utils::AppUtils::appCode()).append("_%1.qm");
}

//static
std::string Mere::Utils::I18nUtils::i18nPath()
{
    return i18nMerePath().append(Mere::Utils::AppUtils::appCode().c_str()).append("/").append("i18n/");
}

//static
std::string Mere::Utils::I18nUtils::i18nMerePath()
{
    return i18nBasePath().append("mere/");
}

//static
std::string Mere::Utils::I18nUtils::i18nBasePath()
{
    return "/usr/local/share/";
}

//static
std::string Mere::Utils::I18nUtils::fallback(QLocale locale)
{
    QString lang = locale.languageToString(locale.language());
    QString pattern = QString(i18nPattern().c_str());

    std::vector<std::string> paths {
            pattern.arg(lang).toStdString(),
            pattern.arg("en_US").toStdString(),
            pattern.arg("en").toStdString()
    };

    for(const std::string &path : paths)
    {
        if (FileUtils::isExist(path))
            return path;

        std::cout << "WARN: Failed to load i18n resource file for fallback - " << path << std::endl;
    }

    return "";
}
