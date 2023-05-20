#include "tile.hpp"
#include "widget.hpp"
#include "graphics.hpp"
#include "gamemaster.hpp"

using namespace std;
using namespace genv;

tile::tile(int x, int y, int xM, int yM, bool CIR, bool XLET, bool rajta): widget(x,y), xM(xM), yM(yM), CIR(CIR), XLET(XLET), rajta(rajta)
{
}

const int width = 1000;
const int height = 1000;

bool tile::getrajta()
{
    return rajta;
}

bool tile::getCIR()
{
    return CIR;
}

bool tile::getXLET()
{
    return XLET;
}

void tile::setCIR()
{
    CIR = true;

}

void tile::setXLET()
{
    XLET = true;

}

int tile::getposx()
{
    return x;
}

int tile::getposy()
{
    return y;
}

void tile::clearrajta()
{
    rajta = false;
}

int tile::getxM()
{
    return xM;
}

int tile::getyM()
{
    return yM;
}

void tile::torol()
{
    gout << color(0,0,0) << move_to(0,0) << box(width,height) << refresh;
}

void tile::kirajzol() //50 size
{

    gout << color(255,255,255) << move_to(x,y) << box_to(x+50,y+50);
    gout << color(0,0,0) << move_to(x+2,y+2) << box_to(x+48,y+48);

}


void tile::previewround(bool pl1turn, bool pl2turn, int r)
{
    gout << color(255,255,255) << move_to(930,200) << box_to(1130,400);
    gout << color(0,0,0) << move_to(940,210) << box_to(1120,390);
    gout << color(255,255,255) << move_to(930,180) << text("Soron levo jatekos: ");

    if(pl1turn)
    {
        gout << color(255,0,0) << move_to(960,240) << line_to(1100,370);
        gout << color(255,0,0) << move_to(960,239) << line_to(1100,369);
        gout << color(255,0,0) << move_to(960,238) << line_to(1100,368);
        gout << color(255,0,0) << move_to(960,237) << line_to(1100,367);
        gout << color(255,0,0) << move_to(960,236) << line_to(1100,366);
        gout << color(255,0,0) << move_to(960,235) << line_to(1100,365);
        gout << color(255,0,0) << move_to(960,234) << line_to(1100,364);
        gout << color(255,0,0) << move_to(960,233) << line_to(1100,363);
        gout << color(255,0,0) << move_to(960,232) << line_to(1100,362);
        gout << color(255,0,0) << move_to(960,231) << line_to(1100,361);
        gout << color(255,0,0) << move_to(960,230) << line_to(1100,360);

        gout << color(255,0,0) << move_to(1100,240) << line_to(960,370);
        gout << color(255,0,0) << move_to(1100,239) << line_to(960,369);
        gout << color(255,0,0) << move_to(1100,238) << line_to(960,368);
        gout << color(255,0,0) << move_to(1100,237) << line_to(960,367);
        gout << color(255,0,0) << move_to(1100,236) << line_to(960,366);
        gout << color(255,0,0) << move_to(1100,235) << line_to(960,365);
        gout << color(255,0,0) << move_to(1100,234) << line_to(960,364);
        gout << color(255,0,0) << move_to(1100,233) << line_to(960,363);
        gout << color(255,0,0) << move_to(1100,232) << line_to(960,362);
        gout << color(255,0,0) << move_to(1100,231) << line_to(960,361);
        gout << color(255,0,0) << move_to(1100,230) << line_to(960,360);

    }

    if(pl2turn)
    {
        for (int i=-r; i<=r; i++)
                {
                    for (int j=-r; j<=r; j++)
                    {
                        if (i*i+j*j<=r*r)
                        {
                            if (i*i+j*j<=(r-10)*(r-10))
                            {
                                gout<<move_to(1030 + i, 300 + j)<<color(0,0,0)<< dot;
                            }
                            else
                            {
                                gout<<move_to(1030 + i, 300 + j)<<color(0,0,255)<<dot;
                            }

                        }
                    }
                }
    }




}

void tile::previewclick(event ev)
{
    if(ev.pos_x > x+3 and ev.pos_y > y+3 and ev.pos_x < x+47 and ev.pos_y < y+47 and XLET == false and CIR == false)
    {
        gout << move_to(x+22,y+22) << color(255,255,255) << box_to(x+27,y+27);
        if(ev.button == 1)
        {
            rajta = true;
        }
        else{
            rajta = false;
        }


    }

    /*
    if(rajta and CIR == false and ev.button == 1)
    {
        XLET = true;
    }

    if(rajta and XLET == false and ev.button == 1)
    {
        CIR = true;
    }
    */

}

void tile::xdraw()
{
    if(CIR == false and XLET == true)
    {
        gout << move_to(x+15,y+15) << color(255,0,0) << line_to(x+35,y+35) << move_to(x+35,y+15) << line_to(x+15,y+35);

        gout << move_to(x+15,y+16) << color(255,0,0) << line_to(x+35,y+36) << move_to(x+35,y+16) << line_to(x+15,y+36);

        gout << move_to(x+15,y+14) << color(255,0,0) << line_to(x+35,y+34) << move_to(x+35,y+14) << line_to(x+15,y+34);

    }
}

void tile::circdraw(int r)
{


    if(XLET == false and CIR == true)
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

bool tile::checkwinkor(vector<tile*> p)
{
    bool kor = false;


    for(size_t i = 1; i < p.size(); i++)
    {

        if(p[i]->getCIR() == true and p[i+1]->getCIR() == true and p[i+2]->getCIR() == true and p[i+3]->getCIR() == true and p[i+4]->getCIR() == true )
        {
            kor = true;
        }

        else{
            kor = false;
        }
    }


    return kor;

}


