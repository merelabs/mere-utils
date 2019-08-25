#ifndef MERECLICKDETECTOR_H
#define MERECLICKDETECTOR_H

#include <QDebug>
#include <QEvent>
#include <QWidget>
#include <QObject>

class MereClickDetector : public QObject
{
    Q_OBJECT
public:
    explicit MereClickDetector(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void clicked(QWidget &);

public slots:
};

#endif // MERECLICKDETECTOR_H
