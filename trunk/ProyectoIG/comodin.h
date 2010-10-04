/*************************************************************************/
/*                       F O R N I T U R E                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file comodin.h
 * Implementation of forniture of the entry
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef COMODIN_H
#define COMODIN_H

#include "superficie.h"
#include "primitivas.h"

class comodin
{
private:
    /*Obj.Privados*/
    superficie cajon;
    vector<superficie>borde_cajon;
    _object3D *tirador;
    vector<superficie>mueble_lateral;
    superficie mueble_entrada;
    /*Metodos*/
    void construirCajon();
    void construirMueble();
public:
    /*Constructores*/
    comodin(){tirador=NULL;}
    void construir();
    /*Destructor*/
    ~comodin(){
        if(tirador!=NULL)delete tirador;
    }
    /*Otros Metodos*/
    void drawCajon();
    void drawMueble();
    void draw();
};

#endif // COMODIN_H
