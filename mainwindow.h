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
#include "bomba.h"


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



public:
    void keyPressEvent(QKeyEvent *i);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_grafic();
    void MemDinamic();
    void ProtaIn();
    void bombitaIn();


private:
    Ui::MainWindow *ui;
    QGraphicsScene  *esenas;
    bloques  *block= new bloques,* blocks[fil][col];
    ubicacion matiz =ubicacion(fil,col) ;
    personaje *prota=new personaje;
    unsigned x=tam,y=3*tam;
    int8_t arriba=9,abajo=3,izquierda=0,derecha=6;
    QTimer *tmp ;
    personaje *bombita=new personaje;
    unsigned short estado=4;





};
#endif // MAINWINDOW_H
