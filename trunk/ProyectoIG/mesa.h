/*************************************************************************/
/*                             T A B L E                                 */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file mesa.h
 * Implementation of table for the house
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef MESA_H
#define MESA_H

#include "superficie.h"
#include "primitivas.h"

class mesa
{
private:
    _object3D *patas,*mesita;
    /*metodos*/
    void construirPatas();
    void cosntruirMesa();
    void drawPatas();
    void drawMesa();
public:
    /*constructores*/
    mesa(){patas=mesita=NULL;}
    void construir();
    /*destrucotr*/
    ~mesa(){
        if(patas!=NULL)delete patas;
        if(mesita!=NULL)delete mesita;
    }
    /*otros metodos*/
    void draw();
};

#endif // MESA_H
