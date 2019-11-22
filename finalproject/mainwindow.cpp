#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menu_= new RulesWindow();
    menu_->show();
    this->hide();
    // connect(sender, sender signal, receiver, receiver slot)
    //connect(ui->two_players, &RulesWindow::StartGame, this, &MainWindow::OpenGame);
    //Grid
    BuildGrid_ = new QGraphicsScene;
    QGraphicsView * grid_view = ui->p1_screen;
    grid_view->setScene(BuildGrid_);
    grid_view->setSceneRect(0,0,grid_view->frameSize().width(),grid_view->frameSize().height());

    cell_height_ = grid_view->frameSize().height();
    cell_width_ = grid_view->frameSize().width(); //no matter the number there is still a weird edge



    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++) {
            Cell * item = new Cell(j, i, cell_width_/20, cell_height_/10);
            cells[i][j] = item;
            BuildGrid_->addItem(item);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::OpenGame(){

    this->show();
}

