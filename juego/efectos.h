#include <allegro.h>
#include <iostream>

using namespace std;

class Efectos{
    private:
        float x;float y;
    public:
        Efectos(int _x,int _y){x=_x;y=_y;}
        int get_x(){return x;}
        int get_y(){return y;}
        void set_x(float a){x=x+a;}
        void set_y(float b){y=y+b;}
        void mover_izquierda(BITMAP*,BITMAP*);
        void mover_diagonal(BITMAP*,BITMAP*);
        };

void Efectos::mover_izquierda(BITMAP* ventana,BITMAP* efecto1)
{
    set_x(0.9);
    if(x>2000 || y>1000)
    {
        x=-500;
        set_y(3);
    }
    draw_sprite(ventana,efecto1,x,y);

}

void Efectos::mover_diagonal(BITMAP* ventana,BITMAP* efecto2)
{
    set_x(0.1);set_y(-0.1);
    if(x>1300 || y==0)
    {
        x=0;
        y=700;
    }
    draw_sprite(ventana,efecto2,x,y);
}
