/**
 *
 *   This file is part of visoropengl.h
 *
 *   visoropengl.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   visoropengl.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "visoropengl.h"
#include <QCoreApplication>

 VisorOpenGL::VisorOpenGL(QWidget *parent)
     : QGLWidget(parent) {

     // Definimos el tamaño del volumen de visualización
     Window_width=5;
     Window_height=5;
     Front_plane=10;
     Back_plane=1000;

     // permitimos al componente tener el foco y aceptar eventos
     setFocusPolicy(Qt::StrongFocus);

     // Numero de Camaras:
     camara.crea(8);
     // camara 4 : Fin del juego
     _vertex3f pos,orientacion;
     pos.x=85;
     pos.y=95;
     pos.z=125;
     camara.set(4,pos);
     camara.rotar(4,"axis-v",-80);//izq-dere
     camara.rotar(4,"axis-u",345);//arriba-abajo
     camara.rotar(4,"axis-n",-36);//inclincion
     // camara 5 : Modo Visualizar
     // camara 6 : Menu Principal
     pos.x=450;
     pos.y=400;
     pos.z=0;
     orientacion.x=0;orientacion.y=1;orientacion.z=0;
     camara.set(6,pos,orientacion);
     // camara 7 : Menu Pause
     pos.x=850;
     pos.y=400;
     pos.z=0;
     orientacion.x=0;orientacion.y=1;orientacion.z=0;
     camara.set(7,pos,orientacion);
     // camara 8 : Menu Creditos
     pos.x=1250;
     pos.y=400;
     pos.z=0;
     orientacion.x=0;orientacion.y=1;orientacion.z=0;
     camara.set(8,pos,orientacion);

     camara.activar(6);//menu principal
 }

 VisorOpenGL::~VisorOpenGL() {
     makeCurrent();    
 }

// MOVIMIENTO:
//-------------------
 void VisorOpenGL::desocupado(void){//disparador
     this->escena.idle();
     updateGL();
}

// RATON:
//-------------------
void VisorOpenGL::mousePressEvent(QMouseEvent *event) {
    pos_raton = event->pos();
    int camara_activa=camara.Activa()+1;
    _vertex3f pos, orientacion;
    //
    // Menu PRINCIPAL:
    if(camara_activa == 6){
        if(escena.Boton(pos_raton.x(),pos_raton.y(),width_act,height_act) == "boton1"){ // "comenzar la partida"
            if(!this->escena.Inicializado())//inicializamos el juego a valores por defecto
                this->escena.Inicializar();
            this->escena.ModoPartida(true);
            this->escena.ModoVisual(false);
            this->escena.Pause(false);
            time_0 = false; //temporizador (activado)
            camara.activar(3);// tercera persona (jugando)
        }
        if(escena.Boton(pos_raton.x(),pos_raton.y(),width_act,height_act) == "boton2"){ // "modo visualizar"
            // camara 5 : Modo visualizacion
            pos.x=170;
            pos.y=30;
            pos.z=-125;
            orientacion.x=0;orientacion.y=0;orientacion.z=-1;
            camara.set(5,pos,orientacion);
            //
            if(!this->escena.Inicializado())//inicializamos el juego a valores por defecto
                this->escena.Inicializar();
            this->escena.ModoPartida(false);
            this->escena.ModoVisual(true);
            this->escena.Pause(false);
            this->camara.activar(5);// modo visualizacion
        }
        if(escena.Boton(pos_raton.x(),pos_raton.y(),width_act,height_act) == "boton3"){// "salir del juego"
            QCoreApplication::exit(0); // cerramos la aplicacion
        }
        if(escena.Boton(pos_raton.x(),pos_raton.y(),width_act,height_act) == "boton4"){// "Creditos"
            time_0 = false;//comenzar temporizador
            camara.activar(8);//creditos
        }
    }
    //
    // Menu PAUSE:
    else if(camara_activa == 7){
        if(escena.Boton(pos_raton.x(),pos_raton.y(),width_act,height_act) == "boton1"){// "continuar la partida"
            if(this->escena.ModoPartida())camara.activar(1);
            else camara.activar(5);
            this->escena.Pause(false);
        }
        if(escena.Boton(pos_raton.x(),pos_raton.y(),width_act,height_act) == "boton2"){// "regresar al menu principal"
            this->camara.activar(6);
            this->escena.ModoPartida(false);
            this->escena.ModoVisual(false);
            this->escena.Pause(true);
        }
        if(escena.Boton(pos_raton.x(),pos_raton.y(),width_act,height_act) == "boton3"){// "salir de la partida"
            QCoreApplication::exit(0); // cerramos la aplicacion
        }
    }
    //
    // Menu CREDITOS:
    if(camara_activa == 8){//pulsamos raton
        camara.activar(6);//menu principal
    }
    //
    // Fin Juego
    if(camara_activa == 4){//pulsamos raton
        this->camara.activar(6);
        this->escena.ModoPartida(false);
        this->escena.ModoVisual(false);
        this->escena.Pause(true);
        camara.activar(6);// regreso al menu principal
    }
}
//-------------------

void VisorOpenGL::initializeGL()  {
     glClearColor(1.0,1.0,1.0,1.0);
     glShadeModel(GL_FLAT);
     glEnable(GL_DEPTH_TEST);
     // Dibujar, por delante y detras:
     //glEnable(GL_CULL_FACE);
     // Animation - QTimer
     timer = new QTimer(this);
                       //this creates a Qt timer event
     connect(timer, SIGNAL(timeout()), this, SLOT(desocupado(void)));
                       //this specifies what is to happen when the timer sends
                       //  a signal, ie, when the timer event occurs
                       //  (SIGNAL(timeout)) send a signal to
                       //  SLOT(animate()) - which is in glbox.cpp
     timer->start(0);
                       //this specifies that the timer event happens every 4
                       //milliseconds and that it is infinite loop
 }


QSize VisorOpenGL::minimumSizeHint() const {
    return QSize(400,400);
}

QSize VisorOpenGL::sizeHint() const {
    return QSize(800,800);
}

 void VisorOpenGL::resizeGL(int width, int height)
 {
     int side = qMin(width, height);
     height_act = height;
     width_act = width;
     glViewport((width - side) / 2, (height - side) / 2, side, side);
     setProjection();
}

void VisorOpenGL::setProjection(){
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
     glMatrixMode(GL_MODELVIEW);
 }

void VisorOpenGL::setCamara(){
    /*  Construccion de las camaras del PORCHE  */
    _vertex3f pos=this->escena.LeerPosicion();
    _vertex3f orientacion=this->escena.LeerOrientacion();
    string estado=this->escena.LeerEstado();
    if(camara.Activa()+1 == 8){ // menu de creditos
         float seg=Temporizador();
         if(seg>=10)camara.activar(6);//menu principal
    }
    else if(camara.Activa()+1 == 4){// fin juego
        float seg=Temporizador();
        if(seg>=10){
            this->escena.ModoPartida(false);
            this->escena.ModoVisual(false);
            this->escena.Pause(true);
            this->camara.activar(6);
        }
    }
    else if(!(estado=="GAME_OVER" || estado=="GANADOR")){
        //1º. vista en primera persona:
        camara.set(1,pos,orientacion);
        camara.rotar(1,"axis-v",180);
        camara.movCamara(1,"axis-z",7);
        camara.movCamara(1,"axis-y",7);
        //2º. vista por retrovisor:
        camara.set(2,pos,orientacion);
        camara.movCamara(2,"axis-z",4.22);//4.5
        camara.movCamara(2,"axis-y",6.5);//6
        //3º. vista en tercera persona:
        camara.set(3,pos,orientacion);
        camara.rotar(3,"axis-v",180);
        camara.movCamara(3,"axis-z",35);
        camara.movCamara(3,"axis-y",14);
        // cambio vista
        if(this->escena.Colision(0))
            if(camara.Activa()==2)camara.activar(1);

        // objetos - coche
        escena.drawInfo(camara.Activa());//información del coche
    }
    else if((estado=="GAME_OVER" || estado=="GANADOR") && this->escena.ModoPartida())camara.activar(4);

    /* Generamos mov-camara */
    camara.setCamara();
}

void VisorOpenGL::paintGL() {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
     setProjection();
     setCamara();
     dibujarEscena();
 }

void VisorOpenGL::keyPressEvent(QKeyEvent *event){
    /*Juego Parado y en "Modo Visualizar"*/
    if(!this->escena.Pause()){
        if(this->escena.ModoVisual()){
            switch( event->key() )   {
                /*--> Camara:*/
                //Rotaciones:
                case Qt::Key_L:camara.rotar("axis-v","der");break;
                case Qt::Key_J:camara.rotar("axis-v","izq");break;
                case Qt::Key_I:camara.rotar("axis-u","der");break;
                case Qt::Key_K:camara.rotar("axis-u","izq");break;
                //inclinacion derecha/izquierda:
                case Qt::Key_N:camara.rotar("axis-n","der");break;
                case Qt::Key_M:camara.rotar("axis-n","izq");break;
                //Movimiento:
                case Qt::Key_W:camara.movCamara("axis-z","up");break;
                case Qt::Key_S:camara.movCamara("axis-z","down");break;
                case Qt::Key_A:camara.movCamara("axis-x","up");break;
                case Qt::Key_D:camara.movCamara("axis-x","down"); break;
                case Qt::Key_E:camara.movCamara("axis-y","up");break;
                case Qt::Key_R:camara.movCamara("axis-y","down");break;

                // menu pause:
                case Qt::Key_Escape:
                     camara.activar(7);
                     this->escena.Pause(true);
                     break;
            }
        }
        /*El juego NO parado y "comenzando la partida"*/
        else if(this->escena.ModoPartida()){
            if(this->escena.ComienzoPartida()){
                switch( event->key() )   {
                    /*Camara*/
                    case Qt::Key_1:camara.activar(1);break;
                    case Qt::Key_2:camara.activar(2);break;
                }
            }
            switch( event->key() )   {
                /*Camara*/
                case Qt::Key_3:camara.activar(3);break;
                /*Coches ordenador*/
                case Qt::Key_L:this->escena.lineal(true); break;
                case Qt::Key_S:this->escena.lineal(false); break;
                /*Coche (controlado por humano)*/
                case Qt::Key_Up:(this->escena.ObtenTecla()=="UP")?this->escena.cambiaTecla("UP_2"):this->escena.cambiaTecla("UP");break;
                case Qt::Key_Down:this->escena.cambiaTecla("DOWN");break;
                case Qt::Key_Left:this->escena.cambiaTecla("LEFT");break;
                case Qt::Key_Right:this->escena.cambiaTecla("RIGHT");break;
                case Qt::Key_Insert:this->escena.cambiaTecla("PARAR");break;
                case Qt::Key_Space:this->escena.cambiaTecla("RECARGA");break;

                // menu pause:
                case Qt::Key_Escape:
                     camara.activar(7);
                     this->escena.Pause(true);
                     break;
            }
        }
        //
        // COMUN
        switch( event->key() )   {
            /*--> Modo Y Tipo de pintado: */
            case Qt::Key_F1: Draw_type=1;break;
            case Qt::Key_F2: Draw_type=2;break;
            case Qt::Key_F3: Draw_type=3;break;
            case Qt::Key_F4: Draw_type=4;break;
            case Qt::Key_F5: Draw_type=5;break;
            case Qt::Key_F6: Draw_type=6;break;

            default: QGLWidget::keyPressEvent(event);
        }
    }

    this->escena.setDrawType(Draw_type);
    updateGL();
}

void VisorOpenGL::dibujarEscena() {
      this->escena.draw();
}

float VisorOpenGL::Temporizador(void){
    if(!time_0){
        time_0=true;
        time_ini=clock();
    }
    time_fin=clock();
    float segundos=(time_fin-time_ini)/CLOCKS_PER_SEC;
    return segundos;
}



/////////////////////////////////////////////////////


/*
// Animacion:
case Qt::Key_Plus:this->escena.upTime();break;
case Qt::Key_Minus:this->escena.downTime(); break;
case Qt::Key_1:this->escena.upAngular();break;
case Qt::Key_2:this->escena.downAngular(); break;

*/
