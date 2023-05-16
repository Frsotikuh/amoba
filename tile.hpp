#ifndef TILE_HPP
#define TILE_HPP
#include <vector>

using namespace std;

class tile
{
public:
    tile(int x, int y, int xM, int yM, bool CIR, bool TRI);


protected:
int x,y,xM,yM;
bool CIR,TRI;

};

#endif // TILE_HPP
