#include "Potter.h"

potter::potter(int y, int x, unsigned char ch) :player(y,x,ch) {

}
potter::potter(){ch='M';}

potter::~potter(){}
//in the movement of the potter, the input from the keyboard is controlled and depending on the arrow pressed (up, down..)
// calls the corresponding methods move_up,move_down to move the player his movement returns true/false, so that if potter moves,
// malfoy will also move. mainly for the case that he moves in a direction that has a wall, then it returns  false and Malfoy
//doesn't move either, it's considered an invalid key
bool potter::move(vector<vector<char>> &map,int input)
{
    switch(input){
        case 1:
            if(map[y][x-1]!= 'L' && map[y][x-1]!= '*'){
                move_left(map);
                return true;}

            break;

        case 2:
            if(map[y-1][x]!= 'L' && map[y-1][x]!= '*'){
                move_up(map);
                return true;}

            break;

        case 3:
            if(map[y][x+1]!= 'L' && map[y][x+1]!= '*'){
                move_right(map);
                return true;}
            break;


        case 4:
            if(map[y+1][x]!= 'L' && map[y+1][x]!= '*'){
                move_down(map);
                return true;}

            break;
        case ' ':
            map[y][x]=ch;
            return true;
            break;

    }return false;
}

