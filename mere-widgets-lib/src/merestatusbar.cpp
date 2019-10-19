#include "merestatusbar.h"

#include <QHBoxLayout>

MereStatusBar::MereStatusBar(QWidget *parent)
    : QWidget(parent),
      m_status(new QLabel)
{
    QPalette p = palette();
    p.setColor( QPalette::Background, Qt::gray);
    setAutoFillBackground(true);
    setPalette( p );

    setMaximumHeight(24);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(9, 2, 9, 2);
    setLayout(layout);

    initUI();
}

void MereStatusBar::initUI()
{
    QHBoxLayout *layout = static_cast<QHBoxLayout *>(this->layout());

    layout->addWidget(m_status);

    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    layout->addSpacerItem(spacer);

    setStatus("Item <b>MERE-1234</b> has been dropped to space <b>SPACE-1</b> from space <b>SPACE-2</b>.");
}

void MereStatusBar::setStatus(const QString status)
{
    m_status->setText(status);
}

