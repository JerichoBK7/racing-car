/*************************************************************************/
/*                                 R A C K                               */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file estanteria.h
 * Implementation of rack for the house
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



#ifndef ESTANTERIA_H
#define ESTANTERIA_H

#include "superficie.h"
#include "primitivas.h"

class estanteria
{
private:
    /*Obj.Privados*/
    superficie puerta;
    vector<superficie>borde_puerta;
    _object3D *balda,*tirador;
    /*Metodos*/
    void construirPuerta();
    void construirMueble();
public:
    /*Constructores*/
    estanteria(){tirador=balda=NULL;}
    void construir();
    /*Destructor*/
    ~estanteria(){
        if(balda!=NULL)delete balda;
        if(tirador!=NULL)delete tirador;
    }
    /*Otros Metodos*/
    void drawPuerta();
    void drawMueble();
    void draw();
};

#endif // ESTANTERIA_H
