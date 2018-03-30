/********************************************************************************
** Form generated from reading UI file 'migong.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIGONG_H
#define UI_MIGONG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_migong
{
public:
    QWidget *mgjiemian;
    QWidget *caidan;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *Xline;
    QLineEdit *Yline;
    QLabel *tiplabel;
    QPushButton *createwaybtn;
    QHBoxLayout *horizontalLayout;
    QPushButton *juese;
    QPushButton *juese_1;
    QPushButton *juese_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *juese_3;
    QPushButton *juese_4;
    QPushButton *juese_5;
    QLabel *label;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLCDNumber *time_num;
    QPushButton *findwaybtn_2;
    QPushButton *chaiqiangbtn;
    QPushButton *cancelbtn;

    void setupUi(QWidget *migong)
    {
        if (migong->objectName().isEmpty())
            migong->setObjectName(QStringLiteral("migong"));
        migong->resize(938, 656);
        mgjiemian = new QWidget(migong);
        mgjiemian->setObjectName(QStringLiteral("mgjiemian"));
        mgjiemian->setGeometry(QRect(220, 10, 691, 641));
        mgjiemian->setStyleSheet(QStringLiteral(""));
        caidan = new QWidget(migong);
        caidan->setObjectName(QStringLiteral("caidan"));
        caidan->setEnabled(true);
        caidan->setGeometry(QRect(10, 10, 201, 641));
        caidan->setMaximumSize(QSize(300, 16777215));
        caidan->setStyleSheet(QStringLiteral("background-color: rgb(255, 226, 110);"));
        verticalLayout = new QVBoxLayout(caidan);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Xline = new QLineEdit(caidan);
        Xline->setObjectName(QStringLiteral("Xline"));
        Xline->setMinimumSize(QSize(0, 20));
        Xline->setMaximumSize(QSize(60, 30));

        gridLayout_2->addWidget(Xline, 0, 0, 1, 1);

        Yline = new QLineEdit(caidan);
        Yline->setObjectName(QStringLiteral("Yline"));
        Yline->setMinimumSize(QSize(0, 20));
        Yline->setMaximumSize(QSize(60, 60));

        gridLayout_2->addWidget(Yline, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        tiplabel = new QLabel(caidan);
        tiplabel->setObjectName(QStringLiteral("tiplabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tiplabel->sizePolicy().hasHeightForWidth());
        tiplabel->setSizePolicy(sizePolicy);
        tiplabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(tiplabel);

        createwaybtn = new QPushButton(caidan);
        createwaybtn->setObjectName(QStringLiteral("createwaybtn"));
        createwaybtn->setMaximumSize(QSize(16777215, 50));
        createwaybtn->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        createwaybtn->setFont(font);
        createwaybtn->setMouseTracking(false);
        createwaybtn->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/menu1.jpg);"));

        verticalLayout->addWidget(createwaybtn);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        juese = new QPushButton(caidan);
        juese->setObjectName(QStringLiteral("juese"));
        juese->setMaximumSize(QSize(50, 50));
        juese->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/1.jpg);"));

        horizontalLayout->addWidget(juese);

        juese_1 = new QPushButton(caidan);
        juese_1->setObjectName(QStringLiteral("juese_1"));
        juese_1->setMaximumSize(QSize(50, 50));
        juese_1->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/2.jpg);"));

        horizontalLayout->addWidget(juese_1);

        juese_2 = new QPushButton(caidan);
        juese_2->setObjectName(QStringLiteral("juese_2"));
        juese_2->setMaximumSize(QSize(50, 50));
        juese_2->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/3.jpg);"));

        horizontalLayout->addWidget(juese_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        juese_3 = new QPushButton(caidan);
        juese_3->setObjectName(QStringLiteral("juese_3"));
        juese_3->setMaximumSize(QSize(50, 50));
        juese_3->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/4.jpg);"));

        horizontalLayout_2->addWidget(juese_3);

        juese_4 = new QPushButton(caidan);
        juese_4->setObjectName(QStringLiteral("juese_4"));
        juese_4->setMaximumSize(QSize(50, 50));
        juese_4->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/5.jpg);"));

        horizontalLayout_2->addWidget(juese_4);

        juese_5 = new QPushButton(caidan);
        juese_5->setObjectName(QStringLiteral("juese_5"));
        juese_5->setMaximumSize(QSize(50, 50));
        juese_5->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/6.jpg);"));

        horizontalLayout_2->addWidget(juese_5);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(caidan);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(200, 200));
        label->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/1.jpg);"));

        verticalLayout->addWidget(label);

        label_1 = new QLabel(caidan);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setMaximumSize(QSize(200, 200));
        label_1->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/2.jpg);"));

        verticalLayout->addWidget(label_1);

        label_2 = new QLabel(caidan);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(200, 200));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/3.jpg);"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(caidan);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(200, 200));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/4.jpg);"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(caidan);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(200, 200));
        label_4->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/5.jpg);"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(caidan);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(200, 200));
        label_5->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/6.jpg);"));

        verticalLayout->addWidget(label_5);

        time_num = new QLCDNumber(caidan);
        time_num->setObjectName(QStringLiteral("time_num"));
        time_num->setMaximumSize(QSize(200, 100));

        verticalLayout->addWidget(time_num);

        findwaybtn_2 = new QPushButton(caidan);
        findwaybtn_2->setObjectName(QStringLiteral("findwaybtn_2"));
        findwaybtn_2->setEnabled(false);
        findwaybtn_2->setMaximumSize(QSize(16777215, 50));
        findwaybtn_2->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/menu2.jpg);"));

        verticalLayout->addWidget(findwaybtn_2);

        chaiqiangbtn = new QPushButton(caidan);
        chaiqiangbtn->setObjectName(QStringLiteral("chaiqiangbtn"));
        chaiqiangbtn->setEnabled(false);
        chaiqiangbtn->setMaximumSize(QSize(16777215, 50));
        chaiqiangbtn->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/menu3.jpg);"));

        verticalLayout->addWidget(chaiqiangbtn);

        cancelbtn = new QPushButton(caidan);
        cancelbtn->setObjectName(QStringLiteral("cancelbtn"));
        cancelbtn->setEnabled(false);
        cancelbtn->setMaximumSize(QSize(16777215, 50));
        cancelbtn->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/menu4.jpg);"));

        verticalLayout->addWidget(cancelbtn);

        QWidget::setTabOrder(chaiqiangbtn, cancelbtn);

        retranslateUi(migong);

        QMetaObject::connectSlotsByName(migong);
    } // setupUi

    void retranslateUi(QWidget *migong)
    {
        migong->setWindowTitle(QApplication::translate("migong", "migong", 0));
        tiplabel->setText(QApplication::translate("migong", "\350\277\267\345\256\253\351\225\277\345\256\275\344\273\205\350\203\275\350\276\223\345\205\245\345\245\207\346\225\260", 0));
        createwaybtn->setText(QString());
        juese->setText(QString());
        juese_1->setText(QString());
        juese_2->setText(QString());
        juese_3->setText(QString());
        juese_4->setText(QString());
        juese_5->setText(QString());
        label->setText(QString());
        label_1->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        findwaybtn_2->setText(QString());
        chaiqiangbtn->setText(QString());
        cancelbtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class migong: public Ui_migong {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIGONG_H
