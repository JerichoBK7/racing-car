/*************************************************************************/
/*                              S C E N E                                */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file escena.h
 * Implementation of scene
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



#ifndef ESCENA_H
#define ESCENA_H

#include "axis.h"
#include "math.h"
//#include "_object3d.h"
#include "_esfera.h"
#include "_ply.h"
#include <vector>
#include "entidad_game.h"
#include "casa.h"
#include  "_battery.h"
#include "_posicion.h"
#include "_vueltas.h"
#include "_menu.h"

using namespace std;

class Escena : public entidad_game
{

        protected:
		Axis ejes;
                int Draw_type;
	public:
                Escena();
                ~Escena();
                void setDrawType(int drawtype);
                void draw();
                double num_particulas;               
                void idle();
                void Dibujar(int,int,int);
                void upTime(void);
                void downTime(void);
                void upAngular(void);
                void downAngular(void);
                void lineal(bool mov){for(int i=0;i<this->num_particulas;i++)this->particulas[i].mov_lineal=mov;}
                // camara
                _vertex3f LeerPosicion(){return this->particulas[0].pos_act;}
                _vertex3f LeerOrientacion(){return this->particulas[0].ori_nueva;}
                string LeerEstado(){return this->particulas[0].Estado;}
                double LeerAngulo(){return this->particulas[0].angulo_orientacion;}
                // particula humana
                void cambiaTecla(string tecla){this->particulas[0].tecla=tecla;}
                string ObtenTecla(void){return this->particulas[0].tecla;}
                bool Colision(int i){return this->particulas[i].colisiones[i];}
                // información coche
                void drawInfo(int);
                // pause , partida, visual ?
                bool Pause(){return pause;}
                void Pause(bool estado){pause=estado;}
                bool ModoVisual(){return modo_visual;}
                bool ModoPartida(){return modo_partida;}
                void ModoVisual(bool estado){modo_visual=estado;}
                void ModoPartida(bool estado){modo_partida=estado;}
                bool ComienzoPartida(void){return start;}
                // raton BOTON
                string Boton(int x, int y, int ancho, int alto){return menus.BotonPulsado(x,y,ancho,alto);}
                // movimiento (juego)
                void Inicializar(void);
                bool Inicializado(void){if(inicializado)return true;return false;}
        private:
                // objetos
                _ply *camioneta,*porche, *escarabajo, *formula1, *coche_antiguo;
                _battery bateria;
                _posicion posicion;
                _vueltas vueltas;
                _menu menus;
                // movimiento
                void InicializarMov(void);
                bool inicializado;
                // casa
                casa *hogar;
                // dibujado
                int modo, tipo;
                // MODO pause, visual, partida
                bool pause;
                bool modo_visual;
                bool modo_partida;
                // MODO comenzar-carrera
                bool start;
                // Otros Métodos
                int carrera_comenzara;
                bool time_0;
                time_t time_ini, time_fin;
                void ComenzarCarrera(void);
                float Temporizador(void);
};

#endif

