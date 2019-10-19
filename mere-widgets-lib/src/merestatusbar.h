#ifndef MERESTATUSBAR_H
#define MERESTATUSBAR_H

#include <QLabel>
#include <QWidget>

class MereStatusBar : public QWidget
{
    Q_OBJECT
public:
    explicit MereStatusBar(QWidget *parent = nullptr);

    void setStatus(const QString message);

private:
    void initUI();

signals:

public slots:
private:
    QLabel *m_status;
};

#endif // MERESTATUSBAR_H
