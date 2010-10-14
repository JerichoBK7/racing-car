/*************************************************************************/
/*                      B M P - L O A D E R                              */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/

/**
 *
 * @file BMPLoader.h
 * Implementation of Data Type BMP (read images .BMP)
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


#ifndef BMPLOADER_H
#define BMPLOADER_H
#define BMPError char
#define BMPNOTABITMAP 'b' //Possible error flags
#define BMPNOOPEN 'o'
#define BMPFILEERROR 'f'
#define BMPBADINT 'i'
#define BMPNOERROR '\0'
#define BMPUNKNOWNFORMAT 'u'
typedef unsigned char BYTE;

#include <string>
#include <vector>
#include "vertex.h"

using namespace std;

class BMPClass
{
public:
    vector<_vertex2f> textura;
    int width,height;
    vector<BYTE> pixel;

    BMPClass(){pixel.resize(0);}
    ~BMPClass(){}
    bool Vacio(void){(this->pixel.size()!=0)?false:true;}
    bool Vaciar(void){this->pixel.resize(0);}
    BYTE& obtenerPixel(int x,int y,int c);
    void allocateMem();
    //Loads the bmp in fname, and puts the data in bmp
    BMPError BMPLoad(std::string fname, _vertex4f colores);

    //Translates my error codes into English
    std::string TranslateBMPError(BMPError err);

    //Load and select in OpenGL
    BMPError BMPLoadGL(std::string fname);
};


#endif
