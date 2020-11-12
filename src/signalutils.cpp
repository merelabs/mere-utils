#include "signalutils.h"

Mere::Utils::SignalUtils::SignalUtils(QObject *parent) : QObject(parent)
{
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, g_fd))
        qFatal("Couldn't create SIG* socketpair");

    socketNotifier = new QSocketNotifier(g_fd[1], QSocketNotifier::Read, this);
    connect(socketNotifier, SIGNAL(activated(int)), this, SLOT(handleSignal()));
}

void Mere::Utils::SignalUtils::watch(int signal)
{
    switch (signal)
    {
        case SIGHUP:
            watchSIGHUP();
            break;

        case SIGQUIT:
            watchSIGQUIT();
            break;

        case SIGTERM:
            watchSIGTERM();
            break;

        default:
            qDebug() << "INFO: Unhandled SIGNAL";
            break;
    }
}

void Mere::Utils::SignalUtils::watchSIGHUP()
{
    setupUnixSignal(SIGHUP);
}

void Mere::Utils::SignalUtils::watchSIGQUIT()
{
    setupUnixSignal(SIGQUIT);
}

void Mere::Utils::SignalUtils::watchSIGTERM()
{
    setupUnixSignal(SIGTERM);
}

int Mere::Utils::SignalUtils::setupUnixSignal(int signal)
{
    struct sigaction signalAction;

    signalAction.sa_handler = Mere::Utils::SignalUtils::signalHandler;
    sigemptyset(&signalAction.sa_mask);

    signalAction.sa_flags = 0;
    signalAction.sa_flags |= SA_RESTART;

    if (sigaction(signal, &signalAction, 0))
       return signal;

    return 0;
}

void Mere::Utils::SignalUtils::signalHandler(int signal)
{
    ::write(g_fd[0], &signal, sizeof(signal));
}

void Mere::Utils::SignalUtils::handleSignal()
{
    socketNotifier->setEnabled(false);
    int signal;
    ::read(g_fd[1], &signal, sizeof(signal));

    emit fired(signal);

    socketNotifier->setEnabled(true);
}
