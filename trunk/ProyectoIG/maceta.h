/*************************************************************************/
/*                            H A N D L E                                */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file maceta.h
 * Implementation of handle for the house
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef MACETA_H
#define MACETA_H

#include "_object3d.h"
#include "primitivas.h"
#include "_ply.h"

class maceta
{
private:
    _object3D *soporte,*florero;
    _ply *arbol;
public:
    /*Constructor*/
    maceta(){
        soporte=florero=NULL;
        arbol=NULL;
    }
    void construir();
    /*Desctructor*/
    ~maceta(){
        if(arbol!=NULL)delete arbol;
        if(florero!=NULL)delete florero;
        if(soporte!=NULL)delete soporte;
    }
    /*Otros Metodos*/
    void draw();
};

#endif // MACETA_H
