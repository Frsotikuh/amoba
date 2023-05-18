#ifndef TILE_H
#define TILE_H

#include "widget.hpp"
#include "graphics.hpp"

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


    int xM,yM;
    bool CIR,XLET;
    bool rajta;
};

#endif // TILE_H
