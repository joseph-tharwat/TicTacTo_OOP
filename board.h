
#ifndef BOARD_H
#define BOARD_H

#include<iostream>
#include"configration.h"

class board
{
private:
    char boardArray[BOARD_SIZE];
    static board* boardInstance;
    int counter;
public:
    board();
    ~board() = default;

    void clearScreen();
    void DrawBoard();

    static board* getBoardInstance();

    void setSymbol(char symbol, int position);
    char getSymbol(int position);

    bool isBoardComplete();
};

#endif
