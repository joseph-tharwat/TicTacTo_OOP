
#include <iostream>

using namespace std;

// char board[9] = {'0','1','2','3','4','5','6','7','8'};

// void DrawBoard()
// {
//     for(int row = 0; row<3; row++)
//     {
//         for(int column = 0; column<3;column++)
//         {
//             printf(" %c |",board[column+row*3]);
//         }
//         printf("\n");
//         printf("_______________\n");
//     }

// }

// void clearScrean()
// {
//      system("cls");
// }

char checkResult()
{
    int xCounter;
    int yCounter;
    for(int row = 0; row<3; row++)
    {
        xCounter = 0;
        yCounter = 0;
        for(int column = 0; column<3; column++)
        {
            if(board[column+row*3] == 'x')
            {
                xCounter++;
            }
            else if(board[column+row*3] == 'o')
            {
                yCounter++;
            }
        }
        if(xCounter==3)
        {
            return 'x';
        }
        else if(yCounter==3)
        {
            return 'y';
        }
    }

    for(int column = 0; column<3; column++)
    {
        xCounter = 0;
        yCounter=0;
        for(int row = 0; row<3; row++)
        {
            if(board[row+column*3] == 'x')
            {
                xCounter++;
            }
            else if(board[column+row*3] == 'o')
            {
                yCounter++;
            }
        }
        if(xCounter==3)
        {
            return 'x';
        }
        else if(yCounter==3)
        {
            return 'y';
        }
    }

    for(int i = 0; i<9; i++)
    {
        xCounter = 0;
        yCounter = 0;
        if(i%4 ==0)
        {
            if(board[i] == 'x')
            {
                xCounter++;
            }
            else if(board[i] == 'o')
            {
                yCounter++;
            }
        }
    }
    if(xCounter==3)
    {
        return 'x';
    }
    else if(yCounter==3)
    {
        return 'y';
    }

    for(int i = 0; i<8; i++)
    {
        xCounter = 0;
        yCounter = 0;
        if(i%2 ==0)
        {
            if(board[i] == 'x')
            {
                xCounter++;
            }
            else if(board[i] == 'o')
            {
                yCounter++;
            }
        }
    }
    if(xCounter==3)
    {
        return 'x';
    }
    else if(yCounter==3)
    {
        return 'y';
    }

    return 'N';//No one win until now
}

// void getSymbol(char symbol)
// {
//     int position;
//     printf("Enter the position: ");
//     scanf("%d", &position);
//     putSymbol(position, symbol);
// }

// void putSymbol(int position, char symbol)
// {
//     board[position] = symbol;
// }

int old_main()
{
    // char role = 'x';
    // // clearScrean();
    // // DrawBoard();
    // char result ='N';

    // role = 'x';
    // while(result == 'N')
    // {    
    //     if(role == 'x')
    //     {
    //         role = 'o';
    //     }
    //     else if(role=='o')
    //     {
    //         role = 'x';
    //     }
    //     getSymbol(role);
    //     clearScrean();
    //     DrawBoard();

    //     result = checkResult();
    //     if(result == 'x')
    //     {
    //         printf("x is win");
    //     }
    //     else if(result == 'y')
    //     {
    //         printf("y is win");
    //     }
    // }
    
    return 0;
}