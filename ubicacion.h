#ifndef UBICACION_H
#define UBICACION_H

#include <QObject>

class ubicacion
{
public:
    ubicacion(unsigned f, unsigned c );
    void matriz();
    unsigned mostras(unsigned f,unsigned c);
private:
    unsigned fila,columna,**ubicado;
};

#endif // UBICACION_H
