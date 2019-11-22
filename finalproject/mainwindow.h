#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ruleswindow.h"
#include <QMainWindow>
#include "cell.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void OpenGame();
private:
    Ui::MainWindow *ui;
    RulesWindow *menu_;
    Cell * cells[10][20];
    QGraphicsScene *BuildGrid_;
    int cell_height_;
    int cell_width_;
    int turn_ = 0;
    double speed_ = 1.0;
    QTimer *timer;

};
#endif // MAINWINDOW_H
