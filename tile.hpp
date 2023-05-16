#ifndef TILE_H
#define TILE_H

#include "widget.hpp"

class tile: public  widget{

public:
    tile(int x, int y, int xM, int yM, bool CIR, bool TRI, bool rajta);

    virtual void torol();
    virtual void kirajzol();

    bool rajta;
};

#endif // TILE_H
