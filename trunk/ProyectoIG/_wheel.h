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
