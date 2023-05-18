#include "graphics.hpp"
#include "gamemaster.hpp"
#include "menuin.hpp"
using namespace genv;
using namespace std;


const int width = 1200;
const int height = 1000;







int main()
{
    gamemaster* g = new gamemaster(true,false,false,false,false,false,false);
    g->handlegame(g);

    return 0;
}
