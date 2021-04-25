#include "signalutils.h"

#include <sstream>
#include <QDataStream>

int Mere::Utils::SignalUtils::socketPair[2] = {0, 0};

Mere::Utils::SignalUtils::SignalUtils(QObject *parent) : QObject(parent)
{
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, socketPair))
        qFatal("Couldn't create SIG* socketpair");

    socketNotifier = new QSocketNotifier(socketPair[1], QSocketNotifier::Read, this);
    connect(socketNotifier, SIGNAL(activated(int)), this, SLOT(handleSignal()));
}

int Mere::Utils::SignalUtils::watch(int signal)
{
    return setupSignal(signal);
}

int Mere::Utils::SignalUtils::ignore(int s)
{
    signal(s, SIG_IGN);

    return 0;
}

void Mere::Utils::SignalUtils::watchSIGHUP()
{
    setupSignal(SIGHUP);
}

void Mere::Utils::SignalUtils::watchSIGQUIT()
{
    setupSignal(SIGQUIT);
}

void Mere::Utils::SignalUtils::watchSIGTERM()
{
    setupSignal(SIGTERM);
}

int Mere::Utils::SignalUtils::setupSignal(int signal)
{
    qDebug() << "INFO: Handle SIGNAL:" << signal;

    struct sigaction signalAction;
    sigemptyset(&signalAction.sa_mask);

    //    signalAction.sa_flags = 0;
    signalAction.sa_flags = SA_RESTART | SA_SIGINFO;

    //signalAction.sa_handler = Mere::Utils::SignalUtils::signalHandler;
    signalAction.sa_sigaction = Mere::Utils::SignalUtils::signalHandler;

    if (sigaction(signal, &signalAction, nullptr))
       return signal;

    return 0;
}

//static
void Mere::Utils::SignalUtils::signalHandler(int signal)
{
    ::write(socketPair[0], &signal, sizeof(signal));
}

//static
void Mere::Utils::SignalUtils::signalHandler(int signal, siginfo_t *si, void *ucontext)
{
    ::write(socketPair[0], &signal, sizeof(signal));
}

void Mere::Utils::SignalUtils::handleSignal()
{
    socketNotifier->setEnabled(false);

    int signal;
    ::read(socketPair[1], &signal, sizeof(signal));

    emit fired(signal);

    socketNotifier->setEnabled(true);
}
