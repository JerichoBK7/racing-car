/*************************************************************************/
/*                                B E L L                                */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file campana.h
 * Implementation of beel for the kitchen
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef CAMPANA_H
#define CAMPANA_H

#include <iostream>
#include "_object3d.h"
#include "primitivas.h"
#include "_car.h"
using namespace std;

class campana
{
protected:
    _object3D *cono;
    _object3D *cilindro;
    _car coche;

public:
    /*Constructores*/
    campana();
    /*Destructor*/
    ~campana();
    /*Otras funciones*/
    void draw();
};

#endif // CAMPANA_H
