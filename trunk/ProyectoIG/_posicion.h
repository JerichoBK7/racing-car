/*************************************************************************/
/*                         P O S I T I O N                               */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file _posicion.h
 * Implementation of position of the car (control by human) in the career
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


