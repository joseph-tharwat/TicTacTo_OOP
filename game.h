#ifndef GAME_H
#define GAME_H

#include<iostream>
#include"board.h"
#include "player.h"

using namespace std;

enum gameStatus
{
    DRAW = 0,
    PLAYER_1_WIN = 1,
    PLAYER_2_WIN = 2,
};

class game
{
private:
    enum gameStatus status;
    board* boardPtr;
    bool isFinish;
    player *player1;
    player *player2;
public:
    game(player *p1, player *p2);
    ~game() = default;
    
    enum gameStatus checkRows();
    enum gameStatus checkColumns();
    enum gameStatus checkMainDiagonal();
    enum gameStatus checkSecondaryDiagonal();
    enum gameStatus checkResult();

    bool isGameEnd();

    void displayResult();

    enum gameStatus getStaus();
};

#endif
