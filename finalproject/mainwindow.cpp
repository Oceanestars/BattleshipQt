#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(menu_,&QAbstractButton::clicked,this,slot);
    menu_= new RulesWindow();
    menu_->show();
    this->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}




