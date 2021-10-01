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
        bombitaIn();
        tmp=new QTimer;
        connect(tmp,SIGNAL(timeout()),this,SLOT(setbomba()));
        tmp->start(500);
         //estado++;

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


}

MainWindow::~MainWindow()
{
    delete ui;
    delete esenas;
    delete block;
    delete prota;
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
}


void MainWindow::bombitaIn()
{
    QPixmap *setbo= new QPixmap ;
    setbo->load(":/new/prefix1/sprites/bomba.png");
    bombita->set_carga(*setbo);
    delete setbo;
    bombita->set_dimenciones(tam,tam);
    bombita->setPos(prota->x(),prota->y());
    bombita->movimiento(&izquierda);
    esenas->addItem(bombita);



}


