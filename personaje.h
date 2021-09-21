#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <bloques.h>


class personaje:public bloques
{
public:
    personaje();
    void movimiento(int8_t *sprites);
    void SMovimiento(int8_t sprites);


private:
    QPixmap *sprites=new QPixmap;

};

#endif // PERSONAJE_H
