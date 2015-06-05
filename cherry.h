#ifndef CHERRY_H
#define CHERRY_H

#include <QWidget>
#include <QLabel>
#include <QShowEvent>

namespace Ui {
class cherry;
}

class cherry : public QLabel
{
    Q_OBJECT
    friend class GameBoard;
public:
    explicit cherry(QPoint* pos,QLabel *parent = 0);
    void showEvent(QShowEvent* e);
    ~cherry();
    QPoint get_position(){return *position;}
    void setPosition(unsigned int x, unsigned int y){position->setX(x);position->setY(y);return;}
private:
    Ui::cherry *ui;
    QPoint* position;
};

#endif // CHERRY_H
