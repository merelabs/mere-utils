#include "merei18nutils.h"
#include "mereapputils.h"
#include "merestringutils.h"

#include <QFileInfo>
#include <QCoreApplication>

//static
bool MereI18nUtils::apply()
{
    QLocale locale = QLocale::system();
    return apply(locale);
}

//static
bool MereI18nUtils::apply(QLocale locale)
{
    QTranslator *translator = new QTranslator();
    return apply(translator, locale);
}

//static
bool MereI18nUtils::apply(QTranslator *translator)
{
    QLocale locale = QLocale::system();
    return apply(translator, locale);
}

//static
bool MereI18nUtils::apply(QTranslator *translator, QLocale locale)
{
    QCoreApplication::removeTranslator(translator);

    QString path = i18nFile(locale);
    if (MereStringUtils::isBlank(path))
        return false;

    bool ok = translator->load(path);
    if (!ok) return false;

    QCoreApplication::installTranslator(translator);

    return true;
}

//static
bool MereI18nUtils::exist(QLocale locale)
{
    QString name = locale.name();

    QString pattern = i18nPattern();
    QString path = pattern.arg(name);

    QFileInfo file(path);

    return file.exists();
}

//static
QString MereI18nUtils::i18nFile(QLocale locale)
{
    QString name = locale.name();

    QString pattern = i18nPattern();
    QString path = pattern.arg(name);

    QFileInfo file(path);

    return file.exists() ? path : fallback(locale);
}

//static
QString MereI18nUtils::i18nPattern()
{
    QString path = i18nPath();

    // As lupdate creates .ts file using project file name and
    // lrelease convert those files, we keep using pattern
    // {project-file-name}_{local-lang_and/or_country}.qm
    QString pattern = path.append("/").append(qAppName()).append("_%1.qm");

    return pattern;
}

//static
QString MereI18nUtils::i18nPath()
{
    QString base = MereAppUtils::AppCode();
    if (MereStringUtils::isBlank(base))
    {
        base = qAppName().trimmed();
        // need more checks to make it as folder name
        // ...
    }
    return i18nMerePath().append("/").append(base).append("/").append("i18n");
}

//static
QString MereI18nUtils::i18nMerePath()
{
    return i18nBasePath().append("/mere");
}

//static
QString MereI18nUtils::i18nBasePath()
{
    return "/usr/local/share";
}

//static
QString MereI18nUtils::fallback(QLocale locale)
{
    QString lang = locale.languageToString(locale.language());
    QString pattern = i18nPattern();

    QStringList paths;
    paths << pattern.arg(lang)
          << pattern.arg("en_US")
          << pattern.arg("en");

    QFileInfo file;
    QString path = "";

    QStringListIterator it(paths);
    while (it.hasNext())
    {
        path = it.next();
        file.setFile(path);
        if (file.exists()) break;
        path = "";
        qDebug() << QString("WARN: Failed to load i18n resource file for fallback - %1").arg(file.absoluteFilePath()) << file.exists();
    }

    return path;
}
