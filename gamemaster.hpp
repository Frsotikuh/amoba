#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "graphics.hpp"

using namespace genv;

class gamemaster
{
public:
    gamemaster(bool menu, bool singlemode, bool multimode, bool gamestart, bool gameend, bool pl1turn, bool pl2turn);



    virtual void gameprep();
    virtual void handlegame(gamemaster* g);






protected:
    bool menu, singlemode, multimode, gamestart, gameend, pl1turn, pl2turn;
};

#endif // GAMEMASTER_HPP
