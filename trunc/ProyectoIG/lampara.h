/*************************************************************************/
/*                              L A M P                                  */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file lampara.h
 * Implementation of lamp for the rooms of the house
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



#ifndef LAMPARA_H
#define LAMPARA_H

#include "_object3d.h"
#include "primitivas.h"
#include "_esfera.h"

class lampara
{
private:
    _object3D *cono, *cono2;// diseño lampara
    Esfera bombilla;
    _object3D *cilindro, *conector;//cable lampara
    /*Metodos*/
    void construirLampara();
    void construirBombilla();
    void construirCable();
    void drawLampara(char*,char*);
    void drawBombilla();
    void drawCable();

public:
    /*Constructores*/
    lampara(){cono=cilindro=cono2=conector=NULL;}
    void construir();
    /*Destructor*/
    ~lampara(){
        if(cono!=NULL)delete cono;
        if(cilindro!=NULL)delete cilindro;
        if(cono2!=NULL)delete cono2;
        if(conector!=NULL)delete conector;
    }
    /*Otros Metodos*/
    void draw(char*,char*);//lampara + borde
};

#endif // LAMPARA_H
