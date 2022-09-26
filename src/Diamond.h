#ifndef CPPGAME_DIAMOND_H
#define CPPGAME_DIAMOND_H
#include <iostream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <ncurses.h>
#include <panel.h>
#include "Object.h"
//diamond class is child of object class,this way it inherits x and y variables for its place on map and character ch for diamond animation
//diamond has no movement function,because its movement is controlled by engine class
using namespace std;
class diamond:public object
{
public:
    diamond();
    diamond(int y, int x, unsigned char ch);
    virtual ~diamond();
};


#endif //CPPGAME_DIAMOND_H
