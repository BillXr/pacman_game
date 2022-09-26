#ifndef CPPGAME_OBJECT_H
#define CPPGAME_OBJECT_H
#include <iostream>
//the class contains the x,y and char ch coordinates, as every object in the game has these attributes.
//It is inherited by the game objects (diamond, potter, malfoy) together with the getters, setters of the characteristics.
using namespace std;
class object{
protected:
    int y,x;
    unsigned char ch;
public:

    object(int y, int x, unsigned char ch);
    object();
    virtual ~object();


    int getY() const;
    void setY(int y);
    int getX() const;
    void setX(int x);
    unsigned char getCh() const;
    void setCh(unsigned char ch);

};
#endif //CPPGAME_OBJECT_H
