#include "ubicacion.h"


ubicacion::ubicacion(unsigned f, unsigned c)
{
    fila=f;
    columna=c;
    ubicado= new unsigned *[fila];
    for(f=0;f<fila;f++) ubicado[f]=new unsigned [c];
    srand(time(NULL));

}

void ubicacion::matriz()
{
    for(unsigned f=0;f<fila;f++)
    {
        for(unsigned c=0;c<columna;c++)
        {


            if(f*c==0 || c==columna-1 || f==fila-1 || (f%2==0 && c%2==0))
                ubicado[f][c]=0;
            else if ((f==1 && c==1) || (f==1 && c==2) ||(f==2 && c==1))
            {
                ubicado[f][c]=8;
            }
            else if(aleatorio() ) ubicado[f][c]=1;
            else  ubicado[f][c]=8;


        }
    }
}

unsigned ubicacion::mostras(unsigned int f, unsigned int c)
{
    return ubicado[f][c];
}

bool ubicacion::aleatorio()
{
    int n=rand();
    float x=p*(RAND_MAX+1)-1;
    return n<=x;
}

void ubicacion::modificacion(unsigned x, unsigned y, unsigned cambio)
{
    ubicado[x][y]=cambio;
}





