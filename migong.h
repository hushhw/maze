#ifndef MIGONG_H
#define MIGONG_H

#include <QWidget>
#include <iostream>
#include <stack>
#include <vector>
#include <QTimer>
#include <QDateTime>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPixmap>
#include <queue>
#include <QPoint>
#include "victory.h"
#include "chaiqiang.h"
#include "defeatmenu.h"
#include <QMediaPlayer>
class victory;
class chaiqiang;
class defeatmenu;
using namespace std;

namespace Ui {
class migong;
}

class maze
{
public:
    int i;
    int j;
    int state;//用来判断是否为墙
};

class Box//定义一个用于迷宫寻路存放迷宫节点信息的类
{
public:
    int i;
    int j;
    int di;//代表寻路四个方向 0上 1右 2下 3左
};

class Box1//定义一个用于迷宫寻最短路径存放迷宫节点的类
{
public:
    int i;
    int j;
    int pre;
    int num;
};

class migong : public QWidget
{
    Q_OBJECT

public:
    explicit migong(QWidget *parent = 0);
    ~migong();
    //void paintEvent(QPaintEvent *);
    void creatmaze();
    void paintEvent(QPaintEvent *);
    bool judgeisJiShu();//判断lineedit输入是否为奇数
    void keyPressEvent(QKeyEvent *);//重写时间
    void Findway();//深度优先遍历寻找迷宫路径
    void selectjuese(int t);
    QMediaPlayer *player;
    QMediaPlayer *defeat;
    QMediaPlayer *victorybgm;
    QMediaPlayer *move;
    victory *v;
    chaiqiang *c;
    defeatmenu *d;
    int temp;

private slots:
    void creatmazebtnSlot();
    void findwaybtnSlot();
    void chaiqiangbtnSlot();
    void cancelbtnSlot();
    void timerUpDate();
    void on_juese_clicked();
    void on_juese_1_clicked();
    void on_juese_2_clicked();
    void on_juese_3_clicked();
    void on_juese_4_clicked();
    void on_juese_5_clicked();

private:
    Ui::migong *ui;
    int M;
    int N;
    bool first;
    bool chaiqiangbool;//用于判断是否进行拆墙
    maze **matrix;
    stack<maze> *MazeStack;//定义一个栈用于存放迷宫节点
    vector<maze> *FinalPath;//定义一个向量用于存放迷宫路径
    stack<Box> *BoxStack;//定义一个栈用于存放寻路节点
    //老鼠的坐标
    int X;
    int Y;
    QTimer *timer;
    int type;
};

#endif // MIGONG_H
