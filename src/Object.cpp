#include "Object.h"

object::object(int y, int x, unsigned char ch)  {
    this->y=y;
    this->x=x;
    this->ch=ch;

}

object::object() {

}
object::~object(){}


int object::getY() const {
    return y;
}

void object::setY(int y) {
    object::y = y;
}

int object::getX() const {
    return x;
}

void object::setX(int x) {
    object::x = x;
}

unsigned char object::getCh() const {
    return ch;
}

void object::setCh(unsigned char ch) {
    object::ch = ch;
}

