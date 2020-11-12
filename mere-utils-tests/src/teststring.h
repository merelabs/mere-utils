#ifndef TESTSTRING_H
#define TESTSTRING_H

#include <QtTest/QtTest>

class TestString : public QObject
{
    Q_OBJECT
public:
    explicit TestString(QObject *parent = nullptr);

private slots:
    void isBlank();
    void indexOf();

signals:

};

#endif // TESTSTRING_H
