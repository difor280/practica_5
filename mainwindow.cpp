#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_grafic();
    MemDinamic();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete esenas;
    delete block;
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
    ubicacion matiz=ubicacion(fil,col) ;
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


