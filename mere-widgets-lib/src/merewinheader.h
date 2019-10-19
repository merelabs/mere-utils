#ifndef MEREWINHEADER_H
#define MEREWINHEADER_H

#include <QMouseEvent>
#include <QLabel>
#include <QWidget>
#include <QDebug>

class MereWinHeader : public QWidget
{
    Q_OBJECT
public:
    explicit MereWinHeader(QWidget *parent = nullptr);
    void setTitle(const QString title);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void initUI();
    void initLeftPanel();
    void initCenterPanel();
    void initRightPanel();

signals:

public slots:
private slots:
    void close();

private:
    bool m_lock;
    QPoint m_point;

    QLabel *m_title;
};

#endif // MEREWINHEADER_H
