#include "piece.h"
#include <QtWidgets>

Piece::Piece(QColor color, int team, bool alive, Piece_Type piece_type,int x,int y) //Constructor
{
    color_ = color;
    team_ = team;
    alive_ = alive;
    piece_type_ = piece_type;
    // adding 7 centers it in square!!
    x_ = x * (475 / 8) + 7;
    y_ = y * (475 / 8) + 7;
    vecPosRow_ = y;
    vecPosCol_ = x;
}

QRectF Piece::boundingRect() const
{
    return QRectF(x_, y_, size_, size_);
}

//Shape of object
QPainterPath Piece::shape() const
{
    QPainterPath path;
    //path.addRect(x_, y_, size_, size_);
    path.addEllipse(x_, y_, size_, size_);
    return path;
}


void Piece::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(widget);

    QBrush b = painter->brush();
    QColor black(Qt::black); //Alive
    if (this->color_ == black)
    {
        painter->setBrush(QBrush(Qt::black));
    }
    else
    {
        painter->setBrush(QBrush(Qt::gray));
    }

    //Applies conditionals of above
    //painter->drawRect(QRect(this->x_, this->y_, this->size_, this->size_));
    painter->drawEllipse(QRect(this->x_, this->y_, this->size_, this->size_));
    painter->setBrush(b);
}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        emit PLeftClick(this);
    }
    if (event->buttons() == Qt::RightButton)
    {
        emit PRightClick(this);
    }

}

