#include "merewinheader.h"

MereWinHeader::MereWinHeader(QWidget *parent) : QWidget(parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);

    setMaximumHeight(48);
}

void MereWinHeader::mousePressEvent(QMouseEvent *event)
{
    m_lock = false;
    m_point = event->globalPos();
}

void MereWinHeader::mouseReleaseEvent(QMouseEvent *event)
{
    m_lock = true;
}

void MereWinHeader::mouseMoveEvent(QMouseEvent *event)
{
    if (m_lock) return;

    QPoint point = event->globalPos();
    parentWidget()->move(parentWidget()->pos() + point - m_point);
    m_point = point;
}

