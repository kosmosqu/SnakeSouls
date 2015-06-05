#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include <QWidget>
#include <QLabel>
#include <QShowEvent>

namespace Ui {
class SnakeBody;
}

class SnakeBody : public QLabel
{
    Q_OBJECT
    friend class GameBoard;


public:
    SnakeBody(SnakeBody& s);
    SnakeBody();
    explicit SnakeBody(QPoint* pos,QLabel *parent = 0);
    void showEvent(QShowEvent* e);
    virtual ~SnakeBody();
    virtual void move(){position = new QPoint(former->position->x(),former->position->y());}
    QPoint get_position(){return *position;}
    void set_former_node(SnakeBody* pre){former = pre;}
    void set_later_node(SnakeBody* post){later = post;}
   // virtual void addBodyPart(){};
    //virtual void set_direction();
private:
    bool hor_dir;
    bool ver_dir;
    Ui::SnakeBody *ui;
    SnakeBody* former;
    SnakeBody* later;
    QPoint* position;
    QPixmap* image;

};

#endif // SNAKEBODY_H
