#ifndef MEREPUSHMENU_H
#define MEREPUSHMENU_H

#include <QDebug>
#include <QMenu>

class MerePushMenu : public QMenu
{
    Q_OBJECT
public:
    enum Position { Default, LeftBottom };
    explicit MerePushMenu(QWidget *parent = nullptr);

    void setPosition(Position position);

protected:
    void showEvent(QShowEvent *event);
    void paintEvent(QPaintEvent *event);

signals:

public slots:
private:
    Position m_position;
};

#endif // MEREPUSHMENU_H
