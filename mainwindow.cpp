#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//*slots for three different difficult levels, although they are same right now*/
void MainWindow::begin_new_game(){
    board = new GameBoard;
    setCentralWidget(board);
    return;
}
void MainWindow::begin_new_game_plus(){
    board = new GameBoard;
    setCentralWidget(board);
    return;
}
void MainWindow::begin_new_game_plusplus(){
    board = new GameBoard;
    setCentralWidget(board);
    return;
}
