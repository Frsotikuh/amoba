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

gamemaster::gamemaster(bool menu, bool singlemode, bool multimode, bool gamestart, bool gameend, bool pl1turn, bool pl2turn, bool pl1win, bool pl2win, bool horwin, bool verwin):
    menu(menu), singlemode(singlemode),multimode(multimode),gamestart(gamestart), gameend(gameend), pl1turn(pl1turn), pl2turn(pl2turn), pl1win(pl1win), pl2win(pl2win), horwin(horwin), verwin(verwin)
{}


bool gamemaster::quit()
{
    bool kilep = false;
    if(singlemode == false and multimode == false and menu == false)
    {
        kilep = true;
    }
    else{
        kilep = false;
    }
    return kilep;
}

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


void gamemaster::handlegame()
{
    int const width = 1200;
    int const height = 1000;

    event ev;

    vector<tile*> p;
    menuin* m = new menuin(true);


    int distx = 0;
    int disty = 0;
    int tracker = -1;
    int melyiki = 0;
    int melyikj = 0;


    bool nocheat = false;






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




   gameprep();





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
            if(m->getquitselect(ev))
            {
                menu = false;
                singlemode = false;
                multimode = false;
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
                p[i] -> xdraw();
                p[i] -> circdraw(15);

                if(pl1turn == true)  //SIGSEGV CRASH ???
                {

                   if(p[i] -> getrajta() == true and p[i]-> getCIR() == false and p[i] -> getXLET() == false and ev.button == 1)
                   {

                       p[i]->setXLET();
                   }
                }


                if(pl2turn == true) //SIGSEGV CRASH ???
                {
                    if(p[i] -> getrajta() == true and p[i]-> getXLET() == false and p[i]->getCIR() == false and ev.button == 1)
                    {
                       p[i]->setCIR();
                    }
                }


                if(p[i]->getrajta() == true) //NO BORDER CLICKING
                {
                    nocheat = true;
                    p[i] -> clearrajta();
                }

                if(pl2win or pl1win)
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



            if(nocheat == true)
            {
                tracker++;
                nocheat = false;
                cout << tracker << endl;
            }

            for(int j = 0; j < 15; j++) //WIN CHECK
            {
                for(int i = 0; i < 15; i++)
                {
                    //HORIZONTAL CHECK

                    if(p[i+(j*15)]->getCIR() and p[i+1+(j*15)]->getCIR() and p[i+2 + (j*15)]->getCIR() and p[i+3 + (j*15)]->getCIR() and p[i+4 + (j*15)]->getCIR())
                    {

                        pl2win = true;
                        horwin = true;
                        melyiki = i;
                        melyikj = j;

                    }

                    if(p[i+(j*15)]->getXLET() and p[i+1+(j*15)]->getXLET() and p[i+2 + (j*15)]->getXLET() and p[i+3 + (j*15)]->getXLET() and p[i+4 + (j*15)]->getXLET())
                    {

                        pl1win = true;
                        horwin = true;
                        melyiki = i;
                        melyikj = j;
                    }


                    /*
                    //VERTICAL CHECK
                    if((p[i]->getCIR() and p[i+16]->getCIR() and p[i+32]->getCIR() and p[i+48]->getCIR() and p[i+64]->getCIR())
                            or (p[i+16]->getCIR() and p[i+32]->getCIR() and p[i+48]->getCIR() and p[i+64]->getCIR() and p[i+80]->getCIR())
                            or (p[i+128]->getCIR() and p[i+144]->getCIR() and p[i+160]->getCIR() and p[i+176]->getCIR() and p[i+192]->getCIR())
                            or (p[i+160]->getCIR() and p[i+176]->getCIR() and p[i+192]->getCIR() and p[i+208]->getCIR() and p[i+224]->getCIR()))
                    {
                        pl2win = true;
                    }

                    if((p[i]->getXLET() and p[i+16]->getXLET() and p[i+32]->getXLET() and p[i+48]->getXLET() and p[i+64]->getXLET())
                            or (p[i+80]->getXLET() and p[i+96]->getXLET() and p[i+112]->getXLET() and p[i+128]->getXLET() and p[i+144]->getXLET())
                            or (p[i+160]->getXLET() and p[i+176]->getXLET() and p[i+192]->getXLET() and p[i+208]->getXLET() and p[i+224]->getXLET()) )
                    {
                        pl1win = true;
                    }
                    */



                }


            }

            for(int c = 0; c < 15; c++)
            {
                for(int k = 0; k < 15; k++)
                {
                    if(p[k+(c*15)]->getCIR() and p[k+((c+1)*15)]->getCIR() and p[k+((c+2)*15)]->getCIR() and p[k+((c+3)*15)]->getCIR() and p[k+((c+4)*15)]->getCIR())
                    {
                        pl2win = true;
                        verwin = true;
                        melyiki = k;
                        melyikj = c;
                    }

                    if(p[k+(c*15)]->getXLET() and p[k+((c+1)*15)]->getXLET() and p[k+((c+2)*15)]->getXLET() and p[k+((c+3)*15)]->getXLET() and p[k+((c+4)*15)]->getXLET())
                    {
                        pl1win = true;
                        verwin = true;
                        melyiki = k;
                        melyikj = c;
                    }
                }
            }






        }

        //END OF GAME

        if(gamestart == false and (pl1win or pl2win) and horwin)
        {
            p[melyiki + melyikj*15]->winnerdrawvertical(pl1win,pl2win);
            p[melyiki+1 + melyikj*15]->winnerdrawvertical(pl1win,pl2win);
            p[melyiki+2 + melyikj*15]->winnerdrawvertical(pl1win,pl2win);
            p[melyiki+3 + melyikj*15]->winnerdrawvertical(pl1win,pl2win);
            p[melyiki+4 + melyikj*15]->winnerdrawvertical(pl1win,pl2win);



            if(pl1win)
            {
                p[melyiki + melyikj*15]->xdraw();
                p[melyiki+1 + melyikj*15]->xdraw();
                p[melyiki+2 + melyikj*15]->xdraw();
                p[melyiki+3 + melyikj*15]->xdraw();
                p[melyiki+4 + melyikj*15]->xdraw();
            }

            if(pl2win)
            {
                p[melyiki + melyikj*15]->circdraw(15);
                p[melyiki+1 + melyikj*15]->circdraw(15);
                p[melyiki+2 + melyikj*15]->circdraw(15);
                p[melyiki+3 + melyikj*15]->circdraw(15);
                p[melyiki+4 + melyikj*15]->circdraw(15);
            }

            gout << refresh;


        }

        if(gamestart == false and (pl1win or pl2win) and verwin)
        {
            p[melyiki+(melyikj*15)]->winnerdrawvertical(pl1win,pl2win);
            p[melyiki+((melyikj+1)*15)]->winnerdrawvertical(pl1win,pl2win);
            p[melyiki+((melyikj+2)*15)]->winnerdrawvertical(pl1win,pl2win);
            p[melyiki+((melyikj+3)*15)]->winnerdrawvertical(pl1win,pl2win);
            p[melyiki+((melyikj+4)*15)]->winnerdrawvertical(pl1win,pl2win);



            if(pl1win)
            {
                p[melyiki+(melyikj*15)]->xdraw();
                p[melyiki+((melyikj+1)*15)]->xdraw();
                p[melyiki+((melyikj+2)*15)]->xdraw();
                p[melyiki+((melyikj+3)*15)]->xdraw();
                p[melyiki+((melyikj+4)*15)]->xdraw();
            }

            if(pl2win)
            {
                p[melyiki + melyikj*15]->circdraw(15);
                p[melyiki+1 + melyikj*15]->circdraw(15);
                p[melyiki+2 + melyikj*15]->circdraw(15);
                p[melyiki+3 + melyikj*15]->circdraw(15);
                p[melyiki+4 + melyikj*15]->circdraw(15);
            }

            gout << refresh;


        }




    }


}
