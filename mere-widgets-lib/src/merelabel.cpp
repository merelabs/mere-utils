#include "merelabel.h"

MereLabel::MereLabel(QWidget *parent, Qt::WindowFlags flags)
    : QLabel(parent, flags),
      m_text(""),
      m_percent(100)
{

}

MereLabel::MereLabel(const QString &text, QWidget *parent, Qt::WindowFlags flags)
    : QLabel(text, parent, flags),
      m_text(text),
      m_percent(100)
{
    QLabel::setText(build(m_text, m_percent));
}

void MereLabel::setText(const QString &text)
{
    m_text = text;
    QLabel::setText(build(m_text, m_percent));
}

void MereLabel::setLineHeight(int percent)
{
    m_percent = percent;
    QLabel::setText(build(m_text, m_percent));
}

QString MereLabel::build(const QString &text, int &percent) const
{
    QString html = "<p style=\"line-height:%1%\">%2</p>";

    return html.arg(percent).arg(text);
}

