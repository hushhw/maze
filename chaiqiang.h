#ifndef CHAIQIANG_H
#define CHAIQIANG_H
#include "migong.h"
#include <QWidget>

namespace Ui {
class chaiqiang;
}

class chaiqiang : public QWidget
{
    Q_OBJECT

public:
    explicit chaiqiang(QWidget *parent = 0);
    ~chaiqiang();
    void mousePressEvent(QMouseEvent *e);
private slots:
    void on_pushButton_clicked();

private:
    Ui::chaiqiang *ui;
};

#endif // CHAIQIANG_H
