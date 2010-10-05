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
