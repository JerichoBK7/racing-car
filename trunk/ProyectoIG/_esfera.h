/*************************************************************************/
/*                             S P H E R E                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 * @file _esfera.h
 * Implementation of Data Type Sphere
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef MGE_SPHERE_H
#define MGE_SPHERE_H

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <unistd.h>
#include "_object3d.h"
using namespace std;

class Esfera : public _object3D
{
private:
    int divisiones;
    int radio;
public:
    /*Constructores*/
    Esfera():divisiones(0){}
    Esfera(int,int,_vertex4f,_vertex4f);
    void Construir(int,int,_vertex4f,_vertex4f);
    /*Destructor*/
    ~Esfera(){}
};


#endif // _ESFERA_H
