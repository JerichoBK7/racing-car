/*************************************************************************/
/*                        P A R T I C L E S                              */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file entidad_game.h
 * Implementation of particles and all "IA" for its
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




#ifndef ENTIDAD_GAME_H
#define ENTIDAD_GAME_H

#include <GL/gl.h>
#include "vertex.h"
#include "_ply.h"
#include <vector>
#include "random.h"
#include <iostream>
#include <time.h>
#include "casa.h"
#include "time.h"
using namespace std;

class entidad_game
{
private:
    struct particula{
        _vertex3f pos_i, pos_act, pos_f, pos_ant;
        double giro, giro_y, alfa, beta, giro_beta;
        _vertex4f giro_inicial;//orientar en el eje de las 'z', 'x'
        _vertex4f giro_inicial_y;//orientar en el eje de la 'y'
        _vertex3f escala;//escalado inicial de la  particula
        _vertex3f ori_nueva, ori_bat;
        double angulo_orientacion;
        _vertex3f orientacion;
        _vertex3f translate_i;
        _ply *obj;
        _vertex4f luz,ambient,diffuse,specular;
        string material;
        // movimiento:
        double ticks,ticks_angulares;
        double distancia;
        double num_ticks,cont_ticks;
        bool mov_lineal;
        double num_angular, cont_angular;
        string Estado;
        double subir;
        bool humano;
        string tecla;
        double avanza_dist; //distancia que aceleramos
        double turbo_distancia, turbo_tick;// caso de poner turbo (solo acelerar)
        int zona_mov;// zona que se mueve el coche manejado por el ordenador
        int zona_mov_ant;
        double gasolina;
        double gasolina_ant;
        int repostando;
        // num_vueltas + posicion (en la carrera
        bool bandera[3];
        int num_vueltas;
        int posicion;

        vector<bool> colisiones;

        void up_Time(){ticks+=0.15;}
        void down_Time(){if(ticks>=0.15)ticks-=0.15;}
        void up_Angular(){ticks_angulares+=0.5;}
        void down_Angular(){if(ticks_angulares>0.5)ticks_angulares-=0.5;}
    };

    /*Otros metodos*/
    bool ColisionParticula(int);
    bool ColisionTrayecto(int,int);
    int siguienteZona(int);
    bool MasAdelantada(int,int);
    string DeterminarSuperficie(int);
    /*Gasolinera*/
    _vertex3f pos_gasolinera[3];
    double electricidad[3];
    bool time_0[3];
    time_t time_ini[3], time_f[3];
    double nivel_electricidad;
    /*Vueltas y posicion*/
    void RefrescaPosicion(int);
    void RefrescaVueltas(int);


protected:
    double num_particulas;
    vector<particula> particulas;
    //MOVimiento del coche por la CASA
    int num_zonas; //5-Zonas por habitacion (18): [0-4]:Entrada; [5-9]:Salon; [10,14]:Cocina -- 15:EnchufeEntrada, 16:EnchufeSalon, 17:EnchufeCocina
    vector<_vertex4f> mover;
    // colision_casa
    casa *hogar;
    // movimiento:
    void movimiento(int);
    void descolision(int);//intenta descolisionar
    void colision(int);   //comprueba colision

    // gasolineras
    //  0: libre
    // -1: vacia
    //  1: ocupada
    int gasolinera[3];
    double umbral;
    void gasolineraTime(void);//tiempo de recarga de la gasolina

    //posicion + vueltas
    int meta;
    /*Otros Métodos*/
    void InicializaParticulas(void);

public:
    entidad_game();
};

#endif // ENTIDAD_GAME_H

