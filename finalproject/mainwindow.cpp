/**
Abby Nay & Oceane Andreis
Homework 5
Date: November 20 2019

This is our mainwindow.cpp
We are including QGraphicsScene, QGraphicsItem, QGraphicsView, QtWidget,and QDebug so we can
access elements of its library.


*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ruleswindow.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtWidgets>


/**
    Return nothing(constructor)

    @param QWidget
    @return nothing, Sets up the grid, shows the menu,

*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//    Grid
    BuildGrid_ = new QGraphicsScene;
    QGraphicsView * grid_view = ui->p1_screen;
    grid_view->setScene(BuildGrid_);
    grid_view->setSceneRect(0,0,grid_view->frameSize().width(),grid_view->frameSize().height());

    cell_height_ = grid_view->frameSize().height();
    cell_width_ = grid_view->frameSize().width();

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            int percent = rand() % 100 + 1;
            if(percent <= 5){
                Cell * item = new Bomb(j, i, cell_width_/10, cell_height_/10,1);
                is_bomb = true;
            }
            else if(percent <= 15){
                is_torpedo = true;
            }
            Cell * item = new Cell(j, i, cell_width_/10, cell_height_/10,1);
            cells[i][j] = item;
            BuildGrid_->addItem(item);
            connect(item, &Cell::scorechanger, this, &MainWindow::ChangeScore);
        }
    }

    //second player grid
    BuildGrid_2 = new QGraphicsScene;
    QGraphicsView * grid_view2 = ui->p2_screen;
    grid_view2->setScene(BuildGrid_2);
    grid_view2->setSceneRect(0,0,grid_view2->frameSize().width(),grid_view2->frameSize().height());

    cell_height_ = grid_view2->frameSize().height();
    cell_width_ = grid_view2->frameSize().width();

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            Cell * item = new Cell(j, i, cell_width_/10, cell_height_/10,2);
            cells2[i][j] = item;
            BuildGrid_2->addItem(item);
            connect(item, &Cell::scorechanger, this, &MainWindow::ChangeScore);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Uboat1_clicked()
{
    Cell::clicked_button=2;
    ui->Uboat1->setEnabled(false);

}

void MainWindow::on_Submarine1_clicked()
{
    Cell::clicked_button=3;
    ui->Submarine1->setEnabled(false);
}

void MainWindow::on_Carrier1_clicked()
{
    Cell::clicked_button=5;
    ui->Carrier1->setEnabled(false);
}

void MainWindow::HideCell(){

    QColor color(255, 0, 0);
    color.setRgb(0, 0, 200);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {

            cells[i][j]->set_color(color);
            qDebug()<<"Hello";
        }
    }
    Cell::is_game1=true;
    update();

}

void MainWindow::on_Done1_clicked()
{
    ishidden1=true;
    HideCell();
}

// Second Player
void MainWindow::HideCell2(){

    QColor color(255, 0, 0);
    color.setRgb(0, 0, 200);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cells2[i][j]->set_color(color);

        }
    }
    Cell::is_game2=true;
    update();

}

void MainWindow::on_Uboat2_clicked()
{
    Cell::clicked_button=2;
    ui->Uboat2->setEnabled(false);
}


void MainWindow::on_Submarine2_clicked()
{
    Cell::clicked_button=3;
    ui->Submarine2->setEnabled(false);
}

void MainWindow::on_Carrier2_clicked()
{
    Cell::clicked_button=5;
    ui->Carrier2->setEnabled(false);
}

void MainWindow::on_Done2_clicked()
{
    ishidden2=true;
    HideCell2();

}

void MainWindow::ChangeScore(){

    ui->ScorePlayer1->display(Cell::score);
    ui->ScorePlayer2->display(Cell::score2);
    ui->torpedo_2->setText(QString::number(Cell::inv_t2));
    ui->torpedo_1->setText(QString::number(Cell::inv_t1));
    ui->bomb_2->setText(QString::number(Cell::inv_b2));
    ui->bomb_1->setText(QString::number(Cell::inv_b1));
        qDebug()<<"ScoreFinal:"<<Cell::score;
        qDebug()<<"ScoreFinal2:"<<Cell::score2;
//        while(Cell::is_game1==true && Cell::is_game2==true){
//        WinnerBar();
//    }
}

void MainWindow::WinnerBar(){
    if(Cell::score==10){
        QMessageBox::information(
                this,
                tr("Congratulation"),
                tr("The winner is Player 1") );

    }
    else if(Cell::score2==10){
        QMessageBox::information(
                this,
                tr("Congratulation"),
                tr("The winner is Player 2") );
    }

}
