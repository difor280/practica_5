#ifndef PROTA_H
#define PROTA_H

#include <QObject>
#include <QGraphicsPixmapItem>

class prota:public QObject, public QGraphicsPixmapItem
{
public:
    prota();
    void set_dimenciones(unsigned a, unsigned b);
    void Smovimientos(unsigned i);

private:
    QPixmap carga,movimiento;
    unsigned AlPer,AnPer;
};

#endif // PROTA_H
