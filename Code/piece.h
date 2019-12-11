#ifndef PIECE_H
#define PIECE_H

#include "Piece_Type.h"
#include "square.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>

using namespace std;

//Class for Checkers Pieces
class Piece : public QObject, public QGraphicsItem
{

    Q_OBJECT

public:
        Piece(QColor color, int team, bool alive, Piece_Type piece_type,int x, int y); //Constructor

        //GETTERS, INLINE
        int GetTeam() {return team_;}
        bool GetAlive() {return alive_;}
        Piece_Type GetPieceType() {return piece_type_;}
        int GetX(){return x_;}
        int GetY(){return y_;}
        int GetRow(){return vecPosRow_;}
        int GetCol(){return vecPosCol_;}
        QColor GetColor(){return color_;}
        vector<Square*> GetAvailableMoves() {return available_moves_;}

        //SETTERS, INLINE
        void setColor(QColor color) {color_ = color;} //Sets color of cell
        void SetPieceType(Piece_Type new_type) {piece_type_ = new_type;}
//        void SetX(int x){x_ = x;}
//        void SetY(int y){y_ = y;}
        void SetRow(int r){vecPosRow_ = r;}
        void SetCol(int c){vecPosCol_ = c;}

        void setX(int x){x_ = x;}
        void setY(int y){y_ = y;}


        void SetAlive(bool alive_status) {alive_ = alive_status;}
        void SetAvailableMoves(vector<Square*> current_moves) {available_moves_ = current_moves;}


        //Need these
        void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
        QRectF boundingRect() const override;
        QPainterPath shape() const override;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget) override;
        void prepareGeometryChange();

signals:
    void PRightClick(Piece* c);
    void PLeftClick(Piece* c);

private:
        QColor color_;
        int team_; //Hold value of 1 for P1 and 2 for P2
        Piece_Type piece_type_; //Normal, king, or Ace
        bool alive_; //True if alive, false if dead
        int x_;
        int y_;
        int vecPosRow_;
        int vecPosCol_;
        static const int size_ = 40; //Size of cell


        vector<Square*> available_moves_; //Vector that holds pointers to Sqaures of available moves
};

#endif // PIECE_H
