#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QRect>
#include <QPaintEvent>
#include <QKeyEvent>
#include "player.h"
#include "snakehead.h"
#include <QShowEvent>
#include <vector>
#include <random>
#include <QLabel>
namespace Ui {
class GameBoard;
}

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = 0,unsigned int size =10);
    ~GameBoard();
    void keyPressEvent(QKeyEvent* keypress);
    void paintEvent(QPaintEvent* p);
    void showEvent(QShowEvent* e);
    void update_cherry();
    void update_player();
    void update_snake();
    void turn();
    bool player_die();
    void snake_push_back();
    void snake_pop_back();
    int cherry_hor_distance();
    int cherry_ver_distance();
    int player_hor_distance();
    int player_ver_distance();
    void set_snake_direction();
    void snake_hurt();
private:
    bool game_over;
    bool player_is_alive;
    bool snake_is_alive;

    Player* p1;
    QLabel** units;//a pointer to the collection of Qlabel pointers
    //SnakeHead* snake;
    std::vector<SnakeBody*> snake;//the snake

    unsigned int board_size;//@param board_size length of the square board's edge
    cherry* che;
    bool winning;
    Ui::GameBoard *ui;

    //@param board_size length of the square board's edge
};

#endif // GAMEBOARD_H
