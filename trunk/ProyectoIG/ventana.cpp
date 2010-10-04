 #include <QtGui>

 #include "ventana.h"

 Ventana::Ventana()
 {
     visorOpenGL = new VisorOpenGL;

     QHBoxLayout *mainLayout = new QHBoxLayout;
     mainLayout->addWidget(this->visorOpenGL);
     setLayout(mainLayout);
	
     setWindowTitle(tr("(c) Informatica Grafica. Miguel Angel Diaz Lopez [2010]"));
     resize(800,800);
 }


void Ventana::keyPressEvent(QKeyEvent *){
}
