/*************************************************************************/
/*                               M E N U                                 */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file _menu.h
 * Implementation of menu
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


#ifndef _MENU_H
#define _MENU_H

#include "superficie.h"
#include "primitivas.h"

class _menu
{
private:
    //menus
    superficie menu_pause, menu_principal, menu_creditos;
    BMPClass *textura_menu_principal, *textura_menu_pause, *textura_menu_creditos;
    //resultados
    superficie has_ganado, has_perdido;
    BMPClass *textura_ganador, *textura_perdedor;
    _object3D *juntas;
    /*metodos Menus*/
    void construirBotonera(void);
    void construirMenuPrincipal();
    void drawMenuPrincipal();
    void construirMenuPause();
    void drawMenuPause();
    void construirMenuCreditos();
    void drawMenuCreditos();
    /*metodos Resultados*/
    void construirResultado();
    void construirJuntas();
    void drawResultado(string);
    void drawJuntas();
    /*Posiciones de los botones*/
    int x_min, x_max;
    int ancho, alto;
    int boton1_min, boton1_max;
    int boton2_min, boton2_max;
    int boton3_min, boton3_max;
    int boton4_x, boton4_y;
public:
    /*Constructores*/
    _menu(){
        textura_menu_principal=textura_menu_pause=textura_menu_creditos=NULL;
        textura_ganador=textura_perdedor=NULL;
        juntas=NULL;
    }
    void construir();
    /*Destructor*/
    ~_menu(){
        if(textura_menu_principal!=NULL)delete textura_menu_principal;
        if(textura_menu_pause!=NULL)delete textura_menu_pause;
        if(textura_menu_creditos!=NULL)delete textura_menu_creditos;
        if(textura_ganador!=NULL)delete textura_ganador;
        if(textura_perdedor!=NULL)delete textura_perdedor;
        if(juntas!=NULL)delete juntas;
    }
    /*Otros Metodos*/
    string BotonPulsado(int,int,int,int);
    void draw(string);
};

#endif // _MENU_H
