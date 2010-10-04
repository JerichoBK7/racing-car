/*************************************************************************/
/*                         P O S I T I O N                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file _posicion.h
 * Implementation of position of the car (control by human) in the career
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef _POSICION_H
#define _POSICION_H

#include "stdlib.h"
#include "BMPLoader.h"
#include "superficie.h"
#include "primitivas.h"

class _posicion
{
private:
    vector<BMPClass *> puesto;
    vector<superficie> posicion;
    _object3D *juntas,*juntas2;
    int pos_actualizada;
public:
    /*Constructor*/
    _posicion();
    /*Destructor*/
    ~_posicion();
    /*Otros Metodos*/
    void draw(int, char*);
    void draw(int);
    void draw(void);
};

#endif // _POSICION_H


