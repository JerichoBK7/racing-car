/*************************************************************************/
/*                       F O R N I T U R E                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file comodin.h
 * Implementation of forniture of the entry
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


#ifndef COMODIN_H
#define COMODIN_H

#include "superficie.h"
#include "primitivas.h"

class comodin
{
private:
    /*Obj.Privados*/
    superficie cajon;
    vector<superficie>borde_cajon;
    _object3D *tirador;
    vector<superficie>mueble_lateral;
    superficie mueble_entrada;
    /*Metodos*/
    void construirCajon();
    void construirMueble();
public:
    /*Constructores*/
    comodin(){tirador=NULL;}
    void construir();
    /*Destructor*/
    ~comodin(){
        if(tirador!=NULL)delete tirador;
    }
    /*Otros Metodos*/
    void drawCajon();
    void drawMueble();
    void draw();
};

#endif // COMODIN_H
