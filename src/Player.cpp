#include "Player.h"

player::player(int y, int x, unsigned char ch): object(y,x,ch)  {

}
player::player() {}

player::~player(){}

//the check functions check if there is a wall in the desired location we want to go to, if there is it returns false ,
//while if the location is empty it returns true
bool player::check_move_left(vector<vector<char>> & map)
{
    if(map[y][x - 1] == '*')
        return false;
    else
        return true;
}

bool player::check_move_up(vector<vector<char>> & map){
    if(map[y - 1][x] == '*')
        return false;
    else
        return true;
}
bool player::check_move_down(vector<vector<char>> & map){
    if(map[y + 1][x] == '*')
        return false;
    else
        return true;
}
bool player::check_move_right(vector<vector<char>> & map){
    if(map[y][x + 1] == '*')
        return false;
    else
        return true;
}
//then the functions move_left,move_up,move_right,move_down call the corresponding methods to check the new position, if they return true then it changes the coordinates
//to the object and places the character ch of the player in the new x,y. In the old position it leaves the space. If there is a wall in the new direction, then the check function,
//will return false and the object will not be moved.

void player::move_left(vector<vector<char>> & map){
    if(check_move_left(map)){
        map[y][x] = ' ';
        map[y][x - 1] = ch;
        x--;
    }
}

void player::move_up(vector<vector<char>> & map){
    if(check_move_up(map)){
        map[y][x] = ' ';
        map[y - 1][x] = ch;
        y--;
    }
}
void player::move_down(vector<vector<char>> & map){
    if(check_move_down(map)){
        map[y][x] = ' ';
        map[y + 1][x] = ch;
        y++;
    }
}
void player::move_right(vector<vector<char>> & map){
    if(check_move_right(map)){
        map[y][x] = ' ';
        map[y][x + 1] = ch;
        x++;
    }
}

