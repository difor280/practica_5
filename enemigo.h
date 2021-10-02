#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "string.h"
#include <time.h>
#include "personaje.h"


class enemigo:public personaje
{
public:
    enemigo();

    void posAleatoria();
    int alfi,alcol;
private:
    QPixmap malito;

};

#endif // ENEMIGO_H
