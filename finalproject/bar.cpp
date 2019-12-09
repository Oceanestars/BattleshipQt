#include "bar.h"
#include "mainwindow.h"
#include <mainwindow.cpp>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets>
#include <QTimer>


Bar::Bar(const int x, const int y, int h) {

    x_ = x;
    y_ = y;
    height_ = -h; //without a negative I couldn't see the rectangle
    color_ = "white";

}

QRectF Bar::boundingRect() const
{
    return QRectF(x_, y_, width_, height_);
}

QPainterPath Bar::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, height_);
    return path;
}

//bar paint using QBrush
void Bar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    Q_UNUSED(widget);

    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

    painter->drawRect(this->x_, this->y_, this->width_, this->height_);
    painter->setBrush(b);
}
