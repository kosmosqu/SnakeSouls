#include "player.h"
#include "ui_player.h"

Player::Player(QPoint* ini, QLabel *parent) :
    QLabel(parent),
    ui(new Ui::Player),
    cherrys(0),
    player_position(ini)
{
    ui->setupUi(this);
    QString filename(":/make.jpg");
    player_image = new QPixmap(filename);
    setPixmap(*player_image);
}

Player::~Player()
{
    delete player_position;
    delete player_image;
    delete ui;
}


void Player::moveUp(){
    if(player_position->y() > 0){
    player_position->setY(player_position->ry()-1);
        return;}
    else
        return;
}

void Player::moveLeft(){
    if(player_position->x() > 0){
    player_position->setX(player_position->rx()-1);
        return;}
    else
        return;
}

void Player::moveRight(){
    if(player_position->x() < 10){
    player_position->setX(player_position->rx()+1);
        return;}
    else
        return;
}

void Player::moveDown(){
    if(player_position-> y() < 10){
    player_position->setY(player_position->ry()+1);
        return;}
    else
        return;
}

unsigned int Player::get_x(){
    return player_position->x();
}

unsigned int Player::get_y(){
    return player_position->y();
}

void Player::showEvent(QShowEvent* e){
    QWidget::show();
}


