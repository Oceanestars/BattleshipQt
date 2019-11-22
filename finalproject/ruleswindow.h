#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class RulesWindow;
}
QT_END_NAMESPACE

class RulesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RulesWindow(QWidget *parent = nullptr);
    ~RulesWindow();

private slots:
    void on_two_player_clicked();

private:
    Ui::RulesWindow *ui;
    //MainWindow *game_;
signals:
    void StartGame();

};

#endif // RULESWINDOW_H
