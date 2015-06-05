#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<gameboard.h>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void begin_new_game();
    void begin_new_game_plus();
    void begin_new_game_plusplus();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GameBoard* board;
};

#endif // MAINWINDOW_H
