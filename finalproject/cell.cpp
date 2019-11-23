/**
Abby Nay & Oceane Andreis
Homework 5
Date: November 20 2019

This is our cell.cpp.
We are including QGraphicsScene, QGraphicsItem, QGraphicsView, QtWidget,and QDebug so we can
access elements of its library.
We have implemented our class Cell to create the grid.

*/

#include "cell.h"
#include "mainwindow.h"
#include <mainwindow.cpp>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QtWidgets>


/**
Constructor
*/
Cell::Cell(int x, int y, int width, int height){
    QColor color(255, 0, 0);
    color.setRgb(255, 255, 255);
    color_ = color;
    x_ = x * width; //since we are creating squares we need x and y to be more than simply a point
    y_ = y * height;
    width_ = width;
    height_ = height;
}

/**
 * Draws the outline for the cells so that we can contain our cells within a square.
 * @param nothing
 * @return the rectangle we drew
 */
QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

/**
 * we draw the shape of the cell that we can add to the grid
 * @return the shape of the cell
 */
QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, width_);
    return path;
}

/**
 * Takes in graphics parameters to paint the cell the color we have assigned it in the constructor.
 * This also repaints our cells when they die/repopulate.
 * @param painter
 * @param option
 * @param widget
 * @return nothing
 */
void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget) //should not have a semi colon


    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));

    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}

/**

 */
void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
