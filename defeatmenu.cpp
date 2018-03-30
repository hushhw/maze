#include "defeatmenu.h"
#include "ui_defeatmenu.h"

defeatmenu::defeatmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::defeatmenu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Popup);
}

defeatmenu::~defeatmenu()
{
    delete ui;
}

void defeatmenu::mousePressEvent(QMouseEvent *e)
{
    setAttribute(Qt::WA_NoMouseReplay);
    QWidget::mousePressEvent(e);
}

void defeatmenu::on_pushButton_clicked()
{
    close();
}
