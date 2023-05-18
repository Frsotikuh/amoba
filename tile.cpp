#include "tile.hpp"
#include "widget.hpp"
#include "graphics.hpp"

using namespace std;
using namespace genv;

tile::tile(int x, int y, int xM, int yM, bool CIR, bool XLET, bool rajta): widget(x,y), xM(xM), yM(yM), CIR(CIR), XLET(XLET), rajta(rajta)
{
}

const int width = 1000;
const int height = 1000;

void tile::torol()
{
    gout << color(0,0,0) << move_to(0,0) << box(width,height);
}

void tile::kirajzol() //50 size
{

    gout << color(255,255,255) << move_to(x,y) << box_to(x+50,y+50);
    gout << color(0,0,0) << move_to(x+2,y+2) << box_to(x+48,y+48);

}

void tile::previewclick(event ev)
{
    if(ev.pos_x > x+1 and ev.pos_y > y+1 and ev.pos_x < x+49 and ev.pos_y < y+49 and XLET == false and CIR == false)
    {
        gout << move_to(x+22,y+22) << color(255,255,255) << box_to(x+27,y+27);
        if(ev.button == 1)
        {
            rajta = true;
        }

    }


    if(rajta and CIR == false and ev.button == 1)
    {
        XLET = true;
    }

    if(rajta and XLET == false and ev.button == 1)
    {
        CIR = true;
    }

}

void tile::xdraw()
{
    if(rajta and CIR == false and XLET == true)
    {
        gout << move_to(x+15,y+15) << color(255,0,0) << line_to(x+35,y+35) << move_to(x+35,y+15) << line_to(x+15,y+35);

        gout << move_to(x+15,y+16) << color(255,0,0) << line_to(x+35,y+36) << move_to(x+35,y+16) << line_to(x+15,y+36);

        gout << move_to(x+15,y+14) << color(255,0,0) << line_to(x+35,y+34) << move_to(x+35,y+14) << line_to(x+15,y+34);

    }
}

void tile::circdraw(int r)
{


    if(rajta)
    {
        for (int i=-r; i<=r; i++)
                {
                    for (int j=-r; j<=r; j++)
                    {
                        if (i*i+j*j<=r*r)
                        {
                            if (i*i+j*j<=(r-3)*(r-3))
                            {
                                gout<<move_to(x+25 + i, y+25 + j)<<color(0,0,0)<< dot;
                            }
                            else
                            {
                                gout<<move_to(x+25 + i, y+25 + j)<<color(0,0,255)<<dot;
                            }

                        }
                    }
                }
    }
}

tile* tile::ujmezo(int x, int y, int xM, int yM){

    return new tile(x,y, xM, yM, false, false,false);
}


