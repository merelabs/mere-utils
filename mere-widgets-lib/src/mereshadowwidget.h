#ifndef MERESHADOWWIDGET_H
#define MERESHADOWWIDGET_H

#include "merewidgetresizer.h"

#include <QWidget>

class MereShadowWidget : public QWidget, public MereResizeableWidget
{
    Q_OBJECT
public:
    explicit MereShadowWidget(QWidget *parent = nullptr);

    void setResizer(MereWidgetResizer *resizer);
    void adjustSize(const QSize &size);

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    void initUI();
    void initHeaderUI();
    void initContentUI();
    void initFooterUI();

    void moveToCenterScreen();

signals:

public slots:
private:
    MereWidgetResizer *m_resizer;
};

#endif // MERESHADOWWIDGET_H
