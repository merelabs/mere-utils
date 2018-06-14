#include <QCoreApplication>

#include "merefileutils.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString path("/bin/ls");
    MereFileUtils::isBinary(path);

    return app.exec();
}

