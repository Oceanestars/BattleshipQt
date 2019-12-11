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
    srand(time(NULL));
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
            connect(item, &Cell::yes_clicked, this, &MainWindow::click);
            connect(item, &Cell::check_score, this, &MainWindow::score_check);
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
            connect(item, &Cell::yes_clicked, this, &MainWindow::click);
            connect(item, &Cell::check_score, this, &MainWindow::score_check);
        }
    }

    //bar

    BuildGraph_ = new QGraphicsScene;
    QGraphicsView * graph_view = ui->scorebar;
    graph_view->setScene(BuildGraph_);
    graph_view->setSceneRect(0,0,graph_view->frameSize().width(),graph_view->frameSize().height());

    y_bar=graph_view->frameSize().height()-2;
    h_bar = graph_view->frameSize().height() ;

    //players

    qDebug()<<"Rulewindow:"<<RulesWindow::num_players;
//    if(RulesWindow::num_players == 1){
//        qDebug()<<"IS AI being called?";
//        this->AI_Boats();
//    }

}
bool MainWindow::start_game=false;
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
//            qDebug()<<"Hello";
        }
    }
    Cell::is_game1=true;
    update();

}

void MainWindow::on_Done1_clicked()
{
    HideCell();
    ishidden1=true;
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
    int t3 = 0;
    if (MainWindow::start_game){
        qDebug()<<"Try start game";
        if(RulesWindow::num_players == 2)
        {
        p1_= new Player();
        p2_= new Player();
        }
        else if (RulesWindow::num_players == 1)
        {
            p3_=new AI();
            p2_= new Player();
        }
        MainWindow::start_game=false;
    }
    int t=0;
    if(RulesWindow::num_players == 2){
        p1_->Player::set_turn(1);
        t =  p1_->get_turns();
    }
    else{
        p2_->Player::set_turn(1);
        p3_->AI::set_turn(0);
        t = p2_->get_turns();
        t3 = p3_->get_turns();
    }
    ui->turn_2->setText("Turns: "+QString::number(t));
    ui->turn_1->setText("Turns: "+QString::number(t3));
    this->update();
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
//        qDebug()<<"ScoreFinal:"<<Cell::score;
//        qDebug()<<"ScoreFinal2:"<<Cell::score2;

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
    if(RulesWindow::num_players==2){
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

    ui->turn_1->setText("Turns: "+QString::number(0));
    ui->turn_2->setText("Turns: "+QString::number(0));
    p1_->Player::set_turn(-1);

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            Cell * item = new Cell(j, i, cell_width_/10, cell_height_/10,1);
            cells[i][j] = item;
            BuildGrid_->addItem(item);
            connect(item, &Cell::scorechanger, this, &MainWindow::ChangeScore);
            connect(item, &Cell::bom, this, &MainWindow::Bomb);
            connect(item, &Cell::torp, this, &MainWindow::Torpedo);
            connect(item, &Cell::yes_clicked, this, &MainWindow::click);
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
            connect(item, &Cell::yes_clicked, this, &MainWindow::click);
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
    else{
        //BuildGrid_->clear();
        BuildGrid_2->clear();

        AI_Boats();
        Cell::score=0;
        Cell::score2=0;
        Cell::inv_t2=0;
        Cell::inv_t1=0;
        Cell::inv_b1=0;
        Cell::inv_b2=0;
        Cell::is_game1=false;
        Cell::is_game2=false;

        ui->turn_1->setText("Turns: "+QString::number(0));
        ui->turn_2->setText("Turns: "+QString::number(0));

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                Cell * item = new Cell(j, i, cell_width_/10, cell_height_/10,2);
                cells2[i][j] = item;
                BuildGrid_2->addItem(item);
                connect(item, &Cell::scorechanger, this, &MainWindow::ChangeScore);
                connect(item, &Cell::bom, this, &MainWindow::Bomb);
                connect(item, &Cell::torp, this, &MainWindow::Torpedo);
                connect(item, &Cell::yes_clicked, this, &MainWindow::click);
            }
        }
        ui->Uboat2->setEnabled(true);
        ui->Submarine2->setEnabled(true);
        ui->Carrier2->setEnabled(true);
        ui->Done2->setEnabled(true);
   }

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
               Cell::score++;

            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));
               Cell::score++;
               }
            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));
               Cell::score++;
               }
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
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
               Cell::score2++;

            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
               }
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
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
               Cell::score++;
            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));
               Cell::score2++;

            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
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
               Cell::score++;


            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
                if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));
               Cell::score2++;

            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
                if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
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
               Cell::score++;

            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));
               Cell::score2++;

            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
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
               Cell::score++;

            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));
               Cell::score2++;

            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
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
               Cell::score++;

            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
        }
        else{
            if(temp->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));
               Cell::score2++;

            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
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
               Cell::score++;

            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
                if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));
               Cell::score2++;

            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
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
               Cell::score++;

            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));
               Cell::score2++;

            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y][x+1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
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
               Cell::score++;

            }
            temp = cells[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));
               Cell::score++;
               }
            }
            temp = cells[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
               c->set_color(QColor(255,0,0));
               Cell::score2++;

            }
            temp = cells2[y][x-1];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
            temp = cells2[y+1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
               }
            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));
               Cell::score2++;
               }
            }
        }
    }
    this->ChangeScore();
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
        if(c->grid == 1){
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
                c->set_color(QColor(255,0,0));
                Cell::score++;
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
                c->set_color(QColor(255,0,0));
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
                Cell::score++;

            }
            temp = cells[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
               if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score++;
               }
            }
        }
        else{
            if(c->s != SquareType::Boat){
                c->set_color(QColor(255,255,255));
            }
            else{
                c->set_color(QColor(255,0,0));
                Cell::score2++;

            }
            temp = cells2[y-1][x];
            if(temp->s != SquareType::Boat){
                temp->set_color(QColor(255,255,255));
            }
            else{
                if(temp->get_color()!= QColor(255, 0, 0)){
               temp->set_color(QColor(255,0,0));

               Cell::score2++;
               }
            }
        }
    }
    this->ChangeScore();
}

void MainWindow::click()
{

    int t=0;
    int t2=0;

//qDebug()<<"p1 debug:"<<p1_->get_turns();
//qDebug()<<"p2 debug:"<<p2_->get_turns();

    if(RulesWindow::num_players == 2){

        if(p1_->get_turns() > 0){ //player's 1 turn

            p1_->Player::set_turn(-1);  // go from 1 to
            t = p1_->get_turns();
            if(t == 0){
                qDebug()<<"The value of t";
                p2_->Player::set_turn(1);
                qDebug()<<"second";
                t2 = p2_->get_turns();
                qDebug()<<"third";
                ui->turn_2->setText("Turns: "+QString::number(t2));
                qDebug()<<t;
            }
            ui->turn_1->setText("Turns: "+QString::number(t));
        }
        else if(p2_->get_turns() > 0){ //player's 2 turn
            p2_->Player::set_turn(-1);
            t = p2_->get_turns();
            if(p2_->get_turns() == 0){
                p1_->Player::set_turn(1);
                t2 = p1_->get_turns();
                ui->turn_1->setText("Turns: "+QString::number(t2));
            }
            ui->turn_2->setText("Turns: "+QString::number(t));
        }
    }
    else{ //AI Mode
        if(p3_->get_turns() > 0){
            qDebug()<<"do we get here?";
            this->AI_Turn();
            p3_->AI::set_turn(-1);
            t = p3_->get_turns();
            p2_->Player::set_turn(1);
            t2 = p2_->get_turns();
            ui->turn_2->setText("Turns: "+QString::number(t2));
            ui->turn_1->setText("Turns: "+QString::number(t));
        }
        else if(p2_->get_turns() > 0){
            p2_->Player::set_turn(-1);
            t = p2_->get_turns();
            if(p2_->get_turns() == 0){
                p3_->Player::set_turn(1);
                t2 = p3_->get_turns();
                ui->turn_1->setText("Turns: "+QString::number(t2));
            }
            ui->turn_2->setText("Turns: "+QString::number(t));
            this->update();
            this->AI_Turn();
            //this->click();
        }
    }
    this->update();

}

void MainWindow::score_check(){
    int t;
    if(Cell::score2 < 5 && Cell::score < 5){
        return;
    }
    if(Cell::score2 > Cell::score && !Player::extra_turns && RulesWindow::num_players == 2){
        p2_->set_turn(2);
        t = p2_->get_turns();
        ui->turn_2->setText("Turns: "+QString::number(t));
        Player::extra_turns = true;
    }
    else if(Cell::score > Cell::score2 && !Player::extra_turns && RulesWindow::num_players == 2){
        p1_->set_turn(2);
        t = p1_->get_turns();
        ui->turn_1->setText("Turns: "+QString::number(t));
        Player::extra_turns = true;
    }
    else if(Cell::score2 > Cell::score && !Player::extra_turns && RulesWindow::num_players == 1){
        p2_->set_turn(2);
        t = p2_->get_turns();
        ui->turn_2->setText("Turns: "+QString::number(t));
        Player::extra_turns = true;
    }
    this->update();
}

void MainWindow::AI_Boats(){


    ui->label->setText("AI");
    int x = rand() % 10;
    int y = rand() % 10;

    cells[y][x]->s = SquareType::Boat;
     qDebug()<<"Original y:"<<y<<"x:"<<x;
    //Carrier - vertical 5 squares
    if(y>=4)
    {
       cells[y-1][x]->s = SquareType::Boat;
       cells[y-2][x]->s = SquareType::Boat;
       cells[y-3][x]->s = SquareType::Boat;
       cells[y-4][x]->s = SquareType::Boat;
       qDebug()<<"y:"<<y-1<<"x:"<<x;
       qDebug()<<"y:"<<y-2<<"x:"<<x;
       qDebug()<<"y:"<<y-3<<"x:"<<x;
       qDebug()<<"y:"<<y-4<<"x:"<<x;
    }
    else
    {
        cells[y+1][x]->s=SquareType::Boat;
        cells[y+2][x]->s=SquareType::Boat;
        cells[y+3][x]->s=SquareType::Boat;
        cells[y+4][x]->s=SquareType::Boat;
        qDebug()<<"y:"<<y+1<<"x:"<<x;
        qDebug()<<"y:"<<y+2<<"x:"<<x;
        qDebug()<<"y:"<<y+3<<"x:"<<x;
        qDebug()<<"y:"<<y+4<<"x:"<<x;
    }

    //Submarine - horizontal 3 squares
    int x2 = rand() % 10 ;
    int y2 = rand() % 10 ;
    while(cells[y2][x2]->s == SquareType::Boat)
    {
         x2 = rand() % 10 ;
         y2 = rand() % 10 ;

    }
    cells[y2][x2]->s = SquareType::Boat;
    qDebug()<<"Original y2:"<<y2<<"x2:"<<x2;
    if(x<=2) // left most columns
    {
  //if statement if there is already a boat to the right
       if(cells[y2][x2+1]->s != SquareType::Boat && cells[y2][x2+2]->s != SquareType::Boat){
           cells[y2][x2+1]->s = SquareType::Boat;
           cells[y2][x2+2]->s = SquareType::Boat;
           qDebug()<<"are we in here?";
           qDebug()<<"y22:"<<y2<<"x22:"<<x2;
       }
       else if(y2<=7){
           cells[y2+1][x2]->s = SquareType::Boat;
           cells[y2+2][x2]->s = SquareType::Boat;
           qDebug()<<"are we in here?22";
       }
       else{
           cells[y2-1][x2]->s = SquareType::Boat;
           cells[y2-2][x2]->s = SquareType::Boat;
           qDebug()<<"are we in here?3333";
       }
    }
    else {
        //if statement if there is already a boat to the left
        if(cells[y2][x2-1]->s != SquareType::Boat && cells[y2][x2-2]->s != SquareType::Boat){
            cells[y2][x2-1]->s = SquareType::Boat;
            cells[y2][x2-2]->s = SquareType::Boat;
            qDebug()<<"are we in here?444";
            qDebug()<<"y24:"<<y2<<"x24:"<<x2-1;
            qDebug()<<"y24:"<<y2<<"x24:"<<x2-2;
        }
        else if(y<=7){
            cells[y2+1][x2]->s = SquareType::Boat;
            cells[y2+2][x2]->s = SquareType::Boat;
            qDebug()<<"are we in here?5555";
            qDebug()<<"y25:"<<y2+1<<"x25:"<<x2;
            qDebug()<<"y25:"<<y2+2<<"x25:"<<x2;
        }
        else{
            cells[y2-1][x2]->s = SquareType::Boat;
            cells[y2-2][x2]->s = SquareType::Boat;
            qDebug()<<"are we in here?6666";
        }
    }
    //Uboat - horizontal or vertical 2 squares
    int x3 = rand() % 10 ;
    int y3 = rand() % 10 ;
    while(cells[x3][y3]->s == SquareType::Boat)
    {
         x3 = rand() % 10 ;
         y3 = rand() % 10 ;

    }
    cells[y3][x3]->s = SquareType::Boat;
    qDebug()<<"UBOAT OG y:"<<y3<<"x:"<<x3;

    //check the cell above first
    if(y>0){
        //cell above first
        if(cells[y3-1][x3]->s != SquareType::Boat){
            cells[y3-1][x3]->s = SquareType::Boat;
            qDebug()<<"y:"<<y3-1<<"x:"<<x3;
        }
        else if(y!=9){
            //cell below
            if(cells[y3+1][x3]->s != SquareType::Boat){
                cells[y3+1][x3]->s = SquareType::Boat;
                qDebug()<<" y:"<<y3+1<<"x:"<<x3;

            }
        }
        else if(x!=9){
            //cell right
            if(cells[y3][x3+1]->s != SquareType::Boat){
                cells[y3][x3+1]->s = SquareType::Boat;
                qDebug()<<" y:"<<y3<<"x:"<<x3+1;
            }
        }
        else if(x!=0){
            //cell left
            if(cells[y3][x3-1]->s != SquareType::Boat){
                cells[y3][x3-1]->s = SquareType::Boat;
                qDebug()<<" y:"<<y3<<"x:"<<x3-1;
            }
        }
    }
    else if(y==0){
        //cell below
        if(cells[y3+1][x3]->s != SquareType::Boat){
            cells[y3+1][x3]->s = SquareType::Boat;
        }
        //cell right
        if(cells[y3][x3+1]->s != SquareType::Boat){
            cells[y3][x3+1]->s = SquareType::Boat;
        }
        //cell left
        if(cells[y3][x3-1]->s != SquareType::Boat){
            cells[y3][x3-1]->s = SquareType::Boat;
        }
    }
    HideCell();

    Cell::is_game1 = true;
    ishidden1=true;
    ui->Done1->setEnabled(false);
}

void MainWindow::AI_Turn(){
    qDebug()<<"do we get here? pt 2";
    int x = rand() % 10;
    int y = rand() % 10;
    while(cells2[y][x]->get_color() == QColor(255,255,255) || cells2[y][x]->get_color() == QColor(255,0,0)){
        x = rand() % 10;
        y = rand() & 10;
    }
    if(cells2[y][x]->s==SquareType::Boat){
        qDebug()<<"do we get here? pt 4";
        cells2[y][x]->set_color(QColor(255,0,0));
        cells2[y][x]->is_hit = true;
        Cell::score2++;
        this->update();
        this->ChangeScore();
    }
    if(cells2[y][x]->s==SquareType::Bomb){
        qDebug()<<"do we get here? pt 5";
        cells2[y][x]->set_color(QColor(255,255,255));
        this->Bomb(cells2[y][x]);
        this->update();
    }
    if(cells2[y][x]->s==SquareType::Torpedo){
        qDebug()<<"do we get here? pt 6";
        cells2[y][x]->set_color(QColor(255,255,255));
        this->Torpedo(cells2[y][x]);
        this->update();
    }
    else if (cells2[y][x]->s==SquareType::Water){
        qDebug()<<"do we get here? pt 7";
        cells2[y][x]->set_color(QColor(255,255,255));
        this->update();
    }
    p3_->set_turn(-1);
    int t = p3_->get_turns();
    ui->turn_1->setText("Turns: "+QString::number(t));
    p2_->set_turn(1);
    int t2 = p2_->get_turns();
    ui->turn_2->setText("Turns: "+QString::number(t2));
    this->update();

}
