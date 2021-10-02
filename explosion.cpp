#include "explosion.h"

explosion::explosion()
{
    explociones.load(":/new/prefix1/sprites/explocion.png");
}



void explosion::arriba(unsigned q)
{
   if(q==1) explociones.copy(32,0,16,16);
   else if(q==2) explociones.copy(112,0,16,16);
   else if(q==3)explociones.copy(32,5*16,16,16);
   else if(q==4) explociones.copy(112,5*16,16,16);
   setPixmap(explociones.scaled(50,50));
}

void explosion::abajo(unsigned q)
{
    if(q==1) explociones.copy(32,4*16,16,16);
    else if(q==2)explociones.copy(112,4*16,16,16);
    else if(q==3)explociones.copy(32,9*16,16,16);
    else if(q==4)explociones.copy(112,9*16,16,16);
    setPixmap(explociones);
}

void explosion::izquierda(unsigned q)
{
    if(q==1)explociones.copy(0,2*16,16,16);
    else if(q==2)explociones.copy(5*16,2*16,16,16);
    else if(q==3)explociones.copy(0,7*16,16,16);
    else if(q==4)explociones.copy(5*16,7*16,16,16);
     setPixmap(explociones.scaled(50,50));
}

void explosion::derecha(unsigned q)
{
    if(q==1)explociones.copy(4*16,2*16,16,16);
    else if(q==2)explociones.copy(9*16,2*16,16,16);
    else if(q==3)explociones.copy(4*16,7*16,16,16);
    else if(q==4)explociones.copy(5*16,9*16,16,16);
     setPixmap(explociones.scaled(50,50));
}
void explosion::centro(unsigned q)
{
    if(q==1)explociones.copy(2*16,2*16,16,16);
    else if(q==2)explociones.copy(7*16,2*16,16,16);
    else if(q==3)explociones.copy(2*16,7*16,16,16);
    else if(q==4)explociones.copy(7*16,7*16,16,16);
     setPixmap(explociones.scaled(50,50));
}

void explosion::Set_dimension(unsigned int y, unsigned int x)
{
    alto=y;
    ancho=x;
}

