/*************************************************************************/
/*                               D O O R                                 */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file puerta.h
 * Implementation of door for the house
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef PUERTA_H
#define PUERTA_H

#include <superficie.h>

class puerta
{
private:
    superficie p;
    vector<superficie> juntas;
    // texturas
    BMPClass *p_;
public:
    puerta(){p_=NULL;}
    ~puerta(){if(p_!=NULL)delete p_;}
    void construir(void);
     void construirPuerta(void);
     void construirJuntas(void);
    void draw(void);
};

#endif // PUERTA_H
