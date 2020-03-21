#include "meresignal.h"

MereSignal::MereSignal(QObject *parent) : QObject(parent)
{
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, g_fd))
        qFatal("Couldn't create SIG* socketpair");

    socketNotifier = new QSocketNotifier(g_fd[1], QSocketNotifier::Read, this);
    connect(socketNotifier, SIGNAL(activated(int)), this, SLOT(handleSignal()));
}

void MereSignal::watch(int signal)
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

void MereSignal::watchSIGHUP()
{
    setupUnixSignal(SIGHUP);
}

void MereSignal::watchSIGQUIT()
{
    setupUnixSignal(SIGQUIT);
}

void MereSignal::watchSIGTERM()
{
    setupUnixSignal(SIGTERM);
}

int MereSignal::setupUnixSignal(int signal)
{
    struct sigaction signalAction;

    signalAction.sa_handler = MereSignal::signalHandler;
    sigemptyset(&signalAction.sa_mask);

    signalAction.sa_flags = 0;
    signalAction.sa_flags |= SA_RESTART;

    if (sigaction(signal, &signalAction, 0))
       return signal;

    return 0;
}

void MereSignal::signalHandler(int signal)
{
    ::write(g_fd[0], &signal, sizeof(signal));
}

void MereSignal::handleSignal()
{
    socketNotifier->setEnabled(false);
    int signal;
    ::read(g_fd[1], &signal, sizeof(signal));

    emit fired(signal);

    socketNotifier->setEnabled(true);
}
