#include <allegro.h>
#include "efectos.h"
#include <iostream>

using namespace std;

Efectos efec1(-600,0);
Efectos efec2(0,700);

class Nave{
    private:
        int x,y;
        char estado;
    public:
        Nave(){x=610;y=280;estado='u';}
        int X(){return x;}
        int Y(){return y;}
        char get_estado(){return estado;}
        void set_estado(char x){estado=x;}
        void set_X(int a){x=x+a;}
        void set_Y(int b){y=y+b;}
        void mover(BITMAP*,BITMAP*,BITMAP*,BITMAP*,BITMAP*);
    };

void Nave::mover(BITMAP* ventana,BITMAP* inicio,BITMAP* nave,BITMAP* efecto1,BITMAP* efecto2)
{
    blit(inicio,ventana,0,0,0,0,1340,700);
    efec1.mover_izquierda(ventana,efecto1);
    efec2.mover_diagonal(ventana,efecto2);
    if(estado=='d')draw_sprite(ventana,nave,x,y);
    if(estado=='u')draw_sprite(ventana,nave,x,y);
    if(estado=='l')draw_sprite(ventana,nave,x,y);
    if(estado=='r')draw_sprite(ventana,nave,x,y);
    if(key[KEY_RIGHT])
    {
        set_X(3);
        if(x>1300)
        {
            x=0;
        }
        set_estado('r');
    }
    else if(key[KEY_LEFT])
    {
        set_X(-3);
        if(x<0)
        {
            x=1300;
        }
        set_estado('l');
    }
    else if(key[KEY_UP])
    {
        set_Y(-3);
        if(y<3)
        {
            y=3;
        }
        set_estado('u');
    }
    else if(key[KEY_DOWN])
    {
        set_Y(3);
        if(y>568)
        {
            y=568;
        }
        set_estado('d');
    }
}
