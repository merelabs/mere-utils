#include "meresignal.h"

MereSignal::MereSignal(QObject *parent) : QObject(parent)
{
}

void MereSignal::watch(int signal)
{
    switch (signal)
    {
        case SIGHUP:
            watchSIGHUP();
            break;

        default:
            break;
    }
}

void MereSignal::watchSIGHUP()
{
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, fileDescriptor))
    {
        qFatal("Couldn't create HUP socketpair");
        return;
    }

    socketNotifier = new QSocketNotifier(fileDescriptor[1], QSocketNotifier::Read, this);
    connect(socketNotifier, SIGNAL(activated(int)), this, SLOT(handleSignal()));

    setupUnixSignal(SIGHUP);
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

void MereSignal::signalHandler(int)
{
    char a = 1;
    ::write(fileDescriptor[0], &a, sizeof(a));
}

void MereSignal::handleSignal()
{
    socketNotifier->setEnabled(false);
    char tmp;
    ::read(fileDescriptor[1], &tmp, sizeof(tmp));

    // do Qt stuff
    emit fired(SIGHUP);

    socketNotifier->setEnabled(true);
}
