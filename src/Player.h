#ifndef CPPGAME_PLAYER_H
#define CPPGAME_PLAYER_H
#include <iostream>
#include <vector>
#include "Object.h"
using namespace std;
//the player class inherits object, and includes the basic functions for moving the game's moving objects (Potter, Malfoy).
//Functions for moving to top, bottom, left, right as well as functions to check if this movement can be done (that is, if there is no wall).
// The potter and malfoy classes inherit the player
class player:public object
{
public:
    player(int y, int x, unsigned char ch);
    player();
    virtual ~player();


    bool check_move_up(vector<vector<char>> & map);
    bool check_move_down(vector<vector<char>> & map);
    bool check_move_right(vector<vector<char>> & map);
    bool check_move_left(vector<vector<char>> & map);

    void move_up(vector<vector<char>> & map);
    void move_down(vector<vector<char>> & map);
    void move_right(vector<vector<char>> & map);
    void move_left(vector<vector<char>> & map);
};

#endif //CPPGAME_PLAYER_H
