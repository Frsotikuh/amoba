#include "gamemaster.hpp"
#include "graphics.hpp"
#include "tile.hpp"
#include "menuin.hpp"



using namespace genv;


gamemaster::gamemaster(bool menu, bool singlemode, bool multimode, bool gamestart, bool gameend, bool pl1turn, bool pl2turn):
    menu(menu), singlemode(singlemode),multimode(multimode),gamestart(gamestart), gameend(gameend), pl1turn(pl1turn), pl2turn(pl2turn)
{}




void gamemaster::gameprep()
{
    gout.open(1200,1000);
}

tile* ujmezo(int x, int y, int xM, int yM){

    return new tile(x,y, xM, yM, false, false,false);
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

    for(int j = 1; j <= 15; j++) //STAGE SET UP
    {
        for(int i = 1; i <= 15; i++)
        {

            p.push_back(ujmezo(130+distx,130+disty,j,i));
            distx += 48;

        }
        distx = 0;
        disty += 50;
    }



    g->gameprep();





    gout << move_to(0,0) << color(0,0,0) << box_to(width,height);
    gin.timer(2000); //NO INSTANT PICK

    while(gin >> ev) {

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
                p[i] -> xdraw();
                //p[i] -> circdraw(15);
            }
        }


        if(ev.type == ev_timer)
        {
            gamestart = true;
        }

        if(ev.type == ev_mouse)
        {
            gout << refresh;
        }






    }
}
