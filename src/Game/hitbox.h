//hitbox class that can be used to determine when two objects are touching.
//All numbered values are by pixel

#ifndef HITBOX_H
#define HITBOX_H

class Hitbox{

    public:
       
        Hitbox(int x_ = 0, int y_ = 0, int w = 1, int h = 1); //Constructor for a Hitbox. Defaults to a small hitobox in the corner          
        void set_xy(int x_, int y_);                          //Function that sets the xy placement of the hitbox
        void set_wh(int w, int h);                            //Function that sets the height and width of the hitbox
        bool is_touching(const Hitbox & other);               //Function that checks to see if another hitbox is touching it

    private:
        int x;                     //x position on map
        int y;                     //y position on map
        int width;                 //width of hitbox     
        int height;                //height of hit box
};

#endif
