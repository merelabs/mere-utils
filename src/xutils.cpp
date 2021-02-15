#include "xutils.h"

#include <QFile>

//static
int Mere::Utils::XUtils::display()
{
    int display = 0;
    while(true)
    {
        QFile lockfile(QString("/tmp/.X%1-lock").arg(display));
        QFile sockfile(QString("/tmp/.X11-unix/X%1").arg(display));

        if (!lockfile.exists() && !sockfile.exists()) break;

        display++;
    }

    return display;
}

