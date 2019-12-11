#include "grid.h"
#include <stdlib.h>
#include <time.h>
#include <qDebug>
#include <QString>

//Constructor, creates a playing board
Grid::Grid(QGraphicsScene* scene, QGraphicsView* view)
{
    //FOR CELL_GRID_

    int alternate = 0;


    //Colors of board
    QColor red(Qt::red);
    QColor white(Qt::white);

    //Will be the color of part of board
    QColor cell_color;

    //Traverses row
    for (int i = 0; i < 8; i++)
    {
        //Column
        vector<Square*> temp_row;
        for (int j = 0; j < 8; j++)
        {
            //Red cell
            if (alternate == 1)
            {
                cell_color = red;
                alternate = 0;
            }
            //White cell...
            else
            {
                cell_color = white;
                alternate = 1;
            }

            //Create a new cell
            Square* newCell = new Square(cell_color, j, i);

            //Add each new cell in row to remp_row
            temp_row.push_back(newCell);
            scene->addItem(newCell);
        }

        //To switch colors once we hit new row in board
        if (alternate == 1)
        {
            alternate = 0;
        }
        else
        {
            alternate = 1;
        }

        //Once its gone through the whole row, add to final cell_grid_
        cell_grid_.push_back(temp_row);
    }

    //FOR PIECE_GRID_

    //For making each piece
    int team = 0;
    bool alive = true;
    Piece_Type p = Piece_Type::Normal;
    QColor black(Qt::black);
    QColor gray(Qt::gray);


    QColor piece_color;
    Piece* newPiece = NULL;

    //Row
    for (int i = 0; i < 8; i++)
    {
        vector<Piece*> temp_row1;

        //Column
        for (int j = 0; j < 8; j++)
        {
            newPiece = NULL;

            if ((i == 0) and (j == 1 or j == 3 or j == 5 or j == 7))
            {
               piece_color = gray;
               team = 2;
               newPiece = new Piece(piece_color,team,alive, p, j, i);
            }

            if ((i == 1) and (j == 0 or j == 2 or j == 4 or j == 6))
            {
               piece_color = gray;
               team = 2;
               newPiece = new Piece(piece_color,team,alive, p, j, i);
            }

            if ((i == 2) and (j == 1 or j == 3 or j == 5 or j == 7))
            {
               piece_color = gray;
               team = 2;
               newPiece = new Piece(piece_color,team,alive, p, j, i);
            }

            if ((i == 5) and (j == 0 or j == 2 or j == 4 or j == 6))
            {
               piece_color = black;
               team = 1;
               newPiece = new Piece(piece_color,team,alive, p, j, i);
            }

            if ((i == 6) and (j == 1 or j == 3 or j == 5 or j == 7))
            {
               piece_color = black;
               team = 1;
               newPiece = new Piece(piece_color,team,alive, p, j, i);
            }

            if ((i == 7) and (j == 0 or j == 2 or j == 4 or j == 6))
            {
               piece_color = black;
               team = 1;
               newPiece = new Piece(piece_color,team,alive, p, j, i);
            }

            //Add each new cell in row to remp_row
            temp_row1.push_back(newPiece);

            if (newPiece != NULL)
            {
                scene->addItem(newPiece);
            }

        }
        //Once its gone through the whole row, add to final cell_grid_
        piece_grid_.push_back(temp_row1);
    }

    //piece_grid_[4][1] = NULL;
}

//Returns a vector of all available moves for the inputted piece
vector<Square*> Grid::CurrentMoveForPiece(Piece* piece)
{
    //If a normal piece or ace piece
    if (piece->GetPieceType() == Piece_Type::Normal || piece->GetPieceType() == Piece_Type::Ace)
    {
        //If P1
        if (piece->GetTeam() == 1)
        {
            return HelperMovesForNormalP1(piece);
        }
        //If P2
        else
        {
            return HelperMovesForNormalP2(piece);
        }
    }

    //If a king piece
    if (piece->GetPieceType() == Piece_Type::King)
    {
        //If P1
        if (piece->GetTeam() == 1)
        {
            return HelperMovesForPieceKingP1(piece);
        }
        //If P2
        else
        {
            return HelperMovesForPieceKingP2(piece);
        }
    }
}

//Helper function returns vector of moves for normal/ace pieces P1
//Starts at bottom of board, moves up
vector<Square*> Grid::HelperMovesForNormalP1(Piece* piece)
{
    vector<Square*> moves;

    int current_row = piece->GetRow();
    int current_column = piece->GetCol();

    //Edge case, should never happen. If a normal piece is on top row, return no moves
    if (current_row <= 0)
    {
        return moves;
    }

    //Check to see if can move up to left
    if (current_row - 1 >= 0 && current_column - 1 >= 0)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row - 1][current_column - 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row - 1][current_column - 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row - 1][current_column - 1]->GetTeam() == 2)
        {
            //If up to the left of that piece is in the grid
            if (current_row - 2 >= 0 && current_column - 2 >= 0)
            {
                //If there is nothing up to the left of other piece
                if (piece_grid_[current_row - 2][current_column - 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row - 2][current_column - 2]);
                }
            }
        }

    }

    //Check to see if can move up to right
    if (current_row - 1 >= 0 && current_column + 1 <= 7)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row - 1][current_column + 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row - 1][current_column + 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row - 1][current_column + 1]->GetTeam() == 2)
        {
            //If up to the right of that piece is in the grid
            if (current_row - 2 >= 0 && current_column + 2 <= 7)
            {
                //If there is nothing up to the right of other piece
                if (piece_grid_[current_row - 2][current_column + 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row - 2][current_column + 2]);
                }
            }
        }

    }
    return moves;
}

//Helper function returns vector of moves for normal/ace pieces P1
//Starts at top of board, moves down
vector<Square*> Grid::HelperMovesForNormalP2(Piece* piece)
{
    vector<Square*> moves;

    int current_row = piece->GetRow();
    int current_column = piece->GetCol();

    //Edge case, should never happen. If a normal piece is on bottom row, return no moves
    if (current_row >= 7)
    {
        return moves;
    }

    //Check to see if can move down to left
    if (current_row + 1 <= 7 && current_column - 1 >= 0)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row + 1][current_column - 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row + 1][current_column - 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row + 1][current_column - 1]->GetTeam() == 1)
        {
            //If down to the left of that piece is in the grid
            if (current_row + 2 <= 7 && current_column - 2 >= 0)
            {
                //If there is nothing down to the left of other piece
                if (piece_grid_[current_row + 2][current_column - 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row + 2][current_column - 2]);
                }
            }
        }
    }

    //Check to see if can move down to right
    if (current_row + 1 <= 7 && current_column + 1 <= 7)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row + 1][current_column + 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row + 1][current_column + 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row + 1][current_column + 1]->GetTeam() == 1)
        {
            //If down to the right of that piece is in the grid
            if (current_row + 2 <= 7 && current_column + 2 <= 7)
            {
                //If there is nothing up to the right of other piece
                if (piece_grid_[current_row + 2][current_column + 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row + 2][current_column + 2]);
                }
            }
        }
    }

    return moves;
}

//Helper function return vector of moves for P1 king
vector<Square*> Grid::HelperMovesForPieceKingP1(Piece* piece)
{
    vector<Square*> moves;

    int current_row = piece->GetRow();
    int current_column = piece->GetCol();

    //Check to see if can move down to left
    if (current_row + 1 <= 7 && current_column - 1 >= 0)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row + 1][current_column - 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row + 1][current_column - 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row + 1][current_column - 1]->GetTeam() == 2)
        {
            //If down to the left of that piece is in the grid
            if (current_row + 2 <= 7 && current_column - 2 >= 0)
            {
                //If there is nothing down to the left of other piece
                if (piece_grid_[current_row + 2][current_column - 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row + 2][current_column - 2]);
                }
            }
        }
    }

    //Check to see if can move down to right
    if (current_row + 1 <= 7 && current_column + 1 <= 7)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row + 1][current_column + 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row + 1][current_column + 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row + 1][current_column + 1]->GetTeam() == 2)
        {
            //If down to the right of that piece is in the grid
            if (current_row + 2 <= 7 && current_column + 2 <= 7)
            {
                //If there is nothing up to the right of other piece
                if (piece_grid_[current_row + 2][current_column + 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row + 2][current_column + 2]);
                }
            }
        }

    }

    //Check to see if can move up to left
    if (current_row - 1 >= 0 && current_column - 1 >= 0)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row - 1][current_column - 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row - 1][current_column - 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row - 1][current_column - 1]->GetTeam() == 2)
        {
            //If up to the left of that piece is in the grid
            if (current_row - 2 >= 0 && current_column - 2 >= 0)
            {
                //If there is nothing up to the left of other piece
                if (piece_grid_[current_row - 2][current_column - 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row - 2][current_column - 2]);
                }
            }
        }

    }

    //Check to see if can move up to right
    if (current_row - 1 >= 0 && current_column + 1 <= 7)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row - 1][current_column + 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row - 1][current_column + 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row - 1][current_column + 1]->GetTeam() == 2)
        {
            //If up to the right of that piece is in the grid
            if (current_row - 2 >= 0 && current_column + 2 <= 7)
            {
                //If there is nothing up to the right of other piece
                if (piece_grid_[current_row - 2][current_column + 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row - 2][current_column + 2]);
                }
            }
        }

    }

    return moves;
}

//Helper function return vector of moves for P2 King
vector<Square*> Grid::HelperMovesForPieceKingP2(Piece* piece)
{
    vector<Square*> moves;

    int current_row = piece->GetRow();
    int current_column = piece->GetCol();

    //Check to see if can move down to left
    if (current_row + 1 <= 7 && current_column - 1 >= 0)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row + 1][current_column - 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row + 1][current_column - 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row + 1][current_column - 1]->GetTeam() == 1)
        {
            //If down to the left of that piece is in the grid
            if (current_row + 2 <= 7 && current_column - 2 >= 0)
            {
                //If there is nothing down to the left of other piece
                if (piece_grid_[current_row + 2][current_column - 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row + 2][current_column - 2]);
                }
            }
        }
    }

    //Check to see if can move down to right
    if (current_row + 1 <= 7 && current_column + 1 <= 7)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row + 1][current_column + 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row + 1][current_column + 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row + 1][current_column + 1]->GetTeam() == 1)
        {
            //If down to the right of that piece is in the grid
            if (current_row + 2 <= 7 && current_column + 2 <= 7)
            {
                //If there is nothing up to the right of other piece
                if (piece_grid_[current_row + 2][current_column + 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row + 2][current_column + 2]);
                }
            }
        }

    }

    //Check to see if can move up to left
    if (current_row - 1 >= 0 && current_column - 1 >= 0)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row - 1][current_column - 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row - 1][current_column - 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row - 1][current_column - 1]->GetTeam() == 1)
        {
            //If up to the left of that piece is in the grid
            if (current_row - 2 >= 0 && current_column - 2 >= 0)
            {
                //If there is nothing up to the left of other piece
                if (piece_grid_[current_row - 2][current_column - 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row - 2][current_column - 2]);
                }
            }
        }

    }

    //Check to see if can move up to right
    if (current_row - 1 >= 0 && current_column + 1 <= 7)
    {
        //If nothing there can move to it
        if (piece_grid_[current_row - 1][current_column + 1] == NULL)
        {
            moves.push_back(cell_grid_[current_row - 1][current_column + 1]);
        }
        //If there is an enemy piece there
        else if (piece_grid_[current_row - 1][current_column + 1]->GetTeam() == 1)
        {
            //If up to the right of that piece is in the grid
            if (current_row - 2 >= 0 && current_column + 2 <= 7)
            {
                //If there is nothing up to the right of other piece
                if (piece_grid_[current_row - 2][current_column + 2] == NULL)
                {
                    moves.push_back(cell_grid_[current_row - 2][current_column + 2]);
                }
            }
        }

    }
    return moves;
}
