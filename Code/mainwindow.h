#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <square.h>

#include "grid.h"

//Class for overall driver of program

namespace Ui
{
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void SLeftClickSlot(Square* click);
    void SRightClickSlot(Square * click);

    void TakeTurn(Square* move_to);
    void MovePiece(Piece* click, Square* move_to);
    vector<Piece*> TeamXPieces(int team); //Helper function which returns a vector of all pieces that belong to a certain team
    void MakeBoard();

    void Recolor();
    void RecolorPieces();
    void UpdateBoard(int x, int y,Piece_Type p,QColor c);
    void makeBarChart();
    void ConnectHelper();
    void Play();


public slots:

    void PLeftClickSlot(Piece* click);
    void PRightClickSlot(Piece * click);

private slots:
    void on_newGame_clicked();
    void on_P1Human_clicked();
    void on_P1Comp_clicked();
    void on_P2Human_clicked();
    void on_P2Comp_clicked();

    void on_GO_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* cellScene_;
    QGraphicsScene* barScene_;

    Grid g;
    int turn_; //Turn == 1 if P1, 2 if P2
    bool P1Human;
    bool P2Human;

    Piece* current_piece; //For MovePiece function


    double bars_[20];
    int bh_;
    int bw_;

    int C1Wins_;
    int C2Wins_;

};
#endif // MAINWINDOW_H
