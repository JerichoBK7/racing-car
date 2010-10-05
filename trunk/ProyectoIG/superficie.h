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
