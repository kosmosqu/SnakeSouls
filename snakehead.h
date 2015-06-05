#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include <QWidget>
#include "snakebody.h"
#include <stack>
#include <QShowEvent>
#include <vector>
#include <QLabel>
namespace Ui {
class SnakeHead;
}


/* @description inherited from SnakeBody class
   @param body the container for all following body parts of the snake

    */
class SnakeHead : public SnakeBody
{
    Q_OBJECT
    friend class GameBoard;
public:
    explicit SnakeHead(QPoint* ini = new QPoint(0,0));
    const unsigned int get_x();
    const unsigned int get_y();
    ~SnakeHead();
    unsigned int get_length();
    //void set_length();
    //void calculate_player();
    //void calculate_cherry();
    //void addBodyPart();
    void moveUp(){position->setY(position->y()-1);}
    void moveDown(){position->setY(position->y()+1);}
    void moveLeft(){position->setX(position->x()-1);}
    void moveRight(){position->setX(position->x()+1);}
    void move();
private:
    bool hor_dir;
    bool ver_dir;
    Ui::SnakeHead *ui;
    //SnakeBody* body = new SnakeBody[];
    //std::stack<SnakeBody> body;
    //std::vector<SnakeBody> body;
    QPixmap* image;
    unsigned int length;
    QPoint* position;

};

#endif // SNAKEHEAD_H
