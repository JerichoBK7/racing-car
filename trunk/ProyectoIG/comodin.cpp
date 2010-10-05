/**
 *
 *   This file is part of comodin.h
 *
 *   comodin.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   comodin.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "comodin.h"

void comodin::construir(){
    // cajon
    construirCajon();
    // mueble
    construirMueble();
}

void comodin::construirCajon(){
    int divisiones=1;
    /*color y luz*/
    _vertex4f blanco, luz, luz_borde;
    blanco.r=1;blanco.g=1;blanco.b=1;blanco.a=1;
    luz.x=0;luz.y=10;luz.z=0;luz.w=0.75;
    luz_borde.x=0;luz_borde.y=50;luz_borde.z=0;luz_borde.w=1;
    /*construccion*/
    cajon.construir(divisiones,10,58,blanco,luz,NULL);
    borde_cajon.resize(4);
    borde_cajon[0].construir(divisiones,1,60,blanco,luz_borde,NULL);// largo
    luz_borde.y=10;
    borde_cajon[1].construir(divisiones,1,10,blanco,luz_borde,NULL);// cortos
    borde_cajon[2].construir(divisiones,1,60,blanco,luz_borde,NULL);// largo
    borde_cajon[3].construir(divisiones,1,14,blanco,luz_borde,NULL);// cortos

    cajon.CambiaMaterial("cobre_1");
    borde_cajon[0].CambiaMaterial("bronce");
    borde_cajon[1].CambiaMaterial("bronce");
    borde_cajon[2].CambiaMaterial("plasticoNegro");
    borde_cajon[3].CambiaMaterial("plasticoNegro");

    // tiradores
    tirador = new Cono;
    tirador->Construir(1,2,20);
    tirador->setColor(1,1,1,0);
    tirador->setLuz(0,-60,0,1);
    tirador->Normalizar();
    tirador->CambiaMaterial("plata");
}

void comodin::construirMueble(){
    int divisiones=1;
    /*color y luz*/
    _vertex4f blanco, luz, luz_lateral,luz_lateral_;
    blanco.r=1;blanco.g=1;blanco.b=1;blanco.a=1;
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;
    luz_lateral.x=0;luz_lateral.y=20;luz_lateral.z=0;luz_lateral.w=0.75;
    luz_lateral_.x=0;luz_lateral_.y=10;luz_lateral_.z=0;luz_lateral_.w=0.75;
    /*construccion*/
    mueble_entrada.construir(divisiones,42,62,blanco,luz,NULL);//(anchoxalto)
    mueble_lateral.resize(3);
    mueble_lateral[0].construir(divisiones,6,62,blanco,luz_lateral,NULL);// hacer escalon_mueble (altoxancho)
    mueble_lateral[1].construir(divisiones,6,62,blanco,luz_lateral_,NULL);// hacer escalon_mueble (abajo)
    mueble_lateral[2].construir(divisiones,42,48,blanco,luz_lateral,NULL);// laterales

    mueble_entrada.CambiaMaterial("bronce");
    mueble_lateral[0].CambiaMaterial("bronce");
    mueble_lateral[1].CambiaMaterial("bronce");
    mueble_lateral[2].CambiaMaterial("bronce");
}

void comodin::drawCajon(){
    /*1º.- cajon:*/
    glPushMatrix();
        cajon.draw(1,3);
    glPopMatrix();

    /*2º.- filos:*/
    //largos
    glPushMatrix();
    glTranslatef(0,0,5);
        borde_cajon[0].draw(1,3);
    glTranslatef(0,0,-11);
        borde_cajon[0].draw(1,3);
    glPopMatrix();
    //borde_negro
    glPushMatrix();
    glTranslatef(0,0,6);
        borde_cajon[2].draw(1,3);
    glTranslatef(0,0,-13);
        borde_cajon[2].draw(1,3);
    glPopMatrix();
    //cortos
    glPushMatrix();
    glTranslatef(-30,0,0);
    glRotatef(90,0,0.75,0);
        borde_cajon[1].draw(1,3);
    glTranslatef(0,0,59);
        borde_cajon[1].draw(1,3);
    glPopMatrix();
    //borde_negro
    glPushMatrix();
    glTranslatef(-31,0,0);
    glRotatef(90,0,0.75,0);
        borde_cajon[3].draw(1,3);
    glTranslatef(0,0,61);
        borde_cajon[3].draw(1,3);
    glPopMatrix();

    /*3º.- tiradores:*/
    glPushMatrix();
    glTranslatef(0,-0.05,0);
    glTranslatef(-25,0,0);
    glRotatef(180,1,0,0);
        tirador->draw(1,3);
    glTranslatef(50,0,0);
        tirador->draw(1,3);
    glPopMatrix();
}

void comodin::drawMueble(){
    // superficie
    glPushMatrix();
    glTranslatef(0,48,0);
        mueble_entrada.draw(1,3);
    glPopMatrix();
    // listones superficie
    glPushMatrix();
    glTranslatef(0,45,0);
    glTranslatef(0,0,21);
    glRotatef(90,1,0,0);
        mueble_lateral[0].draw(1,3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,42,0);
    glTranslatef(0,0,18);
        mueble_lateral[1].draw(1,3);
    glPopMatrix();
    // laterales
    glPushMatrix();
    glTranslatef(0,24,0);
    glTranslatef(-31,0,0);
    glRotatef(90,0,0,1);
        mueble_lateral[2].draw(1,3);
    glTranslatef(0,-62,0);
        mueble_lateral[2].draw(1,3);
    glPopMatrix();
}

void comodin::draw(){
    // cajon
    glPushMatrix();
        glTranslatef(0,7,0);
        glTranslatef(0,0,15);
        glRotatef(90,1,0,0);
            drawCajon();
        glTranslatef(0,0,-14);
            drawCajon();
        glTranslatef(0,0,-14);
            drawCajon();
    glPopMatrix();
    // mueble
    drawMueble();
}
