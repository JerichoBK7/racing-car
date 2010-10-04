/*************************************************************************/
/*                             L O U N G E                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file salon.h
 * Implementation of lounge of the house
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef SALON_H
#define SALON_H

#include "mesa.h"
#include "primitivas.h"
#include "_ply.h"
#include "estanteria.h"

class salon
{
private:
    mesa mesita;
    estanteria estante;
    _object3D *asiento;
    _ply tv;
    /*metodos*/
    void drawMesa();
    void drawAsientos();
    void drawTv();
    void drawEstanteria();
public:
    /*constructores*/
    salon(){asiento=NULL;}
    void construir();
    /*destructor*/
    ~salon(){
        if(asiento==NULL)delete asiento;
    }
    /*otros metodos*/
    void draw();
};

#endif // SALON_H
