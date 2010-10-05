/*************************************************************************/
/*                            H A N D L E                                */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file maceta.h
 * Implementation of handle for the house
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



#ifndef MACETA_H
#define MACETA_H

#include "_object3d.h"
#include "primitivas.h"
#include "_ply.h"

class maceta
{
private:
    _object3D *soporte,*florero;
    _ply *arbol;
public:
    /*Constructor*/
    maceta(){
        soporte=florero=NULL;
        arbol=NULL;
    }
    void construir();
    /*Desctructor*/
    ~maceta(){
        if(arbol!=NULL)delete arbol;
        if(florero!=NULL)delete florero;
        if(soporte!=NULL)delete soporte;
    }
    /*Otros Metodos*/
    void draw();
};

#endif // MACETA_H
