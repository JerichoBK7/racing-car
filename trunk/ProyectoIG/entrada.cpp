#include "entrada.h"


void entrada::construir(){
    // mueble_entrada
    comoda.construir();
    // espejo
    construirEspejo();
    // flor
    construirFLor();
}

void entrada::construirFLor(){
    // flor
    flor=new _ply;
    flor->LecturaPly("PLY/rosa.ply");

    flor->setColor(1,1,1,1);
    flor->setLuz(-500,-70,150,1);
    flor->CambiaMaterial("gomaRoja");
}

void entrada::construirEspejo(){
    int divisiones=1;
    /*color y luz*/
    _vertex4f blanco, luz, luz_lateral,luz_lateral_,color;
    blanco.r=1;blanco.g=1;blanco.b=1;blanco.a=1;
    color.r=0.65;color.g=0.65;color.b=0.8;color.a=1;
    luz.x=0;luz.y=30;luz.z=0;luz.w=0.25;
    luz_lateral.x=0;luz_lateral.y=10;luz_lateral.z=0;luz_lateral.w=1;
    luz_lateral_.x=0;luz_lateral_.y=3;luz_lateral_.z=0;luz_lateral_.w=1;
    /*construccion*/
    espejo.construir(divisiones,60,30,color,luz,NULL);
    borde_espejo.resize(2);
    borde_espejo[0].construir(divisiones,2,60,blanco,luz_lateral,NULL);// largo
    borde_espejo[1].construir(divisiones,2,34,blanco,luz_lateral_,NULL);// largo

    borde_espejo[0].CambiaMaterial("plata");
    borde_espejo[1].CambiaMaterial("plata");
}

void entrada::drawEspejo(){
    // superficie
    glPushMatrix();
    glTranslatef(0,81,0);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
        espejo.draw(1,3);
    glPopMatrix();
    // marco
    glPushMatrix();//largo
    glTranslatef(0,65,0);
    glRotatef(90,1,0,0);
        borde_espejo[0].draw(1,3);
    glTranslatef(0,0,-32);
        borde_espejo[0].draw(1,3);
    glPopMatrix();

    glPushMatrix();//corto
    glTranslatef(0,81,0);
    glTranslatef(31,0,0);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
        borde_espejo[1].draw(1,3);
    glTranslatef(0,0,-62);
        borde_espejo[1].draw(1,3);
    glPopMatrix();

}

void entrada::drawFlor(){
    glPushMatrix();
    glTranslatef(0,58,0);
    glTranslatef(0,0,10);
    glRotatef(90,0,1,0);
    glScalef(0.2,0.2,0.2);
        flor->draw(1,3);
    glPopMatrix();
}

void entrada::draw(){
    // mueble_entrada
    comoda.draw();
    // espejo
    glPushMatrix();
    glTranslatef(0,0,-20);
        drawEspejo();
    glPopMatrix();
    // flor
    drawFlor();
}

