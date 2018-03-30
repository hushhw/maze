/********************************************************************************
** Form generated from reading UI file 'victory.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VICTORY_H
#define UI_VICTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_victory
{
public:
    QPushButton *return_2;

    void setupUi(QWidget *victory)
    {
        if (victory->objectName().isEmpty())
            victory->setObjectName(QStringLiteral("victory"));
        victory->resize(506, 217);
        victory->setStyleSheet(QStringLiteral(""));
        return_2 = new QPushButton(victory);
        return_2->setObjectName(QStringLiteral("return_2"));
        return_2->setGeometry(QRect(0, 0, 511, 221));
        return_2->setStyleSheet(QStringLiteral("border-image: url(:/meze/img/victory.jpg);"));

        retranslateUi(victory);

        QMetaObject::connectSlotsByName(victory);
    } // setupUi

    void retranslateUi(QWidget *victory)
    {
        victory->setWindowTitle(QApplication::translate("victory", "Form", 0));
        return_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class victory: public Ui_victory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VICTORY_H
