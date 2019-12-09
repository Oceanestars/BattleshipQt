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
            Cell * item = new Cell(j, i, cell_width_/10, cell_height_/10,1);
            cells[i][j] = item;
            BuildGrid_->addItem(item);
            connect(item, &Cell::scorechanger, this, &MainWindow::ChangeScore);
            connect(item, &Cell::bom, this, &MainWindow::Bomb);
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
            connect(item, &Cell::bom, this, &MainWindow::Bomb);
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

void MainWindow::Bomb(Cell *c){
    int x = c->get_x();
    int y = c->get_y();
    int width = c->get_width();
    int height = c->get_height();
    x = x/width;
    y = y/height;
    Cell * temp = new Cell(1,1,1,1,1);
    if(x<9 && x>0 && y<9 && y>0){
        if(c->grid == 1){
            if(!c->is_boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));
            }
            temp = cells[x-1][y];
            if(!temp->is_boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
            }
            temp = cells[x][y-1];
            if(!temp->is_boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
            }
            temp = cells[x+1][y];
            if(!temp->is_boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
            }
            temp = cells[x][y+1];
            if(!temp->is_boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
            }
            update();
        }
        else{
            if(!c->is_boat){
                c->set_color(QColor(0,25,0));
            }
            else{
               c->set_color(QColor(255,0,0));
            }
            temp = cells2[x-1][y];
            if(!temp->is_boat){
                temp->set_color(QColor(255,0,0));
            }
            else{
               temp->set_color(QColor(255,0,0));
            }
            temp = cells2[x-2][y+1];
            if(!temp->is_boat){
                temp->set_color(QColor(255,0,0));
            }
            else{
               temp->set_color(QColor(255,0,0));
            }
            temp = cells2[x-1][y+2];
            if(!temp->is_boat){
                temp->set_color(QColor(255,0,0));
            }
            else{
               temp->set_color(QColor(255,0,0));
            }
            temp = cells2[x][y+1];
            if(!temp->is_boat){
                temp->set_color(QColor(255,0,0));
            }
            else{
               temp->set_color(QColor(255,0,0));
            }
            update();
        }
    }
}

void MainWindow::Torpedo(Cell *c){

}
