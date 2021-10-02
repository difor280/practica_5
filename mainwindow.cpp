#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    const int e=i->key();
    unsigned posy=  prota->y(),posx=prota->x();
    if(e== Qt::Key_S)
    {
         posy=  posy+10;
        if((matiz.ubicado[(posy-51)/tam][unsigned(prota->x())/tam]==8)and (matiz.ubicado[(posy-51)/tam][(posx+49)/tam]==8))
            prota->setY(posy);

        prota->movimiento(&abajo);
    }
    else if (e == Qt::Key_W)
    {   posy=posy-10;
        if((matiz.ubicado[(posy-100)/tam][unsigned(prota->x())/tam]==8) and (matiz.ubicado[(posy-100)/tam][unsigned(posx+49)/tam]==8))
        prota->setY(posy);
        prota->movimiento(&arriba);
    }
    else if (e== Qt::Key_A)
    {   posx=posx-10;
        if((matiz.ubicado[(posy-100)/tam][posx/tam]==8)and(matiz.ubicado[(posy-51)/tam][posx/tam]==8))
            prota->setX(posx);
        prota->movimiento(&izquierda);

    }
    else if (e== Qt::Key_D)
    {   posx=posx+10;
        if((matiz.ubicado[(posy-100)/tam][(posx+49)/tam]==8)and(matiz.ubicado[(posy-51)/tam][(posx+49)/tam]==8))
            prota->setX(posx);
        prota->movimiento(&derecha);
    }
    else if(e== Qt::Key_P)
    {
        if(estado==0)
        {
            bombitaIn(posx,posy);
            tmp=new QTimer;
            connect(tmp,SIGNAL(timeout()),this,SLOT(setbomba()));
            tmp->start(700);
            explo=new QTimer;

            connect(explo,SIGNAL(timeout()),this,SLOT(exploto()));
            explo->start(400);
            //explo->stop();

        }

    }

}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_grafic();
    MemDinamic();
    ProtaIn();
    setmalito();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete esenas;
    delete block;
    delete prota;
    delete tmp;
    delete explo;
}

void MainWindow::set_grafic()
{
    esenas= new QGraphicsScene;
    esenas->setSceneRect(0,0,tam*col,tam*(fil+2));
    ui->graphicsView->setGeometry(0,0,tam*col+2,tam*(fil+2)+2);
    ui->graphicsView->setScene(esenas);

    setMaximumSize(tam*col+2,tam*(fil+3)+2);
    setMinimumSize(tam*col+2,tam*(fil+2)+2);
    setWindowTitle("Bomberman");

}

void MainWindow::MemDinamic()
{
    block->set_dimenciones(col*tam,2*tam);
    block->SBloques(9);
    block->setPos(0,0);
    esenas->addItem(block);

    matiz.matriz();

    for (unsigned f=0;f<fil ;f++ )
    {
        for (unsigned c=0;c<col;c++ )
        {
            blocks[f][c]=new bloques;
            blocks[f][c]->set_dimenciones(tam,tam);

            blocks[f][c]->SBloques(matiz.mostras(f,c));
            blocks[f][c]->setPos(c*tam,(f+2)*tam);
            esenas->addItem(blocks[f][c]);

        }
    }
}

void MainWindow::ProtaIn()
{
    prota->set_dimenciones(tam,tam);
    prota->SBloques(4);
    prota->setPos(x,y);
    esenas->addItem(prota);
}

void MainWindow::setbomba()
{
    bombita->movimiento(&izquierda);
    estado++;
}


void MainWindow::bombitaIn(unsigned  x, unsigned y)
{
    QPixmap *setbo= new QPixmap ;
    setbo->load(":/new/prefix1/sprites/bomba.png");
    bombita->set_carga(*setbo);
    delete setbo;
    bombita->set_dimenciones(tam,tam);
    if(x%50==0 and y%50 ==0);
    else
    {
        if((x+25)%50 <25) x=((x/50)*50)+50;
        else x=((x/50)*50);

        if((y+25)%50<25) y=((y/50)*50)+50;
        else y=((y/50)*50);

    }
    //preExplocion(x,y);
    bombita->setPos(x,y);
    bombita->movimiento(&izquierda);
    esenas->addItem(bombita);

}

void MainWindow::preExplocion(unsigned x,unsigned y)
{
       w->arriba(1);
       s->abajo(1);
       a->izquierda(1);
       d->derecha(1);

       w->setPos(x,y-50);
       s->setPos(x,y+50);
       a->setPos(x-50,y);
       d->setPos(x+50,y);
       if(matiz.mostras((y-50)/tam,(x)/tam)==8)
            sm=1;
       else sm=0;

       if(matiz.mostras((y-100)/tam,x/tam)==8)
            wm=1;
       else sm=0;

       if(matiz.mostras((y-100)/tam,x/tam)==8)
            am=1;
       else sm=0;

       if(matiz.mostras((y-100)/tam,(x+49)/tam))
            dm=1;
       else sm=0;
}

void MainWindow::setmalito()
{
  malito->set_dimenciones(tam,tam);
  malito->posAleatoria();
  while(matiz.mostras(malito->alfi,malito->alcol)!=8)
      malito->posAleatoria();
  malito->setPos(malito->alcol,malito->alfi);
  malito->SBloques(4);
  esenas->addItem(malito);

  enemi =new QTimer;
  //connect(enemi,SIGNAL(timeout()),this,SLOT(setmalos()));
  enemi->start(400);
}


void MainWindow::exploto()
{
    if(estado==3)
    {
        esenas->removeItem(bombita);
        tmp->stop();
        /*esenas->addItem(w);
        esenas->addItem(s);
        esenas->addItem(a);
        esenas->addItem(d);
        */estado=0;
        explo->stop();

    }

    /*if(estado<7 and estado>3)
    {
        if(sm==0)
        {

            matiz.modificacion((s->y()-51)/tam,s->x()/tam,estado-3);
        }
        else
        {
            sm++;
            s->abajo(sm);

        }
        if(wm==0)
        {

            matiz.modificacion((w->y()-51)/tam,(w->x())/tam,estado-3);
        }
        else
        {
            wm++;
            w->arriba(wm);
        }
         estado++;
    }*/

}

void MainWindow::setmalos()
{
    if((matiz.ubicado[(int(malito->y())-100-10)/tam][(int(malito->x()))/tam]==8 && matiz.ubicado[((int(malito->y())-100-10))/tam][(int(malito->x())+49)/tam]==8)&& fila=='S'){
          malito-> setY(malito->y()-10);
          //malito->movimiento(&izquierda);
          if(matiz.ubicado[(int(malito->y())-100-10)/tam][(int(malito->x()))/tam]!=8 && matiz.ubicado[((int(malito->y())-100-10))/tam][(int(malito->x())+49)/tam]!=8)
              fila='W';
      }else if((matiz.ubicado[(int(malito->y())-51+10)/tam][(int(malito->x()))/tam]==8 && matiz.ubicado[((int(malito->y()-51+10))/tam)][(int(malito->x()+49)/tam)]==8) && fila=='W'){
          malito-> setY(malito->y()+10);
          if(matiz.ubicado[(int(malito->y())-51+10)/tam][(int(malito->x()))/tam]!=8 && matiz.ubicado[((int(malito->y()-51+10))/tam)][(int(malito->x()+49)/tam)]!=8)
              fila='S';
      }else if((matiz.ubicado[(int(malito->y())-100)/tam][(int(malito->x())+49+10)/tam]==8 && matiz.ubicado[((int(malito->y()))-51)/tam][(int(malito->x()+49+10))/tam]==8) && columna=='A'){
          malito-> setX(malito->x()+10);
          if((matiz.ubicado[(int(malito->y())-100)/tam][(int(malito->x())+49+10)/tam]!=8 && matiz.ubicado[((int(malito->y()))-51)/tam][(int(malito->x()+49+10))/tam]!=8)){
               columna='D';}
      }else if((matiz.ubicado[(int(malito->y()-100)/tam)][(int(malito->x())-10)/tam]==8 && matiz.ubicado[(((int(malito->y())-100+49))/tam)][((int(malito->x())-10)/tam)]==8) && columna=='D'){
          malito-> setX(malito->x()-10);
          if((matiz.ubicado[(int(malito->y()-100)/tam)][(int(malito->x())-10)/tam]!=8 && matiz.ubicado[(((int(malito->y())-100+49))/tam)][((int(malito->x())-10)/tam)]!=8)){
              columna='A';}
      }else{
          columna = 'D';
          fila='S';
        }
}


