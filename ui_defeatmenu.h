/********************************************************************************
** Form generated from reading UI file 'defeatmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFEATMENU_H
#define UI_DEFEATMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_defeatmenu
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *defeatmenu)
    {
        if (defeatmenu->objectName().isEmpty())
            defeatmenu->setObjectName(QStringLiteral("defeatmenu"));
        defeatmenu->resize(568, 233);
        pushButton = new QPushButton(defeatmenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 571, 241));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/defeatmenu.jpg);"));

        retranslateUi(defeatmenu);

        QMetaObject::connectSlotsByName(defeatmenu);
    } // setupUi

    void retranslateUi(QWidget *defeatmenu)
    {
        defeatmenu->setWindowTitle(QApplication::translate("defeatmenu", "Form", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class defeatmenu: public Ui_defeatmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFEATMENU_H
