/**
Abby Nay & Oceane Andreis
Homework 5
Date: November 20 2019

This is our mainwindow.h.
We are including QGraphicsScene, QTimer, QGraphicsItem, QGraphicsView, QtWidget,and QDebug so we can
access elements of its library.

*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "cell.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtWidgets>

//Pop up messsage
//QMessageBox::information(
//        this,
//        tr("Congratulation"),
//        tr("The winner is "+ playername) );

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_Uboat1_clicked();

    void on_Submarine1_clicked();

    void on_Carrier1_clicked();

    void on_Done1_clicked();

    void on_Uboat2_clicked();

    void on_Submarine2_clicked();

    void on_Carrier2_clicked();

    void on_Done2_clicked();

    void ChangeScore();

    void on_restart_game_clicked();

private:
    Ui::MainWindow *ui;
    Cell * cells[10][10];
    Cell * cells2[10][10];
    QGraphicsScene *BuildGrid_;
    QGraphicsScene *BuildGrid_2;
    QGraphicsScene *BuildGraph_;
    int cell_height_;
    int cell_width_;
    int turn_ = 0;
    void HideCell();
    void HideCell2();
    void WinnerBar();
    bool ishidden1=false;
    bool ishidden2=false;
    bool torp1 = false;
    bool bomb1 = false;
    bool torp2 = false;
    bool bomb2 = false;
    bool p1_t = false;
    bool p1_b = false;
    bool p2_t = false;
    bool p2_b = false;
    std::vector <Bar*> bars_;
    int y_bar;
    double h_bar;
    int bar_height_;
    int bar_width_;
    int Gamescore1 =0;
    int Gamescore2 =0;


};
#endif // MAINWINDOW_H
