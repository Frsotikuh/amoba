#include "graphics.hpp"
#include "tile.hpp"
using namespace genv;
using namespace std;


const int width = 1200;
const int height = 1000;


tile* ujmezo(int x, int y, int xM, int yM){

    return new tile(x,y, xM, yM, false, false,false);
}

void torol()
{
    gout << color(0,0,0) << move_to(0,0) << box(width,height);
}


int main()
{
    gout.open(width,height);
    gout << move_to(0,0) << color(0,0,0) << box_to(width,height);

    event ev;

    vector<tile*> p;



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





    while(gin >> ev) {

        for( int i = 0; i < p.size(); i++)
        {
            p[i] -> kirajzol();
        }

        gout << refresh;


        if(ev.keycode == key_escape)
        {
            return 0;
        }


    }
    return 0;
}
