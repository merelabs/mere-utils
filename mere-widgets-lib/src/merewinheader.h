#ifndef MEREWINHEADER_H
#define MEREWINHEADER_H

#include <QMouseEvent>
#include <QWidget>

class MereWinHeader : public QWidget
{
    Q_OBJECT
public:
    explicit MereWinHeader(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:

public slots:

private:
    bool m_lock;
    QPoint m_point;
};

#endif // MEREWINHEADER_H
