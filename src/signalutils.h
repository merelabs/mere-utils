#ifndef MERE_UTILS_SIGNALUTILS_H
#define MERE_UTILS_SIGNALUTILS_H

#include "global.h"

#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>

#include <QObject>
#include <QSocketNotifier>

namespace Mere
{

namespace Utils
{


class MERE_UTILS_LIB_SPEC SignalUtils : public QObject
{
    Q_OBJECT
public:
    explicit SignalUtils(QObject *parent = nullptr);
    int watch(int signal);
    int ignore(int signal);

private:
    static int setupSignal(int signal);
    static void signalHandler(int signal);
    static void signalHandler(int signal, siginfo_t *si, void *ucontext);

    void watchSIGHUP();
    void watchSIGQUIT();
    void watchSIGTERM();

signals:
    void fired(int);
//    void fired(siginfo_t);

public slots:

private slots:
    void handleSignal();

private:
    static int socketPair[2];
    QSocketNotifier *socketNotifier;
};

}
}
#endif // MERE_UTILS_SIGNALUTILS_H
