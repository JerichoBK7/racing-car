/*************************************************************************/
/*                            C A M E R A                                */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file camara.h
 * Implementation of camera
 * @author Miguel Ángel Díaz López
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef CAMARA_H
#define CAMARA_H

#include <iostream>
#include <GL/gl.h>
#include "vertex.h"
#include "matrix.h"

class camara
{
private:
    _vertex3f VRP;//Posición de la cámara
    _vertex3f VPN;//Orientacion, hacia donde se mira
    _vertex3f VUP;//vector de "hacia arriba"
    _vertex3f n;//= VPN
    _vertex3f u;//= VPN(x)VUP
    _vertex3f v;//= n(x)u
    float angle_n;
    float angle_u;
    float angle_v;
    void setInicializa();
public:
    /*Constructores*/
    camara();
    void set(_vertex3f);
    /*Rotaciones de la camara*/
    void rotateN(float angle); //axis-n
    void rotateU(float angle);  //axis-u
    void rotateV(float angle);//axis-v
    /*Movimiento de la camara*/
    void movCamara(_vertex3f);
    /*Establecer la camara*/
    void setCamara(void);
    void setOrientacion(_vertex3f orientacion){VPN=orientacion;VPN.normalize();setInicializa();}
    /*Obtener valores*/
    void getAngleN(float &angle){angle=angle_n;}
    void getAngleU(float &angle){angle=angle_u;}
    void getAngleV(float &angle){angle=angle_v;}
    void getVRP(_vertex3f &vrp_){vrp_=VRP;}

};

#endif // CAMARA_H
