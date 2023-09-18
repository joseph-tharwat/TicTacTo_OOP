
#include "main.h"

using namespace std;

int main()
{
    board *my_board = new board();
    player *p1 = new player(PLAYER_1_NAME, PLAYER_1_SYMBOL);
    player *p2 = new player(PLAYER_2_NAME, PLAYER_2_SYMBOL);
    game *my_game = new game(p1, p2);   
    
    while(!my_game->isGameEnd() && my_game->getStaus() == DRAW)
    {
        my_board->DrawBoard();
        while(!p1->play());
        if(my_game->isGameEnd() || my_game->checkResult() != DRAW)
        {
            break;
        }

        my_board->DrawBoard();
        while(!p2->play());
        my_game->checkResult();
    }

    my_board->DrawBoard();
    my_game->displayResult();
}