/*************************************************************************/
/*                          B A S I C - O B J E C T S                    */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file primitivas.h
 * Implementation of Data Type basic objects
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



#ifndef PRIMITIVAS_H
#define PRIMITIVAS_H
#include <iostream>
#include <GL/gl.h>
#include <math.h>
#include "_object3d.h"
using namespace std;

/*************************************************************************/
/*                        T E T R A E D R O                              */
/*                                                                       */
/*************************************************************************/
class Tetraedro:public _object3D
{
protected:
    float radio;
    void Construir(float);
public:
    /*Constructores*/
    Tetraedro():radio(0){}
    Tetraedro(float);
    /*Destructor*/
    ~Tetraedro();
};

/*************************************************************************/
/*                              C U B O                                  */
/*                                                                       */
/*************************************************************************/
class Cube:public _object3D
{
protected:
    float lado;
    void Construir(float);
public:
    /*Constructores*/
    Cube():lado(0){}
    Cube(float);
    /*Destructor*/
    ~Cube();
};

/*************************************************************************/
/*                              C O N O                                  */
/*                                                                       */
/*************************************************************************/
class Cono:public _object3D
{
protected:
    float radio;
    float altura;
    int divisiones;
    void Construir(float,float,int);
public:
    /*Constructores*/
    Cono():radio(0),altura(0),divisiones(0){}
    Cono(float,float,int);
    /*Destructor*/
    ~Cono();
};

/*************************************************************************/
/*                         C I L I N D R O                               */
/*                                                                       */
/*************************************************************************/
class Cilindro:public _object3D
{
protected:
    float radio;
    float altura;
    int divisiones;
    void Construir(float,float,int);
public:
    /*Constructores*/
    Cilindro():radio(0),altura(0),divisiones(0){}
    Cilindro(float,float,int);
    /*Destructor*/
    ~Cilindro();
};

#endif // PRIMITIVAS_H
