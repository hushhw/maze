#include "migong.h"
#include "ui_migong.h"
#include "victory.h"
#include <QSound>
#include <QUrl>     //用于设置资源地址

migong::migong(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::migong)
{

        player = new QMediaPlayer;
        player->setMedia(QUrl("qrc:/bgm/debug/Two Steps From Hell - Victory.wav"));
        player->setVolume(100);

        defeat = new QMediaPlayer;
        defeat->setMedia(QUrl("qrc:/bgm/debug/defeat.wav"));
        defeat->setVolume(100);

        victorybgm = new QMediaPlayer;
        victorybgm->setMedia(QUrl("qrc:/bgm/debug/victory.wav"));
        victorybgm->setVolume(100);

        move = new QMediaPlayer;
        move->setMedia(QUrl("qrc:/bgm/debug/yidong.wav"));
        move->setVolume(100);

    type=33;
    first=true;
    M = 33;
    N = 33;
    ui->setupUi(this);
    this->setWindowTitle("迷宫游戏");
    ui->Xline->setText("33");
    ui->Yline->setText("33");
    ui->label_1->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    matrix=new maze *[M];//申请长度为行数的二级指针
    for(int i=0; i<M; i++)
    {
        matrix[i]=new maze[N];//申请每个二级指针的空间
    }
    for(int i=0; i<M; i++)
        for(int j=0;j<N;j++)
        {
            matrix[i][j].i=i;
            matrix[i][j].j=j;
            matrix[i][j].state=0;//0墙，1路
        }

    QTimer *timer=new QTimer(this);
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    MazeStack=new stack<maze>;
    FinalPath=new vector<maze>;
    BoxStack=new stack<Box>;
    X=1;
    Y=1;
    chaiqiangbool=false;
    connect(ui->createwaybtn,SIGNAL(clicked()),this,SLOT(creatmazebtnSlot()));
    connect(ui->findwaybtn_2,SIGNAL(clicked()),this,SLOT(findwaybtnSlot()));
    connect(ui->chaiqiangbtn,SIGNAL(clicked()),this,SLOT(chaiqiangbtnSlot()));
    connect(ui->cancelbtn,SIGNAL(clicked()),this,SLOT(cancelbtnSlot()));

}

migong::~migong()
{
    delete ui;
}

void migong::keyPressEvent(QKeyEvent *e)
{
    if(chaiqiangbool)//如果拆墙
    {
        if(e->key()==Qt::Key_Up ||e->key()=='W')//上
        {
            if(X>1)
            {
                X=X-1;
            }
            move->play();
        }
        else if(e->key()==Qt::Key_Down||e->key()=='S')//下
        {
            if(X<M-2)
            {
                X=X+1;
            }
            move->play();
        }
        else if(e->key()==Qt::Key_Left||e->key()=='A')//左
        {
            if(Y>1)
            {
                Y=Y-1;
            }
            move->play();
        }
        else if(e->key()==Qt::Key_Right||e->key()=='D')//右
        {

            if(Y<N-2)
            {
                Y=Y+1;
            }
            move->play();
        }
        matrix[X][Y].state=1;

        if(X==M-2&&Y==N-2)
        {
            player->stop();
            victorybgm->play();
            //QMessageBox::information(this,"提示","恭喜过关",QMessageBox::Yes);
            v=new victory;
            v->move(700,400);
            v->show();


            temp = ui->Xline->text().toInt() + 1;
            for(int i=0;i<M;i++)
                for(int j=0;j<N;j++)
                    matrix[i][j].state=0;
            this->creatmaze();
            chaiqiangbool=false;
            ui->cancelbtn->setEnabled(false);
            ui->chaiqiangbtn->setEnabled(true);
            ui->findwaybtn_2->setEnabled(true);
            ui->createwaybtn->setEnabled(true);
            FinalPath->clear();
            X=1;
            Y=1;
            if(X%2==0)
                X+=1;
            if(Y%2==0)
                Y+=1;
        }

    }
    else
    {
        int k;
        if(e->key()==Qt::Key_Up||e->key()=='W')//上
        {
            k=X-1;
            if(k>0&&matrix[k][Y].state!=0)
                X=k;
            move->play();
        }
        else if(e->key()==Qt::Key_Down||e->key()=='S')//下
        {
            k=X+1;
            if(k<M-1&&matrix[k][Y].state!=0)
                X=k;
            move->play();
        }
        else if(e->key()==Qt::Key_Left||e->key()=='A')//左
        {
            k=Y-1;
            if(k>0&&matrix[X][k].state!=0)
                Y=k;
            move->play();
        }
        else if(e->key()==Qt::Key_Right||e->key()=='D')//右
        {
            k=Y+1;
            if(k<N-1&&matrix[X][k].state!=0)
                Y=k;
            move->play();
        }

        if(X==M-2&&Y==N-2)
        {
            player->stop();
            victorybgm->play();
            //QMessageBox::information(this,"提示","恭喜过关",QMessageBox::Yes);
            v=new victory;
            v->move(700,400);
            v->show();

            temp = ui->Xline->text().toInt() + 1;
            for(int i=0;i<M;i++)
                for(int j=0;j<N;j++)
                    matrix[i][j].state=0;
            this->creatmaze();
            FinalPath->clear();
            X=1;
            Y=1;
            if(X%2==0)
                X+=1;
            if(Y%2==0)
                Y+=1;
        }

    }
    update();
}

void migong::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    for(int i=FinalPath->size()-1;i>=0;i--)
    {
        matrix[FinalPath->at(i).i][FinalPath->at(i).j].state=2;
        if(FinalPath->at(i).i==X&&FinalPath->at(i).j==Y)
        {
            matrix[FinalPath->at(i).i][FinalPath->at(i).j].state=1;
            FinalPath->pop_back();
        }
    }

    if(!first)
    {
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
            {
                if(i==X&&j==Y)
                {
                    switch(type)
                    {
                    case 0:
                        painter.drawPixmap(ui->mgjiemian->x() +j*20,ui->mgjiemian->y() +i*20,20,20,QPixmap(":/meze/img/1.jpg").scaled(20,20));
                        break;
                    case 1:
                        painter.drawPixmap(ui->mgjiemian->x() +j*20,ui->mgjiemian->y() +i*20,20,20,QPixmap(":/meze/img/2.jpg").scaled(20,20));
                        break;
                    case 2:
                        painter.drawPixmap(ui->mgjiemian->x() +j*20,ui->mgjiemian->y() +i*20,20,20,QPixmap(":/meze/img/3.jpg").scaled(20,20));
                        break;
                    case 3:
                        painter.drawPixmap(ui->mgjiemian->x() +j*20,ui->mgjiemian->y() +i*20,20,20,QPixmap(":/meze/img/4.jpg").scaled(20,20));
                        break;
                    case 4:
                        painter.drawPixmap(ui->mgjiemian->x() +j*20,ui->mgjiemian->y() +i*20,20,20,QPixmap(":/meze/img/5.jpg").scaled(20,20));
                        break;
                    case 5:
                        painter.drawPixmap(ui->mgjiemian->x() +j*20,ui->mgjiemian->y() +i*20,20,20,QPixmap(":/meze/img/6.jpg").scaled(20,20));
                        break;
                    }
                }
                else if(i==M-2&&j==N-2)
                {
                    painter.drawPixmap(ui->mgjiemian->x() +j*20,ui->mgjiemian->y() +i*20,20,20,QPixmap(":/meze/img/liangcang.jpg").scaled(20,20));
                }
                else
                {
                    switch(matrix[i][j].state)
                    {
                    case 0://画墙壁
                        painter.setBrush(QColor(255, 204, 0));
                        painter.setPen(QColor(255,204, 0));
                        painter.drawRect(QRect(ui->mgjiemian->x() +j*20,ui->mgjiemian->y() +i*20,20,20));
                        break;
                    case 1://画通路
                        painter.setBrush(Qt::white);
                        painter.setPen(Qt::white);
                        painter.drawRect(QRect(ui->mgjiemian->x() +j*20,ui->mgjiemian->y() +i*20,20,20));
                        break;
                    case 2://画迷宫寻找路径
                        painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
                        painter.drawRect(QRect(ui->mgjiemian->x() +j*20,ui->mgjiemian->y() +i*20,20,20));
                        break;
                    }
                }
            }
    }
}

void migong::creatmazebtnSlot()
{
    type = qrand()%6;
    temp = ui->Xline->text().toInt() + 1;
    if(judgeisJiShu())
    {
        if(ui->Xline->text().toInt()>5&&ui->Yline->text().toInt()>5)
        {
            //删除原先matrix数组
            for(int i=0;i<M;i++)
            delete [] matrix[i];
            delete [] matrix;
            M=ui->Xline->text().toInt();
            N=ui->Yline->text().toInt();
            ui->caidan->resize(190,M*20);
            ui->mgjiemian->resize(N*20, M*20);
            this->resize(ui->mgjiemian->x() + N*20 + 20,M*20 + 20);
            FinalPath->clear();

            ui->findwaybtn_2->setEnabled(true);
            ui->chaiqiangbtn->setEnabled(true);
            chaiqiangbool=false;

            //初始老鼠的位置，在迷宫的中央
            X=1;
            Y=1;
            if(X%2==0)
                X+=1;
            if(Y%2==0)
                Y+=1;
            //重新创建新matrix数组，因为M和N发生了改变

            matrix=new maze*[M];
            for(int i=0;i<M;i++)
            {
                matrix[i]=new maze[N];
            }
            for(int i=0;i<M;i++)
                for(int j=0;j<N;j++)
                {
                    matrix[i][j].state=0;//初始化迷宫矩阵，将所有节点设置为墙
                    matrix[i][j].i=i;
                    matrix[i][j].j=j;
                }
            this->creatmaze();
            first=false;
            update();
        }
        else
        {
            QMessageBox::information(this,"警告","输入的数不能小于5",QMessageBox::Yes);
            ui->Xline->clear();
            ui->Yline->clear();
        }
    }
    else
    {
        QMessageBox::information(this,"警告","请输入奇数",QMessageBox::Yes);
        ui->Xline->clear();
        ui->Yline->clear();
    }

}

bool migong::judgeisJiShu()
{
    if(ui->Xline->text().toInt()%2==0||ui->Yline->text().toInt()%2==0)
        return false;
    return true;
}

//创建迷宫节点矩阵
void migong::creatmaze()
{

    player->play();
    this->setFocus(Qt::MouseFocusReason);
    int i=3,j=3;//设置随机数
    int randNum=0;//设置迷宫节点矩阵初始点位置为通路
    matrix[i][j].state=1;//定义一个临时节点
    maze temp;
    temp.i=i;
    temp.j=j;
    temp.state=1;//false表示访问的方向，
    bool Up=false;
    bool Down=false;
    bool Right=false;
    bool Left=false;//进入循环，不断生成迷宫矩阵，直至栈为空
    while(1)
    {
        temp.i=i;
        temp.j=j;
        randNum=qrand()%4;
        switch(randNum)
        {
        case 0://上
            if(!Up&&i>2&&matrix[i-2][j].state==0)
            {
                MazeStack->push(temp);
                matrix[i-2][j].state=1;
                matrix[i-1][j].state=1;
                i=i-2;
                Up=false;
                Down=false;
                Right=false;
                Left=false;
            }
            else
                Up=true;
            break;
        case 1://下
            if(!Down&&i<M-3&&matrix[i+2][j].state==0)
            {
                MazeStack->push(temp);
                matrix[i+2][j].state=1;
                matrix[i+1][j].state=1;
                i=i+2;
                Up=false;
                Down=false;
                Right=false;
                Left=false;
            }
            else
                Down=true;
            break;
        case 2://左
            if(!Left&&j>2&&matrix[i][j-2].state==0)
            {
                MazeStack->push(temp);
                matrix[i][j-2].state=1;
                matrix[i][j-1].state=1;
                j=j-2;
                Up=false;
                Down=false;
                Right=false;
                Left=false;
            }
            else
                Left=true;
            break;
        case 3://右
            if(!Right&&j<N-3&&matrix[i][j+2].state==0)
            {
                MazeStack->push(temp);
                matrix[i][j+2].state=1;
                matrix[i][j+1].state=1;
                j=j+2;
                Up=false;
                Down=false;
                Right=false;
                Left=false;
            }
            else
                Right=true;
            break;
        }
        if(Up&&Down&&Right&&Left)//如果当前访问节点四个方向都没有可拆的节点，回溯
        {
            if(!MazeStack->empty())
            {
                i=MazeStack->top().i;
                j=MazeStack->top().j;
                MazeStack->pop();
                Up=false;
                Down=false;
                Right=false;
                Left=false;
            }
            else//如果栈为空的话就返回，此时迷宫矩阵已经创建完毕
                return;
        }
    }

}

//用深度优先遍历的方法寻找路径,将路径数据保存在FinalPath容器中
void migong::Findway()
{
    FinalPath->clear();
    int i,j,di,find;
    maze mm[M][N];
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
        {
            mm[i][j].state=matrix[i][j].state;
            mm[i][j].i=i;
            mm[i][j].j=j;
        }
    Box box;
    box.i=X;
    box.j=Y;
    box.di=-1;
    BoxStack->push(box);
    mm[X][Y].state=-1;
    while(1)
    {
        i=BoxStack->top().i;
        j=BoxStack->top().j;
        di=BoxStack->top().di;
        if(i==M-2&&j==N-2)//如果当前栈顶为节点，将路径存放劲FinalPath
        {
            while(!BoxStack->empty())
            {
                maze temp;
                temp.i=BoxStack->top().i;
                temp.j=BoxStack->top().j;
                temp.state=1;
                FinalPath->push_back(temp);
                BoxStack->pop();
            }
            return;
        }
        find=0;
        while(find==0&&di<4)
        {
            di++;
            switch(di)
            {
            case 0:i=BoxStack->top().i-1;j=BoxStack->top().j;break;//向上寻路
            case 1:i=BoxStack->top().i;j=BoxStack->top().j+1;break;//向右寻路
            case 2:i=BoxStack->top().i+1;j=BoxStack->top().j;break;//向下寻路
            case 3:i=BoxStack->top().i;j=BoxStack->top().j-1;break;//向左寻路
            }
            if(mm[i][j].state==1)
            {
                find=1;
            }
        }
        if(find==1)
        {
            mm[i][j].state=-1;
            BoxStack->top().di=di;
            box.i=i;
            box.j=j;
            box.di=-1;
            BoxStack->push(box);
        }
        else
        {
            BoxStack->pop();
        }
    }
}
void migong::findwaybtnSlot()
{
      //使得迷宫矩阵的state为2的值变为1
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
        {
            if(matrix[i][j].state==2)
            {
                matrix[i][j].state=1;
            }
        }
    this->Findway();
    this->setFocus(Qt::MouseFocusReason);
    update();
}

void migong::chaiqiangbtnSlot()
{
    FinalPath->clear();
    //使得迷宫矩阵的state为2的值变为1
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
        {
            if(matrix[i][j].state==2)
            {
                matrix[i][j].state=1;
            }
        }
    update();
    chaiqiangbool=true;
    ui->findwaybtn_2->setEnabled(false);
    this->setFocus(Qt::MouseFocusReason);
    ui->cancelbtn->setEnabled(true);
    ui->chaiqiangbtn->setEnabled(false);
    ui->createwaybtn->setEnabled(false);
    //QMessageBox::information(this,"提示","你已经获得超能力，你可以操作它来拆墙",QMessageBox::Yes);
    c = new chaiqiang;
    c->move(700,400);
    c->show();
}

void migong::cancelbtnSlot()
{
    chaiqiangbool=false;
    this->setFocus(Qt::MouseFocusReason);
    ui->chaiqiangbtn->setEnabled(true);
    ui->cancelbtn->setEnabled(false);
    ui->findwaybtn_2->setEnabled(true);
    ui->createwaybtn->setEnabled(true);
}

void migong::timerUpDate(){
    if(X!=M-2&&Y!=N-2)
    temp--;
    ui->time_num->display(temp);

    if(temp==0){
        player->stop();
       defeat->play();
        //QMessageBox::information(this,"提示","时间到，是否重新开始挑战！",QMessageBox::Yes);
       d = new defeatmenu();
       d->move(700,400);
       d->show();
        //temp = ui->Xline->text().toInt();
        creatmazebtnSlot();
    }

    //ui->time_num->startTimer(temp);
}



void migong::on_juese_clicked()
{
    type = 0;
    this->setFocus(Qt::MouseFocusReason);
    ui->label->show();
    ui->label_1->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    repaint();

}

void migong::on_juese_1_clicked()
{

    type = 1;
    this->setFocus(Qt::MouseFocusReason);
    ui->label->hide();
    ui->label_1->show();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    repaint();
}

void migong::on_juese_2_clicked()
{
    type = 2;
    this->setFocus(Qt::MouseFocusReason);
    ui->label->hide();
    ui->label_1->hide();
    ui->label_2->show();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    repaint();
}

void migong::on_juese_3_clicked()
{
    type = 3;
    this->setFocus(Qt::MouseFocusReason);
    ui->label->hide();
    ui->label_1->hide();
    ui->label_2->hide();
    ui->label_3->show();
    ui->label_4->hide();
    ui->label_5->hide();
    repaint();
}

void migong::on_juese_4_clicked()
{
    type = 4;
    this->setFocus(Qt::MouseFocusReason);
    ui->label->hide();
    ui->label_1->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->show();
    ui->label_5->hide();
    repaint();
}

void migong::on_juese_5_clicked()
{
    type = 5;
    this->setFocus(Qt::MouseFocusReason);
    ui->label->hide();
    ui->label_1->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->show();
    repaint();
}
