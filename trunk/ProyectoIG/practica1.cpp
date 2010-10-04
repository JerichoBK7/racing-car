
#include <QApplication>

#include "ventana.h"
#include "visoropengl.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     Ventana ventana;
     ventana.show();
     return app.exec();
 }
