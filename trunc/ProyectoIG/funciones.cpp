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
 *   This file is part of funciones.h
 *
 *   funciones.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   funciones.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "funciones.h"

funciones::funciones()
{
}

void funciones::StoF(float &resultado,char *cad){
    resultado=atoi(cad);
    if(cad[0]=='-')resultado=0-resultado;
    int i, b=1, primero=0;
    for (i=0; i<strlen(cad); i++){
        if(primero==0&&cad[i]=='.')primero=-1;
        else if(primero==-1){//empezamos a crear flotante
            char *c;
            if(cad[i]=='e'){
                int resultado2=0,b2=0;
                for(int j=strlen(cad)-1;j>=i+2;j--){
                    c=(char*)malloc(sizeof(char));
                    sprintf(c,"%c",cad[j]);
                    resultado2+=(atoi(c)*1.0)*pow(10,b2);
                    b2++;
                    free(c);
                }
                if(cad[i+1]=='-')resultado2=0-resultado2;
                resultado*=pow(10,resultado2);
                i=strlen(cad);
            }
            else{
                c=(char*)malloc(sizeof(char));
                sprintf(c,"%c",cad[i]);
                resultado+=(atoi(c)*1.0)/pow(10,b);
                b++;
                free(c);
            }
        }
    }
    if(cad[0]=='-')resultado=0-resultado;
}
