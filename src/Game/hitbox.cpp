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
bool Hitbox::is_touching(const Hitbox & other) const{

    bool width_in_range;              //Boolean that determines if the widths of the two hitboxs are in range with each other
    bool height_in_range;             //Boolean that determines if the heights of the two hitboxs are in range with each othe

    //check and see which hitbox has a smaller x range
    if (width < other.width)
    {
        if ((x <= other.x + other.width and x >= other.x) or \
           (x + width <= other.x + other.width and x + width >= other.x))
        {    
             width_in_range = true;
        }
    }
    else
    {
        if ((other.x <= x + width and other.x >= x) or \
           (other.x + other.width <= x + width and other.x + other.width >= x))
        {
            width_in_range = true;
        }
    }
    
    //check and see which hitbox has a smaller y range
    if (height < other.height)
    {
        if((y <= other.y + other.height and y >= other.y) or \
          (y + height <= other.y + other.height and y + height >= other.y))
        {
            height_in_range = true;
        }
    }
    else
    {
        if((other.y <= y + height and other.y >= y) or \
          (other.y + other.height <= y + height and other.y + other.height >= y))
        {
            height_in_range = true;
        }
    }

    return width_in_range and height_in_range; 
}

//Function that checks to see if a certain side is touched
bool Hitbox::touching_side(const Hitbox & other, Direction to_check) const{
    if (!is_touching(other))
        return false;

    if (to_check == Left){
        if (x <= other.x + other.width and x >= other.x)
            return true;
    }

    if (to_check == Right){
        if (x + width <= other.x + other.width and x + width >= other.x)
            return true;
    }
    if (to_check == Up){
        if (y <= other.y + other.height and y >= other.y)
            return true;
    }
    if (to_check == Down){
        if (y + height <= other.y + other.height and y + height >= other.y)
            return true;
    }
    return false;    

}







