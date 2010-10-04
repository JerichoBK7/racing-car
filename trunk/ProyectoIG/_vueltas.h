/*************************************************************************/
/*                           R E T U R N S                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file _vueltas.h
 * Implementation of number of the returns in the career
 * @author Miguel Ángel Díaz López
 *
 */


#ifndef _VUELTAS_H
#define _VUELTAS_H


#include "stdlib.h"
#include "BMPLoader.h"
#include "superficie.h"
#include "primitivas.h"


class _vueltas
{
private:
    vector<BMPClass *> textura_vuelta;
    vector<superficie> vuelta;
    _object3D *juntas,*juntas2;
public:
    /*Constructor*/
    _vueltas();
    /*Destructor*/
    ~_vueltas();
    /*Otros Metodos*/
    void draw(int);
};


#endif // _VUELTAS_H
