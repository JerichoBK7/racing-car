/*************************************************************************/
/*                             C H A R G E                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file _enchufe.cpp
 * Implementation of place to charge
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef _ENCHUFE_H
#define _ENCHUFE_H

#include "superficie.h"
#include "primitivas.h"

class _enchufe
{
private:
    _object3D *juntas;
    superficie enchufe;
    BMPClass *textura;
    /*metodos*/
    void construirEnchufe();
    void construirJuntas();
    void drawEnchufe();
    void drawJuntas();
public:
    /*Constructores*/
    _enchufe(){juntas=NULL;textura=NULL;}
    void construir();
    /*Destructor*/
    ~_enchufe(){
        if(textura!=NULL)delete textura;
        if(juntas!=NULL)delete juntas;
    }
    /*Otros Metodos*/
    void draw(int);
};

#endif // _ENCHUFE_H
