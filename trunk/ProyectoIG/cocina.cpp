/**
 *
 *   This file is part of cocina.h
 *
 *   cocina.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   cocina.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "cocina.h"


void cocina :: construir(){
    // encimera
    construirEncimera();
    // frigo
    construirFrigo();
    // mueble
    construirMueble();
    // mesa cocina der
    construirTablaCocina();
}

void cocina :: construirTablaCocina(void){
    int divisiones=1;
    /*luces y blanco*/
    _vertex4f blanco,luz_repisa,luz_lateral;
    blanco.r=1;blanco.g=1;blanco.b=1;blanco.a=1;
    luz_lateral.x=0;luz_lateral.y=50;luz_lateral.z=0;luz_lateral.w=1;
    luz_repisa.x=0;luz_repisa.y=25;luz_repisa.z=0;luz_repisa.w=0.75;
    /*construccion*/
    mesa_cocina.construir(divisiones,50,114,blanco,luz_repisa,NULL);//repisa mesa
    lateral_mesa.resize(2);
    lateral_mesa[0].construir(divisiones,4,114,blanco,luz_lateral,NULL);//largo
    lateral_mesa[1].construir(divisiones,4,50,blanco,luz_lateral,NULL);//corto

    mesa_cocina.CambiaMaterial("esmeralda");
    lateral_mesa[0].CambiaMaterial("esmeralda");
    lateral_mesa[1].CambiaMaterial("esmeralda");
}

void cocina :: construirEncimera(void){
    _vertex4f luz,color,luz_juntas;
    int divisiones;
    divisiones=1;
    /*Configuración*/
    luz.x=0;luz.y=70;luz.z=0;luz.w=0.85;
    luz_juntas.x=0;luz_juntas.y=100;luz_juntas.z=0;luz_juntas.w=0.5;
    color.r=0;color.g=0;color.b=0;color.a=1;
    /*Construcción*/
    encimera.construir(divisiones,76,198,color,luz,NULL);//encimera
    encimera.CambiaMaterial("esmeralda");
    juntas_encimera.resize(2);
    juntas_encimera[0].construir(divisiones,4,198,color,luz_juntas,NULL);//laterales_encimera (largo)
    juntas_encimera[1].construir(divisiones,4,76,color,luz_juntas,NULL);//laterales_encimera (corto)
    juntas_encimera[0].CambiaMaterial("esmeralda");
    juntas_encimera[1].CambiaMaterial("esmeralda");
}

void cocina :: construirFrigo(void){
    _vertex4f luz,color,color_;
    int divisiones;
    divisiones=1;
    /*Configuración*/
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;
    color.r=1;color.g=1;color.b=1;color.a=1;
    color_.r=1;color_.g=0;color_.b=0;color_.a=1;
    /*Construccion*/
    f=new BMPClass;
    f->BMPLoad("BMP/frigo.bmp",color);
    frigo.construir(divisiones,90,54,color,luz,f);

    glRotatef(90,1,0,0);
    luz.x=0;luz.y=100;luz.z=0;luz.w=0.5;
    juntas_frigo.resize(2);
    juntas_frigo[0].construir(divisiones,60,90,color_,luz,NULL);//lateral_frigo (largo)
    juntas_frigo[1].construir(divisiones,60,54,color_,luz,NULL);//lateral_frigo (corto)
    juntas_frigo[0].CambiaMaterial("cromo");
    juntas_frigo[1].CambiaMaterial("cromo");
}

void cocina :: construirMueble(void){
    _vertex4f luz,luz_liston,blanco,color;
    int divisiones;
    divisiones=1;
    /*Configuración*/
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;
    luz_liston.x=0;luz_liston.y=20;luz_liston.z=0;luz_liston.w=1;
    blanco.r=1;blanco.g=1;blanco.b=1;color.a=1;
    /*Construccion*/
    // horno
    h=new BMPClass;
    h->BMPLoad("BMP/horno.bmp",blanco);
    horno.construir(divisiones,40,46,blanco,luz,h);
    // lavaplatos
    l=new BMPClass;
    l->BMPLoad("BMP/lavaplatos.bmp",blanco);
    lavaplatos.construir(divisiones,46,48,blanco,luz,l);
    // mueble-encimera
    mueble_=new BMPClass;
    mueble_->BMPLoad("BMP/mueble.bmp",blanco);
    mueble.resize(3);
    mueble[0].construir(divisiones,40,55,blanco,luz,mueble_);//arriba der y laterales izqu
    mueble[1].construir(divisiones,40,56,blanco,luz,mueble_);//arriba izq
    mueble[2].construir(divisiones,40,46,blanco,luz,mueble_);//abajo der-lavaplatos
    // lateral-encimera
    lateral_mueble.construir(divisiones,70,46,blanco,luz,NULL);
    lateral_mueble.CambiaMaterial("esmeralda");
    // listones-abajo
    liston_mueble.resize(3);
    liston_mueble[0].construir(divisiones,6,128,blanco,luz_liston,NULL);
    liston_mueble[0].CambiaMaterial("esmeralda");
    luz_liston.y=10;
    liston_mueble[1].construir(divisiones,6,46,blanco,luz_liston,NULL);
    liston_mueble[1].CambiaMaterial("esmeralda");
    luz_liston.y=20;
    liston_mueble[2].construir(divisiones,6,110,blanco,luz_liston,NULL);
    liston_mueble[2].CambiaMaterial("esmeralda");
}

void cocina::drawEncimera(){
    //parte arriba y abajo (superficie)
    glPushMatrix();
    glTranslatef(0,2,0);
        encimera.draw(1,3);
    glTranslatef(0,-4,0);
        encimera.draw(1,3);
    glPopMatrix();
    //lateral grande (abajo y arriba)
    glPushMatrix();
    glTranslatef(0,0,38);
    glRotatef(90,1,0,0);
        juntas_encimera[0].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-38);
    glRotatef(90,1,0,0);
        juntas_encimera[0].draw(1,3);
    glPopMatrix();
    //lateral pequeño (izq y der)
    glPushMatrix();
    glTranslatef(-99,0,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
        juntas_encimera[1].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(99,0,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
        juntas_encimera[1].draw(1,3);
    glPopMatrix();
}

void cocina::drawFrigo(){
    //textura frigo (superficie - 90x50)
    glPushMatrix();
    glTranslatef(0,45,0);
    glRotatef(180,0,1,0);
    glRotatef(90,1,0,0);
        frigo.draw(1,4);
    glPopMatrix();
    //lateral izq - der (80x90)
    glPushMatrix();
    glTranslatef(0,45,0);
    glTranslatef(0,0,-30);
    glTranslatef(-27,0,0);
    glRotatef(90,0,0,1);
        juntas_frigo[0].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,45,0);
    glTranslatef(0,0,-30);
    glTranslatef(27,0,0);
    glRotatef(90,0,0,1);
        juntas_frigo[0].draw(1,3);
    glPopMatrix();
    // arriba (54x60)
    glPushMatrix();
    glTranslatef(0,90,0);
    glTranslatef(0,0,-30);
        juntas_frigo[1].draw(1,3);
    glPopMatrix();
}

void cocina :: drawHorno(){
    glPushMatrix();
    glTranslatef(0,26,0);
    glTranslatef(0,0,32);
    glTranslatef(21,0,0);
    glRotatef(180,0,1,0);
    glRotatef(90,1,0,0);
        horno.draw(1,4);
    glPopMatrix();
}

void cocina :: drawLavaplatos(){
    glPushMatrix();
    glTranslatef(0,23,0);
    glTranslatef(0,0,102);
    glTranslatef(-29,0,0);
    glRotatef(90,0,-1,0);
    glRotatef(90,1,0,0);
        lavaplatos.draw(1,4);
    glPopMatrix();
}

void cocina :: drawMueble(){
    // mueble 0 (arriba der-horno)
    glPushMatrix();
    glTranslatef(0,26,0);
    glTranslatef(71,0,0);
    glTranslatef(0,0,32);
    glRotatef(90,1,0,0);
        mueble[0].draw(1,4);
    glPopMatrix();
    // mueble 1 (arriba izq-horno)
    glPushMatrix();
    glTranslatef(0,26,0);
    glTranslatef(-30,0,0);
    glTranslatef(0,0,32);
    glRotatef(90,1,0,0);
        mueble[1].draw(1,4);
    glPopMatrix();
    // mueble 2 (abajo der-lavaplatos)
    glPushMatrix();
    glTranslatef(0,26,0);
    glTranslatef(-29,0,0);
    glTranslatef(0,0,55);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
        mueble[2].draw(1,4);
    glPopMatrix();
    // mueble 3
    glPushMatrix();
    glTranslatef(0,26,0);
    glTranslatef(-29,0,0);
    glTranslatef(0,0,154);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
        mueble[0].draw(1,4);
    glPopMatrix();
    // mueble 4
    glPushMatrix();
    glTranslatef(0,26,0);
    glTranslatef(-29,0,0);
    glTranslatef(0,0,209);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
        mueble[0].draw(1,4);
    glPopMatrix();

    // listones
    glPushMatrix();//liston arriba
    glTranslatef(0,3,0);
    glTranslatef(35,0,0);
    glTranslatef(0,0,32);
    glRotatef(90,1,0,0);
        liston_mueble[0].draw(1,3);
    glPopMatrix();
    glPushMatrix();//izq-(der-lavaplatos)
    glTranslatef(0,3,0);
    glTranslatef(-29,0,0);
    glTranslatef(0,0,55);
    glRotatef(90,0,0,1);
    glRotatef(90,0,1,0);
        liston_mueble[1].draw(1,3);
    glPopMatrix();
    glPushMatrix();//izq-(izq-lavaplatos)
    glTranslatef(0,3,0);
    glTranslatef(-29,0,0);
    glTranslatef(0,0,181);
    glRotatef(90,0,0,1);
    glRotatef(90,0,1,0);
        liston_mueble[2].draw(1,3);
    glPopMatrix();
}

void cocina::drawTablaCocina(){
    // superficies
    glPushMatrix();
    glTranslatef(0,2,0);
        mesa_cocina.draw(1,3);
    glTranslatef(0,-4,0);
        mesa_cocina.draw(1,3);
    glPopMatrix();
    // lateral largo
    glPushMatrix();
    glTranslatef(0,0,25);
    glRotatef(90,1,0,0);
        lateral_mesa[0].draw(1,3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-25);
    glRotatef(90,1,0,0);
        lateral_mesa[0].draw(1,3);
    glPopMatrix();
    // laterales pequeños
    glPushMatrix();
    glTranslatef(57,0,0);
    glRotatef(90,0,0,1);
    glRotatef(90,0,1,0);
        lateral_mesa[1].draw(1,3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-57,0,0);
    glRotatef(90,0,0,1);
    glRotatef(90,0,1,0);
        lateral_mesa[1].draw(1,3);
    glPopMatrix();
}

void cocina::draw(){
    // encimera
    glPushMatrix();
    glTranslatef(0,48,0);
        drawEncimera();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,48,0);
    glTranslatef(-61,0,0);
    glTranslatef(0,0,137);
    glRotatef(90,0,1,0);
        drawEncimera();
    glPopMatrix();
    // frigo 54x60x90
    glPushMatrix();
    glTranslatef(0,0,22);//adelantamos
    glTranslatef(126,0,0);//situamos al lado de la encimera
        drawFrigo();
    glPopMatrix();
    // horno 40x54
    drawHorno();
    // lavaplatos 40x45
    drawLavaplatos();
    // mueble
    drawMueble();
    // juntas-mueble-encimera 70x45
    glPushMatrix();
    glTranslatef(0,23,0);
    glTranslatef(-64,0,0);
    glTranslatef(0,0,236);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
        lateral_mueble.draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,23,0);
    glTranslatef(0,0,-3);
    glTranslatef(99,0,0);
    glRotatef(90,0,0,1);
        lateral_mueble.draw(1,3);
    glPopMatrix();
    // campana
    campana_horno.draw();
    // mesa_cocina
    glPushMatrix();
    glTranslatef(0,48,0);
    glTranslatef(0,0,159);
    glTranslatef(186,0,0);
    glRotatef(90,0,1,0);
        drawTablaCocina();
    glPopMatrix();
}
