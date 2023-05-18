#include "gamemaster.hpp"
#include "menuin.hpp"
#include "graphics.hpp"

using namespace genv;


const int x = 600;
const int y = 500;

menuin::menuin(bool inmenu):
    inmenu(inmenu)
{

}

bool menuin::getmenustate()
{
    return inmenu;
}

bool menuin::getquitselect(event ev)
{
    bool select = false;
    if(ev.pos_x > x - 98 and ev.pos_x < x+98 and ev.pos_y > y+101 and ev.pos_y < y + 148 and ev.button == 1)
    {
        select = true;
    }
    else{
        select = false;
    }
    return select;
}


bool menuin::turnoffmenu()
{
    inmenu = false;
    return inmenu;
}

bool menuin::getpl2select(event ev)
{
    bool select = false;
    if(ev.pos_x > x - 98 and ev.pos_x < x+98 and ev.pos_y > y+2 and ev.pos_y < y +48 and ev.button == 1)
    {
        select = true;
    }
    else{
        select = false;
    }
    return select;
}

void menuin::menukirajzol(event ev)
{
    gout << move_to(550,350) << color(255,255,255) << text("Amobae Game");

    gout << move_to(x-98,y-98) << color(0,0,0) << box_to(x+98,y-52);


    gout << move_to(x-100,y-100) << color(120,120,120) << box_to(x+100,y-50);
    gout << move_to(x-98,y-98) << color(0,0,0) << box_to(x+98,y-52);
    gout << move_to(x-60,y-70) << color(120,120,120) << text("S T A R T  (1 P)");







    if(ev.pos_x > x-98 and ev.pos_x < x+98 and ev.pos_y > y+1 and ev.pos_y < y+48)
    {
        gout << move_to(x-100,y) << color(255,255,0) << box_to(x+100,y+50);
        gout << move_to(x-98,y+2) << color(0,0,0) << box_to(x+98,y+48);
        gout << move_to(x-60,y+30) << color(255,255,0) << text("S T A R T  (2 P)");
    }
    else{
        gout << move_to(x-100,y) << color(255,255,255) << box_to(x+100,y+50);
        gout << move_to(x-98,y+2) << color(0,0,0) << box_to(x+98,y+48);
        gout << move_to(x-60,y+30) << color(255,255,255) << text("S T A R T  (2 P)");
    }

    if(ev.pos_x > x-98 and ev.pos_x < x+98 and ev.pos_y > y+101 and ev.pos_y < y+148)
    {
        gout << move_to(x-100,y+100) << color(255,255,0) << box_to(x+100,y+150);
        gout << move_to(x-98,y+102) << color(0,0,0) << box_to(x+98,y+148);
        gout << move_to(x-30,y+130) << color(255,255,0) << text("Q U I T");

    }
    else{
        gout << move_to(x-100,y+100) << color(255,255,255) << box_to(x+100,y+150);
        gout << move_to(x-98,y+102) << color(0,0,0) << box_to(x+98,y+148);
        gout << move_to(x-30,y+130) << color(255,255,255) << text("Q U I T");
    }



}
