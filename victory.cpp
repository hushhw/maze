#include "victory.h"
#include "ui_victory.h"
#include "migong.h"

victory::victory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::victory)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Popup);
    mg = new migong;
}

victory::~victory()
{
    delete ui;
}

void victory::mousePressEvent(QMouseEvent *e)
{
    setAttribute(Qt::WA_NoMouseReplay);
    QWidget::mousePressEvent(e);
}


void victory::on_return_2_clicked()
{
    mg->creatmaze();
    close();

}
