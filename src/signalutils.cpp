#include "signalutils.h"

#include <sstream>
#include <QDataStream>

Mere::Utils::SignalUtils::SignalUtils(QObject *parent) : QObject(parent)
{
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, g_fd))
        qFatal("Couldn't create SIG* socketpair");

    socketNotifier = new QSocketNotifier(g_fd[1], QSocketNotifier::Read, this);
    connect(socketNotifier, SIGNAL(activated(int)), this, SLOT(handleSignal()));
}

int Mere::Utils::SignalUtils::watch(int signal)
{
//    switch (signal)
//    {
//        case SIGHUP:
//            watchSIGHUP();
//            break;

//        case SIGQUIT:
//            watchSIGQUIT();
//            break;

//        case SIGTERM:
//            watchSIGTERM();
//            break;

//        default:
//            qDebug() << "INFO: Unhandled SIGNAL";
//            break;
//    }

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
    qDebug() << "Single param called...";
    ::write(g_fd[0], &signal, sizeof(signal));
}

//static
void Mere::Utils::SignalUtils::signalHandler(int signal, siginfo_t *si, void *ucontext)
{
    qDebug() << "Multiple param called...";
    ::write(g_fd[0], &signal, sizeof(signal));


    qDebug() << "1...." << si->si_signo;
    qDebug() << "2...." << si->si_code;
//    std::ostringstream oss;
//    oss.write((const char *)si->si_signo, sizeof(si->si_signo));

//    std::string str = oss.str();
//    const char *data = str.data();
//    unsigned int size = str.size();

//    ::write(g_fd[0], data, size);

//    QDataStream os;
//    os << si->si_signo;
//    os << si->si_errno;
//    os << si->si_code;
//    os << si->si_pid;
//    os << si->si_uid;

//    os.
}

void Mere::Utils::SignalUtils::handleSignal()
{
    socketNotifier->setEnabled(false);


    int signal;
    ::read(g_fd[1], &signal, sizeof(signal));

    emit fired(signal);

//    std::string str;
//    ::read(g_fd[1], &signal, sizeof(signal));


//    std::istringstream(str);


//    siginfo_t siginfo;
//    emit fired(siginfo);

    socketNotifier->setEnabled(true);
}
