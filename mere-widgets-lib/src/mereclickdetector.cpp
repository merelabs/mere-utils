#include "mereclickdetector.h"

MereClickDetector::MereClickDetector(QObject *parent) : QObject(parent)
{

}

bool MereClickDetector::eventFilter(QObject *obj, QEvent *event)
{
    switch( event->type() )
    {
        case QEvent::MouseButtonDblClick:
            qDebug() << "Mouse Button Double Clicked";
            break;

        case QEvent::MouseButtonPress:
            qDebug() << "Mouse Button Pressed";
            break;

        case QEvent::MouseButtonRelease:
            qDebug() << "Mouse Button Released";
            break;

        default:
            break;
    }

    return false;
}
