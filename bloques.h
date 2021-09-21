#ifndef BLOQUES_H
#define BLOQUES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "string.h"

class bloques:public QObject, public QGraphicsPixmapItem
{

public:
    bloques();
    void set_carga(QPixmap);
    void set_dimenciones(unsigned a, unsigned b);
    void SBloques(unsigned i);
    void setbloque(unsigned x,unsigned y);

private:
    QPixmap cargar,bloque;
    unsigned alto, ancho;
};

#endif // BLOQUES_H
