/**
Abby Nay & Oceane Andreis
Homework 5
Date: December 10 2019

This is our ruleswindow.cpp
This will help us control the ruleswindow ui.
We set up a game based on if there are two human players or one human player and one computer player.

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
    This sets up our game for two real human players. We will start the game and show our board.
    @param nothing
    @return nothing,will hide the current ui(ruleswindow) and will emit a signal

*/
int RulesWindow::num_players = 0;
void RulesWindow::on_two_player_clicked()
{
    num_players = 2;
    this->hide();
    game.show();
   MainWindow::start_game=true;


}

/**
    Return nothing
    This sets up our game for one real human player and one computer player. We will start the game and show our board.
    This function also sets up our AI with a board full of secret boats. Thus, the AI's board is ready and hidden before the
    other player even sees the game board.
    @param nothing
    @return nothing,will hide the current ui(ruleswindow) and will emit a signal

*/
void RulesWindow::on_one_player_clicked()
{
    num_players = 1;
    this->hide();
    game.show();
    MainWindow::start_game=true;
    game.AI_Boats();

}
