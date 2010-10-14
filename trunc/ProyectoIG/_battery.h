/*************************************************************************/
/*                             B A T T E R Y                             */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 * @file _battery.h
 * Implementation of battery for the car
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

#ifndef _BATTERY_H
#define _BATTERY_H

#include "stdlib.h"
#include "BMPLoader.h"
#include "superficie.h"
#include "random.h"
#include "primitivas.h"

class _battery
{
private:
    vector<BMPClass *> bateria;
    vector<superficie> battery;
    _object3D *juntas,*juntas2;
public:
    /*Constructor*/
    _battery();
    /*Destructor*/
    ~_battery();
    /*Otros metodos*/
    void draw(int);
};

#endif // _BATTERY_H
