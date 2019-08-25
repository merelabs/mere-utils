#include "merepushmenu.h"

#include <QPainter>
MerePushMenu::MerePushMenu(QWidget *parent)
    : QMenu(parent),
      m_position(Position::Default)
{

}

void MerePushMenu::setPosition(Position position)
{
    m_position = position;
}

void MerePushMenu::showEvent(QShowEvent* event)
{
    switch (m_position)
    {
        case LeftBottom:
            {
                QWidget *widget = parentWidget();
                int x = widget->width() - width();
                int y = widget->height();
                QPoint pos(widget->mapToGlobal(QPoint(x, y)));
                this->move(pos);
                return;
            }
            break;
        default:
            break;
    }

    return QMenu::showEvent(event);
}

void MerePushMenu::paintEvent(QPaintEvent*event)
{
//    QMenu::paintEvent(event);


//    QPainter painter(this);

//    QPoint top  = QPoint(width() - parentWidget()->width()/2, 0);
//    QPoint left = QPoint(width() - parentWidget()->width()/2 - 5, 10);
//    QPoint right= QPoint(width() - parentWidget()->width()/2 + 5, 10);


//    QPolygon polygon;
//    polygon << top << left << right;

//    QPainterPath path;
//    path.addPolygon(polygon);

//    painter.fillPath(path, QBrush(Qt::lightGray));

//    QVector<QPointF> vertices;
//        vertices << QPointF(0, 0)
//                 << QPointF((width()+0), 0)
////                 << QPointF((width()+0), height() * 0.8)
////                 << QPointF((width()+0) * 0.60, height() * 0.8)
////                 << QPointF((width()+0) * 0.5, height())
////                 << QPointF((width()+0) * 0.40, height() * 0.8)
//                 << QPointF(0, height() * 0.8);

//        QPolygonF balloonPoly = QPolygonF(vertices);

//        QPainter painter(this);
//        painter.setRenderHint(QPainter::Antialiasing, true);
//        painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
//        painter.setBrush(QBrush(Qt::red));

//        QRegion maskRegion(balloonPoly.toPolygon(), Qt::WindingFill);
//        painter.drawPolygon(balloonPoly);
//        setMask(maskRegion);

//            QPainterPath path;
//            path.addPolygon(balloonPoly);

//        painter.fillPath(path, QBrush(Qt::lightGray));

          QMenu::paintEvent(event);
}
