
/**
Abby Nay & Oceane Andreis
Homework 5
Date: November 20 2019

This is our cell.h.
We are including QGraphicsScene, QMainWindow, QGraphicsItem, QGraphicsView, QColor, QtWidget,and QDebug so we can
access elements of its library.
We have our class Cell.

*/


#ifndef CELL_H
#define CELL_H

#include <QColor>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtWidgets>
#include <QObject>

enum class SquareType { Boat, Bomb, Torpedo,Water};

class Cell : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    Cell(int x, int y, int width, int height, int grid); //constructor
    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function
    int get_width() { return width_; }
    int get_current_status() { return current_status; }
    int get_next_status() { return next_turn_status; }
    int get_height() { return height_; }
    QColor get_color() { return color_; }

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    void set_current_status(bool current_status_){current_status=current_status_;}
    void set_next_status(bool next_turn_status_){next_turn_status=next_turn_status_;}
    void set_color(QColor color){
        color_=color;
        update();
    }
//    void set_is_game(bool b){is_game1=b;}

    static int clicked_button;
    static int score;
    static int score2;
    static bool is_game1;
    static bool is_game2;
    static int inv_t2;
    static int inv_t1;
    static int inv_b1;
    static int inv_b2;
    static bool torp_mode;
    static bool bomb_mode;
    bool is_hit;
    int grid;
    SquareType s;


signals:
    void increase();
    void decrease();
    void neighbors(int x,int y);
    void bom(Cell *);
    void torp(Cell *);
    void scorechanger(Cell *p);

private:
  int x_;
  int y_;
  int width_;
  int height_;
  bool current_status;
  bool next_turn_status;




  QColor color_;

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
//is hidden and is hit is boat
};



class Bar : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Bar(int x, int y, int h);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    static int get_w() { return width_; }  // inline member function
     int get_x() { return x_; }  // inline member function

    void set_x(int offset) { x_ = x_ + offset; } //inline setter
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

private:
    int x_;
    int y_;

    QColor color_;

    static const int width_ = 30; //600/20
    int height_;

};



#endif // CELL_H
