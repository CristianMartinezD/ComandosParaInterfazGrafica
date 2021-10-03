#include "interfaz.h"
#include "ui_interfaz.h"

interfaz::interfaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::interfaz)
{
    ui->setupUi(this);

    ui->detenerse->setText("detenerse"); //Este boton no se encuentra en en la escena
    ui->derecha->setText("derecha");



    escenario = new QGraphicsScene(); // Aqui estoy inicializando el objeto escenario, asignandole memoria
                                      // ya que yo lo cree en el hip y no en el stack.
    escenario->setSceneRect(0,0,ui->graphicsView->width()-5,ui->graphicsView->height()-5); //Esto es para colocar
    //El escenario en toda la interfaz.





    //AHORA VOY A INCLUIR ELEMENTOS EN EL ESCENARIO//
    escenario->addRect(0,0,100,100); // (x,y,ancho,altura) esas dimensiones son en pixeles




    QPen contorno(Qt::green,5,Qt::SolidLine); //Creo un contorno que puedo utilizar en varias figu
    QBrush pintura(Qt::red,Qt::SolidPattern); //Pintura para ser utilizada por cualquier figu.

    escenario->addEllipse(0,0,100,100, contorno, pintura);




    //Modifico color del contorno y color de pintura para que sean usadas en otra figura.
    contorno.setColor(Qt::red);
    pintura.setColor(Qt::black);

    QGraphicsRectItem *rectangulo = escenario->addRect(290,0,100,100, contorno, pintura);

    rectangulo->setPos(292,0); //Aqui cambio la posicion que le puse inicialmente a
                                 //la figura que acave de guardar en *rectangulo.




    /* ################## AHORA PONDRE UNA IMAGEN EN LA ESCENA ##################### */

    rutas.push_back(":/imagenes/ave1.png");
    rutas.push_back(":/imagenes/ave2.png");
    rutas.push_back(":/imagenes/ave3.png");
    rutas.push_back(":/imagenes/ave4.png");
    rutas.push_back(":/imagenes/ave5.png");
    rutas.push_back(":/imagenes/ave6.png");
    rutas.push_back(":/imagenes/ave7.png");
    rutas.push_back(":/imagenes/ave8.png");
    rutas.push_back(":/imagenes/ave7.png");
    rutas.push_back(":/imagenes/ave6.png");
    rutas.push_back(":/imagenes/ave5.png");
    rutas.push_back(":/imagenes/ave4.png");
    rutas.push_back(":/imagenes/ave3.png");
    rutas.push_back(":/imagenes/ave2.png");

    pajaro = new QGraphicsPixmapItem();
    pajaro->setPixmap(QPixmap(rutas.at(0)));
    pajaro->setPos(posicionX, posicionY);
    escenario->addItem(pajaro);

    /* ################## LISTO! YA ESTA LA IMAGEN PUESTA EN LA ESCENA ############### */



    /* ########### VAMOS A CONECTAR UNA SEÑAL CON CON UN SLOT ############# */
    reloj1 = new QTimer();
    connect(reloj1, SIGNAL(timeout()), this, SLOT(on_derecha_clicked()));
    //reloj1->start(70);
    /* ########### FIN ######################## FIN ###################### */



    /*NOTA: Un contorno puede tener todos los siguientes atributos.*/

    QPen contorno0(Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);

    escenario->addRect(120,0,50,50,contorno,Qt::red);

    /* FIN DE NOTA */




    /* ######### SI QUEREMOS QUE LA PINTURA DE UN RECTANGULO SEA UNA IMAGEN ########### */

    QString ruta = "../intergrafica/imagenes/bloque.png";
    QImage im(ruta);
    QBrush brocha(im);

    contorno0.setStyle(Qt::SolidLine);
    escenario->addRect(200,0,80,80,contorno0, brocha);

    /* ######### LISTO! ESE RECTANGULO QUEDO CON LA IMAN DE colo.png ADENTRO ########### */



    //FINALMENTE MUESTRO EL ESCENARIO QUE SE ENCUENTRA DENTRO DEL EDIFICIO, EL CUAL A SU VEZ ESTA CONTRUIDO
    //EN LA INTERFAZ QUE ES CONTROLADA POR EL OBJETO ui.
    ui->graphicsView->setScene(escenario);
}





interfaz::~interfaz()
{
    delete ui;
}



static int contador = 0;
void interfaz::on_derecha_clicked()
{
    reloj1->start(30);
    posicionX += 5;
    posicionY += 0;

    pajaro->setPixmap(QPixmap(rutas.at(contador)));

    pajaro->setPos(posicionX, posicionY);

    contador++;

    if(contador >= 14) contador = 0;
}


void interfaz::on_detenerse_clicked()
{
    reloj1->stop();

}
