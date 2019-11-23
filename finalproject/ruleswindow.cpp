/**
Abby Nay & Oceane Andreis
Homework 5
Date: November 20 2019

This is our ruleswindow.cpp
This will help us control the ruleswindow ui

*/

#include "ruleswindow.h"
#include "ui_ruleswindow.h"
#include "mainwindow.h"

/**
    Return nothing(constructor)

    @param QWidget
    @return Sets up the ui

*/
RulesWindow::RulesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RulesWindow)
{
    ui->setupUi(this);
}

/**
    Return nothing(Deconstructor)

    @param nothing
    @return delete the ui

*/
RulesWindow::~RulesWindow()
{
    delete ui;
}

/**
    Return nothing

    @param nothing
    @return nothing,will hide the current ui(ruleswindow) and will emit a signal

*/
void RulesWindow::on_two_player_clicked()
{

    this->hide();
    game.show();



}
