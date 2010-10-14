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
 *   This file is part of camara.h
 *
 *   camara.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   camara.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */



#include "camara.h"

camara::camara(){
    int Front_plane=10;
    /* camara */
    // punto de referencia:
    VRP.x=0;VRP.y=500;VRP.z=0;
    // orientacion:
    VPN.x=0;VPN.y=1;VPN.z=0;
    // hacia arriba:
    VUP.x=0;VUP.y=1;VUP.z=0;
    // vectores n,u,v:
    n=VPN;
    u=VUP.cross_product(n);
    v=n.cross_product(u);
    /* Angulos */
    angle_n=0;
    angle_u=0;
    angle_v=0;
}

void camara::set(_vertex3f pos){
    // punto de referencia y orientacion:
    VPN=VRP=pos;
    VPN.normalize();
    // inicializa
    setInicializa();
}

void camara::setInicializa(void){
    // hacia arriba:
    VUP.x=0;VUP.y=1;VUP.z=0;
    // vectores n,u,v:
    n=VPN;
    u=VUP.cross_product(n);
    v=n.cross_product(u);
    /* Angulos */
    angle_n=0;
    angle_u=0;
    angle_v=0;
}

void camara::setCamara(void){
    _matrix4f mat;
    _vertex3f n_,u_,u__;
    float alpha, beta, gamma;

    alpha=atan2(n.y,n.z)*180/M_PI;
    n_=n*mat.rotate_axis_x(alpha);
    u_=u*mat.rotate_axis_x(alpha);
    beta=atan2(n.x,n_.z)*180/M_PI;
    u__=u_*mat.rotate_axis_y(-beta);
    gamma=atan2(u__.y,u__.x)*180/M_PI;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-gamma,0,0,1);
    glRotatef(-beta,0,1,0);
    glRotatef(alpha,1,0,0);
    glTranslatef(-VRP.x,-VRP.y,-VRP.z);
}

//>>>>>>>>>>>>>>>>>>>>>>>> DESPLAZAMIENTO DE LA camara <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void camara :: movCamara(_vertex3f mov){
      //To move a distance delU along the u-axis, set
      //eye to eye + delU u.  This combines all three
      //movements to slide the camera an amount delU
      //along u, delV along v, and delN along n.
      VRP.x += mov.x * u.x + mov.y * v.x + mov.z * n.x;
      VRP.y += mov.x * u.y + mov.y * v.y + mov.z * n.y;
      VRP.z += mov.x * u.z + mov.y * v.z + mov.z * n.z;
      setCamara();
}


//>>>>>>>>>>>>>>>>>>>>>>>>>> ROTACIONES DE LA camara <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//Rotar la camara sobre el eje: N
//(INCLINARSE hacia la derecha o hacia la izquierda...)
void camara :: rotateN(float angle){
    angle_n=angle;
    //Rotamos la camara por angulos sobre el eje "n":
    float cs = cos (3.14159265/180 * angle);
    float sn = sin (3.14159265/180 * angle);
    _vertex3f t = u;
    //El nuevo vector "u":  u cos(angle) - v sin(angle)
    u.x=cs*t.x - sn*v.x;
    u.y=cs*t.y - sn*v.y;
    u.z=cs*t.z - sn*v.z;
    //El nuevo vector "v":  u sin(angle) + v cos(angle)
    v.x=sn*t.x + cs*v.x;
    v.y=sn*t.y + cs*v.y;
    v.z=sn*t.z + cs*v.z;
    setCamara();
}
//Rotar la camara sobre el eje: U
//(OBSERVAR hacia la izquierda o hacia la derecha...)
void camara :: rotateU(float angle){
     angle_u=angle;
    //Rotamos la camara por angulos sobre el eje "u":
    float cs = cos (3.14159265/180 * angle);
    float sn = sin (3.14159265/180 * angle);
    _vertex3f t = v;
    //determine the new u by finding  u cos(angle) - v sin(angle)
    v.x=cs*t.x + sn*n.x;
    v.y=cs*t.y + sn*n.y;
    v.z=cs*t.z + sn*n.z;
    //determine the new v by finding  u sin(angle) + v cos(angle)
    n.x=-sn*t.x + cs*n.x;
    n.y=-sn*t.y + cs*n.y;
    n.z=-sn*t.z + cs*n.z;
    setCamara();
}
//Rotar la camara sobre el eje: V
//(OBSERVAR hacia arriba o hacia abajo...)
void camara :: rotateV(float angle){
     angle_v=angle;
    //Rotamos la camara por angulos sobre el eje "v":
    float cs = cos (3.14159265/180 * angle);
    float sn = sin (3.14159265/180 * angle);
    _vertex3f t = u;
    //El nuevo vector "u":  u cos(angle) - v sin(angle)
    u.x=cs*t.x + sn*n.x;
    u.y=cs*t.y + sn*n.y;
    u.z=cs*t.z + sn*n.z;
    //El nuevo vector "n":  u sin(angle) + v cos(angle)
    n.x=-sn*t.x + cs*n.x;
    n.y=-sn*t.y + cs*n.y;
    n.z=-sn*t.z + cs*n.z;
    setCamara();
}


