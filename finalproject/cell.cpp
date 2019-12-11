/**
Abby Nay & Oceane Andreis
Homework 5
Date: December 10 2019

This is our cell.cpp.
We are including QGraphicsScene, QGraphicsItem, QGraphicsView, QtWidget,and QDebug so we can
access elements of its library.
We have implemented our class Cell to create the grid.
We also have a class (Factory design) with players being either AI or human that are created here.
We also have a class Bar to keep track of which players win over time and can plot them on a bar graph in the right corner of our board.

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
    Return nothing(constructor)
    We create a cell that is assigned treasures such as bombs (5% probability) or torpedos (10% probability) that
    will be placed on our board.
    @param int x, int y, int width, int height, int g (which grid the cell belongs to (1 or 2)
    @return nothing

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
        s=SquareType::Bomb;
    }
    else if(percent <= 15){
        s=SquareType::Torpedo;
    }
    else{
        s=SquareType::Water;
    }
}

/**
 * Here we are initializing all the static variables from Cell and Player that we will want to use to keep track of scores
 * and turns.
 */
int Cell::clicked_button=0;
int Cell::score=0;
int Cell::score2=0;
bool Cell::is_game1=false;
bool Cell::is_game2=false;
int Cell::inv_t2=0;
int Cell::inv_t1=0;
int Cell::inv_b1=0;
int Cell::inv_b2=0;
bool Cell::torp_mode = false;
bool Cell::bomb_mode = false;
bool Player::extra_turns = false;

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
 * This also repaints our cells when they are hit.
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
 * Returns nothing (constructor)
 * Takes in a height, x, and y coordinates to create an instance of a bar object. This will be used
 * to create a bar graph of which players have won games over time.
 * @param x
 * @param y
 * @param h
 */
Bar::Bar(const int x, const int y, int h) {

    x_ = x;
    y_ = y;
    height_ = -h; //without a negative I couldn't see the rectangle
    color_ = "white";

}
/**
 * Creates the rectangle we have in our bar graph.
 * @return  the rectangle
 */
QRectF Bar::boundingRect() const
{
    return QRectF(x_, y_, width_, height_);
}
/**
 * Draws the shape of the rectangle we use in our bar graph.
 * @return the shape of the rectangle
 */
QPainterPath Bar::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, height_);
    return path;
}

//bar paint using QBrush
/**
 * Here we just set the color of the bar we are using in our graph. We paint it to our ui.
 * @param painter
 * @param option
 * @param widget
 */
void Bar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    Q_UNUSED(widget)

    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

    painter->drawRect(this->x_, this->y_, this->width_, this->height_);
    painter->setBrush(b);
}



/**
 * When we left click and the game has not started yet, we want to make sure each click sets up a square that will
 * be a player's boats. Once all boats have been placed the game mode changes to true and we can click to hit the other
 * person's squares.
 * Once we are in game mode if we hit a boat the player's score is increased and the cell turns red. If they hit a
 * square with a bomb or a torpedo they get those items added to their inventory.
 * If a person has pressed their torpedo or bomb button then the click mode is changed and the torpedo and bomb functions are
 * called on the cells we just clicked on.
 * If a cell with only water on it is clicked the cell turns white.
 * @param event
 */
void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //create another slot, if statement to figure out which mode we are in, set boat or hit boat
    //shift
    //qDebug()<<clicked_button;
    if(is_game1 == true && is_game2 == true){// is game = happens after done
//        qDebug()<<"Yes emitted";
        emit yes_clicked();

    }
    if(Cell::clicked_button>0){
        qDebug()<<Cell::clicked_button;

    if(event->button() == Qt::LeftButton && (is_game1==false || is_game2==false)){
        if(this->get_color() == QColor(255, 255, 255)){

            this->set_color(QColor(242,19,131));
            //Cell::clicked_button--;
            //ishidden1=true;
            this->s = SquareType::Boat;
            //this->is_boat=true;
            update();
            qDebug()<<"Score should be zero"<<score;
            //return;
        }

    }
  }
     qDebug()<<"Can we get to here?1111"<<is_game1<<"space"<<is_game2;
    if(event->button() == Qt::LeftButton && is_game1==true && is_game2==true){
        qDebug()<<"Can we get to here?";
        if(this->s==SquareType::Boat){
            this->set_color(QColor(255,0,0));
            this->is_hit = true;
            this->update();
            if (grid ==1)
            {
             score++;
             qDebug()<<"Score:"<<score;
            }
           else if (grid==2){
              qDebug()<<"Grid2";
             score2++;
             qDebug()<<"Score2:"<<score2;
            }
        }
        if(this->s==SquareType::Bomb){
            if(this->grid == 1){
                this->set_color(QColor(255,255,255));
                inv_b2++;
                this->update();
            }
            else{
                this->set_color(QColor(255,255,255));
                inv_b1++;
                this->update();
            }
        }
        if(this->s==SquareType::Torpedo){
            if(this->grid == 1){
                this->set_color(QColor(255,255,255));
                inv_t2++;
                this->update();
            }
            else{
                this->set_color(QColor(255,255,255));
                inv_t1++;
                this->update();
            }
        }
        if(torp_mode){
            if(this->grid == 1 && inv_t2 > 0){
                inv_t2--;
                this->torp(this);
                torp_mode = false;
                this->update();
            }
            else if(inv_t1 > 0){
                inv_t1--;
                this->torp(this);
                torp_mode = false;
                this->update();
            }
        }
        if(bomb_mode){
            if(this->grid == 1 && inv_b2 > 0){
                inv_b2--;
                this->bom(this);
                bomb_mode = false;
                this->update();
            }
            else if(inv_b1 > 0){
                inv_b1--;
                this->bom(this);
                bomb_mode = false;
                this->update();
            }
        }
        else if (this->s==SquareType::Water){
//            qDebug()<<"WTF";
            this->set_color(QColor(255,255,255));
            this->update();
        }
    }
    update();
    emit scorechanger(this);
    //qDebug()<<"Hellooooo";
    //qDebug()<<"This cells game bool is set to:";
    //qDebug()<<this->is_game;
     Cell::clicked_button--;

}
