
#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>
#include "board.h"

using namespace std;

class player
{
    private:
        string name;
        char symbol;
        board* boardPtr;
    public:
        player() = delete;
        player(string player_name, char player_symbol);
        bool play();
        string getName();   
        char getSymbol();
};


#endif