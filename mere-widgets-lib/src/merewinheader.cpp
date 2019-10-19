#include "merewinheader.h"

#include <QLabel>
#include <QHostInfo>
#include <QPushButton>
#include <QHBoxLayout>
#include <QApplication>

MereWinHeader::MereWinHeader(QWidget *parent) : QWidget(parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);

    setMaximumHeight(48);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(5, 5, 5, 5);

    initUI();
}

void MereWinHeader::initUI()
{
    initLeftPanel();
    initCenterPanel();
    initRightPanel();
}

void MereWinHeader::initLeftPanel()
{
    QWidget *pane = new QWidget(this);
    pane->setMaximumWidth(100);
    layout()->addWidget(pane);
}

void MereWinHeader::initCenterPanel()
{
    QWidget *pane = new QWidget(this);
    layout()->addWidget(pane);

    QVBoxLayout *layout = new QVBoxLayout(pane);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(3);
    layout->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

     m_title = new QLabel("[Unknown app]");
     m_title->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
     m_title->setObjectName("MereWinHeaderTitle");
     layout->addWidget(m_title);

     QLabel *host = new QLabel(QString("@").append(QHostInfo::localHostName()));
     host->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
     layout->addWidget(host);
}

void MereWinHeader::initRightPanel()
{
    QWidget *pane = new QWidget(this);
    pane->setMaximumWidth(100);
    layout()->addWidget(pane);

    QHBoxLayout *layout = new QHBoxLayout(pane);
    layout->setAlignment(Qt::AlignRight);

    QPushButton *close = new QPushButton(QIcon(":/pkg/close.png"),"");
    close->setMaximumWidth(24);
    close->setFlat(true);
    layout->addWidget(close);
    connect(close, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void MereWinHeader::setTitle(const QString title)
{
    m_title->setText(title);
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

void MereWinHeader::close()
{
    qApp->exit();
}

