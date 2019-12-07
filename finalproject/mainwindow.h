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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Cell * cells[10][10];
    QGraphicsScene *BuildGrid_;
    QGraphicsScene *BuildGrid_2;
    int cell_height_;
    int cell_width_;
    int turn_ = 0;



};
#endif // MAINWINDOW_H
