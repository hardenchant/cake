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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAction
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QLabel *label_2;
    QLineEdit *lineEdit_command;
    QLabel *label;
    QLineEdit *lineEdit_path;
    QPushButton *button_add;

    void setupUi(QWidget *AddAction)
    {
        if (AddAction->objectName().isEmpty())
            AddAction->setObjectName(QStringLiteral("AddAction"));
        AddAction->resize(405, 278);
        verticalLayoutWidget = new QWidget(AddAction);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 341, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(15, 8, 15, 10);
        listView = new QListView(verticalLayoutWidget);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_command = new QLineEdit(verticalLayoutWidget);
        lineEdit_command->setObjectName(QStringLiteral("lineEdit_command"));

        verticalLayout->addWidget(lineEdit_command);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit_path = new QLineEdit(verticalLayoutWidget);
        lineEdit_path->setObjectName(QStringLiteral("lineEdit_path"));

        verticalLayout->addWidget(lineEdit_path);

        button_add = new QPushButton(verticalLayoutWidget);
        button_add->setObjectName(QStringLiteral("button_add"));

        verticalLayout->addWidget(button_add);


        retranslateUi(AddAction);

        QMetaObject::connectSlotsByName(AddAction);
    } // setupUi

    void retranslateUi(QWidget *AddAction)
    {
        AddAction->setWindowTitle(QApplication::translate("AddAction", "Add Voice Action", 0));
        label_2->setText(QApplication::translate("AddAction", "Path to file:", 0));
        label->setText(QApplication::translate("AddAction", "Command:", 0));
        button_add->setText(QApplication::translate("AddAction", "Add Action", 0));
    } // retranslateUi

};

namespace Ui {
    class AddAction: public Ui_AddAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDACTION_H
