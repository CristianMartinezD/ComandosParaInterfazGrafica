#include "interfaz.h"
#include "ui_interfaz.h"

interfaz::interfaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::interfaz)
{
    ui->setupUi(this);

    ui->pushButton->setText("Enviar");

    escenario = new QGraphicsScene(); // Aqui estoy inicializando el objeto escenario, asignandole memoria
                                      // ya que yo lo cree en el hip y no en el stack.
    escenario->setSceneRect(0,0,ui->graphicsView->width()-5,ui->graphicsView->height()-5); //Esto es para colocar
    //El escenario en toda la interfaz.


    //AHORA VOY A INCLUIR ELEMENTOS EN EL ESCENARIO//
    escenario->addRect(0,0,100,100); // (x,y,ancho,altura) esas dimensiones son en pixeles

    escenario->addEllipse(0,0,100,100);

    auto *rectangulo = escenario->addRect(0,200,100,100);

    imagen = new QGraphicsPixmapItem();
    imagen->setPixmap(QPixmap(":/imagenes/ave1.png"));
    imagen->setPos(120,250);
    escenario->addItem(imagen);



    //Si quiero que la figura que voy a agregar tenga un contorno personalizado le paso un Qpen.

    QPen contorno(Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);

    escenario->addRect(120,0,50,50,contorno,Qt::red);


    QPen contorno1(Qt::blue, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    //Y si ademas queremos agregarle a la figura un color.

    QString ruta = "colo.png";
    QImage im(ruta);

    QBrush brocha(im);
    //brocha.setColor(Qt::green);

    escenario->addRect(130,130,80,80,contorno1, brocha);



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
