#include "ubicacion.h"


ubicacion::ubicacion(unsigned f, unsigned c)
{
    fila=f;
    columna=c;
    ubicado= new unsigned *[fila];
    for(f=0;f<fila;f++) ubicado[f]=new unsigned [c];

}

void ubicacion::matriz()
{
    for(unsigned f=0;f<fila;f++)
    {
        for(unsigned c=0;c<columna;c++)
        {
            if(f*c==0 || c==columna-1 || f==fila-1 || (f%2==0 && c%2==0))
                ubicado[f][c]=0;
            else
            {
                ubicado[f][c]=8;
            }
        }
    }
}

unsigned ubicacion::mostras(unsigned int f, unsigned int c)
{
    return ubicado[f][c];
}
