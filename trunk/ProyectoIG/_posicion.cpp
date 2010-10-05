/**
 *
 *   This file is part of _posicion.h
 *
 *   _posicion.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   _posicion.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "_posicion.h"


_posicion::_posicion()
{
    // variables
    int num_posiciones=5,divisiones=1;
    char cadena[10];
    _vertex4f blanco,luz,ambient,diffuse,specular;
    string ruta;
    blanco.r=blanco.g=blanco.b=blanco.a=1;

    /*1º.-Construccion de las texturas*/
    puesto.resize(num_posiciones);
    for(int i=0;i<num_posiciones;i++){
        puesto[i] = new BMPClass;
        //conversion del entero a cadena
        sprintf(cadena,"%d",i+1);
        ruta="INFORMACION/Posicion-0"+(string)cadena+".bmp";
        puesto[i]->BMPLoad(ruta,blanco);
    }
    /*2º.-Imagen-Posición del coche*/
    //Luces
    luz.x=0;luz.y=100;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.2;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.3;specular.w=1;
    //superficie
    posicion.resize(num_posiciones);
    for(int i=0;i<num_posiciones;i++){
        posicion[i].construir(divisiones,3,3,blanco,luz,puesto[i]);
        posicion[i].CambiaLuz(luz,ambient,diffuse,specular);
    }
    /*3º.-Embellecedor*/
    luz.x=0;luz.y=4;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
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
    juntas->CambiaMaterial("plasticoAzul");

    luz.x=0;luz.y=4;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.3;specular.w=1;
    juntas2->setColor(1,1,1,1);
    juntas2->CambiaLuz(luz,ambient,diffuse,specular);
    juntas2->Normalizar();
    juntas2->CambiaMaterial("plasticoAzul");
}

_posicion::~_posicion(){
    //imagenes
    for(int i=0;i<puesto.size();i++)
        delete puesto[i];
    //cubo
    delete juntas;
    delete juntas2;
}

void _posicion::draw(int pos, char* material){
    if(pos<0)return;
    pos_actualizada=pos-1;
    juntas->CambiaMaterial(material);
    juntas2->CambiaMaterial(material);
    draw();
}

void _posicion::draw(int pos){
    if(pos<0)return;
    pos_actualizada=pos-1;
    juntas->CambiaMaterial("plasticoAzul");
    juntas2->CambiaMaterial("plasticoAzul");
    draw();
}

void _posicion::draw(void){
    //1º.-Bateria
    glPushMatrix();
    glRotatef(180,0,0,1);
        posicion[pos_actualizada].draw(1,4);
    glPopMatrix();

    //2º.-Juntas
    //abajo - arriba
    glPushMatrix();
    glTranslatef(-0.445,0,-1.03);
    glScalef(2.88,0.15,0.15);
        juntas->draw(1,3);
    glTranslatef(0,0,20.5);
        juntas->draw(1,3);
    glPopMatrix();
    //izq
    glPushMatrix();
    glTranslatef(-1.95,0,0.5);
    glRotatef(90,0,1,0);
    glScalef(3.22,0.15,0.15);
        juntas2->draw(1,3);
    glPopMatrix();
    //der
    glPushMatrix();
    glTranslatef(1.07,0,0.5);
    glRotatef(90,0,1,0);
    glScalef(3.22,0.15,0.15);
        juntas2->draw(1,3);
    glPopMatrix();
}


