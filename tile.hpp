#ifndef TILE_H
#define TILE_H

#include "widget.hpp"
#include "graphics.hpp"
#include "gamemaster.hpp"

using namespace genv;

class tile: public  widget{

public:
    tile(int x, int y, int xM, int yM, bool CIR, bool XLET, bool rajta);

    virtual void torol();
    virtual void kirajzol();
    virtual void previewclick(event ev);
    virtual void xdraw();
    virtual void circdraw(int r);
    virtual tile* ujmezo(int x, int y, int xM, int yM);
    virtual void previewround(bool pl1turn, bool pl2turn, int r);
    virtual void winnerdrawvertical(bool pl1win, bool pl2win);

    virtual bool getrajta();
    virtual bool getCIR();
    virtual bool getXLET();
    virtual int getxM();
    virtual int getyM();
    virtual int getposx();
    virtual int getposy();


    virtual void setCIR();
    virtual void setXLET();
    virtual void clearrajta();



    int xM,yM;
    bool CIR,XLET;
    bool rajta;
};

#endif // TILE_H
