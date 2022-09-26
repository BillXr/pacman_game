#ifndef CPPGAME_MALFOY_H
#define CPPGAME_MALFOY_H

#include <iostream>
#include <ctime>
#include "Player.h"
#include <ncurses.h>
#include <panel.h>
#include <climits>
#include <vector>
//the malfoy class inherits the player class (which also inherited the object), so the x,y coordinates of the malfoy ch character are available to him
//as well as the functions for move, move down..
using namespace std;
class malfoy:public player
{
private:
    vector<vector<int>> dist;
public:
    malfoy();
    virtual ~malfoy();
    malfoy(int y, int x, unsigned char ch);
    void move(object player, vector<vector<char>> & map);
    void initDistances(vector<vector<char>> & map);
    void calculateDistances(object & p, vector<vector<char>> & map);
    bool checkDistMap(vector<vector<char>> & map);
};
#endif //CPPGAME_MALFOY_H
