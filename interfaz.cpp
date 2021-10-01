#include "interfaz.h"
#include "ui_interfaz.h"

interfaz::interfaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::interfaz)
{
    ui->setupUi(this);

    ui->pushButton->setText("Enviar"); //Este boton no se encuentra en en la escena



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

    auto *rectangulo = escenario->addRect(0,200,100,100, contorno, pintura);

    rectangulo->setPos(350,250); //Aqui cambio la posicion que le puse inicialmente a
                                 //la figura que acave de guardar en *rectangulo.




    /* ################## AHORA PONDRE UNA IMAGEN EN LA ESCENA ##################### */

    imagen = new QGraphicsPixmapItem();
    imagen->setPixmap(QPixmap(":/imagenes/ave1.png"));
    imagen->setPos(120,250);
    escenario->addItem(imagen);

    /* ################## LISTO! YA ESTA LA IMAGEN PUESTA EN LA ESCENA ############### */



    /*NOTA: Un contorno puede tener todos los siguientes atributos.*/

    QPen contorno0(Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);

    escenario->addRect(120,0,50,50,contorno,Qt::red);

    /* FIN DE NOTA */




    /* ######### SI QUEREMOS QUE LA PINTURA DE UN RECTANGULO SEA UNA IMAGEN ########### */

    QString ruta = "colo.png";
    QImage im(ruta);
    QBrush brocha(im);

    contorno0.setStyle(Qt::SolidLine);
    escenario->addRect(130,130,80,80,contorno0, brocha);

    /* ######### LISTO! ESE RECTANGULO QUEDO CON LA IMAN DE colo.png ADENTRO ########### */



    //FINALMENTE MUESTRO EL ESCENARIO QUE SE ENCUENTRA DENTRO DEL EDIFICIO, EL CUAL A SU VEZ ESTA CONTRUIDO
    //EN LA INTERFAZ QUE ES CONTROLADA POR EL OBJETO ui.
    ui->graphicsView->setScene(escenario);
}





interfaz::~interfaz()
{
    delete ui;
}




void interfaz::on_pushButton_clicked()
{
    ui->textBrowser->setText("Este rectacgulo no esta dentro de la escena sino dentro del graphicview");

}
