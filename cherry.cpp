#include "cherry.h"
#include "ui_cherry.h"

cherry::cherry(QPoint *pos, QLabel *parent) :
    QLabel(parent),
    ui(new Ui::cherry),
    position(pos)
{

    ui->setupUi(this);
}

cherry::~cherry()
{
    delete ui;
    delete position;
}

void cherry::showEvent(QShowEvent* e){
    QWidget::show();
}

