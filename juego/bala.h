#include <allegro.h>
#include <iostream>

using namespace std;

class Bala{
    private:
        int x;int y;
    public:
        Bala(int _x,int _y){x=_x;y=_y;}
        int get_x(){return x;}
        int get_y(){return y;}
        void suma_x(int a){x=x+a;}
        void suma_y(int b){y=y+b;}
        void mover_bala(){suma_y(-2);}
        bool fuera();
    };

bool Bala::fuera()
{
    if(y<0){return true;}
    return false;
}
