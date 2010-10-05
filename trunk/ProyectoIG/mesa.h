/*************************************************************************/
/*                             T A B L E                                 */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file mesa.h
 * Implementation of table for the house
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



#ifndef MESA_H
#define MESA_H

#include "superficie.h"
#include "primitivas.h"

class mesa
{
private:
    _object3D *patas,*mesita;
    /*metodos*/
    void construirPatas();
    void cosntruirMesa();
    void drawPatas();
    void drawMesa();
public:
    /*constructores*/
    mesa(){patas=mesita=NULL;}
    void construir();
    /*destrucotr*/
    ~mesa(){
        if(patas!=NULL)delete patas;
        if(mesita!=NULL)delete mesita;
    }
    /*otros metodos*/
    void draw();
};

#endif // MESA_H
