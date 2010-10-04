/*************************************************************************/
/*                                 R A C K                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file estanteria.h
 * Implementation of rack for the house
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef ESTANTERIA_H
#define ESTANTERIA_H

#include "superficie.h"
#include "primitivas.h"

class estanteria
{
private:
    /*Obj.Privados*/
    superficie puerta;
    vector<superficie>borde_puerta;
    _object3D *balda,*tirador;
    /*Metodos*/
    void construirPuerta();
    void construirMueble();
public:
    /*Constructores*/
    estanteria(){tirador=balda=NULL;}
    void construir();
    /*Destructor*/
    ~estanteria(){
        if(balda!=NULL)delete balda;
        if(tirador!=NULL)delete tirador;
    }
    /*Otros Metodos*/
    void drawPuerta();
    void drawMueble();
    void draw();
};

#endif // ESTANTERIA_H
