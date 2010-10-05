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
 *   This file is part of campana.h
 *
 *   campana.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   campana.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */



#include "campana.h"

campana::campana(){
    _vertex4f color,luz_cono,luz_cilindro;
    /*luces y color*/
    luz_cono.x=0;luz_cono.y=100;luz_cono.z=0;luz_cono.w=1;
    luz_cilindro.x=0;luz_cilindro.y=50;luz_cilindro.z=0;luz_cilindro.w=1;
    color.r=0;color.g=0;color.b=0;color.a=1;
    /*Construccion*/
    cono = new Cono;
    cono->setColor(color.r,color.g,color.b,color.a);
    cono->setLuz(luz_cono.x,luz_cono.y,luz_cono.z,luz_cono.w);
    cono->Construir(34,26,20);

    cilindro = new Cilindro;
    cilindro->setColor(color.r,color.g,color.b,color.a);
    cilindro->setLuz(luz_cilindro.x,luz_cilindro.y,luz_cilindro.z,luz_cilindro.w);
    cilindro->Construir(15,20,20);

    cono->Normalizar();
    cilindro->Normalizar();

    cono->CambiaMaterial("cromo");
    cilindro->CambiaMaterial("cromo");
}

campana::~campana(){
    delete cono;
    delete cilindro;
}

void campana::draw(){
    glPushMatrix();
    glTranslatef(0,80,0);
    glTranslatef(16,0,0);
    glTranslatef(0,0,-35);
        glPushMatrix();
        glTranslatef(0,4,0);
            cono->draw(1,3);
        glPopMatrix();
        glPushMatrix();
        glPushMatrix();
        glTranslatef(0,10,0);
            cilindro->draw(1,3);
        glPopMatrix();
    glPopMatrix();
}
