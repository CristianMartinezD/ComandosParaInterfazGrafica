#include "interfaz.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interfaz w;
    w.show();
    return a.exec();
}
