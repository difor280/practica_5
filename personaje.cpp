#include "personaje.h"

personaje::personaje()
{

    sprites->load(":/new/prefix1/sprites/movimiento.png");
    set_carga(*sprites);
}

void personaje::movimiento(int8_t *sprites)
{
    *sprites=*sprites+1;
    if(*sprites%3 != 0)
    {
        SMovimiento(*sprites);
    }
    else
    {
        *sprites=*sprites-3;
        SMovimiento(*sprites);
    }
}

void personaje::SMovimiento(int8_t sprites)
{
    if(sprites<6)
    {
        setbloque(sprites*16,0);
    }
    else
    {
        setbloque((sprites-6)*16,16);
    }
}

