//**************************************************************************
//
// Utilizando las primitivas de _object3D ( EJE del coche)
//
// Author: Miguel Ángel Díaz López
//
// GPL3
//
//  (c) Marzo 2010
//**************************************************************************
/**
 *
 * @file _wheel.h
 * Implementation of wheel for the car
 * @author Miguel Ángel Díaz López
 *
 */


#ifndef _WHEEL_H
#define _WHEEL_H
#include "primitivas.h"
#include <vector>

class _wheel
{
protected:
    _object3D *ruedas;
public:
    /*Constructor*/
    _wheel():ruedas(0){}
    _wheel(int,int);
    /*Destructor*/
    ~_wheel();
    /*Otros Metodos*/
    void drawEje(int ancho, int largo, int modo, int tipo);
    void ConstruirR(int,int);

};

#endif // _WHEEL_H
