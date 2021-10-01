#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QImage>

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
    void on_pushButton_clicked();

private:
    Ui::interfaz *ui;

    QGraphicsScene *escenario; // Aqui estoy creando el escenario en el hip.

    QGraphicsPixmapItem *imagen;
};
#endif // INTERFAZ_H
