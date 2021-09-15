#ifndef BLOQUES_H
#define BLOQUES_H

#include <QObject>
#include <QGraphicsPixmapItem>

class bloques:public QObject, public QGraphicsPixmapItem
{

public:
    bloques();    
    void set_dimenciones(unsigned a, unsigned b);
    void SBloques(unsigned i);

private:
    QPixmap cargar,bloque;
    unsigned alto, ancho;
};

#endif // BLOQUES_H
