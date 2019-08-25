#include "mereshadowwidget.h"

#include <QPainter>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QGraphicsDropShadowEffect>

MereShadowWidget::MereShadowWidget(QWidget *parent)
    : QWidget(parent),
      m_resizer(new MereWidgetResizer(this, this))
{
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowModality(Qt::ApplicationModal);

    resize(800, 450);
    moveToCenterScreen();

    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(249, 249, 249, 50));
    setAutoFillBackground(true);
    setPalette(pal);

    QGraphicsDropShadowEffect* dropShadowEffect = new QGraphicsDropShadowEffect(this);
    dropShadowEffect->setColor(Qt::lightGray);
    dropShadowEffect->setOffset(3);
    dropShadowEffect->setBlurRadius(9);
    setGraphicsEffect(dropShadowEffect);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(15, 15, 15, 15);

//    initUI();
}

void MereShadowWidget::initUI()
{
    initHeaderUI();
    initContentUI();
    initFooterUI();
}

void MereShadowWidget::initHeaderUI()
{

}

void MereShadowWidget::initContentUI()
{

}

void MereShadowWidget::initFooterUI()
{

}

void MereShadowWidget::moveToCenterScreen()
{
    QDesktopWidget desktop;
    QRect rect = desktop.screenGeometry();

    QPoint center = rect.center() - this->rect().center();
    move(center);
}

void MereShadowWidget::setResizer(MereWidgetResizer *resizer)
{

}

void MereShadowWidget::adjustSize(const QSize &size)
{
    resize(width() + size.width(), height() + size.height());
}

void MereShadowWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    m_resizer->move( event->size().width() - m_resizer->width(),
    event->size().height() - m_resizer->height() );

    event->accept();
}

void MereShadowWidget::paintEvent(QPaintEvent *event )
{
    QWidget::paintEvent(event);

    int length = 10;

    QPainter painter(this);
    painter.setRenderHint( QPainter::Antialiasing, true );
    painter.setPen( QPen( Qt::blue, 2 ) );

    // Left-Top
    painter.drawLine( QPointF(0, 0 ), QPointF(length, 0 ));
    painter.drawLine( QPointF(0, 0 ), QPointF(0, length ));

    // Top-Right
    painter.drawLine( QPointF(width(), 0 ), QPointF(width() - length, 0 ));
    painter.drawLine( QPointF(width(), 0 ), QPointF(width(), length ));

    // Right-Bottom
    //painter.drawLine( QPointF(width(), height()), QPointF(width() - length, height() ));
    //painter.drawLine( QPointF(width(), height()), QPointF(width(), height() - length ));

    // Bottom-Left
    painter.drawLine( QPointF(0, height()), QPointF(0, height() - length ));
    painter.drawLine( QPointF(0, height()), QPointF(length, height() ));
}
