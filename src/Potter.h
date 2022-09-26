#ifndef CPPGAME_POTTER_H
#define CPPGAME_POTTER_H
#include <iostream>
#include "Player.h"

using namespace std;
//the potter class inherits the player class (which also inherited the object), so the potter's ch character has the x,y coordinates at its disposal
//as well as the functions for movement moveup,movedown..
class potter:public player
{
public:
    potter();
    potter(int, int, unsigned char);
    virtual ~potter();
    bool move(vector<vector<char>> &map,int input);
};
#endif //CPPGAME_POTTER_H
