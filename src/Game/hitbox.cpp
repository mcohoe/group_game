//implementation of the hitbox class

#include "hitbox.h"

//Constructor for a Hitbox. Defaults to a small hitobox in the corner
Hitbox::Hitbox(int x_, int y_, int w, int h){
    set_xy(x_, y_);
    set_wh(w, h);
}

//Function that sets the xy placement of the hitbox
void Hitbox::set_xy(int x_, int y_){
    x = x_;
    y = y_;
}

//Function that sets the height and width of the hitbox
void Hitbox::set_wh(int w, int h){
    width = w;
    height = h;
}

//Function that checks to see if another hitbox is touching it
bool Hitbox::is_touching(const Hitbox & other){
    if (((x < other.x + other.width and x > other.x) or \
         (x + width < other.x + other.width and x + width > other.x)) and\
         ((y < other.y + other.height and y > other.y) or \
         (y + height < other.y + other.height and y + height > other.y))){
       return true;
    }
    else return false;
}