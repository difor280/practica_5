#ifndef BOMBA_H
#define BOMBA_H

#include <bloques.h>
#include <QTimer>

class bomba:public bloques
{
public:
    bomba();

private:
     QPixmap *sprites =new QPixmap;
      QTimer *tmp= new QTimer;
};

#endif // BOMBA_H
