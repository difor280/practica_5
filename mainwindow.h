#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "bloques.h"
#include "ubicacion.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


#define tam 50
#define col 31
#define fil 13


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_grafic();
    void MemDinamic();

private:
    Ui::MainWindow *ui;
    QGraphicsScene  *esenas;
    bloques  *block= new bloques,* blocks[fil][col];


};
#endif // MAINWINDOW_H
