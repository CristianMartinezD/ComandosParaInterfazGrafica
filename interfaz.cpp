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
    //escenario->setSceneRect(0,0,ui->graphicsView->width()-5,ui->graphicsView->height()-5); //Esto es para colocar
    //El escenario en toda la interfaz.


    personaje = new QGraphicsEllipseItem();
    personaje = escenario->addEllipse(0,-35,30,30,(Qt::green,2,Qt::SolidLine),(Qt::green,Qt::SolidPattern));


    QPen contorno(Qt::green,5,Qt::DashDotLine); //Creo un contorno que puedo utilizar en varias figu
    QBrush pintura(Qt::red,Qt::SolidPattern); //Pintura para ser utilizada por cualquier figu.


    int matrizLaberinto[10][10] ={
        {1,1,1,0,1,1,1,1,1,1},
        {1,1,1,0,1,1,1,1,1,1},
        {1,1,1,0,0,0,1,1,1,1},
        {1,1,1,1,1,0,1,1,1,1},
        {1,1,0,0,0,0,1,1,1,1},
        {1,1,0,1,1,1,1,0,0,0},
        {1,1,0,1,1,1,1,0,1,1},
        {1,1,0,0,0,0,0,0,1,1},
        {1,1,1,1,1,0,1,1,1,1},
        {1,1,1,1,1,0,1,1,1,1}
    };

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(matrizLaberinto[i][j] == 1){
                paredes.push_back( escenario->addRect(j*50,i*50,50,50, contorno, pintura) );
              }

           }
        }




    /* ################## AHORA PONDRE UNA IMAGEN EN LA ESCENA ##################### */


    rutas.push_back(":/imagenes/ave1.png");
    pajaro = new QGraphicsPixmapItem();
    pajaro->setPixmap(QPixmap(rutas.at(0)));
    pajaro->setPos(posicionX, posicionY);
    //escenario->addItem(pajaro);

    /* ################## LISTO! YA ESTA LA IMAGEN PUESTA EN LA ESCENA ############### */



    /* ########### VAMOS A CONECTAR UNA SEÑAL CON CON UN SLOT ############# */
    reloj1 = new QTimer();
    connect(reloj1, SIGNAL(timeout()), this, SLOT(on_derecha_clicked()));
    //reloj1->start(70);
    /* ########### FIN ######################## FIN ###################### */



    ui->graphicsView->setScene(escenario);
}





interfaz::~interfaz()
{
    delete ui;
}



static int contador = 0;
void interfaz::on_derecha_clicked()
{
//    reloj1->start(30);
//    posicionX += 5;
//    posicionY += 0;

//    pajaro->setPixmap(QPixmap(rutas.at(contador)));

//    pajaro->setPos(posicionX, posicionY);

//    contador++;

//    if(contador >= 14) contador = 0;
}


void interfaz::on_detenerse_clicked()
{
    //reloj1->stop();

}

void interfaz::keyPressEvent(QKeyEvent *tecla)
{
    static int posiX = 0, posiY = 0;

    switch (tecla->key()) { // Ver documentacion de Key().
        case Qt::Key_A:
        qDebug() <<"HAS PRESIONA LA TECLA A, (izquierda)"<<endl;
        posiX -= 10;
        personaje->setPos(posiX,posiY);
        break;

        case Qt::Key_W:
        qDebug() <<"HAS PRESIONA LA TECLA W, (arriba)"<<endl;
        posiY -= 10;
        personaje->setPos(posiX,posiY);
        break;

        case Qt::Key_D:
        qDebug() <<"HAS PRESIONA LA TECLA D, (derecha)"<<endl;
        posiX += 10;
        personaje->setPos(posiX,posiY);
        break;

        case Qt::Key_Z:
        qDebug() <<"HAS PRESIONA LA TECLA Z, (abajo)"<<endl;
        posiY += 10;
        personaje->setPos(posiX,posiY);
        break;


    }

    /* ##########  Para mantener el foco puesto en el personaje ######### */
    ui->graphicsView->setSceneRect(posiX, posiY-100, 500,500);

}
