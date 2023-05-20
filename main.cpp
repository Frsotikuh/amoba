
#include "gamemaster.hpp"


using namespace std;




int main()
{
    gamemaster* g = new gamemaster(true,false,false,false,false,false,false,false,false);
    g->handlegame(g);

    return 0;
}
