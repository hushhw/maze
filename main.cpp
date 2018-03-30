#include "migong.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    migong w;
   // w.setWindowOpacity(1);
   // w.setWindowFlags(Qt::FramelessWindowHint);
   // w.setAttribute(Qt::WA_TranslucentBackground);
    w.show();

    return a.exec();
}
