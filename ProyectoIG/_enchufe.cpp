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
 *   This file is part of _enchufe.h
 *
 *   _enchufe.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   _enchufe.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */



#include "_enchufe.h"



void _enchufe::construir(){
    // enchufe
    construirEnchufe();
    // caja del enchufe
    construirJuntas();
}

void _enchufe::construirEnchufe(){
    int divisiones=1;
    /*luces y blanco*/
    _vertex4f blanco,luz,ambient,diffuse,specular;
    blanco.r=1;blanco.g=1;blanco.b=1;blanco.a=1;
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.3;specular.w=1;
    /*construccion*/
    textura=new BMPClass;
    textura->BMPLoad("BMP/enchufe.bmp",blanco);
    enchufe.construir(divisiones,6,6,blanco,luz,textura);
    enchufe.CambiaLuz(luz,ambient,diffuse,specular);
    enchufe.CambiaMaterial("perla");
}

void _enchufe::construirJuntas(){
    /*luces */
    _vertex4f luz,ambient,diffuse,specular;
    luz.x=-2;luz.y=2;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.3;specular.w=1;
    /*construir*/
    juntas = new Cube;
    juntas->Construir(1);
    /*luz*/
    juntas->setColor(1,1,1,1);
    juntas->CambiaLuz(luz,ambient,diffuse,specular);
    juntas->Normalizar();
    juntas->CambiaMaterial("perla");
}

void _enchufe::drawEnchufe(){
    glPushMatrix();
        enchufe.draw(1,4);
    glPopMatrix();
}

void _enchufe::drawJuntas(){
    glPushMatrix();
    glTranslatef(0,-0.51,0);
    glScalef(6,1,6);
        juntas->draw(1,3);
    glPopMatrix();
}

void _enchufe::draw(int estado){
    // estado del enchufe (color)
    if(estado==0){enchufe.CambiaMaterial("perla");juntas->CambiaMaterial("perla");}
    else if(estado==1){enchufe.CambiaMaterial("esmeralda");juntas->CambiaMaterial("esmeralda");}
    else {enchufe.CambiaMaterial("plasticoRojo");juntas->CambiaMaterial("plasticoRojo");}

    // enchufe
    drawEnchufe();
    // caja del enchufe
    drawJuntas();
}
