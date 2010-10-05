/*************************************************************************/
/*                             E N T R Y                                 */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file entrada.h
 * Implementation of entry of the house
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



#ifndef ENTRADA_H
#define ENTRADA_H


#include <iostream>
#include <superficie.h>
#include "primitivas.h"
#include "_object3d.h"
#include "_ply.h"
#include "comodin.h"
#include "maceta.h"

using namespace std;

class entrada
{
private:
    // mueble de entrada
    comodin comoda;
    // espejo
    superficie espejo;
    vector<superficie>borde_espejo;
    // accesorios
    _ply *flor;
    /*Metodos*/
    // construir:
    void construirEspejo();
    void construirFLor();
    // dibujar:
    void drawEspejo();
    void drawFlor();
public:
    entrada(){flor=NULL;}
    /*Destructor*/
    ~entrada(){
        if(flor!=NULL)delete flor;
    }
    /*Constructores*/
    void construir();
    /*Otros metodos*/
    void draw();
};

#endif // ENTRADA_H
