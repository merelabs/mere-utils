#ifndef MEREBALLONWIDGET_H
#define MEREBALLONWIDGET_H

#include <QShowEvent>
#include <QPaintEvent>
#include <QDebug>
#include <QWidget>

class MereBallonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MereBallonWidget(QWidget *parent = nullptr);
    enum Position { Default = 0,
                    Left    = 1,
                    Top     = 2,
                    Right   = 4,
                    Bottom  = 8,
                    Center  = 16,
                    Corner  = 32};

    void setPosition(int position);

protected:
    void showEvent(QShowEvent *event);
    void paintEvent(QPaintEvent*event);

private:
    QPoint anchorPoint();

signals:

public slots:
private:
    QWidget *m_widget;

    int m_position;
    int m_shiftLeft;
    int m_shiftTop;
};

#endif // MEREBALLONWIDGET_H
