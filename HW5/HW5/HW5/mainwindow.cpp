#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "square.h"

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include <stdlib.h>
#include <time.h>
#include <QTimer>

int random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (max + 1 - min);
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    turn_ = 1; //Initialize turn to be 1
    MakeBoard(); //Call the MakeBoard() function to make a new checkers board
    P1Human = true;
    P2Human = true;
    current_piece = NULL;

    //TESTING
    C1Wins_ = 5;
    C2Wins_ = 3;
}

void MainWindow::makeBarChart()
{

    //qDebug() << currentPopulation_;
    QPen outlinePen(Qt::white);


    bars_[0] = C1Wins_ /10.0;
    bars_[1] = C2Wins_ /10.0;
    qDebug() << C1Wins_;
    qDebug() << bars_[0];
    barScene_->addRect(1 * (bw_ /4), (bh_) * (1-(bars_[0])), bw_ /4 , bh_,outlinePen);
    barScene_->addRect(2 * (bw_ / 4), (bh_) * (1-(bars_[1])), bw_ / 4, bh_,outlinePen);
    barScene_->update();
    return;


}

void MainWindow::Recolor()
{
    QColor green(Qt::green);
    QColor red(Qt::red);
    vector<vector<Square*>> tmp = g.GetCellGrid();
    for(int i =0;i<8;i++){
        for(int j=0;j<8;j++){
            Square * temp = tmp[i][j];
            if(temp->GetColor() == green){
                temp->setColor(red);
                tmp[i][j] = temp;
            }
        }
    }
    g.SetCellGrid(tmp);
    cellScene_->update();
}

void MainWindow::MakeBoard()
{
    ui->setupUi(this);
    cellScene_ = new QGraphicsScene;
    QGraphicsView* cellView = ui->board;
    cellView->setScene(cellScene_);
    cellView->setSceneRect(0,0,cellView->frameSize().width()-10,cellView->frameSize().height()-10);
    g = Grid(cellScene_,cellView);


    //for BAR GRAPH
    barScene_ = new QGraphicsScene;
    QGraphicsView* barView = ui->graph;
    barView->setScene(barScene_);
    int barHeight_ = barView->frameSize().height() - 20;
    int barWidth_ = barView->frameSize().width() - 20;
    bh_ = barHeight_;
    bw_ = barWidth_;
    barView->setSceneRect(0,0,barWidth_,barHeight_);

    //initialize the bar array to zero
    //TESTING
    C1Wins_ = 5;
    C2Wins_ = 3;

    makeBarChart();



    //connect left click feature to all squares
    vector<vector<Square*>>  tmp = g.GetCellGrid();
    for (vector<Square*> v : tmp)
    {
        for (Square* c : v)
        {
            connect(c, &Square::SLeftClick, this, &MainWindow::SLeftClickSlot);
            connect(c, &Square::SRightClick, this, &MainWindow::SRightClickSlot);
        }
    }

    vector<vector<Piece*>>  tmp1 = g.GetPieceGrid();
    for (vector<Piece*> v : tmp1)
    {
        for (Piece* c : v)
        {
            if (c != NULL)
            {
                connect(c, &Piece::PLeftClick, this, &MainWindow::PLeftClickSlot);
                connect(c, &Piece::PRightClick, this, &MainWindow::PRightClickSlot);
            }

        }
    }



}

//Change name of slot
void MainWindow::on_newGame_clicked()
{
    qDebug() << "NEW GAME CLICK !";
    //Clear the board and reset turn
    cellScene_->clear();
    turn_ = 1;
    P1Human = true;
    P2Human = true;
    current_piece = NULL;

    //Call the MakeBoard() function to redo board
    MakeBoard();
}

void MainWindow::SLeftClickSlot(Square* click)
{

    qDebug() << "---------------------";
    qDebug() << "SQUARE";

    vector<vector<Piece*>> PG = g.GetPieceGrid();
    if (PG[click->GetRow()][click->GetCol()] == NULL)
    {
        qDebug() << "NULL";
    }
    QColor green(Qt::green);
    qDebug() << "LEFT CLICK !";
    qDebug() << "ROW" << click->GetRow();
    qDebug() << "COL:" << click->GetCol();
    qDebug() << "---------------------";
    if(click->GetColor() == green){
        //TakeTurn();
        Recolor();
    }
}

void MainWindow::SRightClickSlot(Square* click)
{
    qDebug() << "SQUARE";
    qDebug() << "RIGHT CLICK !";
    qDebug() << click->GetX();
    qDebug() << "Y" << click->GetY();

    TakeTurn(click);
}

void MainWindow::PLeftClickSlot(Piece* click)
{
    Recolor();
    QColor c(Qt::green);
    qDebug() << "Piece";

    //Change value of current_piece if teams match
    if (turn_ == click->GetTeam())
    {
        current_piece = click;
    }

    //qDebug() << "Team: " << click->GetTeam();
    qDebug() << "LEFT CLICK !";
    qDebug() << "Row"<< click->GetRow();
    qDebug() << "Col" << click->GetCol();
    vector<Square*> moves = g.CurrentMoveForPiece(click);
    vector<vector<Square*>> tmp_sg = g.GetCellGrid();
    qDebug() << "MOVES:";
    for (int x = 0; x < moves.size(); x++)
    {
        Square * tmp = moves[x];
        int col = tmp->GetCol();
        int row = tmp->GetRow();
        tmp->setColor(c);
        tmp_sg[row][col] = tmp;


        qDebug() << "MOVE ROW: " << moves[x]->GetRow();
        qDebug() << "MOVE COL: " << moves[x]->GetCol();
    }
    g.SetCellGrid(tmp_sg);
    cellScene_->update();

}

void MainWindow::PRightClickSlot(Piece *click)
{
    MakeBoard();

    qDebug() << "Piece";
    qDebug() << "RIGHT CLICK !";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_P1Human_clicked()
{
    P1Human = true;
}

void MainWindow::on_P1Comp_clicked()
{
    P2Human = false;
}

void MainWindow::on_P2Human_clicked()
{
    P2Human = true;
}

void MainWindow::on_P2Comp_clicked()
{
    P2Human = false;
}

//Helper function which returns a vector of all pieces that belong to a certain team
vector<Piece*> MainWindow::TeamXPieces(int team)
{
    //Return value
    vector<Piece*> pieces;

    //PG is a copy of piece_grid_ (matrix of all pieces on board)
    vector<vector<Piece*>> PG = g.GetPieceGrid();

    //Rows
    for (int i = 0; i < 8; i++)
    {
        //Columns
        for (int j = 0; j < 8; j++)
        {
            //Nasty seg faults...
            if (PG[i][j] != NULL)
            {
                //If right team...
                if (PG[i][j]->GetTeam() == team)
                {
                    //Add it
                    pieces.push_back(PG[i][j]);
                }
            }
        }
    }

    return pieces;
}

void MainWindow::TakeTurn(Square* move_to)
{
    MovePiece(current_piece, move_to);
}

//Main take turn function for game
void MainWindow::MovePiece(Piece* click, Square* move_to)
{
    //PG is a copy of piece_grid_ (matrix of all pieces on board)
    vector<vector<Piece*>> PG = g.GetPieceGrid();

    //Used for human players
    bool found_valid_square = false;


    //If P1's turn
    if (turn_ == 1 && click->GetTeam() == 1)
    {
        //If human
        if (P1Human == true)
        {
            //Make a vector of all squares I can move to from current position named available_squares
            vector<Square*> available_squares = click->GetAvailableMoves();

            //Loop through available_squares and see if desired move is valid
            for (int x = 0; x < available_squares.size(); x++)
            {
                //If we find a matching square
                if (move_to->GetCol() == available_squares[x]->GetCol() && move_to->GetRow() == available_squares[x]->GetRow())
                {
                    found_valid_square = true;
                }
            }

            //Desired move to location was invalid, exit program
            if (found_valid_square == false)
            {
                qDebug() << "Invalid Choice";
                return;
            }

            //Now, move to valid square move_to
            //If move is up or down one unit, don't worry about deleting a piece
            if (move_to->GetRow() - click->GetRow() == -1 || move_to->GetRow() - click->GetRow() == 1)
            {
                //Move the piece and make prev square NULL
                PG[click->GetRow()][click->GetCol()] = NULL;
                click->SetRow(move_to->GetRow());
                click->SetCol(move_to->GetCol());
                PG[move_to->GetRow()][move_to->GetCol()] = click;
            }
            //If take a unit
            else
            {
                //If take up to left
                if (move_to->GetRow() - click->GetRow() == -2 && move_to->GetCol() - click->GetCol() == -2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() - 1][click->GetCol() - 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(move_to->GetRow());
                    click->SetCol(move_to->GetCol());

                    //Add piece to new location
                    PG[move_to->GetRow()][move_to->GetCol()] = click;
                }

                //If take up to right
                if (move_to->GetRow() - click->GetRow() == -2 && move_to->GetCol() - click->GetCol() == 2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() - 1][click->GetCol() + 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(move_to->GetRow());
                    click->SetCol(move_to->GetCol());

                    //Add piece to new location
                    PG[move_to->GetRow()][move_to->GetCol()] = click;
                }

                //If take down to left
                if (move_to->GetRow() - click->GetRow() == 2 && move_to->GetCol() - click->GetCol() == -2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() + 1][click->GetCol() - 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(move_to->GetRow());
                    click->SetCol(move_to->GetCol());

                    //Add piece to new location
                    PG[move_to->GetRow()][move_to->GetCol()] = click;
                }

                //If take down to right
                if (move_to->GetRow() - click->GetRow() == 2 && move_to->GetCol() - click->GetCol() == 2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() + 1][click->GetCol() + 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(move_to->GetRow());
                    click->SetCol(move_to->GetCol());

                    //Add piece to new location
                    PG[move_to->GetRow()][move_to->GetCol()] = click;
                }
            }
        }

        //If computer
        else
        {
            //Gives me a vector of all pieces belonging to P1
            vector<Piece*> P1_pieces = TeamXPieces(1);

            //If game is over, return
            if (P1_pieces.size() == 0)
            {
                qDebug() << "Game over";
                return;
            }

            //Vector of all pieces able to move
            vector<Piece*> P1_pieces_with_moves;

            //Loop through all pieces of P1
            for (int x = 0; x < P1_pieces.size(); x++)
            {
                //For each piece, make a vector of available moves
                vector<Square*> moves = P1_pieces[x]->GetAvailableMoves();

                //If there is an available move...
                if (moves.size() > 0)
                {
                    //Add piece to vector of pieces with moves
                    P1_pieces_with_moves.push_back(P1_pieces[x]);
                }
            }

            //Edge case where there are no available moves
            if (P1_pieces_with_moves.size() == 0)
            {
                qDebug() << "No available pieces!";
                return;
            }

            //Give me a random piece from all pieces with moves
            int random_piece = random(0, P1_pieces_with_moves.size() - 1);

            //Make a copy (selected_piece) of that piece
            Piece* selected_piece = P1_pieces_with_moves[random_piece];

            //Make a vector of all squares selected_piece can go to
            vector<Square*> moves_for_selected = selected_piece->GetAvailableMoves();

            //Will be index selected_piece will move to
            int random_move = -1;

            //If only 1 available move
            if (moves_for_selected.size() == 1)
            {
                random_move = 0;
            }

            //More than 1 available move
            else
            {
                //Set random_move equal to a random index in moves_for_selected
                random_move = random(0, moves_for_selected.size() - 1);
            }

            //Make a copy (selected_square) for this piece's choice of a square
            Square* selected_square = moves_for_selected[random_move];

            //If move is up or down one unit, don't worry about deleting a piece
            if (selected_square->GetRow() - click->GetRow() == -1 || selected_square->GetRow() - click->GetRow() == 1)
            {
                //Move the piece and make prev square NULL
                PG[click->GetRow()][click->GetCol()] = NULL;
                click->SetRow(selected_square->GetRow());
                click->SetCol(selected_square->GetCol());
                PG[selected_square->GetRow()][selected_square->GetCol()] = click;
            }
            //If take a unit
            else
            {
                //If take up to left
                if (selected_square->GetRow() - click->GetRow() == -2 && selected_square->GetCol() - click->GetCol() == -2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() - 1][click->GetCol() - 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(selected_square->GetRow());
                    click->SetCol(selected_square->GetCol());

                    //Add piece to new location
                    PG[selected_square->GetRow()][selected_square->GetCol()] = click;
                }

                //If take up to right
                if (selected_square->GetRow() - click->GetRow() == -2 && selected_square->GetCol() - click->GetCol() == 2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() - 1][click->GetCol() + 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(selected_square->GetRow());
                    click->SetCol(selected_square->GetCol());

                    //Add piece to new location
                    PG[selected_square->GetRow()][selected_square->GetCol()] = click;
                }

                //If take down to left
                if (selected_square->GetRow() - click->GetRow() == 2 && selected_square->GetCol() - click->GetCol() == -2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() + 1][click->GetCol() - 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(selected_square->GetRow());
                    click->SetCol(selected_square->GetCol());

                    //Add piece to new location
                    PG[selected_square->GetRow()][selected_square->GetCol()] = click;
                }

                //If take down to right
                if (selected_square->GetRow() - click->GetRow() == 2 && selected_square->GetCol() - click->GetCol() == 2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() + 1][click->GetCol() + 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(selected_square->GetRow());
                    click->SetCol(selected_square->GetCol());

                    //Add piece to new location
                    PG[selected_square->GetRow()][selected_square->GetCol()] = click;
                }
            }
        }

        turn_ = 2;
    }

    //If P2 turns
    else
    {
        //If human
        if (P2Human == true)
        {
            //Make a vector of all squares I can move to from current position named available_squares
            vector<Square*> available_squares = click->GetAvailableMoves();

            //Loop through available_squares and see if desired move is valid
            for (int x = 0; x < available_squares.size(); x++)
            {
                //If we find a matching square
                if (move_to->GetCol() == available_squares[x]->GetCol() && move_to->GetRow() == available_squares[x]->GetRow())
                {
                    found_valid_square = true;
                }
            }

            //Desired move to location was invalid, exit program
            if (found_valid_square == false)
            {
                qDebug() << "Invalid Choice";
                return;
            }

            //Now, move to valid square move_to
            //If move is up or down one unit, don't worry about deleting a piece
            if (move_to->GetRow() - click->GetRow() == -1 || move_to->GetRow() - click->GetRow() == 1)
            {
                //Move the piece and make prev square NULL
                PG[click->GetRow()][click->GetCol()] = NULL;
                click->SetRow(move_to->GetRow());
                click->SetCol(move_to->GetCol());
                PG[move_to->GetRow()][move_to->GetCol()] = click;
            }
            //If take a unit
            else
            {
                //If take up to left
                if (move_to->GetRow() - click->GetRow() == -2 && move_to->GetCol() - click->GetCol() == -2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() - 1][click->GetCol() - 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(move_to->GetRow());
                    click->SetCol(move_to->GetCol());

                    //Add piece to new location
                    PG[move_to->GetRow()][move_to->GetCol()] = click;
                }

                //If take up to right
                if (move_to->GetRow() - click->GetRow() == -2 && move_to->GetCol() - click->GetCol() == 2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() - 1][click->GetCol() + 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(move_to->GetRow());
                    click->SetCol(move_to->GetCol());

                    //Add piece to new location
                    PG[move_to->GetRow()][move_to->GetCol()] = click;
                }

                //If take down to left
                if (move_to->GetRow() - click->GetRow() == 2 && move_to->GetCol() - click->GetCol() == -2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() + 1][click->GetCol() - 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(move_to->GetRow());
                    click->SetCol(move_to->GetCol());

                    //Add piece to new location
                    PG[move_to->GetRow()][move_to->GetCol()] = click;
                }

                //If take down to right
                if (move_to->GetRow() - click->GetRow() == 2 && move_to->GetCol() - click->GetCol() == 2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() + 1][click->GetCol() + 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(move_to->GetRow());
                    click->SetCol(move_to->GetCol());

                    //Add piece to new location
                    PG[move_to->GetRow()][move_to->GetCol()] = click;
                }
            }
        }

        //If computer
        else
        {
            //Gives me a vector of all pieces belonging to P1
            vector<Piece*> P2_pieces = TeamXPieces(2);

            //If game is over, return
            if (P2_pieces.size() == 0)
            {
                qDebug() << "Game over";
                return;
            }

            //Vector of all pieces able to move
            vector<Piece*> P2_pieces_with_moves;

            //Loop through all pieces of P1
            for (int x = 0; x < P2_pieces.size(); x++)
            {
                //For each piece, make a vector of available moves
                vector<Square*> moves = P2_pieces[x]->GetAvailableMoves();

                //If there is an available move...
                if (moves.size() > 0)
                {
                    //Add piece to vector of pieces with moves
                    P2_pieces_with_moves.push_back(P2_pieces[x]);
                }
            }

            //Edge case where there are no available moves
            if (P2_pieces_with_moves.size() == 0)
            {
                qDebug() << "No available pieces!";
                return;
            }

            //Give me a random piece from all pieces with moves
            int random_piece = random(0, P2_pieces_with_moves.size() - 1);

            //Make a copy (selected_piece) of that piece
            Piece* selected_piece = P2_pieces_with_moves[random_piece];

            //Make a vector of all squares selected_piece can go to
            vector<Square*> moves_for_selected = selected_piece->GetAvailableMoves();

            //Will be index selected_piece will move to
            int random_move = -1;

            //If only 1 available move
            if (moves_for_selected.size() == 1)
            {
                random_move = 0;
            }

            //More than 1 available move
            else
            {
                //Set random_move equal to a random index in moves_for_selected
                random_move = random(0, moves_for_selected.size() - 1);
            }

            //Make a copy (selected_square) for this piece's choice of a square
            Square* selected_square = moves_for_selected[random_move];

            //If move is up or down one unit, don't worry about deleting a piece
            if (selected_square->GetRow() - click->GetRow() == -1 || selected_square->GetRow() - click->GetRow() == 1)
            {
                //Move the piece and make prev square NULL
                PG[click->GetRow()][click->GetCol()] = NULL;
                click->SetRow(selected_square->GetRow());
                click->SetCol(selected_square->GetCol());
                PG[selected_square->GetRow()][selected_square->GetCol()] = click;
            }
            //If take a unit
            else
            {
                //If take up to left
                if (selected_square->GetRow() - click->GetRow() == -2 && selected_square->GetCol() - click->GetCol() == -2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() - 1][click->GetCol() - 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(selected_square->GetRow());
                    click->SetCol(selected_square->GetCol());

                    //Add piece to new location
                    PG[selected_square->GetRow()][selected_square->GetCol()] = click;
                }

                //If take up to right
                if (selected_square->GetRow() - click->GetRow() == -2 && selected_square->GetCol() - click->GetCol() == 2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() - 1][click->GetCol() + 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(selected_square->GetRow());
                    click->SetCol(selected_square->GetCol());

                    //Add piece to new location
                    PG[selected_square->GetRow()][selected_square->GetCol()] = click;
                }

                //If take down to left
                if (selected_square->GetRow() - click->GetRow() == 2 && selected_square->GetCol() - click->GetCol() == -2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() + 1][click->GetCol() - 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(selected_square->GetRow());
                    click->SetCol(selected_square->GetCol());

                    //Add piece to new location
                    PG[selected_square->GetRow()][selected_square->GetCol()] = click;
                }

                //If take down to right
                if (selected_square->GetRow() - click->GetRow() == 2 && selected_square->GetCol() - click->GetCol() == 2)
                {
                    //Delete current piece from board and kill middle piece
                    PG[click->GetRow()][click->GetCol()] = NULL;
                    PG[click->GetRow() + 1][click->GetCol() + 1] = NULL;

                    //Set new coordinates for piece
                    click->SetRow(selected_square->GetRow());
                    click->SetCol(selected_square->GetCol());

                    //Add piece to new location
                    PG[selected_square->GetRow()][selected_square->GetCol()] = click;
                }
            }
        }
        turn_ = 1;
    }

    //Update game board after changes
    g.SetPieceGrid(PG);
}
