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
 *   This file is part of _menu.h
 *
 *   _menu.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   _menu.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */



#include "_menu.h"

void _menu::construir(){
    // menu principal
    construirMenuPrincipal();
    // menu pause
    construirMenuPause();
    // menu creditos
    construirMenuCreditos();
    // botonera
    construirBotonera();
    // Has ganado + Has perdido
    construirResultado();
    // juntas
    construirJuntas();
}

void _menu::construirResultado(){
    // variables
    int divisiones=1;
    _vertex4f blanco,luz,ambient,diffuse,specular;
    blanco.r=blanco.g=blanco.b=blanco.a=1;

    /*1º.-Construccion de las texturas*/
    textura_ganador = new BMPClass;
    textura_perdedor = new BMPClass;

    textura_ganador->BMPLoad("MENUS/HasGanado.bmp",blanco);
    textura_perdedor->BMPLoad("MENUS/HasPerdido.bmp",blanco);

    /*2º.-Imagen- RESULTADOS*/
    //Luces
    luz.x=0;luz.y=10;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.7;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.4;specular.w=1;
    //superficie
    has_ganado.construir(divisiones,4,8,blanco,luz,textura_ganador);
    has_perdido.construir(divisiones,4,8,blanco,luz,textura_perdedor);
    //luz
    has_ganado.CambiaLuz(luz,ambient,diffuse,specular);
    has_perdido.CambiaLuz(luz,ambient,diffuse,specular);
}

void _menu::construirJuntas(){
    // variables
    _vertex4f blanco,luz,ambient,diffuse,specular;;
    blanco.r=blanco.g=blanco.b=blanco.a=1;

    luz.x=0;luz.y=3;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=1;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=1;diffuse.w=1;
    specular.x=specular.y=specular.z=0.45;specular.w=1;
    /*construir*/
    juntas = new Cube;
    juntas->Construir(1);
    /*luz*/
    juntas->setColor(1,1,1,1);
    juntas->CambiaLuz(luz,ambient,diffuse,specular);
    juntas->Normalizar();
    juntas->CambiaMaterial("turquesa");
}

void _menu::construirBotonera(){
    // ancho:
    ancho=778;
    // alto:
    alto=778;
    // margenes:
    x_min=204;
    x_max=578;
    // boton 1:
    boton1_min=566;
    boton1_max=598;
    // boton 2:
    boton2_min=632;
    boton2_max=664;
    // boton 3:
    boton3_min=703;
    boton3_max=735;
    // boton 4:
    boton4_x=635;
    boton4_y=741;

}

void _menu::construirMenuPrincipal(){
    int divisiones=1;
    /*luces y blanco*/
    _vertex4f blanco,luz;
    blanco.r=1;blanco.g=1;blanco.b=1;blanco.a=1;
    luz.x=0;luz.y=1000;luz.z=0;luz.w=1;
    /*construccion*/
    textura_menu_principal=new BMPClass;
    textura_menu_principal->BMPLoad("MENUS/menu_principal.bmp",blanco);
    menu_principal.construir(divisiones,400,400,blanco,luz,textura_menu_principal);
}

void _menu::construirMenuCreditos(){
    int divisiones=1;
    /*luces y blanco*/
    _vertex4f blanco,luz;
    blanco.r=1;blanco.g=1;blanco.b=1;blanco.a=1;
    luz.x=0;luz.y=1000;luz.z=0;luz.w=1;
    /*construccion*/
    textura_menu_creditos=new BMPClass;
    textura_menu_creditos->BMPLoad("MENUS/menu_creditos.bmp",blanco);
    menu_creditos.construir(divisiones,400,400,blanco,luz,textura_menu_creditos);
}


void _menu::construirMenuPause(){
    int divisiones=1;
    /*luces y blanco*/
    _vertex4f blanco,luz;
    blanco.r=1;blanco.g=1;blanco.b=1;blanco.a=1;
    luz.x=0;luz.y=1000;luz.z=0;luz.w=1;
    /*construccion*/
    textura_menu_pause=new BMPClass;
    textura_menu_pause->BMPLoad("MENUS/menu_pause.bmp",blanco);
    menu_pause.construir(divisiones,400,400,blanco,luz,textura_menu_pause);
}

void _menu::drawMenuPrincipal(){
    glPushMatrix();
    glTranslatef(450,0,0);
    glRotatef(180,0,0,1);
        menu_principal.draw(1,4);
    glPopMatrix();
}

void _menu::drawMenuPause(){
    glPushMatrix();
    glTranslatef(850,0,0);
    glRotatef(180,0,0,1);
        menu_pause.draw(1,4);
    glPopMatrix();
}

void _menu::drawMenuCreditos(){
    glPushMatrix();
    glTranslatef(1250,0,0);
    glRotatef(180,0,0,1);
        menu_creditos.draw(1,4);
    glPopMatrix();
}

void _menu::drawResultado(string tipo){
    glPushMatrix();
    glRotatef(180,1,0,0);
    (tipo == "HasGanado")? has_ganado.draw(1,4):has_perdido.draw(1,4);
    glPopMatrix();
}

void _menu::drawJuntas(){
    /*1º.-Juntas de la imagen*/
    juntas->CambiaMaterial("turquesa");
    //abajo
    glPushMatrix();
    glTranslatef(0,-0.2,-2);
    glScalef(8.2,1,0.2);
        juntas->draw(1,3);
    glPopMatrix();
    //arriba
    glPushMatrix();
    glTranslatef(0,-0.2,2);
    glScalef(8.2,1,0.2);
        juntas->draw(1,3);
    glPopMatrix();
    //izq
    glPushMatrix();
    glTranslatef(4,-0.2,0);
    glScalef(0.2,1,3.8);
        juntas->draw(1,3);
    glPopMatrix();
    //der
    glPushMatrix();
    glTranslatef(-4,-0.2,0);
    glScalef(0.2,1,3.8);
        juntas->draw(1,3);
    glPopMatrix();

    /*2º.-Cuerdas (del marco) que sujetan la imagen*/
    juntas->CambiaMaterial("plasticoNegro");
    glPushMatrix();
    glTranslatef(4,0,3.80);
    glRotatef(20,0,1,0);
    glScalef(0.1,0.1,4);
        juntas->draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-4,0,3.80);
    glRotatef(20,0,-1,0);
    glScalef(0.1,0.1,4);
        juntas->draw(1,3);
    glPopMatrix();
}

void _menu::draw(string tipo){
    // menu principal
    drawMenuPrincipal();
    // menu pause
    drawMenuPause();
    // menu creditos
    drawMenuCreditos();
    // resultado final del juego:
    if(tipo == "HasGanado" || tipo == "HasPerdido"){
        glPushMatrix();
        glTranslatef(0,80,162);
        glRotatef(15,0,1,0);//inclinacion
        glRotatef(90,0,0,-1);
        glRotatef(90,0,-1,0);
        glScalef(6,6,6);
            // Resultados
            drawResultado(tipo);
            // Juntas
            drawJuntas();
        glPopMatrix();
    }
}

string _menu::BotonPulsado(int x_,int y_, int ancho_, int alto_){
    double x,y;
    double dim, dif_x=0,dif_y=0;
    if(alto_>ancho_){
        dim=ancho_;
        dif_y=alto_-ancho_;
    }
    else{
        dim=alto_;
        dif_x=ancho_-alto_;
    }

    x = (ancho*1.0 / dim*1.0) * (x_-dif_x/2);
    y = (alto*1.0 /  dim*1.0) * (y_-dif_y/2);

    // boton 4:
    if(y>=boton4_y && x>=boton4_x)return "boton4";
    if(x>=x_min && x<=x_max){
        // boton 1:
        if(y>=boton1_min && y<=boton1_max)return "boton1";
        // boton 2:
        if(y>=boton2_min && y<=boton2_max)return "boton2";
        // boton 3:
        if(y>=boton3_min && y<=boton3_max)return "boton3";
    }
    return "error";
}

