#ifndef TEMP_H
#define TEMP_H

#include <QWidget>

namespace Ui {
class temp;
}

class temp : public QWidget
{
    Q_OBJECT

public:
    explicit temp(QWidget *parent = 0);
    ~temp();

private:
    Ui::temp *ui;
};

#endif // TEMP_H
