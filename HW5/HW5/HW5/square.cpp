#include "square.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

//CONSTRUCTOR
Square::Square(QColor color, int x, int y)
{
  this->color_ = color; //Sets the color

  x_ = x * (475 / 8); //Sets the x coordinate
  y_ = y * (475 / 8); //Sets the y coordinate

  vecRow_ = y;
  vecCol_ = x;

}

//Defines clickable area
QRectF Square::boundingRect() const
{
    return QRectF(x_, y_, size_, size_);
}

//Shape of object
QPainterPath Square::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, size_, size_);
    return path;
}


void Square::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(widget);

    QBrush b = painter->brush();
    QColor red(Qt::red); //Alive
    QColor green(Qt::green);
    if (this->color_ == red)
    {
        painter->setBrush(QBrush(Qt::red));
    }
    else if(this->color_ == green)
    {
        painter->setBrush(QBrush(Qt::green));
    }
    else
    {
        painter->setBrush(QBrush(Qt::white));
    }

    //Applies conditionals of above
    painter->drawRect(QRect(this->x_, this->y_, this->size_, this->size_));
    painter->setBrush(b);
}

//Left click and right click
void Square::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        emit SLeftClick(this);
    }
    if (event->buttons() == Qt::RightButton)
    {
        emit SRightClick(this);
    }

}

