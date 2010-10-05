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
 *   This file is part of _camara.h
 *
 *   _camara.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   _camara.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */



#include "_camara.h"

_camara :: _camara(){
    cam.resize(1);
    num_camaras=1;
    activa=0;
}

void _camara :: crea(int num_cam){
    cam.clear();
    cam.resize(num_cam);
    num_camaras=num_cam;
    activa=0;
}


void _camara :: set(int pos_cam, _vertex3f pos){
    if(pos_cam-1<num_camaras){
        cam[pos_cam-1].set(pos);
        //activa=pos_cam-1;
    }
    //else error
}

void _camara :: set(int pos_cam, _vertex3f pos, _vertex3f orientacion){
    if(pos_cam-1<num_camaras){
        cam[pos_cam-1].set(pos);
        cam[pos_cam-1].setOrientacion(orientacion);
        //activa=pos_cam-1;
    }
    //else error
}


void _camara :: activar(int camara){
    if(camara-1<num_camaras) activa=camara-1;
    //else error
}


void _camara :: rotar(int num_cam, string eje, float _angulo){ //rotar la camara: axis-n, axis-u, axis-v
    if(num_cam-1<num_camaras){
        float angulo;
        if(eje=="axis-n")cam[num_cam-1].getAngleN(angulo);
        else if(eje=="axis-u")cam[num_cam-1].getAngleU(angulo);
        else if(eje=="axis-v")cam[num_cam-1].getAngleV(angulo);
        else return; //se produjo error

        angulo+=_angulo;

        if(eje=="axis-n") cam[num_cam-1].rotateN(angulo);
        else if(eje=="axis-u") cam[num_cam-1].rotateU(angulo);
        else if(eje=="axis-v") cam[num_cam-1].rotateV(angulo);
        //else error
    }
    //else error
}

void _camara :: rotar(string eje, string direccion){ //rotar la camara: axis-n, axis-u, axis-v
    float angulo;
    if(eje=="axis-n")cam[activa].getAngleN(angulo);
    else if(eje=="axis-u")cam[activa].getAngleU(angulo);
    else if(eje=="axis-v")cam[activa].getAngleV(angulo);
    else return; //se produjo error
    if(direccion=="der"){
        if(angulo<0)angulo=0;
        angulo+=0.5;
    }
    else{
        if(angulo>0)angulo=0;
        angulo-=0.5;
    }
    if(eje=="axis-n") cam[activa].rotateN(angulo);
    else if(eje=="axis-u") cam[activa].rotateU(angulo);
    else if(eje=="axis-v") cam[activa].rotateV(angulo);
    //else error
}


void _camara :: movCamara(int num_cam, string eje, float _angulo){ //mover la camara: axis-z, axis-y, axis-x
    if(num_cam-1<num_camaras){
        _vertex3f mov;
        mov.x=mov.y=mov.z=0;
        if(eje=="axis-x")mov.x=_angulo;
        else if(eje=="axis-y")mov.y=_angulo;
        else if(eje=="axis-z")mov.z=_angulo;
        else return; //se produjo error
        cam[num_cam-1].movCamara(mov);
    }
    //else error

}
void _camara :: movCamara(string eje, string dir){ //mover la camara: axis-z, axis-y, axis-x
    _vertex3f mov;
    mov.x=mov.y=mov.z=0;
    if(eje=="axis-x")(dir=="up")?mov.x=-3:mov.x=3;
    else if(eje=="axis-y")(dir=="up")?mov.y=-3:mov.y=3;
    else if(eje=="axis-z")(dir=="up")?mov.z=-3:mov.z=3;
    else return; //se produjo error
    cam[activa].movCamara(mov);
}

void _camara :: next(void){ // activamos la siguiente camara y desactivamos la actual
    activa++;
    if(activa>=num_camaras)activa=0;
}


void _camara :: back(void){ // activamos la camara anterior y descactivamos la actual
    activa--;
    if(activa<0)activa=num_camaras-1;
}




