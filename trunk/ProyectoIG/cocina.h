/*************************************************************************/
/*                           K I T C H E N                               */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file cocina.h
 * Implementation of kitchen of the house
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

#ifndef COCINA_H
#define COCINA_H

#include <superficie.h>
#include <campana.h>

class cocina
{
private:
    // varios
    superficie frigo,horno,lavaplatos,lateral_mueble;
    // encimera
    vector<superficie> juntas_encimera;
    superficie encimera;
    // laterales mueble-encimera
    vector<superficie> mueble;
    vector<superficie> liston_mueble;
    // laterales frigo
    vector<superficie> juntas_frigo;
    // campana
    campana campana_horno;
    BMPClass *f,*h,*l,*mueble_;
    // mesa comer-der-cocina
    vector<superficie> lateral_mesa;
    superficie mesa_cocina;
    /*funciones*/
    void drawEncimera();
    void drawFrigo();
    void drawHorno();
    void drawMueble();
    void drawLavaplatos();
    void drawTablaCocina();

public:
    cocina(){f=h=l=mueble_=NULL;}
    /*Destructor*/
    ~cocina(){
        if(f!=NULL)delete f;
        if(h!=NULL)delete h;
        if(l!=NULL)delete l;
        if(mueble_!=NULL)delete mueble_;
    }
    /*Construir*/
    void construirEncimera(void);
    void construirMueble(void);
    void construirFrigo(void);
    void construirTablaCocina(void);
    void construir(void);
    /*Métodos dibujar*/
    void draw();
};

#endif // COCINA_H
