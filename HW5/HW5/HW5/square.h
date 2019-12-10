#ifndef SQUARE_H
#define SQUARE_H

#include <QColor>
#include <QGraphicsItem>

//Class for each individual cell on the game board


class Square : public QObject, public QGraphicsItem
{

    Q_OBJECT

public:
    Square(QColor color, int x, int y);  //Constructor

    //GETTERS, INLINE
    int GetX() {return x_;}  //Returns x coordinate
    int GetY() {return y_;}  //Returns y coordinate
    int GetRow() {return vecRow_;}
    int GetCol() {return vecCol_;}
    QColor GetColor(){return color_;}
    //SETTERS, INLINE
    void setColor(QColor color) {color_ = color;} //Sets color of cell

    //Need these functions
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    //Changes color of the cell
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget) override;

signals:
    void SRightClick(Square* c);
    void SLeftClick(Square* c);

private:
  int x_; //X coordinate
  int y_; //Y coordinate
  int vecCol_;
  int vecRow_;
  QColor color_; //Color of cell
  static const int size_ = 55; //Size of cell

};

#endif // SQUARE_H
