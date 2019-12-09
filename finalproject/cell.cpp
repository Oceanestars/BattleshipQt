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
#include "ui_mainwindow.h"
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
    //int percent = rand() % 100 + 1;
    //if(percent <= 5){
        //is_bomb = true;
    //}
    //else if(percent <= 15){
        //is_torpedo = true;
    //}
}
int Cell::clicked_button=0;
int Cell::score=0;
int Cell::score2=0;
bool Cell::is_game1=false;
bool Cell::is_game2=false;
int Cell::inv_t2=0;
int Cell::inv_t1=0;
int Cell::inv_b1=0;
int Cell::inv_b2=0;
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

    if(event->button() == Qt::LeftButton && (is_game1==false || is_game2==false)){
        if(this->get_color() == QColor(255, 255, 255)){

            this->set_color(QColor(242,19,131));
            //Cell::clicked_button--;
            //ishidden1=true;
            this->is_boat=true;
            update();
            qDebug()<<"Score should be zero"<<score;
            //return;
        }

    }
  }
    if(event->button() == Qt::LeftButton && is_game1==true && is_game2==true){
        //qDebug()<<"Can we get to here?";
        if(this->is_boat){
            //this->set_color(QColor(255,0,0));
            //this->is_hit = true;
            //if (grid ==1)
            //{
             //score++;
             //qDebug()<<"Score:"<<score;
            //}
           //else if (grid==2){
              //qDebug()<<"Grid2";
             //score2++;
             //qDebug()<<"Score2:"<<score2;
            //}
            Destroy d = new Destroy();
            d.hit(this);

            emit scorechanger(this);

        }
        if(this->is_bomb){
            if(this->grid == 1){
                this->set_color(QColor(255,255,255));
                inv_b2++;
            }
            else{
                this->set_color(QColor(255,255,255));
                inv_b1++;
            }
        }
        if(this->is_torpedo){
            if(this->grid == 1){
                this->set_color(QColor(255,255,255));
                inv_t2++;
            }
            else{
                this->set_color(QColor(255,255,255));
                inv_t1++;
            }
        }
        else{
            //qDebug()<<"WTF";
            this->set_color(QColor(255,255,255));
        }
        emit scorechanger(this);
    }
    update();
    //qDebug()<<"Hellooooo";
    //qDebug()<<"This cells game bool is set to:";
    //qDebug()<<this->is_game;
     Cell::clicked_button--;

}

void Destroy::hit(Cell *c){
    if(c->is_boat){
        c->set_color(QColor(255,0,0));
        c->is_hit = true;
        if (c->grid ==1)
        {
         Cell::score++;
         qDebug()<<"Score:"<<Cell::score;
        }
       else if (c->grid==2){
          qDebug()<<"Grid2";
         Cell::score2++;
         qDebug()<<"Score2:"<<Cell::score2;
        }
    }
}
