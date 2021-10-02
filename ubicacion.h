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
    unsigned **ubicado;
    bool coliciones(unsigned *x,unsigned *y);
    void modificacion(unsigned x, unsigned y,unsigned cambio);
private:
    unsigned fila,columna;
    float p=0.45;
};

#endif // UBICACION_H
