#include <QCoreApplication>

//#include "mereutils.h"
#include "meresignal.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    MereSignal *signal = new MereSignal();
    signal->watch(SIGHUP);
//    connect(signal, SIGNAL(fired(MereSignal::UnixSignal)), this, SLOT(handleSignal(MereSignal::UnixSignal)));

    return app.exec();
}

