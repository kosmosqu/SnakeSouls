#include "snakebody.h"
#include "ui_snakebody.h"

SnakeBody::SnakeBody(QPoint *pos, QLabel *parent) :
    QLabel(parent),
    ui(new Ui::SnakeBody),
    position(pos)
{
    ui->setupUi(this);
}

SnakeBody::SnakeBody():
ui(new Ui::SnakeBody)
{
    former=nullptr;
    later=nullptr;
    image=nullptr;
    position = nullptr;
}

SnakeBody::~SnakeBody()
{
    delete position;
    delete ui;
}

SnakeBody::SnakeBody(SnakeBody &s){
    former = s.former;
    later = s.later;
    position = new QPoint(s.position->rx(),s.position->ry());
}

void SnakeBody::showEvent(QShowEvent* e){
    QWidget::showEvent(e);
}

