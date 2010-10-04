/*************************************************************************/
/*                             E N T R Y                                 */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file entrada.h
 * Implementation of entry of the house
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef ENTRADA_H
#define ENTRADA_H


#include <iostream>
#include <superficie.h>
#include "primitivas.h"
#include "_object3d.h"
#include "_ply.h"
#include "comodin.h"
#include "maceta.h"

using namespace std;

class entrada
{
private:
    // mueble de entrada
    comodin comoda;
    // espejo
    superficie espejo;
    vector<superficie>borde_espejo;
    // accesorios
    _ply *flor;
    /*Metodos*/
    // construir:
    void construirEspejo();
    void construirFLor();
    // dibujar:
    void drawEspejo();
    void drawFlor();
public:
    entrada(){flor=NULL;}
    /*Destructor*/
    ~entrada(){
        if(flor!=NULL)delete flor;
    }
    /*Constructores*/
    void construir();
    /*Otros metodos*/
    void draw();
};

#endif // ENTRADA_H
