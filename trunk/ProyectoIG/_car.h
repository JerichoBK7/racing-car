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
