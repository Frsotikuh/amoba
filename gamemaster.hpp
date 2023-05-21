#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "graphics.hpp"

using namespace genv;

class gamemaster
{
public:
    gamemaster(bool menu, bool singlemode, bool multimode, bool gamestart, bool gameend, bool pl1turn, bool pl2turn, bool pl1win, bool pl2win, bool horwin, bool verwin);



    virtual void gameprep();
    virtual void handlegame();
    virtual int randomstart(int random);
    virtual bool quit();

    virtual bool getpl2turn();
    virtual bool getpl1turn();







protected:
    bool menu, singlemode, multimode, gamestart, gameend, pl1turn, pl2turn, pl1win, pl2win, horwin, verwin;
};

#endif // GAMEMASTER_HPP
