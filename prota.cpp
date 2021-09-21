#include "prota.h"

prota::prota()
{
    carga.load(":/new/prefix1/sprites/movimiento_personaje.png");
}

void prota::set_dimenciones(unsigned a, unsigned b)
{
    AlPer=a;
    AnPer=b;
}

void prota::Smovimientos(unsigned i)
{
    if(i<8)
    {
        movimiento=carga.copy(i*16,0,16,16);
    }
    else if (i==8)
    {
        movimiento= carga.copy(126,15,1,1);
    }
    else
    {
        movimiento= carga.copy(0,0,1,1);
    }
    setPixmap(movimiento.scaled(AlPer,AnPer));
}
