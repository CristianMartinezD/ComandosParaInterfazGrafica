#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QVector>
#include <QList>
#include <QTimer>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QtMath>  //Esta me puede servir para todo lo de matematicas.
#include <QKeyEvent> //Esta es para captar eventos del teclado.
#include <QAbstractButton> //Esto trabaja junto con QKeyEvent para captar las teclas que se oprimen

QT_BEGIN_NAMESPACE
namespace Ui { class interfaz; }
QT_END_NAMESPACE

class interfaz : public QMainWindow
{
    Q_OBJECT

public:
    interfaz(QWidget *parent = nullptr);
    ~interfaz();

private slots:
    void on_derecha_clicked();
    void on_detenerse_clicked();

private:
    Ui::interfaz *ui;

    QGraphicsScene *escenario; // Aqui estoy creando el escenario en el hip.

    QGraphicsPixmapItem *pajaro;
    int posicionX = 120, posicionY = 250;

    QVector<QString> rutas;

    QTimer *reloj1;

    QList<QGraphicsRectItem *> paredes;

    QGraphicsEllipseItem *personaje;


protected:
    void keyPressEvent(QKeyEvent *tecla); //Este es un metodo virtual de la clase QAbstractButton que
                                          //se mantiene a la espera de que se presione
                                          //una tecla para captarla.
};
#endif // INTERFAZ_H
