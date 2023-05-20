#include "gamemaster.hpp"
#include "graphics.hpp"
#include "tile.hpp"
#include "menuin.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <time.h>


using namespace genv;
using namespace std;

gamemaster::gamemaster(bool menu, bool singlemode, bool multimode, bool gamestart, bool gameend, bool pl1turn, bool pl2turn, bool pl1win, bool pl2win):
    menu(menu), singlemode(singlemode),multimode(multimode),gamestart(gamestart), gameend(gameend), pl1turn(pl1turn), pl2turn(pl2turn), pl1win(pl1win), pl2win(pl2win)
{}







bool gamemaster::getpl1turn()
{
    return pl1turn;
}

bool gamemaster::getpl2turn()
{
    return pl2turn;
}

void gamemaster::gameprep()
{
    gout.open(1200,1000);
}

tile* ujmezo(int x, int y, int xM, int yM){

    return new tile(x,y, xM, yM, false, false,false);
}

int gamemaster::randomstart(int random)
{
    int tracker = 0;
    if(random > 51)
    {
        tracker = 0;
    }
    else{
        tracker = -1;
    }

    return tracker;
}


void gamemaster::handlegame(gamemaster* g)
{
    int const width = 1200;
    int const height = 1000;

    event ev;

    vector<tile*> p;
    menuin* m = new menuin(true);


    int distx = 0;
    int disty = 0;
    int tracker = -1;
    srand(time(0));
    int random = rand() % 100;
    bool nocheat = false;
    bool kor = false;
    bool xes = false;

    int checkX = 0;
    int checkY = 0;



    for(int j = 0; j < 15; j++) //STAGE SET UP
    {
        for(int i = 0; i < 15; i++)
        {

            p.push_back(ujmezo(130+distx,130+disty,j,i));
            distx += 48;

        }
        distx = 0;
        disty += 50;
    }




    g->gameprep();





    gout << move_to(0,0) << color(0,0,0) << box_to(width,height);
     //NO INSTANT PICK


    gin.timer(1500);



    while(gin >> ev) {


        if(ev.type == ev_timer)
        {
            gamestart = true;
        }


        if(m->getmenustate() == true)
        {
            m->menukirajzol(ev);
            m->getpl2select(ev);
            m->getquitselect(ev);

            if(m->getpl2select(ev))
            {
                m->turnoffmenu();
                multimode = true;

            }

        }

        if(multimode and gamestart)
        {

            for( size_t i = 0; i < p.size(); i++)
            {


                p[i] -> kirajzol();
                p[i] -> previewclick(ev);
                p[i] -> getrajta();
                p[i] -> getCIR();
                p[i] -> getXLET();





                if(pl1turn == true)
                {

                   if(p[i] -> getrajta() == true and p[i]-> getCIR() == false and ev.button == 1)
                   {
                       p[i]->setXLET();

                   }


                }

                if(pl2turn == true)
                {

                    if(p[i] -> getrajta() == true and p[i]-> getXLET() == false and ev.button == 1)
                    {
                        p[i]->setCIR();


                    }
                }

                p[i] -> xdraw();
                p[i] -> circdraw(15);


                if(kor)
                {
                    gamestart = false;
                }

            }

            p[1] -> previewround(pl1turn,pl2turn,70);


        }

        gout << refresh;

        if(gamestart == true)  //ROUND CHECKER
        {

            if(tracker % 2 != 0)
            {
                pl1turn = true;
                pl2turn = false;
            }
            else{
                pl1turn = false;
                pl2turn = true;
            }


            //NO BORDER CLICKING CHEAT
            for(size_t i = 0; i < p.size();i++)
            {
                if(p[i]->getrajta() == true)
                {
                    nocheat = true;
                    p[i] -> clearrajta();
                }

            }

            if(nocheat == true)
            {
                tracker++;
                nocheat = false;
                cout << tracker << endl;
            }

            for(int j = 0; j < 15; j++) //HORIZONTAL CHECK
            {
                for(int i = 0; i < 15; i++)
                {

                    if(p[i+(j*15)]->getCIR() and p[i+1+(j*15)]->getCIR() and p[i+2 + (j*15)]->getCIR() and p[i+3 + (j*15)]->getCIR() and p[i+4 + (j*15)]->getCIR())
                    {
                        kor = true;
                    }

                    if(p[i+(j*15)]->getXLET() and p[i+1+(j*15)]->getXLET() and p[i+2 + (j*15)]->getXLET() and p[i+3 + (j*15)]->getXLET() and p[i+4 + (j*15)]->getXLET())
                    {
                        xes = true;
                    }

                }


            }

        }


    }


}
