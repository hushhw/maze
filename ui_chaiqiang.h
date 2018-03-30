/********************************************************************************
** Form generated from reading UI file 'chaiqiang.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAIQIANG_H
#define UI_CHAIQIANG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chaiqiang
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *chaiqiang)
    {
        if (chaiqiang->objectName().isEmpty())
            chaiqiang->setObjectName(QStringLiteral("chaiqiang"));
        chaiqiang->resize(535, 245);
        pushButton = new QPushButton(chaiqiang);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 541, 251));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/chuanqiang.jpg);"));

        retranslateUi(chaiqiang);

        QMetaObject::connectSlotsByName(chaiqiang);
    } // setupUi

    void retranslateUi(QWidget *chaiqiang)
    {
        chaiqiang->setWindowTitle(QApplication::translate("chaiqiang", "Form", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class chaiqiang: public Ui_chaiqiang {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAIQIANG_H
