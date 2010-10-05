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
 *   This file is part of _battery.h
 *
 *   _battery.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   _battery.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "_battery.h"

_battery::_battery()
{
    // variables
    int num_baterias=7,divisiones=1;
    char cadena[10];
    _vertex4f blanco,luz,ambient,diffuse,specular;
    string ruta;
    blanco.r=blanco.g=blanco.b=blanco.a=1;

    /*1º.-Construccion de las texturas*/
    bateria.resize(num_baterias);
    for(int i=0;i<num_baterias;i++){
        bateria[i] = new BMPClass;
        //conversion del entero a cadena
        if(i==0)sprintf(cadena,"%d",00);
        else if(i==1)sprintf(cadena,"%d",10);
        else sprintf(cadena,"%d",(i-1)*20);
        (i<1)?ruta="BATERIA/Battery-0"+(string)cadena+".bmp":ruta="BATERIA/Battery-"+(string)cadena+".bmp";
        bateria[i]->BMPLoad(ruta,blanco);
    }
    /*2º.-Imagen-Baterias*/
    //Luces
    luz.x=0;luz.y=100;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.2;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.3;specular.w=1;
    //superficie
    battery.resize(num_baterias);
    for(int i=0;i<num_baterias;i++){
        battery[i].construir(divisiones,2,1,blanco,luz,bateria[i]);
        battery[i].CambiaLuz(luz,ambient,diffuse,specular);
    }
    /*3º.-Embellecedor*/
    luz.x=0;luz.y=3;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.3;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.5;diffuse.w=1;
    specular.x=specular.y=specular.z=0.45;specular.w=1;
    /*construir*/
    juntas = new Cube;
    juntas->Construir(1);
    juntas2 = new Cube;
    juntas2->Construir(1);
    /*luz*/
    juntas->setColor(1,1,1,1);
    juntas->CambiaLuz(luz,ambient,diffuse,specular);
    juntas->Normalizar();
    juntas->CambiaMaterial("perla");

    luz.x=0;luz.y=4;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.3;specular.w=1;
    juntas2->setColor(1,1,1,1);
    juntas2->CambiaLuz(luz,ambient,diffuse,specular);
    juntas2->Normalizar();
    juntas2->CambiaMaterial("perla");
}

_battery::~_battery(){
    //imagenes
    for(int i=0;i<bateria.size();i++)
        delete bateria[i];
    //cubo
    delete juntas;
    delete juntas2;
}

void _battery::draw(int estado){
    int num_bat,bat;
    if(estado<=0)num_bat=0;
    else if(estado<10 && estado>0)num_bat=1;
    else for(bat=20,num_bat=2;   bat<estado;  bat+=20,num_bat++);

    /*1º.-Bateria*/
    glPushMatrix();
        battery[num_bat].draw(1,4);
    glPopMatrix();

    /*2º.-Juntas*/
    //abajo - arriba
    glPushMatrix();
    glTranslatef(0.5,0,1.08);
    glScalef(1,0.15,0.15);
        juntas->draw(1,3);
    glTranslatef(0,0,-13.75);
        juntas->draw(1,3);
    glPopMatrix();
    //izq
    glPushMatrix();
    glTranslatef(-0.07,0,0.053);
    glRotatef(90,0,1,0);
    glScalef(2.22,0.15,0.15);
        juntas2->draw(1,3);
    glPopMatrix();
    //der
    glPushMatrix();
    glTranslatef(1.07,0,0.041);
    glRotatef(90,0,1,0);
    glScalef(2.22,0.15,0.15);
        juntas2->draw(1,3);
    glPopMatrix();
}
