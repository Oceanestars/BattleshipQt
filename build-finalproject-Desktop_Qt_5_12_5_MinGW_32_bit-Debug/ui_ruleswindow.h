/********************************************************************************
** Form generated from reading UI file 'ruleswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULESWINDOW_H
#define UI_RULESWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RulesWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *rules;
    QPushButton *one_player;
    QPushButton *two_player;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RulesWindow)
    {
        if (RulesWindow->objectName().isEmpty())
            RulesWindow->setObjectName(QString::fromUtf8("RulesWindow"));
        RulesWindow->resize(800, 600);
        centralwidget = new QWidget(RulesWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 40, 201, 41));
        QFont font;
        font.setPointSize(35);
        label->setFont(font);
        rules = new QLabel(centralwidget);
        rules->setObjectName(QString::fromUtf8("rules"));
        rules->setGeometry(QRect(40, 110, 391, 341));
        one_player = new QPushButton(centralwidget);
        one_player->setObjectName(QString::fromUtf8("one_player"));
        one_player->setGeometry(QRect(510, 270, 241, 141));
        two_player = new QPushButton(centralwidget);
        two_player->setObjectName(QString::fromUtf8("two_player"));
        two_player->setGeometry(QRect(510, 120, 241, 141));
        RulesWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RulesWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        RulesWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RulesWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RulesWindow->setStatusBar(statusbar);

        retranslateUi(RulesWindow);

        QMetaObject::connectSlotsByName(RulesWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RulesWindow)
    {
        RulesWindow->setWindowTitle(QApplication::translate("RulesWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("RulesWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Battleship</span></p></body></html>", nullptr));
        rules->setText(QApplication::translate("RulesWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600; text-decoration: underline;\">RULES</span></p><p><span style=\" font-size:12pt; color:#333333;\">- You can either play this game with two player or one player and the computer </span></p><p><span style=\" font-size:12pt; color:#333333;\">- Before you start the game the players need to set up their boats. </span></p><p><span style=\" font-size:12pt; color:#333333;\">(Click on the square, they will turn grey) </span></p><p><span style=\" font-size:12pt; color:#333333;\">-Players can pick the type of boat they have by clicking on the </span></p><p><span style=\" font-size:12pt; color:#333333;\">buttons and then can touch the grid to decide its location </span></p><p><span style=\" font-size:12pt; color:#333333;\">-Limited to creating 3 boats</span></p><p><span style=\" font-size:12pt; color:#333333;\">- Bullet will create normal damage, Torpedo wil target the square you target and the one above, </span></p><p><span style=\" fon"
                        "t-size:12pt; color:#333333;\">Bomb will target the square you target and the 8 square around it.</span></p><p><span style=\" font-size:12pt; color:#333333;\">-Blue square = water </span></p><p><span style=\" font-size:12pt; color:#333333;\">-Red square = you're boat has been hit </span></p></body></html>", nullptr));
        one_player->setText(QApplication::translate("RulesWindow", "1 Player", nullptr));
        two_player->setText(QApplication::translate("RulesWindow", "2 Player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RulesWindow: public Ui_RulesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULESWINDOW_H
