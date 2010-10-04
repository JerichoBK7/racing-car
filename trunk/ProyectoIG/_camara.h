/*************************************************************************/
/*                      C O N T R O L - C A M E R A                      */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 * @file _camara.h
 * Implementation of control for the camera
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef _CAMARA_H
#define _CAMARA_H
#include <iostream>
#include <GL/gl.h>
#include "camara.h"
#include "vertex.h"
#include <vector>

using namespace std;

class _camara
{
private:
    int num_camaras;// numero de camaras totales
    int activa;     // en la que nos encontramos
    vector<camara> cam;// vector con todas las camaras
public:
    /* Constructores */
    _camara();
    void crea(int);
    /* Otros métodos */
    void set(int, _vertex3f);
    void set(int, _vertex3f,_vertex3f);
    void setCamara(void){cam[activa].setCamara();}
    void activar(int);
    int Activa(void){return activa;}
    void rotar(string,string); //rotar la camara: axis-n, axis-u, axis-v / der, izq
    void rotar(int,string,float);
    void movCamara(string,string); //mover la camara: axis-z, axis-y, axis-x / up, down
    void movCamara(int,string,float); //mover la camara: axis-z, axis-y, axis-x / up, down
    void next(void); // activamos la siguiente camara y desactivamos la actual
    void back(void); // activamos la camara anterior y descactivamos la actual
};

#endif // _CAMARA_H
