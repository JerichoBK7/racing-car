/*************************************************************************/
/*                         P I C T U R E S                               */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file cuadros.h
 * Implementation of pictures for the house
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



#ifndef CUADROS_H
#define CUADROS_H

#include "superficie.h"

class cuadros
{
private:
    vector<superficie> marco;
    superficie cuadro;
    BMPClass *textura_cuadro;
    int alto,ancho;
    /*metodos*/
    void construirMarco(char *);
    void construirCuadro(char *);
    void drawMarco();
    void drawCuadro();
public:
    cuadros(){textura_cuadro=NULL;}
    void construir(int,int,char*,char *);
    /*Destructor*/
    ~cuadros(){if(textura_cuadro!=NULL)delete textura_cuadro;}
    /*Otros*/
    void draw();
};

#endif // CUADROS_H
