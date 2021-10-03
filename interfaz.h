#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QImage>
#include <QVector>
#include <QTimer>

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
};
#endif // INTERFAZ_H
