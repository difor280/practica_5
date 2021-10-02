#include "enemigo.h"

enemigo::enemigo()
{
    malito.load(":/new/prefix1/sprites/enemigo.png");
    set_carga(malito);
}



void enemigo::posAleatoria()
{
    srand(time(NULL));

    alfi = rand()%(10-3+1)+3;
    alcol = rand()%(26-1+1)+1;
}

