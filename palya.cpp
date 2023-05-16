#include "palya.hpp"
#include "tile.hpp"
#include "graphics.hpp"

using namespace std;
using namespace genv;

palya::palya(int x, int y, int xM, int yM, bool CIR, bool TRI, bool rajta): tile(x,y,xM,yM,CIR,TRI), rajta(rajta)
{
}

const int width = 1000;
const int height = 1000;

void palya::torol()
{
    gout << color(0,0,0) << move_to(0,0) << box(width,height);
}

void palya::kirajzol() //50 size
{

    gout << color(255,255,255) << move_to(x,y) << box_to(x+50,y+50);
    gout << color(0,0,0) << move_to(x+2,y+2) << box_to(x+48,y+48);

}


