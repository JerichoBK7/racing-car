/*************************************************************************/
/*                             C H A R G E                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file _enchufe.cpp
 * Implementation of place to charge
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

#ifndef _ENCHUFE_H
#define _ENCHUFE_H

#include "superficie.h"
#include "primitivas.h"

class _enchufe
{
private:
    _object3D *juntas;
    superficie enchufe;
    BMPClass *textura;
    /*metodos*/
    void construirEnchufe();
    void construirJuntas();
    void drawEnchufe();
    void drawJuntas();
public:
    /*Constructores*/
    _enchufe(){juntas=NULL;textura=NULL;}
    void construir();
    /*Destructor*/
    ~_enchufe(){
        if(textura!=NULL)delete textura;
        if(juntas!=NULL)delete juntas;
    }
    /*Otros Metodos*/
    void draw(int);
};

#endif // _ENCHUFE_H
