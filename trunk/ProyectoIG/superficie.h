/*************************************************************************/
/*                             S U R F A C E                             */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file superficie.h
 * Implementation of Data Type surfaces
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef SUPERFICIE_H
#define SUPERFICIE_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vertex.h>
#include <_object3d.h>
#include <GL/gl.h>
#include <BMPLoader.h>


class superficie : public _object3D
{

protected:
    int alto, ancho;

public:
    superficie();
    void construir(int,int,int,_vertex4f,_vertex4f,BMPClass*);
    /* Obtención datos */
    int getH(){return alto;}
    int getA(){return ancho;}
};

#endif // SUPERFICIE_H
