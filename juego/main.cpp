#include <iostream>
#include <stdio.h>
#include <allegro.h>
#include <list>
#include <stdlib.h>
#include <time.h>
#include "nave.h"
#include "bala.h"
#include "asteroides.h"

using namespace std;

void inicia_allegro(int ANCHO_ , int ALTO_){
   allegro_init();
   install_keyboard();

   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO_, ALTO_, 0, 0);
}

int main()
{
    inicia_allegro(1340,700);
    install_keyboard();
    install_mouse();

    BITMAP * ventana=create_bitmap(1340,700);
    BITMAP * inicio=load_bitmap("espacio.bmp",NULL);
    BITMAP * nave=load_bitmap("naveup.bmp",NULL);
    BITMAP * efecto1=load_bitmap("efecto2.bmp",NULL);
    BITMAP * efecto2=load_bitmap("efecto1.bmp",NULL);
    BITMAP * bala=load_bitmap("bala.bmp",NULL);
    BITMAP * ast1=load_bitmap("ast1.bmp",NULL);
//    BITMAP * explosion1=load_bitmap("explosion.bmp",NULL);

    Nave nave_principal;

    int x=610;int y=280;
    bool jugar=true;

    list<Bala*> B;
    list<Bala*>::iterator itB;

    list<AST*> A;
    list<AST*>::iterator itA;

    srand (time (NULL));
    for(int i=0;i<5;i++){
        A.push_back(new AST(rand()%1300,rand()%700-700));
    }

    blit(inicio,ventana,0,0,0,0,1340,700);
    draw_sprite(ventana,nave,x,y);
    blit(ventana, screen, 0, 0, 0, 0,1340, 700);

    int aux=0;

    while(jugar)
    {
        aux++;
        nave_principal.mover(ventana,inicio,nave,efecto1,efecto2);

        if(aux==20){
            if(key[KEY_SPACE])
            {
                B.push_back(new Bala(nave_principal.X()+65 ,nave_principal.Y()-1));
            }
        aux=0;
        }

        for(itB = B.begin() ; itB != B.end() ; itB++)
        {
            draw_sprite(ventana,bala,(*itB)->get_x(),(*itB)->get_y());
            (*itB)->mover_bala();
            if((*itB)->fuera()){
                delete(*itB);
                itB=B.erase(itB);
            }
        }

        for(itA = A.begin() ; itA != A.end() ; itA++)
        {
            draw_sprite(ventana,ast1,(*itA)->get_x(),(*itA)->get_y());
            (*itA)->mover_ast();
            if((*itA)->get_y()==900)
            {
                delete(*itA);
                itA=A.erase(itA);
                A.push_back(new AST(rand()%1300+3,rand()%700-700));
            }
        }

        blit(ventana, screen, 0, 0, 0, 0,1340, 700);
        if(key[KEY_ESC])
            jugar=false;
    }

    destroy_bitmap(ast1);
    destroy_bitmap(bala);
    destroy_bitmap(inicio);
    destroy_bitmap(ventana);
    destroy_bitmap(nave);
    destroy_bitmap(efecto1);
    destroy_bitmap(efecto2);

    return 0;
}
    END_OF_MAIN();

