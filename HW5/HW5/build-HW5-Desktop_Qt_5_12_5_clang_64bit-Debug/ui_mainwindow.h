/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *board;
    QPushButton *P1Human;
    QPushButton *P1Comp;
    QPushButton *P2Human;
    QPushButton *P2Comp;
    QLabel *label;
    QLabel *label_2;
    QPushButton *newGame;
    QGraphicsView *graph;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        board = new QGraphicsView(centralwidget);
        board->setObjectName(QString::fromUtf8("board"));
        board->setGeometry(QRect(260, 0, 480, 480));
        P1Human = new QPushButton(centralwidget);
        P1Human->setObjectName(QString::fromUtf8("P1Human"));
        P1Human->setGeometry(QRect(70, 360, 80, 24));
        P1Comp = new QPushButton(centralwidget);
        P1Comp->setObjectName(QString::fromUtf8("P1Comp"));
        P1Comp->setGeometry(QRect(160, 360, 91, 24));
        P2Human = new QPushButton(centralwidget);
        P2Human->setObjectName(QString::fromUtf8("P2Human"));
        P2Human->setGeometry(QRect(70, 400, 80, 24));
        P2Comp = new QPushButton(centralwidget);
        P2Comp->setObjectName(QString::fromUtf8("P2Comp"));
        P2Comp->setGeometry(QRect(160, 400, 91, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 360, 58, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 400, 58, 16));
        newGame = new QPushButton(centralwidget);
        newGame->setObjectName(QString::fromUtf8("newGame"));
        newGame->setGeometry(QRect(10, 450, 231, 24));
        graph = new QGraphicsView(centralwidget);
        graph->setObjectName(QString::fromUtf8("graph"));
        graph->setGeometry(QRect(0, 0, 256, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        P1Human->setText(QApplication::translate("MainWindow", "Player", nullptr));
        P1Comp->setText(QApplication::translate("MainWindow", "Computer", nullptr));
        P2Human->setText(QApplication::translate("MainWindow", "Player", nullptr));
        P2Comp->setText(QApplication::translate("MainWindow", "Computer", nullptr));
        label->setText(QApplication::translate("MainWindow", "Player 1 : ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Player 2:", nullptr));
        newGame->setText(QApplication::translate("MainWindow", "NEW GAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
