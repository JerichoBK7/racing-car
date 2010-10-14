/*************************************************************************/
/*                             L O U N G E                               */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file salon.h
 * Implementation of lounge of the house
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



#ifndef SALON_H
#define SALON_H

#include "mesa.h"
#include "primitivas.h"
#include "_ply.h"
#include "estanteria.h"

class salon
{
private:
    mesa mesita;
    estanteria estante;
    _object3D *asiento;
    _ply tv;
    /*metodos*/
    void drawMesa();
    void drawAsientos();
    void drawTv();
    void drawEstanteria();
public:
    /*constructores*/
    salon(){asiento=NULL;}
    void construir();
    /*destructor*/
    ~salon(){
        if(asiento==NULL)delete asiento;
    }
    /*otros metodos*/
    void draw();
};

#endif // SALON_H
