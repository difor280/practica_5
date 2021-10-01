#ifndef BLOQUES_H
#define BLOQUES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "string.h"

class bloques:public QObject, public QGraphicsPixmapItem
{

public:
    bloques();//introduce la imagen de bloque
    void set_carga(QPixmap);//se utiliza para cambiar la imagen ya que la que se introduce por defecto en bloques es la que contiene los bloques
    void set_dimenciones(unsigned y, unsigned x);//introduce el ancho y el largo de la imagen
    void SBloques(unsigned i);//sacar bloques 16*16 hasta el 7 el 8 y el 9 son color verde y gris
    void setbloque(unsigned x,unsigned y);//settena la variable bloque de clase item

private:
    //carga son los sprites
    QPixmap cargar,bloque;
    unsigned alto, ancho;
};

#endif // BLOQUES_H
