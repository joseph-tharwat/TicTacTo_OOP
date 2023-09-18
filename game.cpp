
#include"game.h"

game::game(player *p1, player *p2)
{
    boardPtr = board::getBoardInstance();
    status = DRAW;
    isFinish = false;
    player1 = p1;
    player2 = p2;
}

enum gameStatus game::checkRows()
{
    int xCounter;
    int yCounter;
    for(int row = 0; row<ROW_COUNT; row++)
    {
        xCounter = 0;
        yCounter = 0;
        for(int column = 0; column<COLUMN_COUNT; column++)
        {
            if(boardPtr->getSymbol(column+row*3) == player1->getSymbol())
            {
                xCounter++;
            }
            else if(boardPtr->getSymbol(column+row*3) == player2->getSymbol())
            {
                yCounter++;
            }
        }
        if(xCounter==3)
        {
            return PLAYER_1_WIN;
        }
        else if(yCounter==3)
        {
            return PLAYER_2_WIN;
        }
    }
    return DRAW;   
}

enum gameStatus game::checkColumns()
{
    int xCounter;
    int yCounter;
    for(int column = 0; column < COLUMN_COUNT; column++)
    {
        xCounter = 0;
        yCounter = 0;
        for(int row = 0; row < ROW_COUNT; row++)
        {
            if(boardPtr->getSymbol(column+row*3) == player1->getSymbol())
            {
                xCounter++;
            }
            else if(boardPtr->getSymbol(column+row*3) == player2->getSymbol())
            {
                yCounter++;
            }
        }
        if(xCounter==3)
        {
            return PLAYER_1_WIN;
        }
        else if(yCounter==3)
        {
            return PLAYER_2_WIN;
        }
    }
    return DRAW;
}

enum gameStatus game::checkMainDiagonal()
{
    int xCounter = 0;
    int yCounter = 0;
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        if(i%4 ==0)
        {
            if(boardPtr->getSymbol(i) == player1->getSymbol())
            {
                xCounter++;
            }
            else if(boardPtr->getSymbol(i) == player2->getSymbol())
            {
                yCounter++;
            }
        }
    }
    if(xCounter == 3)
    {
        return PLAYER_1_WIN;
    }
    else if(yCounter == 3)
    {
        return PLAYER_2_WIN;
    }
    return DRAW;
}

enum gameStatus game::checkSecondaryDiagonal()
{
    int xCounter = 0;
    int yCounter = 0;
    for(int i = 1; i < BOARD_SIZE-1; i++)
    {
        if(i%2 == 0)
        {
            if(boardPtr->getSymbol(i) == player1->getSymbol())
            {
                xCounter++;
            }
            else if(boardPtr->getSymbol(i) == player2->getSymbol())
            {
                yCounter++;
            }
        }
    }
    if(xCounter==3)
    {
        return PLAYER_1_WIN;
    }
    else if(yCounter==3)
    {
        return PLAYER_2_WIN;
    }
    return DRAW;
}

enum gameStatus game::checkResult()
{
    status =  checkRows();
    if(status == DRAW)
    {
        status = checkColumns();
        if(status == DRAW)
        {
            status = checkMainDiagonal();
            if(status == DRAW)
            {
                status = checkSecondaryDiagonal();
            }
        }
    }
    return status;
}


bool game::isGameEnd()
{
    if(boardPtr->isBoardComplete())
    {
        return true;
    }
    else
    {
        return false;
    }
}


void game::displayResult()
{
    if(status == DRAW)
    {
        cout<<"draw"<<endl;
    }
    else if(status == PLAYER_1_WIN)
    {
        cout<<player1->getName()<<" with symbol "<<player1->getSymbol()<<" wins"<<endl;
    }
    else if(status == PLAYER_2_WIN)
    {
        cout<<player2->getName()<<" with symbol "<<player2->getSymbol()<<" wins"<<endl;
    }
}

enum gameStatus game::getStaus()
{
    return status;
}





