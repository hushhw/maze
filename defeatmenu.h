#ifndef DEFEATMENU_H
#define DEFEATMENU_H
#include "migong.h"
#include <QWidget>

namespace Ui {
class defeatmenu;
}

class defeatmenu : public QWidget
{
    Q_OBJECT

public:
    explicit defeatmenu(QWidget *parent = 0);
    ~defeatmenu();
    void mousePressEvent(QMouseEvent *e);

private slots:
    void on_pushButton_clicked();

private:
    Ui::defeatmenu *ui;
};

#endif // DEFEATMENU_H
