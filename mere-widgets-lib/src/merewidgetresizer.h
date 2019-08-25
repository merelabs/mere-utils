#ifndef MEREWIDGETRESIZER_H
#define MEREWIDGETRESIZER_H

#include <QDebug>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class MereWidgetResizer;

class MereResizeableWidget //: public QWidget
{
public:
    virtual void setResizer(MereWidgetResizer *resizer) = 0;
    virtual void adjustSize(const QSize &size) = 0;
};

class MereWidgetResizer : public QWidget
{
    Q_OBJECT
public:
    explicit MereWidgetResizer(MereResizeableWidget *resizeableWidget, QWidget *parent = nullptr);
    QSize sizeHint() const;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:

public slots:
private:
    QPoint m_point;
    MereResizeableWidget *m_resizeableWidget;
};

#endif // MEREWIDGETRESIZER_H
