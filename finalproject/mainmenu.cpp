#include "ui_mainmenu.h"
#include "mainmenu.h"


Mainmenu::Mainmenu(QWidget *parent)
    :QMainWindow(parent),
    ui(new Ui::Mainmenu)
{
    ui->setupUi(this);

}

Mainmenu::~Mainmenu()
{
    delete ui;
}




