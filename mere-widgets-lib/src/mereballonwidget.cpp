#include "mereballonwidget.h"

#include <QPainter>
#include <QDesktopWidget>
#include <QApplication>

MereBallonWidget::MereBallonWidget(QWidget *parent)
    : QWidget(parent),
      m_widget(parent),
      m_position(0)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
//    setParent(0);

    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0, 46, 99, 25));
//    pal.setColor(QPalette::Background, Qt::yellow);
    setAutoFillBackground(true);
    setPalette(pal);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void MereBallonWidget::setPosition(int position)
{
    m_position = position;
    qDebug() << "Going to set ballon position:" << m_position;
}

QPoint MereBallonWidget::anchorPoint()
{
    QPoint point;

    if ((m_position & Position::Center) == Position::Center)
    {
        if ((m_position & Position::Top) == Position::Top)
        {
            QPoint centerTop(m_widget->frameGeometry().width()/2, 0);
            point = m_widget->mapToGlobal(centerTop);
        }
        else if ((m_position & Position::Right) == Position::Right)
        {
            QPoint centerRight(m_widget->frameGeometry().width(), m_widget->frameGeometry().height()/2);
            point = m_widget->mapToGlobal(centerRight);
        }
    }

    return point;
}

void MereBallonWidget::showEvent(QShowEvent *event)
{
    m_shiftLeft = 0;
    m_shiftTop  = 0;

    int x = 0, y = 0;
    if ((m_position & Position::Center) == Position::Center)
    {
        if ((m_position & Position::Top) == Position::Top)
        {
            QPoint point = anchorPoint();
            x = point.x() - frameGeometry().width()/2;
            y = point.y() - frameGeometry().height();

            QRect screen = QApplication::desktop()->screenGeometry();
            if (x + frameGeometry().width() >= screen.width())
            {
                m_shiftLeft = x + frameGeometry().width() - screen.width() + 3;
                x -= m_shiftLeft;
            }
            else if (x + frameGeometry().width() <= 0)
            {

            }
        }
        else if ((m_position & Position::Right) == Position::Right)
        {
            QPoint point = anchorPoint();
            x = point.x();
            y = point.y() - frameGeometry().height()/2;

            QRect screen = QApplication::desktop()->screenGeometry();
            if (y + frameGeometry().height() >= screen.height())
            {
                m_shiftTop = y + frameGeometry().height() - screen.height() + 10;
                y -= m_shiftTop;
            }
        }
    }

    move(QPoint(x, y));

    qDebug() << "XXXXXXXXXXX" << this->size();
    QWidget::showEvent(event);
}

void MereBallonWidget::paintEvent(QPaintEvent*event)
{
    int height = 20;
    //int distance = 50;

    QVector<QPointF> vertices;

    if ((m_position & Position::Center) == Position::Center)
    {
        if ((m_position & Position::Top) == Position::Top)
        {
            vertices << QPointF(frameGeometry().width()/2 + m_shiftLeft,
                                frameGeometry().height())                                   /* 1 */
                     << QPointF(frameGeometry().width()/2 - height/2  + m_shiftLeft ,
                                frameGeometry().height() - height)                          /* 2 */
                     << QPointF(0, frameGeometry().height() - height)                       /* 3 */
                     << QPointF(0, 0)                                                       /* 4 */
                     << QPointF(frameGeometry().width(), 0)                                 /* 5 */
                     << QPointF(frameGeometry().width(),
                                frameGeometry().height() - height)                          /* 6 */
                     << QPointF(frameGeometry().width()/2 + height/2  + m_shiftLeft,
                                frameGeometry().height() - height);                         /* 7 */

        }
        else if ((m_position & Position::Right) == Position::Right)
        {
            vertices << QPointF(0,
                                frameGeometry().height()/2  + m_shiftTop)                                   /* 1 */
                     << QPointF(height,
                                frameGeometry().height()/2 - height/2 + m_shiftTop)                          /* 2 */
                     << QPointF(height, 0)                       /* 3 */
                     << QPointF(frameGeometry().width(), 0)   /* 4 */
                     << QPointF(frameGeometry().width(), frameGeometry().height()) /* 5 */
                     << QPointF(height,
                                frameGeometry().height())                          /* 6 */
                     << QPointF(height ,
                                frameGeometry().height()/2 + height/2  + m_shiftTop);                         /* 7 */
        }
        else
        {
            qDebug() << "NOOOOOOOOOOOOOOOOOO";
        }
    }



    QPolygonF balloonPoly = QPolygonF(vertices);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
//    painter.setBrush(QBrush(QColor(100, 46, 99)));
    painter.setBrush(QBrush(Qt::white));
    painter.setPen(Qt::lightGray);


    QRegion maskRegion(balloonPoly.toPolygon(), Qt::WindingFill);
    painter.drawPolygon(balloonPoly);
    setMask(maskRegion);

    QWidget::paintEvent(event);
}
