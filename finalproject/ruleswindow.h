/**
Abby Nay & Oceane Andreis
Homework 5
Date: December 10 2019

This is our ruleswindow.h.
We have a slot for our button

*/
#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class RulesWindow;
}
QT_END_NAMESPACE

class RulesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RulesWindow(QWidget *parent = nullptr);
    ~RulesWindow();
    static int num_players;

private slots:
    void on_two_player_clicked();
    void on_one_player_clicked();

private:
    Ui::RulesWindow *ui;
    MainWindow game;

};

#endif // RULESWINDOW_H
