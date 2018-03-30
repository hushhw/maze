#ifndef VICTORY_H
#define VICTORY_H

#include <QWidget>
#include "migong.h"
class migong;
namespace Ui {
class victory;
}

class victory : public QWidget
{
    Q_OBJECT

public:
    explicit victory(QWidget *parent = 0);
    ~victory();
    void mousePressEvent(QMouseEvent *e);
    migong *mg;

private slots:

    void on_return_2_clicked();

private:
    Ui::victory *ui;
};

#endif // VICTORY_H
