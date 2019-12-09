/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *p1_screen;
    QGraphicsView *p2_screen;
    QPushButton *Uboat1;
    QPushButton *Submarine1;
    QPushButton *Carrier1;
    QPushButton *Carrier2;
    QPushButton *Submarine2;
    QPushButton *Uboat2;
    QPushButton *start_game;
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *ScorePlayer1;
    QLCDNumber *ScorePlayer2;
    QLabel *score_1;
    QLabel *score_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QFrame *line;
    QPushButton *main_menu;
    QLabel *label_5;
    QLabel *torpedo_1;
    QLabel *bomb_1;
    QLabel *label_8;
    QLabel *torpedo_2;
    QLabel *bomb_2;
    QLabel *rules;
    QPushButton *Done1;
    QPushButton *Done2;
    QGraphicsView *scorebar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(901, 619);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        p1_screen = new QGraphicsView(centralwidget);
        p1_screen->setObjectName(QString::fromUtf8("p1_screen"));
        p1_screen->setGeometry(QRect(130, 70, 300, 300));
        p2_screen = new QGraphicsView(centralwidget);
        p2_screen->setObjectName(QString::fromUtf8("p2_screen"));
        p2_screen->setGeometry(QRect(460, 70, 300, 300));
        Uboat1 = new QPushButton(centralwidget);
        Uboat1->setObjectName(QString::fromUtf8("Uboat1"));
        Uboat1->setGeometry(QRect(40, 110, 81, 31));
        Submarine1 = new QPushButton(centralwidget);
        Submarine1->setObjectName(QString::fromUtf8("Submarine1"));
        Submarine1->setGeometry(QRect(40, 160, 91, 31));
        Carrier1 = new QPushButton(centralwidget);
        Carrier1->setObjectName(QString::fromUtf8("Carrier1"));
        Carrier1->setGeometry(QRect(40, 210, 81, 31));
        Carrier2 = new QPushButton(centralwidget);
        Carrier2->setObjectName(QString::fromUtf8("Carrier2"));
        Carrier2->setGeometry(QRect(780, 210, 81, 31));
        Submarine2 = new QPushButton(centralwidget);
        Submarine2->setObjectName(QString::fromUtf8("Submarine2"));
        Submarine2->setGeometry(QRect(780, 160, 91, 31));
        Uboat2 = new QPushButton(centralwidget);
        Uboat2->setObjectName(QString::fromUtf8("Uboat2"));
        Uboat2->setGeometry(QRect(780, 110, 81, 31));
        start_game = new QPushButton(centralwidget);
        start_game->setObjectName(QString::fromUtf8("start_game"));
        start_game->setGeometry(QRect(330, 460, 113, 32));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 40, 59, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(460, 40, 59, 16));
        ScorePlayer1 = new QLCDNumber(centralwidget);
        ScorePlayer1->setObjectName(QString::fromUtf8("ScorePlayer1"));
        ScorePlayer1->setGeometry(QRect(690, 40, 64, 23));
        ScorePlayer2 = new QLCDNumber(centralwidget);
        ScorePlayer2->setObjectName(QString::fromUtf8("ScorePlayer2"));
        ScorePlayer2->setGeometry(QRect(360, 40, 64, 23));
        score_1 = new QLabel(centralwidget);
        score_1->setObjectName(QString::fromUtf8("score_1"));
        score_1->setGeometry(QRect(310, 40, 59, 16));
        score_2 = new QLabel(centralwidget);
        score_2->setObjectName(QString::fromUtf8("score_2"));
        score_2->setGeometry(QRect(640, 40, 59, 16));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(120, 380, 81, 32));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(250, 380, 81, 32));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(360, 380, 81, 32));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(700, 380, 81, 32));
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(460, 380, 81, 32));
        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(590, 380, 81, 32));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(430, 0, 41, 421));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        main_menu = new QPushButton(centralwidget);
        main_menu->setObjectName(QString::fromUtf8("main_menu"));
        main_menu->setGeometry(QRect(460, 460, 113, 32));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 420, 59, 16));
        torpedo_1 = new QLabel(centralwidget);
        torpedo_1->setObjectName(QString::fromUtf8("torpedo_1"));
        torpedo_1->setGeometry(QRect(260, 420, 59, 16));
        bomb_1 = new QLabel(centralwidget);
        bomb_1->setObjectName(QString::fromUtf8("bomb_1"));
        bomb_1->setGeometry(QRect(370, 420, 59, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(470, 420, 59, 16));
        torpedo_2 = new QLabel(centralwidget);
        torpedo_2->setObjectName(QString::fromUtf8("torpedo_2"));
        torpedo_2->setGeometry(QRect(600, 420, 59, 16));
        bomb_2 = new QLabel(centralwidget);
        bomb_2->setObjectName(QString::fromUtf8("bomb_2"));
        bomb_2->setGeometry(QRect(710, 420, 59, 16));
        rules = new QLabel(centralwidget);
        rules->setObjectName(QString::fromUtf8("rules"));
        rules->setGeometry(QRect(20, 420, 341, 161));
        Done1 = new QPushButton(centralwidget);
        Done1->setObjectName(QString::fromUtf8("Done1"));
        Done1->setGeometry(QRect(50, 260, 71, 32));
        Done2 = new QPushButton(centralwidget);
        Done2->setObjectName(QString::fromUtf8("Done2"));
        Done2->setGeometry(QRect(790, 260, 71, 32));
        scorebar = new QGraphicsView(centralwidget);
        scorebar->setObjectName(QString::fromUtf8("scorebar"));
        scorebar->setEnabled(true);
        scorebar->setGeometry(QRect(650, 440, 231, 121));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 901, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Uboat1->setText(QApplication::translate("MainWindow", "U-Boat", nullptr));
        Submarine1->setText(QApplication::translate("MainWindow", "Submarine", nullptr));
        Carrier1->setText(QApplication::translate("MainWindow", "Carrier", nullptr));
        Carrier2->setText(QApplication::translate("MainWindow", "Carrier", nullptr));
        Submarine2->setText(QApplication::translate("MainWindow", "Submarine", nullptr));
        Uboat2->setText(QApplication::translate("MainWindow", "U-Boat", nullptr));
        start_game->setText(QApplication::translate("MainWindow", "Start Game", nullptr));
        label->setText(QApplication::translate("MainWindow", "Player 1", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Player 2", nullptr));
        score_1->setText(QApplication::translate("MainWindow", "Score:", nullptr));
        score_2->setText(QApplication::translate("MainWindow", "Score:", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "Bullet", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "Torpedo", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "Bomb", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "Bomb", nullptr));
        pushButton_12->setText(QApplication::translate("MainWindow", "Bullet", nullptr));
        pushButton_13->setText(QApplication::translate("MainWindow", "Torpedo", nullptr));
        main_menu->setText(QApplication::translate("MainWindow", "Main Menu", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "infinity", nullptr));
        torpedo_1->setText(QApplication::translate("MainWindow", "0", nullptr));
        bomb_1->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "infinity", nullptr));
        torpedo_2->setText(QApplication::translate("MainWindow", "0", nullptr));
        bomb_2->setText(QApplication::translate("MainWindow", "0", nullptr));
        rules->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">U - Boat = Click 2 squares</span></p><p><span style=\" font-weight:600;\">Submarine = Cick 3 squares</span></p><p><span style=\" font-weight:600;\">Carrier = Click 5 squares</span></p><p><span style=\" font-weight:600;\">(You can only add square vertically or horizontally &amp; </span></p><p><span style=\" font-weight:600;\">click done after you've chosen your boats)</span></p></body></html>", nullptr));
        Done1->setText(QApplication::translate("MainWindow", "Done", nullptr));
        Done2->setText(QApplication::translate("MainWindow", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
