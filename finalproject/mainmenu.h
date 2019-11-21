#ifndef MAINMENU_H
#define MAINMENU_H


#include <QMainWindow>
#include "mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui {class Mainmenu;}
QT_END_NAMESPACE
class Mainmenu : public QMainWindow
{
    Q_OBJECT

public:
    Mainmenu(QWidget *parent = nullptr);
    ~Mainmenu();

private slots:
    void on_playButton_clicked();

private:
    Ui::Mainmenu *ui;


};

#endif // MAINMENU_H
