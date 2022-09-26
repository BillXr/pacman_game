#ifndef CPPGAME_ENGINE_H
#define CPPGAME_ENGINE_H

#include <iostream>
#include <ctime>
#include <ncurses.h>
#include <vector>
#include <fstream>
#include "Potter.h"
#include "Malfoy.h"
#include "Diamond.h"
#include "Object.h"
#include "Player.h"
using namespace std;
//the main game management class, the engine is responsible for loading the map into the program, displaying it, placing players in random positions, checking if
//some player reach the diamond and win and generally for running the game
class engine{
private:
    bool win= false;
    bool loss= false;
    bool end_game= false;
    vector<vector<char>> map;
    int counter=0;


public:
    engine();
    void load_map(vector<vector<char>> &map,string file);
    void move(vector<vector<char>> & map,potter & p, malfoy & m,diamond &d,int);
    void begin(vector<vector<char>> & map,potter & p, malfoy & m, diamond &d);
    void play(vector<vector<char>> & map,potter & p, malfoy & m,diamond &d);
    void move_diamond(diamond &d,int,vector<vector<char>> &map);
    void place_potter(vector<vector<char>> & map,potter & p, char m,char d);
    void place_malfoy(vector<vector<char>> & map,malfoy &m,char p,char d);
    void place_diamond(vector<vector<char>> & map,diamond &d,char p,char m);
    void check(vector<vector<char>> & map,potter & p, malfoy & m,diamond &d);
    void show_map(vector<vector<char>> &map);
    bool get_loss();
    bool get_win();
    bool get_end();
};

#endif //CPPGAME_ENGINE_H
