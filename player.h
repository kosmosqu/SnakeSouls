#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QLabel>
#include <QPoint>
#include <QPixmap>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QShowEvent>
#include "cherry.h"
namespace Ui {
class Player;
}

class Player : public QLabel
{
    Q_OBJECT
    friend class GameBoard;

public:
    explicit Player(QPoint* ini = new QPoint(0,0),QLabel *parent = 0);
    ~Player();
    //void obtainCherry(cherry* che){if(*player_position == che->get_position()) ++cherrys; else return;}
    //void hitSnake
    void moveUp();
    void moveLeft();
    void moveRight();
    void moveDown();
    unsigned int get_x();
    unsigned int get_y();
    void showEvent(QShowEvent* e);
    QPoint get_position(){return *player_position;}

private:
    Ui::Player *ui;
    QPoint* player_position;
    QPixmap* player_image;
    unsigned int cherrys;
};

#endif // PLAYER_H
