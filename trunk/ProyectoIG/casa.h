/*************************************************************************/
/*                             H O M E                                   */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file casa.h
 * Implementation of house where you play
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

#ifndef CASA_H
#define CASA_H

#include <superficie.h>
#include <puerta.h>
#include <cocina.h>
#include <entrada.h>
#include <maceta.h>
#include "_ply.h"
#include "salon.h"
#include "cuadros.h"
#include "lampara.h"
#include "_enchufe.h"
#include "_car.h"

class casa
{
private:
    vector<superficie> suelo;
    vector<superficie> pared;
    vector<superficie> techo;
    vector<superficie> juntas;//para acabados de la casa
    puerta p;
    // casa
    cocina c;
    entrada e;
    salon s;
    _enchufe enchufe;// 3 enchufes
    // accesorios
    maceta macetita;
    _ply tetera, ketchup, silla, sandalia, zapatilla, muelle, tijeras, cubo_basura, guitarra;
    cuadros cuadro[6];
    lampara lamparita;
    Esfera pelota;
    _car coche_cutre;
    // texturas
    BMPClass *cocina_, *entrada_, *salon_;
    /*Otros metodos*/
    // constuir
    void construirSuelo(void);
    void construirPared(void);
    void construirTecho(void);
    void construirJuntas(void);
    //pintar
    void drawSuelo();
    void drawPared();
    void drawTecho();
    void drawJuntas();
    void drawPuerta();
    void drawCocina();
    void drawEntrada();
    void drawSalon();
    void drawEnchufe(int,int,int);// estados de los 3 enchufes
    // otras funciones
    _vertex3f recta(_vertex3f,_vertex3f);//recta que pasa entre dos puntos
    double distancia(_vertex3f,_vertex3f);//distancia entre una 'r' y un 'punto'

public:
    casa(){cocina_=entrada_=salon_=NULL;}
    /* destructor */
    ~casa(){
        if(cocina_!=NULL)delete cocina_;
        if(entrada_!=NULL)delete entrada_;
        if(salon_!=NULL)delete salon_;
    }

    /* construir */
    void creaCasa();
    /* dibujar */
    void draw(int,int,int);// estados de los 3 enchufes
    /*Otros metodos*/
    bool CompruebaColision(_vertex3f,double);
};

#endif // CASA_H
