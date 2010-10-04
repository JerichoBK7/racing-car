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
