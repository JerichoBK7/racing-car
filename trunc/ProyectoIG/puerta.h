/*************************************************************************/
/*                               D O O R                                 */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file puerta.h
 * Implementation of door for the house
 * @author Miguel Ángel Díaz López
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
