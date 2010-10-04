/*************************************************************************/
/*                         P I C T U R E S                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file cuadros.h
 * Implementation of pictures for the house
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef CUADROS_H
#define CUADROS_H

#include "superficie.h"

class cuadros
{
private:
    vector<superficie> marco;
    superficie cuadro;
    BMPClass *textura_cuadro;
    int alto,ancho;
    /*metodos*/
    void construirMarco(char *);
    void construirCuadro(char *);
    void drawMarco();
    void drawCuadro();
public:
    cuadros(){textura_cuadro=NULL;}
    void construir(int,int,char*,char *);
    /*Destructor*/
    ~cuadros(){if(textura_cuadro!=NULL)delete textura_cuadro;}
    /*Otros*/
    void draw();
};

#endif // CUADROS_H
