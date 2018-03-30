#include "chaiqiang.h"
#include "ui_chaiqiang.h"

chaiqiang::chaiqiang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chaiqiang)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Popup);
}

chaiqiang::~chaiqiang()
{
    delete ui;
}

void chaiqiang::mousePressEvent(QMouseEvent *e)
{
    setAttribute(Qt::WA_NoMouseReplay);
    QWidget::mousePressEvent(e);
}

void chaiqiang::on_pushButton_clicked()
{
    close();
}
