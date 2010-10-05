/**
 *
 *   This file is part of maceta.h
 *
 *   maceta.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   maceta.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "maceta.h"


void maceta::construir(){
    // arbol
    arbol = new _ply;
    arbol->LecturaPly("PLY/arbol.ply");
    arbol->setColor(1,1,1,0);
    arbol->setLuz(0,200,0,0.75);
    arbol->CambiaMaterial("gomaVerde");
    // macetero
    florero = new Cono;
    florero->Construir(10,26,20);
    florero->Normalizar();
    florero->setColor(1,1,1,1);
    florero->setLuz(-200,70,-150,0.5);
    florero->CambiaMaterial("plata");

    soporte = new Cilindro;
    soporte->Construir(5,2,20);
    soporte->Normalizar();
    soporte->setColor(1,1,1,1);
    soporte->setLuz(-200,70,-150,0.5);
    soporte->CambiaMaterial("plata");
}

void maceta::draw(){
    /*1º.-Arbol:*/
    glPushMatrix();
    glTranslatef(0,50,0);
    glRotatef(-7,1,0,0);
    glScalef(5,7,5);
        arbol->draw(1,3);
    glPopMatrix();
    //2º.-Macetero:
    // florero
    glPushMatrix();
    glTranslatef(0,13,0);
    glRotatef(180,1,0,0);
        florero->draw(1,3);
    glPopMatrix();
    // soporte
    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(90,0,-1,0);
        soporte->draw(1,3);
    glPopMatrix();
}

