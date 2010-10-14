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
 *   This file is part of escena.h
 *
 *   escena.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   escena.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "escena.h"

Escena::Escena(){
    // Mensaje inicial:
    cout << "(c) Videojuego Desarrollado por:  Miguel Ángel Díaz López.  [2010]"<<endl;
    // inicializamos los ply!
    camioneta=porche=NULL;
    // construir coches
    camioneta=porche=escarabajo=formula1=coche_antiguo=NULL;
    // Inicializamos el juego
    this->num_particulas=-1;
    Inicializar();
    modo_visual = false;
    modo_partida = false;
    // construir casa (videojuego)
    hogar = new casa;
    hogar->creaCasa();
    // construimos los menus
    menus.construir();
}

Escena::~Escena(){
    if(camioneta!=NULL)delete camioneta;
    if(porche!=NULL)delete porche;
    if(escarabajo!=NULL)delete escarabajo;
    if(formula1!=NULL)delete formula1;
    if(coche_antiguo!=NULL)delete coche_antiguo;
    delete hogar;
}

void Escena::Inicializar(void){
    //inicializado
    inicializado = true;
    //inicializamos la carrera
    carrera_comenzara=-1;
    time_0= false;
    pause = true;
    start = false;
    //inicializa el movimiento de las particulas
    InicializarMov();
    //inicializa las particulas y estados
    this->InicializaParticulas();
    //dibujado
    modo=1;
    tipo=3;
}

void Escena::InicializarMov(void){
    // variables para -> color
    _random r_(0,1),g_(0,1),b_(0,1);
    int r,g,b;
    /*Luz*/
    _vertex4f luz,ambient,diffuse,specular;
    if(this->num_particulas == -1){
        // num_coches ?
        this->num_particulas=5;
        // creando particulas
        this->particulas.resize(this->num_particulas);
        for(int i=0;i<this->num_particulas;i++){
            this->particulas[i].colisiones.resize(this->num_particulas);
            this->particulas[i].obj=NULL;
        }
    }

    // creamos ply
    if(porche==NULL){
        porche = new _ply;
        porche->LecturaPly("PLY/coche_porche.ply");
    }
    if(camioneta==NULL){
        camioneta = new _ply;
        camioneta->LecturaPly("PLY/coche_camioneta.ply");
    }
    if(escarabajo==NULL){
        escarabajo = new _ply;
        escarabajo->LecturaPly("PLY/coche_escarabajo.ply");
    }
    if(formula1==NULL){
        formula1 = new _ply;
        formula1->LecturaPly("PLY/coche_formula1.ply");
    }
    if(coche_antiguo==NULL){
        coche_antiguo = new _ply;
        coche_antiguo->LecturaPly("PLY/coche_antiguo.ply");
    }
    // casa
    this->hogar=hogar;

/*Inicializamos las particulas*/
    int i=0;
    double caja;
    /*1º.- PORCHE*/
    // estado inicial
    this->particulas[i].humano=true;
    this->particulas[i].Estado="PARADO";
    this->particulas[i].gasolina=100;
    this->particulas[i].repostando=-1;
    // ply
    if(this->particulas[i].obj==NULL){
        this->particulas[i].obj=porche;
        // caja
        caja=this->particulas[i].obj->caja()*1.2;
        this->particulas[i].obj->CambiaCaja(caja);
    }
    //cout << "Porche: "<<this->particulas[i].obj->caja()<<endl;
    // localizacion
    this->particulas[i].subir=-(porche->Subir()-1.5);
    this->particulas[i].pos_act.x=198;
    this->particulas[i].pos_act.y=this->particulas[i].subir;
    this->particulas[i].pos_act.z=-200;
    // material
    this->particulas[i].material="oro_2";
    // color
    r_.init(0,6);(r_.value()<3)?r=1:r=0;
    g_.init(0,6);(g_.value()<3)?g=1:g=0;
    b_.init(0,6);(b_.value()<3)?b=1:b=0;
    this->particulas[i].obj->setColor(r,g,b,1);
    // luz
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.4;diffuse.w=1;
    specular.x=specular.y=specular.z=0.6;specular.w=1;
    this->particulas[i].luz=luz;
    this->particulas[i].ambient=ambient;
    this->particulas[i].diffuse=diffuse;
    this->particulas[i].specular=specular;
    // escalado
    this->particulas[i].escala.x=1.6;
    this->particulas[i].escala.y=1.6;
    this->particulas[i].escala.z=1.6;
    // orientacion
    this->particulas[i].giro_inicial_y.w=90;
    this->particulas[i].giro_inicial.w=0;
    this->particulas[i].angulo_orientacion=90;
    this->particulas[i].giro_inicial_y.y=-1;
    this->particulas[i].orientacion.x=0;
    this->particulas[i].orientacion.y=0;
    this->particulas[i].orientacion.z=1;
    this->particulas[i].ori_nueva=this->particulas[i].orientacion;
    this->particulas[i].ori_bat.x=1;this->particulas[i].ori_bat.y=this->particulas[i].ori_bat.z=0;
    // translate_i
    this->particulas[i].translate_i.x=this->particulas[i].translate_i.y=this->particulas[i].translate_i.z=0;
    // otros
    this->particulas[i].mov_lineal=true;
    this->particulas[i].ticks=0.25;
    this->particulas[i].ticks_angulares=1.5;
    this->particulas[i].beta=this->particulas[i].giro_beta=0;
    this->particulas[i].giro=this->particulas[i].giro_y=0;
    this->particulas[i].colisiones[i]=false;
    //
    //
    i=1;
    /*2º.- CAMIONETA*/
    // estado inicial
    this->particulas[i].humano=false;
    this->particulas[i].Estado="BUSCAR_OBJETIVO";
    this->particulas[i].gasolina=100;
    this->particulas[i].zona_mov=2+(16*(i-1));
    this->particulas[i].zona_mov_ant=this->particulas[i].zona_mov;
    this->particulas[i].repostando=-1;
    // ply
    if(this->particulas[i].obj==NULL){
        this->particulas[i].obj=camioneta;
        // caja
        caja=this->particulas[i].obj->caja()*2.6;
        this->particulas[i].obj->CambiaCaja(caja);
    }
    // localizacion
    this->particulas[i].subir=-(camioneta->Subir()+0.5);
    this->particulas[i].pos_act.x=150;
    this->particulas[i].pos_act.y=this->particulas[i].subir;
    this->particulas[i].pos_act.z=-198;
    // material
    this->particulas[i].material="perla";
    // color
    r_.init(0,6);(r_.value()<3)?r=1:r=0;
    g_.init(0,6);(g_.value()<3)?g=1:g=0;
    b_.init(0,6);(b_.value()<3)?b=1:b=0;
    this->particulas[i].obj->setColor(r,g,b,1);
    // luz
    luz.x=0;luz.y=0;luz.z=3;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.5;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.9;specular.w=1;
    this->particulas[i].luz=luz;
    this->particulas[i].ambient=ambient;
    this->particulas[i].diffuse=diffuse;
    this->particulas[i].specular=specular;
    // escalado
    this->particulas[i].escala.x=2.6;
    this->particulas[i].escala.y=2.6;
    this->particulas[i].escala.z=2.6;
    // orientacion
    this->particulas[i].giro_inicial_y.w=90;
    this->particulas[i].giro_inicial.w=90;
    this->particulas[i].giro_inicial_y.y=-1;
    this->particulas[i].giro_inicial.x=-1;this->particulas[i].giro_inicial.z=0;
    this->particulas[i].angulo_orientacion=90;
    this->particulas[i].orientacion.x=0;
    this->particulas[i].orientacion.y=0;
    this->particulas[i].orientacion.z=1;
    this->particulas[i].ori_nueva=this->particulas[i].orientacion;
    // translate_i
    this->particulas[i].translate_i.x=this->particulas[i].translate_i.y=0;this->particulas[i].translate_i.z=8;
    // otros
    this->particulas[i].mov_lineal=false;
    this->particulas[i].ticks=0.65;
    this->particulas[i].ticks_angulares=5;
    this->particulas[i].beta=this->particulas[i].giro_beta=0;
    this->particulas[i].giro=this->particulas[i].giro_y=0;
    this->particulas[i].colisiones[i]=false;
    //
    i=2;
    /*3º.- COCHE_ANTIGUO*/
    // estado inicial
    this->particulas[i].humano=false;
    this->particulas[i].Estado="BUSCAR_OBJETIVO";
    this->particulas[i].gasolina=100;
    this->particulas[i].zona_mov=2+(16*(i-1));
    this->particulas[i].zona_mov_ant=this->particulas[i].zona_mov;
    this->particulas[i].repostando=-1;
    // ply
    if(this->particulas[i].obj==NULL){
        this->particulas[i].obj=coche_antiguo;
        // caja
        caja=this->particulas[i].obj->caja()*1.5;
        this->particulas[i].obj->CambiaCaja(caja);
    }
    // localizacion
    this->particulas[i].subir=-(coche_antiguo->Subir()-1.9);
    this->particulas[i].pos_act.x=175;
    this->particulas[i].pos_act.y=this->particulas[i].subir;
    this->particulas[i].pos_act.z=-155;
    // material
    this->particulas[i].material="bronce";
    // color
    r_.init(0,6);(r_.value()<3)?r=1:r=0;
    g_.init(0,6);(g_.value()<3)?g=1:g=0;
    b_.init(0,6);(b_.value()<3)?b=1:b=0;
    this->particulas[i].obj->setColor(r,g,b,1);
    // luz
    luz.x=3;luz.y=5;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.6;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.4;diffuse.w=1;
    specular.x=specular.y=specular.z=0.8;specular.w=1;
    this->particulas[i].luz=luz;
    this->particulas[i].ambient=ambient;
    this->particulas[i].diffuse=diffuse;
    this->particulas[i].specular=specular;
    // escalado
    this->particulas[i].escala.x=1.5;
    this->particulas[i].escala.y=1.5;
    this->particulas[i].escala.z=1.5;
    // orientacion
    this->particulas[i].giro_inicial_y.w=90;
    this->particulas[i].giro_inicial.w=0;
    this->particulas[i].giro_inicial_y.y=-1;
    this->particulas[i].angulo_orientacion=90;
    this->particulas[i].orientacion.x=0;
    this->particulas[i].orientacion.y=0;
    this->particulas[i].orientacion.z=1;
    this->particulas[i].ori_nueva=this->particulas[i].orientacion;
    // translate_i
    this->particulas[i].translate_i.x=this->particulas[i].translate_i.y=this->particulas[i].translate_i.z=0;
    // otros
    this->particulas[i].mov_lineal=false;
    this->particulas[i].ticks=0.6;
    this->particulas[i].ticks_angulares=5;
    this->particulas[i].beta=this->particulas[i].giro_beta=0;
    this->particulas[i].giro=this->particulas[i].giro_y=0;
    this->particulas[i].colisiones[i]=false;
    //
    i=3;
    /*4º.- ESCARABAJO*/
    // estado inicial
    this->particulas[i].humano=false;
    this->particulas[i].Estado="BUSCAR_OBJETIVO";
    this->particulas[i].gasolina=100;
    this->particulas[i].zona_mov=2+(16*(i-1));
    this->particulas[i].zona_mov_ant=this->particulas[i].zona_mov;
    this->particulas[i].repostando=-1;
    // ply
    if(this->particulas[i].obj==NULL){
        this->particulas[i].obj=escarabajo;
        // caja
        caja=this->particulas[i].obj->caja()*0.15;
        this->particulas[i].obj->CambiaCaja(10);
    }
    // localizacion
    this->particulas[i].subir=-(escarabajo->Subir()+31.5);
    this->particulas[i].pos_act.x=220;
    this->particulas[i].pos_act.y=this->particulas[i].subir;
    this->particulas[i].pos_act.z=-156;
    // material
    this->particulas[i].material="plata";
    // color
    r_.init(0,6);(r_.value()<3)?r=1:r=0;
    g_.init(0,6);(g_.value()<3)?g=1:g=0;
    b_.init(0,6);(b_.value()<3)?b=1:b=0;
    this->particulas[i].obj->setColor(r,g,b,1);
    // luz
    luz.x=0;luz.y=0;luz.z=10;luz.w=0.5;
    ambient.x=ambient.y=ambient.z=0.2;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.2;diffuse.w=1;
    specular.x=specular.y=specular.z=0.1;specular.w=1;
    this->particulas[i].luz=luz;
    this->particulas[i].ambient=ambient;
    this->particulas[i].diffuse=diffuse;
    this->particulas[i].specular=specular;
    // escalado
    this->particulas[i].escala.x=0.15;
    this->particulas[i].escala.y=0.15;
    this->particulas[i].escala.z=0.15;
    // orientacion
    this->particulas[i].giro_inicial_y.w=0;
    this->particulas[i].giro_inicial.w=90;
    this->particulas[i].giro_inicial.x=-1;this->particulas[i].giro_inicial.z=0;
    this->particulas[i].angulo_orientacion=90;
    this->particulas[i].orientacion.x=0;
    this->particulas[i].orientacion.y=0;
    this->particulas[i].orientacion.z=1;
    this->particulas[i].ori_nueva=this->particulas[i].orientacion;
    // translate_i
    this->particulas[i].translate_i.x=this->particulas[i].translate_i.y=0;this->particulas[i].translate_i.z=6;
    // otros
    this->particulas[i].mov_lineal=false;
    this->particulas[i].ticks=0.6;
    this->particulas[i].ticks_angulares=5;
    this->particulas[i].beta=this->particulas[i].giro_beta=0;
    this->particulas[i].giro=this->particulas[i].giro_y=0;
    this->particulas[i].colisiones[i]=false;
    //
    i=4;
    /*5º.- FORMULA1*/
    // estado inicial
    this->particulas[i].humano=false;
    this->particulas[i].Estado="BUSCAR_OBJETIVO";
    this->particulas[i].gasolina=100;
    this->particulas[i].zona_mov=2+(16*(i-1));
    this->particulas[i].zona_mov_ant=this->particulas[i].zona_mov;
    this->particulas[i].repostando=-1;
    // ply
    if(this->particulas[i].obj==NULL){
        this->particulas[i].obj=formula1;
        // caja
        caja=this->particulas[i].obj->caja()*0.4;
        this->particulas[i].obj->CambiaCaja(caja);
    }
    // localizacion
    this->particulas[i].subir=-(formula1->Subir()+1.8);
    this->particulas[i].pos_act.x=120;
    this->particulas[i].pos_act.y=this->particulas[i].subir;
    this->particulas[i].pos_act.z=-157;
    // material
    this->particulas[i].material="gomaRoja";
    // color
    r_.init(0,6);(r_.value()<3)?r=1:r=0;
    g_.init(0,6);(g_.value()<3)?g=1:g=0;
    b_.init(0,6);(b_.value()<3)?b=1:b=0;
    this->particulas[i].obj->setColor(r,g,b,1);
    // luz
    luz.x=200;luz.y=50;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.7;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.4;diffuse.w=1;
    specular.x=specular.y=specular.z=0.4;specular.w=1;
    this->particulas[i].luz=luz;
    this->particulas[i].ambient=ambient;
    this->particulas[i].diffuse=diffuse;
    this->particulas[i].specular=specular;
    // escalado
    this->particulas[i].escala.x=0.4;
    this->particulas[i].escala.y=0.4;
    this->particulas[i].escala.z=0.4;
    // orientacion
    this->particulas[i].giro_inicial_y.w=90;
    this->particulas[i].giro_inicial.w=90;
    this->particulas[i].giro_inicial_y.y=-1;
    this->particulas[i].giro_inicial.x=-1;this->particulas[i].giro_inicial.z=0;
    this->particulas[i].angulo_orientacion=90;
    this->particulas[i].orientacion.x=0;
    this->particulas[i].orientacion.y=0;
    this->particulas[i].orientacion.z=1;
    this->particulas[i].ori_nueva=this->particulas[i].orientacion;
    // translate_i
    this->particulas[i].translate_i.x=-6;this->particulas[i].translate_i.y=0;this->particulas[i].translate_i.z=-14;
    // otros
    this->particulas[i].mov_lineal=false;
    this->particulas[i].ticks=0.8;
    this->particulas[i].ticks_angulares=5;
    this->particulas[i].beta=this->particulas[i].giro_beta=0;
    this->particulas[i].giro=this->particulas[i].giro_y=0;
    this->particulas[i].colisiones[i]=false;
}

void Escena::setDrawType(int drawtype){
     this->Draw_type=drawtype;
}

void Escena::draw(){
    /*Funcion Dibujar(int,int):
      Modo: alambres, normal, puntos
      Tipo: normal, ajedrez, plano, gouraud
      Particula: numero de la particula a dibujar
    */

    /*Escenario:*/
    //
    /*1º.- ejes:*/
    //ejes.draw();
    //
    /*2º.- menus:*/
    if(this->particulas[0].Estado == "GANADOR")menus.draw("HasGanado");
    else if(this->particulas[0].Estado == "GAME_OVER")menus.draw("HasPerdido");
    else menus.draw("ModoCarrera");

    if(!start && modo_partida){
        ComenzarCarrera();
        inicializado = false;
    }
    //
    /*3º.- casa:*/
    hogar->draw(this->gasolinera[0],this->gasolinera[1],this->gasolinera[2]);
    //
    /*4º.-Dibujado de la particulas:*/
    switch (Draw_type){
        //1º.-Puntos
        case 1:
            modo=2;tipo=0;
            break;
        //2º.-Alambre
        case 2:
            modo=0;tipo=0;
            break;
        //3º.-Ajedrez
        case 3:
            modo=1;tipo=1;
            break;
        //4º.-Solido NO iluminado
        case 4:
            modo=1;tipo=0;
            break;
        //5º.-Solido iluminado-Plano
        case 5:
            modo=1;tipo=2;
            break;
        //6º.-Solido iluminado -Gouraud (defecto)
        case 6:
            modo=1;tipo=3;
            break;
    }
    for(int i=0; i<this->num_particulas;i++)Dibujar(modo,tipo,i);
}

//---- Información sobre el coche ----
void Escena::drawInfo(int camara){
    if(modo_partida && !pause){
        if(!start && carrera_comenzara!=-1){
            glPushMatrix();
            glTranslatef(0,17,0);
            glTranslatef(this->particulas[0].pos_act.x-(this->particulas[0].ori_nueva.x*24),this->particulas[0].pos_act.y,this->particulas[0].pos_act.z-(this->particulas[0].ori_nueva.z*24));
            glRotatef(this->particulas[0].giro,0,this->particulas[0].giro_y,0);
            glRotatef(this->particulas[0].beta,0,this->particulas[0].giro_beta,0);
            glRotatef(190,0,1,0);
            glRotatef(90,1,0,0);
            glScalef(0.8,0.8,0.8);
                posicion.draw(carrera_comenzara,"perla");//Comienzo de la carrera
            glPopMatrix();
        }
        //1º.-Persona || 3º.-Persona
        else if(camara==0 || camara==2){
            /*1º.-Posicion en la carrera*/
            glPushMatrix();
            glTranslatef(0,19,0);
            glTranslatef(this->particulas[0].ori_bat.x*4.35,0,this->particulas[0].ori_bat.z*4.35);
            glTranslatef(this->particulas[0].pos_act.x-(this->particulas[0].ori_nueva.x*23),this->particulas[0].pos_act.y,this->particulas[0].pos_act.z-(this->particulas[0].ori_nueva.z*23));
            glRotatef(this->particulas[0].giro,0,this->particulas[0].giro_y,0);
            glRotatef(this->particulas[0].beta,0,this->particulas[0].giro_beta,0);
            glRotatef(190,0,1,0);
            glRotatef(90,1,0,0);
            glScalef(0.65,0.65,0.65);
                posicion.draw(this->particulas[0].posicion);//posicion coche (humano)
            glPopMatrix();
            /*2º.-Numero de vueltas*/
            glPushMatrix();
            glTranslatef(0,18.17,0);
            glTranslatef(this->particulas[0].ori_bat.x*3.95,0,this->particulas[0].ori_bat.z*3.95);
            glTranslatef(this->particulas[0].pos_act.x-(this->particulas[0].ori_nueva.x*23.1),this->particulas[0].pos_act.y,this->particulas[0].pos_act.z-(this->particulas[0].ori_nueva.z*23.1));
            glRotatef(this->particulas[0].giro,0,this->particulas[0].giro_y,0);
            glRotatef(this->particulas[0].beta,0,this->particulas[0].giro_beta,0);
            glRotatef(190,0,1,0);
            glRotatef(90,1,0,0);
            glScalef(0.2,0.2,0.2);
                vueltas.draw(this->particulas[0].num_vueltas);//número de vueltas alcanzadas
            glPopMatrix();
            /*3º.-Bateria del coche*/
            glPushMatrix();
            glTranslatef(0,18.6,0);
            glTranslatef(this->particulas[0].ori_bat.x*-4.5,0,this->particulas[0].ori_bat.z*-4.5);
            glTranslatef(this->particulas[0].pos_act.x-(this->particulas[0].ori_nueva.x*23),this->particulas[0].pos_act.y,this->particulas[0].pos_act.z-(this->particulas[0].ori_nueva.z*23));
            glRotatef(this->particulas[0].giro,0,this->particulas[0].giro_y,0);
            glRotatef(this->particulas[0].beta,0,this->particulas[0].giro_beta,0);
            glRotatef(190,0,1,0);
            glRotatef(90,1,0,0);
                bateria.draw(this->particulas[0].gasolina);//bateria
            glPopMatrix();
        }
    }
}

//----  MOVIMIENTO ----
void Escena::idle(){//disparador
    if(!pause){
        if(start)for(int i=0; i<this->num_particulas; i++) this->movimiento(i);
        this->gasolineraTime();
    }
}


void Escena::upTime(void){
    if(!pause)
        for(int i=0;i<this->num_particulas;i++)
            this->particulas[i].up_Time();
}
void Escena::downTime(void){
    if(!pause)
        for(int i=0;i<this->num_particulas;i++)
            this->particulas[i].down_Time();
}
void Escena::upAngular(void){
    if(!pause)
        for(int i=0;i<this->num_particulas;i++)
            this->particulas[i].up_Angular();
}
void Escena::downAngular(void){
    if(!pause)
        for(int i=0;i<this->num_particulas;i++)
            this->particulas[i].down_Angular();
}
//---------------- DIBUJAR --------------
void Escena::Dibujar(int modo, int tipo, int i){
    glPushMatrix();
        /*Movimiento*/
        glTranslatef(this->particulas[i].pos_act.x,this->particulas[i].pos_act.y,this->particulas[i].pos_act.z);
        glRotatef(this->particulas[i].giro,0,this->particulas[i].giro_y,0);
        glRotatef(this->particulas[i].beta,0,this->particulas[i].giro_beta,0);
        /*Posicionado incial*/
        if(this->particulas[i].translate_i.x!=0 || this->particulas[i].translate_i.y!=0 || this->particulas[i].translate_i.z!=0)
            glTranslatef(this->particulas[i].translate_i.x,this->particulas[i].translate_i.y,this->particulas[i].translate_i.z);
        if(this->particulas[i].giro_inicial_y.w!=0)
            glRotatef(this->particulas[i].giro_inicial_y.w,0,this->particulas[i].giro_inicial_y.y,0);
        if(this->particulas[i].giro_inicial.w!=0)
            glRotatef(this->particulas[i].giro_inicial.w,this->particulas[i].giro_inicial.x,0,this->particulas[i].giro_inicial.z);
        glScalef(this->particulas[i].escala.x,this->particulas[i].escala.y,this->particulas[i].escala.z);
        /*Material*/
        this->particulas[i].obj->CambiaMaterial(this->particulas[i].material);
        /*Luz*/
        this->particulas[i].obj->CambiaLuz(this->particulas[i].luz,this->particulas[i].ambient,this->particulas[i].diffuse,this->particulas[i].specular);
        /*Dibujado*/
        this->particulas[i].obj->draw(modo,tipo);
    glPopMatrix();
}

//--------- COMENZAR EL JUEGO  -------------
void Escena::ComenzarCarrera(void){
    double sec=Temporizador();
    if(sec > 3)
        //comenzamos la carrera
        start = true;
    //dibujamos [3-2-1]
    else{
        if(sec<=1)carrera_comenzara=3;
        else if(sec<=2)carrera_comenzara=2;
        else carrera_comenzara=1;
    }
}

float Escena::Temporizador(void){
    if(!time_0){
        time_0=true;
        time_ini=clock();
    }
    time_fin=clock();
    float segundos=(time_fin-time_ini)/CLOCKS_PER_SEC;
    return segundos;
}
