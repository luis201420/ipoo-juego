#include <allegro.h>
#include <iostream>

using namespace std;

class AST{
    private:
        int x;int y;
    public:
        AST(int _x,int _y){x=_x;y=_y;}
        int get_x(){return x;}
        int get_y(){return y;}
        void set_x(int a){x=x+a;}
        void set_y(int b){y=y+b;}
        void mover_ast();
    };

void AST::mover_ast()
{
    set_y(+1);
}

