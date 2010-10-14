//**************************************************************************
//                             OBJECTS IN 3D
//
// 1.-Clase para construir las primitivas: Tetraedro, Cubo, Cuadrado, Cilindro
//                                      y Cono
// 2.-Constructor de Caras, aristas y puntos + dibujado de caras (normalizadas + nomral)
// 3.-Dibujado con texturas
// 4.-Dibujado de materiales
//
//         Copyright (C) Miguel Ángel Díaz López [2010]
//
//     License: GPL3
//***************************************************************************
/**
 * @file _object3d.h
 * Implementation of object in 3D
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

#ifndef _OBJECT3D_H
#define _OBJECT3D_H
#include <iostream>
#include <GL/gl.h>
#include <errno.h>
#include "vertex.h"
#include "matrix.h"
#include <vector>
#include <string>
#include <GL/glu.h>
#include "BMPLoader.h"

typedef unsigned char BYTE;
using namespace std;

class _object3D
{
protected:
    vector<_vertex3f> vertices;
    vector<_vertex3f> caras;
    int num_caras;
    int filas;
    int columnas;
    // particulas
    int r_cajafrontera;
    // ply
    int subir;//cuanto? subimos el ply leido(para situarlo a ras de suelo)
    // luz
    _vertex4f color;
    vector<_vertex3f> normalv;
    vector<_vertex3f> normalf;
    bool Luz;
    _vertex4f luz;
    GLfloat luz_ambientLight[4];
    GLfloat luz_diffuseLight[4];
    GLfloat luz_specular[4];
    void copia(GLfloat* gl,_vertex4f punto);
    // materiales
    bool material;
    GLfloat material_ambient[4];
    GLfloat material_diffuse[4];
    GLfloat material_specular[4];
    GLfloat material_brillo;
    // texturas
    BMPClass *img;
    GLuint texID;

public:
    /*Constructor*/
    _object3D();
    /*Destructor*/
    virtual ~_object3D();
    /*Métodos de dibujado*/
    void draw();
    void drawPlano();
    void drawGouraud();
    void drawAjedrez();
    void draw(int modo, int tipo);
    void drawTexture(void);
    void loadTexture(void);
    /*Otros métodos*/
    void Normalizar(void);
    int Subir(void){return subir;}
    void CambiaMaterial(string);//cambiar el tipo del material
    void CambiaLuz(_vertex4f,_vertex4f,_vertex4f,_vertex4f);
    void setColor(int r,int g,int b,int a){color.r=r;color.g=g;color.b=b;color.a=a;}
    void setLuz(int x,int y,int z,int w){luz.x=x;luz.y=y;luz.z=z;luz.w=w;}
    //GLuint getID(){return texID;};
    double caja(){return r_cajafrontera;}
    void CambiaCaja(double caja){r_cajafrontera=(int)caja;}
    virtual void Construir(float);
    virtual void Construir(float,int);
    virtual void Construir(float,float,int);
    _vertex3f& read(const int &fil, const int &col);
    int pos(const int &fil, const int&col);
};
#endif // _OBJECT3D_H
