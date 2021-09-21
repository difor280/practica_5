#include "bloques.h"

bloques::bloques()
{
    cargar.load(":/new/prefix1/sprites/bloques.png");
}

void bloques::set_carga(QPixmap sprite)
{
    cargar=sprite;
}

void bloques::set_dimenciones(unsigned a, unsigned b)
{
    alto=a;
    ancho=b;
}

void bloques::SBloques(unsigned i)
{
    if(i<8)
    {

        bloque=cargar.copy(i*16,0,16,16);
    }
    else if (i==8)
    {
        bloque= cargar.copy(126,15,1,1);
    }
    else
    {
        bloque= cargar.copy(0,0,1,1);
    }
    setPixmap(bloque.scaled(alto,ancho));
}

void bloques:: setbloque(unsigned x,unsigned y)
{
    bloque=cargar.copy(x,y,16,16);
    setPixmap(bloque.scaled(alto,ancho));
}
