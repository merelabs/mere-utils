#ifndef MERESIGNAL_H
#define MERESIGNAL_H

#include "mereutilsglobal.h"

#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>

#include <QObject>
#include <QSocketNotifier>


static int fileDescriptor[2];

class MERE_UTILS_LIBSPEC MereSignal : public QObject
{
    Q_OBJECT
public:
    explicit MereSignal(QObject *parent = nullptr);
    void watch(int signal);

private:
    static int setupUnixSignal(int signal);
    static void signalHandler(int unused);

    void watchSIGHUP();

signals:
    void fired(int);

public slots:

private slots:
    void handleSignal();

private:
    QSocketNotifier *socketNotifier;
};

#endif // MERESIGNAL_H
