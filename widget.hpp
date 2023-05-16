#ifndef WIDGET_H
#define WIDGET_H
#include <vector>

using namespace std;

class widget
{
public:
    widget(int x, int y, int xM, int yM, bool CIR, bool TRI);


protected:
int x,y,xM,yM;
bool CIR,TRI;

};

#endif // WIDGET_H
