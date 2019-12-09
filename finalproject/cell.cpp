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
Cell::Cell(int x, int y, int width, int height, int g){
    QColor color(255, 0, 0);
    color.setRgb(255, 255, 255);
    color_ = color;
    x_ = x * width; //since we are creating squares we need x and y to be more than simply a point
    y_ = y * height;
    width_ = width;
    height_ = height;
    grid = g;
    int percent = rand() % 100 + 1;
    if(percent <= 5){
        is_bomb = true;
    }
    else if(percent <= 15){
        is_torpedo = true;
    }
}
int Cell::clicked_button=0;
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
    //create another slot, if statement to figure out which mode we are in, set boat or hit boat
    //shift
    //qDebug()<<clicked_button;
    if(Cell::clicked_button>0){
        qDebug()<<Cell::clicked_button;

    if(event->button() == Qt::LeftButton && !this->is_game){
        if(this->get_color() == QColor(255, 255, 255)){

            this->set_color(QColor(242,19,131));
            //Cell::clicked_button--;
            //ishidden1=true;
            this->is_boat=true;
            update();
            return;
        }

    }
    if(event->button() == Qt::LeftButton){
        qDebug()<<"Can we get to here?";
        if(this->is_boat){
            this->set_color(QColor(255,0,0));
            this->is_hit = true;
        }
        else if(this->is_bomb){
            if(this->grid == 1){
                emit p2_update(false,true);
            }
            else{
                emit p1_update(false,true);
            }
        }
        else if(this->is_torpedo){

        }
        else{
            qDebug()<<"WTF";
            this->set_color(QColor(255,255,255));
        }
    }
    update();
    qDebug()<<"Hellooooo";
    qDebug()<<"This cells game bool is set to:";
    qDebug()<<this->is_game;
     Cell::clicked_button--;
}
}


