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

//special event if person has 5 points and has more points than the other
//player (who is losing) gets two extra turn.

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
            connect(item, &Cell::torp, this, &MainWindow::Torpedo);
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
            connect(item, &Cell::torp, this, &MainWindow::Torpedo);
        }
    }

    //bar

    BuildGraph_ = new QGraphicsScene;
    QGraphicsView * graph_view = ui->scorebar;
    graph_view->setScene(BuildGraph_);
    graph_view->setSceneRect(0,0,graph_view->frameSize().width(),graph_view->frameSize().height());

    y_bar=graph_view->frameSize().height()-2;
    h_bar = graph_view->frameSize().height() ;
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
    ui->Done1->setEnabled(false);
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
    ui->Done2->setEnabled(false);

}
void MainWindow::on_Torpedo_1_clicked()
{
    Cell::torp_mode = true;
}

void MainWindow::on_Torpedo_2_clicked()
{
    Cell::torp_mode=true;
}
void MainWindow::on_Bomb_1_clicked()
{
    Cell::bomb_mode = true;
}
void MainWindow::on_Bomb_2_clicked()
{
    Cell::bomb_mode = true;
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

        WinnerBar();

}

void MainWindow::WinnerBar(){



    if(Cell::score==10){
         Gamescore1+=10;
          Bar* first_bar = new Bar(100, y_bar, Gamescore1);
        QMessageBox::information(
                this,
                tr("Congratulation"),
                tr("The winner is Player 2") );
        bars_.push_back(first_bar);
        BuildGraph_->addItem(first_bar);

    }
    else if(Cell::score2==10){
        Gamescore2+=10;
         Bar* second_bar = new Bar(50, y_bar, Gamescore2);
        QMessageBox::information(
                this,
                tr("Congratulation"),
                tr("The winner is Player 1") );
        bars_.push_back(second_bar);
        BuildGraph_->addItem(second_bar);
    }

}

void MainWindow::on_restart_game_clicked()
{
    BuildGrid_->clear();
    BuildGrid_2->clear();

    Cell::score=0;
    Cell::score2=0;
    Cell::inv_t2=0;
    Cell::inv_t1=0;
    Cell::inv_b1=0;
    Cell::inv_b2=0;
    Cell::is_game1=false;
    Cell::is_game2=false;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            Cell * item = new Cell(j, i, cell_width_/10, cell_height_/10,1);
            cells[i][j] = item;
            BuildGrid_->addItem(item);
            connect(item, &Cell::scorechanger, this, &MainWindow::ChangeScore);
            connect(item, &Cell::bom, this, &MainWindow::Bomb);
            connect(item, &Cell::torp, this, &MainWindow::Torpedo);
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            Cell * item = new Cell(j, i, cell_width_/10, cell_height_/10,2);
            cells2[i][j] = item;
            BuildGrid_2->addItem(item);
            connect(item, &Cell::scorechanger, this, &MainWindow::ChangeScore);
            connect(item, &Cell::bom, this, &MainWindow::Bomb);
            connect(item, &Cell::torp, this, &MainWindow::Torpedo);
        }
    }
    ui->Uboat1->setEnabled(true);
    ui->Submarine1->setEnabled(true);
    ui->Carrier1->setEnabled(true);
    ui->Uboat2->setEnabled(true);
    ui->Submarine2->setEnabled(true);
    ui->Carrier2->setEnabled(true);
    ui->Done1->setEnabled(true);
    ui->Done2->setEnabled(true);

}

void MainWindow::Bomb(Cell *c){
    int x = c->get_x();
    int y = c->get_y();
    int width = c->get_width();
    int height = c->get_height();
    x = x/width;
    y = y/height;
    Cell * temp = new Cell(0,0,cell_width_/10, cell_height_/10,1);
    qDebug()<<"x:"<<x;
    qDebug()<<"y:"<<y;

    if(x<9 && x>0 && y<9 && y>0){
        if(c->grid == 1){
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else if(c->s == SquareType::Boat){
               c->set_color(QColor(255,0,0));

            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            qDebug()<<"x2:"<<x;
            qDebug()<<"y2:"<<y;
            update();
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            qDebug()<<"x2:"<<x;
            qDebug()<<"y2:"<<y;

            update();
        }
    }
    else if(x==0 && y==9){
        if(c->grid == 1){
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
        }
    }
    else if(x==0 && y==0){
        if(c->grid == 1){
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));


            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
        }
    }
    else if(x==9 && y==0){
        if(c->grid == 1){
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
        }
    }
    else if(x==9 && y==9){
        if(c->grid == 1){
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
        }
    }
    else if(x==0){
        if(c->grid == 1){
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
        }
        else{
            if(temp->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
        }
    }
    else if(y==0){
        if(c->grid == 1){
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
        }
    }
    else if(y==9){
        if(c->grid == 1){
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
        }
    }
    else{
        if(c->grid == 1){
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));

            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
        }
    }
}

void MainWindow::Torpedo(Cell *c){
    int x = c->get_x();
    int y = c->get_y();
    int width = c->get_width();
    int height = c->get_height();
    x = x/width;
    y = y/height;
    Cell * temp = new Cell(0,0,cell_width_/10, cell_height_/10,1);
    qDebug()<<"x:"<<x;
    qDebug()<<"y:"<<y;
    if(y == 9){
        if(c->s != SquareType::Boat){
            c->set_color(QColor(255,255,255));
        }
        else{
            c->set_color(QColor(255,0,0));
        }
    }
    else{
        if(c->grid == 1){
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
                c->set_color(QColor(255,0,0));

            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score++;
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
                c->set_color(QColor(255,0,0));

            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
            }
        }
    }
}
