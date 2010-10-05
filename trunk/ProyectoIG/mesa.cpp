/*************************************************************************/
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*                                                                       */
/*     License: GPL3                                                     */
/*                                                                       */
/*************************************************************************/
/**
 *
 *   This file is part of mesa.h
 *
 *   mesa.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   mesa.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "mesa.h"


void mesa::construir(){
    // patas
    construirPatas();
    // tableros
    cosntruirMesa();
}

void mesa::construirPatas(){
    _vertex4f pos,ambient,diffuse,specular;
    patas=new Cube;
    patas->Construir(6);
    /*luz*/
    patas->setColor(1,1,1,1);
    pos.x=0;pos.y=-100;pos.z=0;pos.w=1;
    ambient.x=ambient.y=ambient.z=0.8;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.5;specular.w=1;
    patas->CambiaLuz(pos,ambient,diffuse,specular);
    patas->Normalizar();
    patas->CambiaMaterial("bronce");
}

void mesa::cosntruirMesa(){
    _vertex4f pos,ambient,diffuse,specular;
    mesita=new Cube;
    mesita->Construir(1);
    /*luz*/
    mesita->setColor(1,1,1,1);
    pos.x=0;pos.y=-100;pos.z=0;pos.w=1;
    ambient.x=ambient.y=ambient.z=0.8;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.5;specular.w=1;
    mesita->CambiaLuz(pos,ambient,diffuse,specular);
    mesita->Normalizar();
    mesita->CambiaMaterial("bronce");
}

void mesa::drawMesa(){
    glPushMatrix();//(64x114)
    glTranslatef(0,48,0);
    glRotatef(180,1,0,0);
    glScalef(20,1,12);
        patas->draw(1,3);
    glPopMatrix();
}

void mesa::drawPatas(){
    glPushMatrix();//altura 48
    glTranslatef(0,24,0);
    glScalef(1,8,1);
    // pata 1
    glPushMatrix();
    glTranslatef(52,0,27);
        patas->draw(1,3);
    glPopMatrix();
    // pata 2
    glPushMatrix();
    glTranslatef(-52,0,27);
        patas->draw(1,3);
    glPopMatrix();
    // pata 3
    glPushMatrix();
    glTranslatef(52,0,-27);
        patas->draw(1,3);
    glPopMatrix();
    // pata 4
    glPushMatrix();
    glTranslatef(-52,0,-27);
        patas->draw(1,3);
    glPopMatrix();
    glPopMatrix();
}

void mesa::draw(){
    // patas
    drawPatas();
    // mesa
    drawMesa();
}

