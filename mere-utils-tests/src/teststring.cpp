#include "teststring.h"
#include "stringutils.h"

TestString::TestString(QObject *parent) : QObject(parent)
{

}

void TestString::isBlank()
{
    QCOMPARE(Mere::Utils::StringUtils::isBlank(nullptr), true);
    QCOMPARE(Mere::Utils::StringUtils::isBlank(""), true);
    QCOMPARE(Mere::Utils::StringUtils::isBlank(" "), true);
    QCOMPARE(Mere::Utils::StringUtils::isBlank(QString("")), true);
    QCOMPARE(Mere::Utils::StringUtils::isBlank(QString(" ")), true);
    QCOMPARE(Mere::Utils::StringUtils::isBlank("a"), false);
}

void TestString::indexOf()
{
    QString str = "Is there a term to describe the repeated usage of the same word in a sentence.";
    QString sub = "a";

    QCOMPARE(Mere::Utils::StringUtils::indexOf(str, sub), 9);
    QCOMPARE(Mere::Utils::StringUtils::indexOf(str, sub, 1), 9);
    QCOMPARE(Mere::Utils::StringUtils::indexOf(str, sub, 2), 36);
}
