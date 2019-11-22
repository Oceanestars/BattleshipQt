#include "ruleswindow.h"
#include "ui_ruleswindow.h"

RulesWindow::RulesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RulesWindow)
{
    ui->setupUi(this);
}

RulesWindow::~RulesWindow()
{
    delete ui;
}

void RulesWindow::on_two_player_clicked()
{

    this->hide();
    emit StartGame();


}
