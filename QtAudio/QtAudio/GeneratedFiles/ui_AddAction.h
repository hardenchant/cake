/********************************************************************************
** Form generated from reading UI file 'AddAction.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDACTION_H
#define UI_ADDACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAction
{
public:
    QPushButton *button_add;
    QLineEdit *lineEdit_command;
    QLabel *label;
    QLineEdit *lineEdit_path;
    QLabel *label_2;
    QListView *listView;

    void setupUi(QWidget *AddAction)
    {
        if (AddAction->objectName().isEmpty())
            AddAction->setObjectName(QStringLiteral("AddAction"));
        AddAction->resize(405, 278);
        button_add = new QPushButton(AddAction);
        button_add->setObjectName(QStringLiteral("button_add"));
        button_add->setGeometry(QRect(290, 210, 75, 23));
        lineEdit_command = new QLineEdit(AddAction);
        lineEdit_command->setObjectName(QStringLiteral("lineEdit_command"));
        lineEdit_command->setGeometry(QRect(112, 170, 151, 20));
        label = new QLabel(AddAction);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 170, 61, 21));
        lineEdit_path = new QLineEdit(AddAction);
        lineEdit_path->setObjectName(QStringLiteral("lineEdit_path"));
        lineEdit_path->setGeometry(QRect(112, 210, 151, 20));
        label_2 = new QLabel(AddAction);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 210, 61, 21));
        listView = new QListView(AddAction);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(50, 10, 321, 151));

        retranslateUi(AddAction);

        QMetaObject::connectSlotsByName(AddAction);
    } // setupUi

    void retranslateUi(QWidget *AddAction)
    {
        AddAction->setWindowTitle(QApplication::translate("AddAction", "Add Voice Action", 0));
        button_add->setText(QApplication::translate("AddAction", "Add Action", 0));
        label->setText(QApplication::translate("AddAction", "Command:", 0));
        label_2->setText(QApplication::translate("AddAction", "Path to file:", 0));
    } // retranslateUi

};

namespace Ui {
    class AddAction: public Ui_AddAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDACTION_H
