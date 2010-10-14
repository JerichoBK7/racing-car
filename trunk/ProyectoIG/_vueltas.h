/*************************************************************************/
/*                           R E T U R N S                               */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file _vueltas.h
 * Implementation of number of the returns in the career
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
