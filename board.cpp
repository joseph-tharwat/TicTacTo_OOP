
#include"board.h"

board* board::boardInstance = NULL;

board::board()
{
    if(boardInstance == NULL)
    {
        for(int i=0; i<BOARD_SIZE; i++)
        {
            boardArray[i] = '0' + i;
        }
        counter = 0;
        
        boardInstance = this;
    }
}

void board::clearScreen()
{
    system("cls");
}

void board::DrawBoard()
{
    clearScreen();

    for(int row = 0; row < ROW_COUNT; row++)
    {
        for(int column = 0; column < COLUMN_COUNT; column++)
        {
            printf(" %c |", boardArray[column+row*3]);
        }
        printf("\n");
        printf("_____________\n");
    }
}

board* board::getBoardInstance()
{
    if(boardInstance == NULL)
    {
        boardInstance = new board();
    }

    return boardInstance;
}

void board::setSymbol(char symbol, int position)
{
    boardArray[position] = symbol;
    counter++;
}

char board::getSymbol(int position)
{
    return boardArray[position];
}

bool board::isBoardComplete()
{
    if(counter == BOARD_SIZE-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


