/**
 *
 *   This file is part of estanteria.h
 *
 *   estanteria.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   estanteria.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "estanteria.h"


void estanteria::construir(){
    // cajon
    construirPuerta();
    // mueble
    construirMueble();
}

void estanteria::construirPuerta(){
    int divisiones=1;
    /*color y luz*/
    _vertex4f blanco;
    _vertex4f luz,ambient,diffuse,specular;
    blanco.r=1;blanco.g=1;blanco.b=1;blanco.a=1;
    luz.x=0;luz.y=20;luz.z=0;luz.w=0.75;
    ambient.x=ambient.y=ambient.z=0.2;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.5;diffuse.w=1;
    specular.x=specular.y=specular.z=0.1;specular.w=1;
    /*construccion*/
    puerta.construir(divisiones,20,38,blanco,luz,NULL);
    borde_puerta.resize(4);
    borde_puerta[0].construir(divisiones,1,40,blanco,luz,NULL);// largo
    borde_puerta[1].construir(divisiones,1,20,blanco,luz,NULL);// cortos
    borde_puerta[2].construir(divisiones,1,40,blanco,luz,NULL);// largo
    borde_puerta[3].construir(divisiones,1,24,blanco,luz,NULL);// cortos

    borde_puerta[0].CambiaLuz(luz,ambient,diffuse,specular);
    borde_puerta[1].CambiaLuz(luz,ambient,diffuse,specular);

    puerta.CambiaMaterial("cobre_1");
    borde_puerta[0].CambiaMaterial("bronce");
    borde_puerta[1].CambiaMaterial("bronce");
    borde_puerta[2].CambiaMaterial("plasticoNegro");
    borde_puerta[3].CambiaMaterial("plasticoNegro");

    // tirador
    tirador = new Cono;
    tirador->Construir(1.5,2,20);
    tirador->setColor(1,1,1,0);
    tirador->setLuz(0,-60,0,1);
    tirador->Normalizar();
    tirador->CambiaMaterial("plata");
}

void estanteria::construirMueble(){
    _vertex4f pos,ambient,diffuse,specular;
    balda = new Cube;
    balda->Construir(1);
    /*luz*/
    balda->setColor(1,1,1,1);
    pos.x=0;pos.y=-100;pos.z=0;pos.w=1;
    ambient.x=ambient.y=ambient.z=0.8;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.8;diffuse.w=1;
    specular.x=specular.y=specular.z=0.6;specular.w=1;
    balda->CambiaLuz(pos,ambient,diffuse,specular);
    balda->Normalizar();
    balda->CambiaMaterial("bronce");
}

void estanteria::drawPuerta(){
    /*1º.- puerta:*/
    glPushMatrix();
        puerta.draw(1,3);
    glPopMatrix();

    /*2º.- filos:*/
    //largos
    glPushMatrix();
    glTranslatef(0,0,10);
        borde_puerta[0].draw(1,3);
    glTranslatef(0,0,-21);
        borde_puerta[0].draw(1,3);
    glPopMatrix();
    //borde_negro
    glPushMatrix();
    glTranslatef(0,0,11);
        borde_puerta[2].draw(1,3);
    glTranslatef(0,0,-23);
        borde_puerta[2].draw(1,3);
    glPopMatrix();
    //cortos
    glPushMatrix();
    glTranslatef(-20,0,0);
    glRotatef(90,0,0.75,0);
        borde_puerta[1].draw(1,3);
    glTranslatef(0,0,39);
        borde_puerta[1].draw(1,3);
    glPopMatrix();
    //borde_negro
    glPushMatrix();
    glTranslatef(-21,0,0);
    glRotatef(90,0,0.75,0);
        borde_puerta[3].draw(1,3);
    glTranslatef(0,0,41);
        borde_puerta[3].draw(1,3);
    glPopMatrix();

    /*3º.- tiradores:*/
    glPushMatrix();
    glTranslatef(0,-0.05,0);
    glTranslatef(0,0,7);
    glRotatef(180,1,0,0);
        tirador->draw(1,3);
    glPopMatrix();
}

void estanteria::drawMueble(){//(40x90)
    // laterales
    glPushMatrix();
    glTranslatef(-26,47,-18);
    glScalef(4,94,40);
        balda->draw(1,3);
    glTranslatef(13,0,0);
        balda->draw(1,3);
    glPopMatrix();
    // baldas
    glPushMatrix();
    glTranslatef(0,44,-18);
    glRotatef(180,0,0,1);
    glScalef(48,4,40);
        balda->draw(1,3);
    glTranslatef(0,-4,0);
        balda->draw(1,3);
    glTranslatef(0,-4,0);
        balda->draw(1,3);
    glTranslatef(0,-4,0);
        balda->draw(1,3);
    glPopMatrix();
    // atras
    glPushMatrix();
    glTranslatef(0,47,-38);
    glRotatef(90,0,1,0);
    glScalef(1,94,56);
        balda->draw(1,3);
    glPopMatrix();
}

void estanteria::draw(){
    // cajon
    glPushMatrix();
    glTranslatef(-12,21,0);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
        drawPuerta();
    glTranslatef(0,0,24);
    glRotatef(180,0,0,1);
    glRotatef(180,1,0,0);
        drawPuerta();
    glPopMatrix();
    // mueble
    drawMueble();
}
