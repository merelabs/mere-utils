#ifndef MERESIGNAL_H
#define MERESIGNAL_H

#include <QObject>

class MereSignal : public QObject
{
    Q_OBJECT
public:
    explicit MereSignal(QObject *parent = nullptr);

    enum UnixSignal
    {
        SIGHUP
    };
    void watch(MereSignal::UnixSignal signal);

private:

signals:

public slots:
};

#endif // MERESIGNAL_H
