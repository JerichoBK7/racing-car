/*************************************************************************/
/*                             S P H E R E                               */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 * @file _esfera.h
 * Implementation of Data Type Sphere
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
