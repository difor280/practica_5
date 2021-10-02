#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "bloques.h"
#include "ubicacion.h"
#include "personaje.h"
#include <QKeyEvent>
#include <QTimer>
#include <explosion.h>
#include "enemigo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


#define tam 50
#define col 31
#define fil 13


class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
     void setbomba();
      void exploto();
      void setmalos();


public:
    void keyPressEvent(QKeyEvent *i);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_grafic();
    void MemDinamic();
    void ProtaIn();
    void bombitaIn(unsigned x,unsigned  y);
    void preExplocion(unsigned x,unsigned y);
    void setmalito();



private:
    Ui::MainWindow *ui;
    QGraphicsScene  *esenas;
    bloques  *block= new bloques,* blocks[fil][col];
    ubicacion matiz =ubicacion(fil,col) ;
    personaje *prota=new personaje;
    unsigned x=tam,y=3*tam;
    int8_t arriba=9,abajo=3,izquierda=0,derecha=6;
    QTimer *tmp,*explo,*enemi ;
    personaje *bombita=new personaje;
    unsigned short estado=0,wm,sm,am,dm;
    explosion *w=new explosion,*s=new explosion,*a =new explosion,*d=new explosion;
    enemigo *malito=new enemigo;
    char fila='W',columna='S';





};
#endif // MAINWINDOW_H
