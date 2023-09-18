#include "player.h"

using namespace std;

player::player(string player_name, char player_symbol): name(player_name), symbol(player_symbol)
{
    boardPtr = board::getBoardInstance();  
};

bool player::play()
{
    cout<<name<<" please enter position you want to play in: "<<endl;
    int position;
    cin>>position;
    //check valid range
    if(position<9)
    {
        //check valid position
        if(boardPtr->getSymbol(position) >= FISRT_POSITION && boardPtr->getSymbol(position) <= LAST_POSITION)
        {
            boardPtr->setSymbol(symbol, position);
        }
        else
        {
            cout<<"envalid position"<<endl;
            return false;
        }
    }
    else
    {
        cout<<"Position out of range"<<endl;
        return false;
    }

    return true;
}


string player::getName()
{
    return name;
}

char player::getSymbol()
{
    return symbol;
}



