#include "salon.h"



void salon::construir(){
    _vertex4f pos,ambient,diffuse,specular;

    // mesa salon
    mesita.construir();
    // cuadros
    // asientos
    asiento = new Cilindro;
    asiento->Construir(15,20,20);
    asiento->Normalizar();
    asiento->setColor(1,1,1,1);
    pos.x=30;pos.y=30;pos.z=0;pos.w=1;
    ambient.x=ambient.y=ambient.z=1;ambient.w=1;
    diffuse.x=0.8;specular.x=0.1;
    diffuse.y=0.8;specular.y=0.1;
    diffuse.z=0.8;specular.z=0.1;
    diffuse.w=specular.w=1;
    asiento->CambiaMaterial("gomaAzul");
    asiento->CambiaLuz(pos,ambient,diffuse,specular);
    // tv
    tv.LecturaPly("PLY/tv.ply");
    tv.setColor(1,1,1,1);
    tv.CambiaMaterial("plasticoNegro");
    pos.x=-200;pos.y=150;pos.z=200;pos.w=0.85;
    ambient.x=ambient.y=ambient.z=0.7;
    diffuse.x=0.3;specular.x=0.2;
    diffuse.y=0.3;specular.y=0.2;
    diffuse.z=0.3;specular.z=0.2;
    tv.CambiaLuz(pos,ambient,diffuse,specular);
    // estanteria
    estante.construir();
}

void salon::drawMesa(){
    // mesa para comer
    glPushMatrix();
    glTranslatef(122,0,153);
    glScalef(1,0.9,1);
        mesita.draw();
    glPopMatrix();
    // mesa de televisor (estar)
    glPushMatrix();
    glTranslatef(-110,0,195);
    glRotatef(90,0,1,0);
    glScalef(0.7,0.3,1);
        mesita.draw();
    glPopMatrix();
}

void salon::drawAsientos(){
    // asientos 1 tv
    glPushMatrix();
    glTranslatef(-195,10,150);
    glRotatef(175,0,1,0);
        asiento->draw(1,3);
    glPopMatrix();
    // asientos 2 tv
    glPushMatrix();
    glTranslatef(-195,10,210);
    glRotatef(185,0,1,0);
        asiento->draw(1,3);
    glPopMatrix();
}

void salon::drawTv(){
    glPushMatrix();
    glTranslatef(-90,30,220);
    glRotatef(130,0,-1,0);
    glRotatef(90,-1,0,0);
    glScalef(0.3,0.3,0.3);
        tv.draw(1,3);
    glPopMatrix();
}

void salon::drawEstanteria(){
    glPushMatrix();
    glTranslatef(5,0,206);
    glRotatef(180,0,1,0);
        estante.draw();
    glPopMatrix();
}

void salon::draw(){
    // mesa
    drawMesa();
    // asientos
    drawAsientos();
    // tv
    drawTv();
    // estanteria
    drawEstanteria();
}

