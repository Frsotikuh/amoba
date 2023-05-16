#ifndef PALYA_HPP
#define PALYA_HPP

#include "tile.hpp"

class palya: public  tile{

public:
    palya(int x, int y, int xM, int yM, bool CIR, bool TRI, bool rajta);

    virtual void torol();
    virtual void kirajzol();

    bool rajta;
};

#endif // PALYA_HPP
