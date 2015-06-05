#include "gameboard.h"
#include "ui_gameboard.h"
#include <QLabel>
#include <QString>

GameBoard::GameBoard(QWidget *parent,unsigned int size) :
    QWidget(parent),
    board_size(size),
    ui(new Ui::GameBoard)
{
    //board_size = 10;
    ui->setupUi(this);

    ui->gridLayout->setGeometry(QRect());

    QLabel** labels = new QLabel*[board_size*board_size];// @param labels a pointer's pointer to create a container for labels.

    for(size_t i = 0;i<board_size;++i){
        for(size_t j = 0;j<board_size;++j){
            labels[i*board_size+j]= new QLabel("Hello World!");//create new labels with text "Hello World!" to test working
            ui->gridLayout->addWidget(labels[i*board_size+j],i,j);
        }
    }


}


GameBoard::~GameBoard()
{
    delete[] units;
    delete p1;
    delete che;
    delete ui;
}


void GameBoard::keyPressEvent(QKeyEvent *keypress){
    switch(keypress->key()){
    case Qt::Key_Left:
        if(p1->player_position->y() > 0){
        p1->moveLeft();
        game_over = player_die();
        turn();
        }
    break;
    case Qt::Key_Up:
        if(p1->player_position->x()> 0){
        p1->moveUp();
        game_over = player_die();
        turn();
         }
    break;
    case Qt::Key_Right:
        if(p1->player_position->y()< 9){
        p1->moveRight();
        game_over = player_die();
        turn();
         }
    break;
    case Qt::Key_Down:
        if(p1->player_position->x() < 9){
        p1->moveDown();
        game_over = player_die();
        turn();
        }
    break;
    default:
        QWidget::keyPressEvent(keypress);
    }
    QCoreApplication::processEvents();
    return;
}

void GameBoard::paintEvent(QPaintEvent *p){
    //delete[] labels;


    //everytime updates, we create a new label matrix
    for(size_t i = 0;i<board_size;++i){
            for(size_t j = 0;j<board_size;++j){
                units[j*board_size+i]= new QLabel();
                ui->gridLayout->addWidget(units[j*board_size+i],i,j);
            }
        }

    int px = p1->get_x();
    int py = p1->get_y();
    units[py*board_size+px] = p1;
    int snake_x;
    int snake_y;
    for(size_t j=0;j<snake.size();++j){
        snake_x = snake[j]->position->rx();
        snake_y = snake[j]->position->ry();
        units[snake_y*board_size +snake_x] = snake[j];
    }
    //unsigned int head_x = snake[0]->get_x();
    //unsigned int head_y = snake[0]->get_y();
    //units[head_y*board_size+head_x] = snake;
    /*unsigned int body_x;
    unsigned int body_y;
    for(size_t i=0; i <snake->get_length();++i){
        body_x = snake
    }*/
}

void GameBoard::showEvent(QShowEvent *e){
    this->activateWindow();
    this->setFocus();
    QWidget::showEvent(e);
    //p1->showEvent(e);
    //snake->showEvent(e);
}

void GameBoard::turn(){
    if(!game_over){
        update_player();
        if(snake_is_alive){
        set_snake_direction();
        update_snake();
    game_over = player_die();
    update_cherry();
    repaint();
    }
    else{
        return;
    }

}
}

void GameBoard::update_cherry(){
    if(che == nullptr){

        int x = rand()%10;
        int y = rand()%10;
        QPoint* cherry_place = new QPoint(x,y);
        che = new cherry(cherry_place);
        return;
    }
    else
        return;
}

void GameBoard::update_snake(){
    SnakeBody* temp = new SnakeBody((*snake[snake.size()-1]));
    for(size_t i=snake.size();i>=0;--i){
        snake[i]->move();
    }
    if(snake[0]->get_position() == che->get_position()){
        snake.push_back(temp);
        delete che;
        che = nullptr;
    }
    else{
        delete temp;
    }
    set_snake_direction();
    return;
}

/*void GameBoard::snake_hurt(){
    for(size_t i = 0;i<snake.size();++i){
        if(*(snake[i]->position) == p1->get_position()){
            if(p1->cherrys == 0){

            }
        }
    }
}*/

bool GameBoard::player_die(){
    for(size_t i = 0;i<snake.size();++i){
        if(snake[i]->get_position() == p1->get_position()){
            if(p1->cherrys == 0){
                player_is_alive = false;
                return true;

            }
            else{
                if(i=0){
                    snake_is_alive=false;
                }
                else{
                    snake_pop_back();
                }
            }
        }
    }
    return false;
}

void GameBoard::update_player(){
    if(p1->get_position() == che->get_position()){
        ++(p1->cherrys);
    }
}

//player on the left => phd >= 0
int GameBoard::player_hor_distance(){
    return snake[0]->position->y()-p1->get_y();
}

//player on the top => pvd>= 0;
int GameBoard::player_ver_distance(){
    return snake[0]->position->x()-p1->get_x();
}

//cherry on the left => chd>= 0
int GameBoard::cherry_hor_distance(){
    return snake[0]->position->y()-che->position->y();
}

//cherry on the top =>cvd>0
int GameBoard::cherry_ver_distance(){
    return (snake[0]->position->x())-(che->position->x());
}

void GameBoard::set_snake_direction(){
    unsigned int snake_to_cherry = ((snake[0]->position->x())-(che->position->x()))*((snake[0]->position->x())-(che->position->x())) +((snake[0]->position->y())-(che->position->y()))*((snake[0]->position->y())-(che->position->y()));
    unsigned int snake_to_player = (snake[0]->position->x()-p1->get_x())*(snake[0]->position->x()-p1->get_x())+(snake[0]->position->y()-p1->get_y())*(snake[0]->position->y()-p1->get_y());
    unsigned int player_to_cherry= (p1->get_x()-(che->position->x()))* (p1->get_x()-(che->position->x()))+ (p1->get_y()-(che->position->y()))* (p1->get_y()-(che->position->y()));

    if(p1->cherrys == 0){
    //case 1:player is closer to cherry,go chase player
    if(snake_to_cherry >= player_to_cherry){
       int del_x= player_hor_distance();
       int del_y= player_ver_distance();
       if (std::abs(del_x)>= std::abs(del_y)){
           if(del_x>0){//goes up
               snake[0]->hor_dir = true;
               snake[0]->ver_dir = false;
           }
           else{//goes down
               snake[0]->hor_dir = false;
               snake[0]->ver_dir = false;
           }

       }

       else{
           if(del_y>0){//goes left
               snake[0]->hor_dir = true;
               snake[0]->ver_dir= true;
           }
           else{//goes right
               snake[0]->hor_dir = false;
               snake[0]->ver_dir = true;
           }
       }
    }
    //case 2:cherry is closer to snake than to player
    else{
        int del_x = cherry_hor_distance();
        int del_y = cherry_ver_distance();
        if ( abs(del_x)>= abs(del_y)){
            if(del_x>0){//goes up
                snake[0]->hor_dir = true;
                snake[0]->ver_dir = false;
            }
            else{//goes down
                snake[0]->hor_dir = false;
                snake[0]->ver_dir = false;
            }

        }

        else{
            if(del_y>0){//goes left
                snake[0]->hor_dir = true;
                snake[0]->ver_dir= true;
            }
            else{//goes right
                snake[0]->hor_dir = false;
                snake[0]->ver_dir = true;
            }}
        }
    }
    else{
        int del_x = cherry_hor_distance();
        int del_y = cherry_ver_distance();
        if (abs(del_x)>=abs(del_y)){
            if(del_x>0){//goes up
                snake[0]->hor_dir = true;
                snake[0]->ver_dir = false;
            }
            else{//goes down
                snake[0]->hor_dir = false;
                snake[0]->ver_dir = false;
            }

        }

        else{
            if(del_y>0){//goes left
                snake[0]->hor_dir = true;
                snake[0]->ver_dir= true;
            }
            else{//goes right
                snake[0]->hor_dir = false;
                snake[0]->ver_dir = true;
            }}
    }
   }

void GameBoard::snake_pop_back(){
    delete snake[snake.size()-1];
    snake.pop_back();
}

