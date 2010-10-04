//**************************************************************************
// Utilizando las primitivas de _object3D - C A R
//
// Author: Miguel Ángel Díaz López
//
//  GPL3
//
//  (c) Marzo 2010
//**************************************************************************
/**
 * @file _car.h
 * Implementation of car
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef _CAR_H
#define _CAR_H
#include <GL/gl.h>
#include "primitivas.h"
#include "_wheel.h"

class _car
{
protected:
    _wheel rueda;
    _object3D *chasis_;
    _object3D *cabina_;
    _object3D *faro;
public:
    /*Constructores*/
    _car();
    /*Destructor*/
    ~_car();
    /*Otros Metodos*/
    void draw(int modo, int tipo);
    void eje(int,int,int,int);
    void chasis(int,int,int,int);
    void cabina(int,int,int,int);
    void faros(int,int,int,int);
};

#endif // _CAR_H
