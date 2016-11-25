/********************************************************************************
** Form generated from reading UI file 'QtAudio.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTAUDIO_H
#define UI_QTAUDIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtAudioClass
{
public:
    QWidget *centralWidget;
    QPushButton *button_start;
    QPushButton *button_stop;
    QPushButton *button_recognize;
    QLabel *label;
    QLineEdit *textOut;
    QTextEdit *textEdit;
    QPushButton *button_go;
    QPushButton *button_clear;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *QtAudioClass)
    {
        if (QtAudioClass->objectName().isEmpty())
            QtAudioClass->setObjectName(QStringLiteral("QtAudioClass"));
        QtAudioClass->resize(224, 442);
        centralWidget = new QWidget(QtAudioClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        button_start = new QPushButton(centralWidget);
        button_start->setObjectName(QStringLiteral("button_start"));
        button_start->setGeometry(QRect(130, 30, 75, 23));
        button_stop = new QPushButton(centralWidget);
        button_stop->setObjectName(QStringLiteral("button_stop"));
        button_stop->setGeometry(QRect(130, 60, 75, 23));
        button_recognize = new QPushButton(centralWidget);
        button_recognize->setObjectName(QStringLiteral("button_recognize"));
        button_recognize->setGeometry(QRect(130, 90, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 47, 13));
        textOut = new QLineEdit(centralWidget);
        textOut->setObjectName(QStringLiteral("textOut"));
        textOut->setGeometry(QRect(30, 120, 171, 20));
        textOut->setReadOnly(true);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 210, 171, 171));
        textEdit->setReadOnly(true);
        button_go = new QPushButton(centralWidget);
        button_go->setObjectName(QStringLiteral("button_go"));
        button_go->setGeometry(QRect(130, 160, 75, 23));
        button_clear = new QPushButton(centralWidget);
        button_clear->setObjectName(QStringLiteral("button_clear"));
        button_clear->setGeometry(QRect(130, 390, 75, 23));
        QtAudioClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtAudioClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 224, 21));
        QtAudioClass->setMenuBar(menuBar);

        retranslateUi(QtAudioClass);
        QObject::connect(button_start, SIGNAL(clicked()), QtAudioClass, SLOT(onPushButton_startRecord()));
        QObject::connect(button_stop, SIGNAL(clicked()), QtAudioClass, SLOT(onPushButton_stopRecord()));
        QObject::connect(button_recognize, SIGNAL(clicked()), QtAudioClass, SLOT(onPushButton_recognize()));
        QObject::connect(button_go, SIGNAL(pressed()), QtAudioClass, SLOT(onPushButton_startRecord()));
        QObject::connect(button_go, SIGNAL(released()), QtAudioClass, SLOT(stopAndRecognize()));
        QObject::connect(button_clear, SIGNAL(clicked()), textEdit, SLOT(clear()));

        QMetaObject::connectSlotsByName(QtAudioClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtAudioClass)
    {
        QtAudioClass->setWindowTitle(QApplication::translate("QtAudioClass", "AudioCake", 0));
        button_start->setText(QApplication::translate("QtAudioClass", "Start", 0));
        button_stop->setText(QApplication::translate("QtAudioClass", "Stop", 0));
        button_recognize->setText(QApplication::translate("QtAudioClass", "Recognize", 0));
        label->setText(QApplication::translate("QtAudioClass", "Record:", 0));
        button_go->setText(QApplication::translate("QtAudioClass", "Go", 0));
        button_clear->setText(QApplication::translate("QtAudioClass", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class QtAudioClass: public Ui_QtAudioClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTAUDIO_H
