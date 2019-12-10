#ifndef GRID_H
#define GRID_H

#include "piece.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

//Class for Game Board

using namespace std;


class Grid
{
public:
    //Constructor, on creation, will go through board and randomely create alive and dead cells
    Grid(QGraphicsScene* scene, QGraphicsView* view);

    //Defualt constructor
    Grid() {}

    //Returns a vector of all available moves for the inputted piece
    vector<Square*> CurrentMoveForPiece(Piece* piece);

    //GETTERS, INLINE
    vector<vector<Square*>> GetCellGrid() {return cell_grid_;}
    vector<vector<Piece*>> GetPieceGrid() {return piece_grid_;}

    //SETTERS, INLINE
    void SetPieceGrid(vector<vector<Piece*>> current_piece_layout) {piece_grid_ = current_piece_layout;}
    void SetCellGrid(vector<vector<Square*>> current_cell_layout) {cell_grid_ = current_cell_layout;}

    //HELPER FUNCTIONS (for CurrentMoveForPiece())
    vector<Square*> HelperMovesForNormalP1(Piece* piece);
    vector<Square*> HelperMovesForNormalP2(Piece* piece);
    vector<Square*> HelperMovesForPieceKingP1(Piece* piece);
    vector<Square*> HelperMovesForPieceKingP2(Piece* piece);




private:
    vector<vector<Square*>> cell_grid_; //Is a 2D vector that will contain pointers of all the cells in the game
    vector<vector<Piece*>> piece_grid_; //Matrix that will contain location all pieces on grid (board)
};

#endif // GRID_H
