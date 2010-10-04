#include "lampara.h"


void lampara::construir(){
    // lampara
    construirLampara();
    // cable
    construirCable();
    // bombilla
    construirBombilla();
}

void lampara::construirLampara(){
    // variables
    _vertex4f pos,ambient,diffuse,specular;
    // cono_lampara
    cono = new Cono;
    cono -> Construir(34,20,20);
    // cono lampara encima
    cono2 = new Cono;
    cono2 -> Construir(34,20,20);
    // conector (entre conos)
    conector = new Cilindro;
    conector -> Construir(34,2,20);
    // luz
    pos.x=0;pos.y=-50;pos.z=0;pos.w=1;
    ambient.x=ambient.y=ambient.z=1;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.5;diffuse.w=1;
    specular.x=specular.y=specular.z=0.2;specular.w=1;
    cono->CambiaLuz(pos,ambient,diffuse,specular);
    cono->Normalizar();

    pos.x=0;pos.y=500;pos.z=0;pos.w=0.5;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.2;diffuse.w=1;
    specular.x=specular.y=specular.z=0.2;specular.w=1;
    cono2->CambiaLuz(pos,ambient,diffuse,specular);
    cono2->Normalizar();

    pos.x=0;pos.y=10;pos.z=0;pos.w=1;
    ambient.x=ambient.y=ambient.z=0.7;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.5;diffuse.w=1;
    specular.x=specular.y=specular.z=0.2;specular.w=1;
    conector->CambiaLuz(pos,ambient,diffuse,specular);
    conector->Normalizar();
}

void lampara::construirCable(){
    // variables
    _vertex4f pos,ambient,diffuse,specular;
    cilindro = new Cilindro;
    cilindro -> Construir(4,12,20);
    // Color y luz
    cilindro->setColor(1,1,1,1);
    pos.x=0;pos.y=-100;pos.z=0;pos.w=1;
    ambient.x=ambient.y=ambient.z=0.8;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.5;specular.w=1;

    cilindro->CambiaLuz(pos,ambient,diffuse,specular);
    cilindro->Normalizar();
    cilindro->CambiaMaterial("plata");
}

void lampara::construirBombilla(){
    // variables
    _vertex4f pos,ambient,diffuse,specular,blanco;
    // Color y luz
    blanco.r=1;blanco.g=1;blanco.b=0;blanco.a=0.75;
    pos.x=0;pos.y=-500;pos.z=0;pos.w=1;
    ambient.x=ambient.y=ambient.z=0.78;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.5;diffuse.w=1;
    specular.x=specular.y=specular.z=0.3;specular.w=1;
    // esfera
    bombilla.Construir(30,8,blanco,pos);
    bombilla.CambiaLuz(pos,ambient,diffuse,specular);
}

void lampara::drawLampara(char*lampara, char*borde){
    glPushMatrix();
        cono->CambiaMaterial(lampara);
        cono->draw(1,3);
    glTranslatef(0,1,0);
        cono2->CambiaMaterial(lampara);
        cono2->draw(1,3);
    glTranslatef(0,-9.9,0);
        conector->CambiaMaterial(borde);
        conector->draw(1,3);
    glTranslatef(0,18,0);
    glScalef(0.8,0.8,0.8);
        cono2->draw(1,3);
    glTranslatef(0,-8.9,0);
        conector->draw(1,3);
    glTranslatef(0,20,0);
    glScalef(0.8,0.8,0.8);
        cono2->draw(1,3);
    glTranslatef(0,-8.9,0);
        conector->draw(1,3);
    glPopMatrix();
}

void lampara::drawBombilla(){
    glPushMatrix();
    glScalef(0.5,2.3,0.5);
        bombilla.draw(1,3);
    glPopMatrix();
}

void lampara::drawCable(){
    // base
    glPushMatrix();
    glTranslatef(0,8,0);
    glScalef(1,3.5,1);
        cilindro->draw(1,3);
    glPopMatrix();
    // cable
    glPushMatrix();
    glTranslatef(0,40,0);
    glScalef(0.25,4,0.25);
        cilindro->draw(1,3);
    glPopMatrix();
}


void lampara::draw(char*lamp, char*borde){
    glPushMatrix();
    glTranslatef(0,-64,0);
    //lampara
    drawLampara(lamp,borde);
    //cable
    drawCable();
    //bombilla
    drawBombilla();
    glPopMatrix();
}
