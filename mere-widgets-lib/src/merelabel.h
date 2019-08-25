#ifndef MERELABEL_H
#define MERELABEL_H

#include <QDebug>
#include <QLabel>

class MereLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MereLabel(QWidget *parent = nullptr, Qt::WindowFlags flags=Qt::WindowFlags());
    explicit MereLabel(const QString &text, QWidget *parent=nullptr, Qt::WindowFlags flags=Qt::WindowFlags());

    void setText(const QString &);
    void setLineHeight(int percent);

private:
    QString build(const QString &text, int &percent) const;

signals:

public slots:
private:
    QString m_text;
    int m_percent;
};

#endif // MERELABEL_H
