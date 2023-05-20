#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP




class gamemaster
{
public:
    gamemaster(bool menu, bool singlemode, bool multimode, bool gamestart, bool gameend, bool pl1turn, bool pl2turn, bool pl1win, bool pl2win);



    virtual void gameprep();
    virtual void handlegame(gamemaster* g);
    virtual int randomstart(int random);

    virtual bool getpl2turn();
    virtual bool getpl1turn();







protected:
    bool menu, singlemode, multimode, gamestart, gameend, pl1turn, pl2turn, pl1win, pl2win;
};

#endif // GAMEMASTER_HPP
