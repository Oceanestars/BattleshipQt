
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

class Cell : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    Cell(int x, int y, int width, int height); //constructor
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

    }
    static int clicked_button;

signals:
    void increase();
    void decrease();
    void neighbors(int x,int y);

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

};


#endif // CELL_H
