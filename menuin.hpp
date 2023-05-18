#ifndef MENUIN_H
#define MENUIN_H


#include "graphics.hpp"

using namespace genv;

class menuin
{
public:
    menuin(bool inmenu);

    virtual void menukirajzol(event ev);

    virtual bool getpl2select(event ev);
    virtual bool getquitselect(event ev);


    virtual bool getmenustate();
    virtual bool turnoffmenu();


protected:
    bool inmenu;

};

#endif // MENUIN_H
