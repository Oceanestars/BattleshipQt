#ifndef BAR_H
#define BAR_H

#include <QColor>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtWidgets>
#include <QObject>



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



#endif // BAR_H
