#include "snakehead.h"
#include "ui_snakehead.h"

SnakeHead::SnakeHead(QPoint* ini) :
    ui(new Ui::SnakeHead),
    position(ini)
{
    ui->setupUi(this);
    QString filename(":/snake-01.jpg");
    image = new QPixmap(filename);
    setPixmap(*image);
    ver_dir = false;
    hor_dir = false;
}

SnakeHead::~SnakeHead()
{
    delete position;
    delete ui;
}


unsigned int SnakeHead::get_length(){
    return length;
}

/*void SnakeHead::set_length(){
    length = body.size();
    return;
}*/

const unsigned int SnakeHead::get_x(){
    return position->rx();
}

const unsigned int SnakeHead::get_y(){
    return position->ry();
}

void SnakeHead::move(){
    if(hor_dir && ver_dir)
        moveLeft();
    else if(hor_dir == true && ver_dir == false)
        moveUp();
    else if(hor_dir == false && ver_dir == true)
        moveRight();
    else
        moveDown();
}
