/*************************************************************************/
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*                                                                       */
/*     License: GPL3                                                     */
/*                                                                       */
/*************************************************************************/
/**
 *
 *   This file is part of superficie.h
 *
 *   superficie.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   superficie.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "superficie.h"

superficie::superficie()
{
}

void superficie::construir(int divisiones, int alto, int ancho, _vertex4f c, _vertex4f l, BMPClass * imagen){
    //otros
    this->color=c;
    this->luz=l;
    this->alto=alto;
    this->ancho=ancho;
    this->vertices.resize((divisiones+1)*(divisiones+1));
    this->num_caras=2*(divisiones)*(divisiones);
    this->columnas=divisiones;
    this->filas=divisiones;
    this->caras.resize(this->num_caras);
    // construccion de vertices de la planta
    for(int i=0;i<=divisiones;i++){
        for(int j=0;j<=divisiones;j++){
            this->vertices[(i*(divisiones+1))+j].x=(-ancho/2)+((ancho/divisiones)*j);
            this->vertices[(i*(divisiones+1))+j].y=0;
            this->vertices[(i*(divisiones+1))+j].z=(-alto/2)+((alto/divisiones)*i);
        }
    }
    // construccion de las caras de la planta:
    int k=0;
    for(int i=0;i<divisiones;i++){
        for(int j=0;j<divisiones;j++){
            this->caras[k]._0=(i*(divisiones+1))+j;
            this->caras[k]._1=((i+1)*(divisiones+1))+(j+1);
            this->caras[k]._2=(i*(divisiones+1))+(j+1);

            this->caras[k+1]._0=(i*(divisiones+1))+j;
            this->caras[k+1]._1=((i+1)*(divisiones+1))+j;
            this->caras[k+1]._2=((i+1)*(divisiones+1))+(j+1);
            k+=2;
        }
    }
    // construccion de la textura
    (imagen==NULL)?this->img=NULL:this->img=imagen;

    // normalizamos para las luces
    this->Normalizar();
}

