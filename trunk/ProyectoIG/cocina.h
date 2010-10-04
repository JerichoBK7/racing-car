/*************************************************************************/
/*                           K I T C H E N                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file cocina.h
 * Implementation of kitchen of the house
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef COCINA_H
#define COCINA_H

#include <superficie.h>
#include <campana.h>

class cocina
{
private:
    // varios
    superficie frigo,horno,lavaplatos,lateral_mueble;
    // encimera
    vector<superficie> juntas_encimera;
    superficie encimera;
    // laterales mueble-encimera
    vector<superficie> mueble;
    vector<superficie> liston_mueble;
    // laterales frigo
    vector<superficie> juntas_frigo;
    // campana
    campana campana_horno;
    BMPClass *f,*h,*l,*mueble_;
    // mesa comer-der-cocina
    vector<superficie> lateral_mesa;
    superficie mesa_cocina;
    /*funciones*/
    void drawEncimera();
    void drawFrigo();
    void drawHorno();
    void drawMueble();
    void drawLavaplatos();
    void drawTablaCocina();

public:
    cocina(){f=h=l=mueble_=NULL;}
    /*Destructor*/
    ~cocina(){
        if(f!=NULL)delete f;
        if(h!=NULL)delete h;
        if(l!=NULL)delete l;
        if(mueble_!=NULL)delete mueble_;
    }
    /*Construir*/
    void construirEncimera(void);
    void construirMueble(void);
    void construirFrigo(void);
    void construirTablaCocina(void);
    void construir(void);
    /*Métodos dibujar*/
    void draw();
};

#endif // COCINA_H
