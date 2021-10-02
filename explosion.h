#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QObject>
#include <QGraphicsPixmapItem>

class explosion:public QGraphicsPixmapItem
{
public:
    explosion();
    void Set_dimension(unsigned y,unsigned x);
    void SExplosion(unsigned short *estado);
    void arriba(unsigned q );
    void abajo(unsigned q);
    void izquierda(unsigned q);
    void derecha(unsigned q);
    void centro(unsigned q);

private:
    QPixmap explociones;
    unsigned alto,ancho;

};

#endif // EXPLOSION_H
