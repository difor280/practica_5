#ifndef UBICACION_H
#define UBICACION_H

#include <time.h>
#include <QObject>
#include <cstdlib>


class ubicacion
{
public:
    ubicacion(unsigned f, unsigned c );
    void matriz();
    unsigned mostras(unsigned f,unsigned c);
    bool aleatorio();
private:
    unsigned fila,columna,**ubicado;
    float p=0.45;
};

#endif // UBICACION_H
