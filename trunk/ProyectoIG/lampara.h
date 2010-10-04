/*************************************************************************/
/*                              L A M P                                  */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file lampara.h
 * Implementation of lamp for the rooms of the house
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef LAMPARA_H
#define LAMPARA_H

#include "_object3d.h"
#include "primitivas.h"
#include "_esfera.h"

class lampara
{
private:
    _object3D *cono, *cono2;// diseño lampara
    Esfera bombilla;
    _object3D *cilindro, *conector;//cable lampara
    /*Metodos*/
    void construirLampara();
    void construirBombilla();
    void construirCable();
    void drawLampara(char*,char*);
    void drawBombilla();
    void drawCable();

public:
    /*Constructores*/
    lampara(){cono=cilindro=cono2=conector=NULL;}
    void construir();
    /*Destructor*/
    ~lampara(){
        if(cono!=NULL)delete cono;
        if(cilindro!=NULL)delete cilindro;
        if(cono2!=NULL)delete cono2;
        if(conector!=NULL)delete conector;
    }
    /*Otros Metodos*/
    void draw(char*,char*);//lampara + borde
};

#endif // LAMPARA_H
