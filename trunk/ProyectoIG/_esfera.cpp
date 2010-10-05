/**
 *
 *   This file is part of _esfera.h
 *
 *   _esfera.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   _esfera.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "_esfera.h"


Esfera::Esfera(int div, int r, _vertex4f c, _vertex4f l){
    (div>=10)?this->Construir(div,r,c,l):this->Construir(10,r,c,l);
}

void Esfera::Construir(int div, int r, _vertex4f c, _vertex4f l)
{
    this->color=c;
    this->luz=l;
    (div>=10)?this->divisiones=div:this->divisiones=10;
    this->radio = r;
    this->columnas=this->divisiones;
    this->filas=this->divisiones/2;
    this->vertices.resize((div/2*div)+2);
    this->num_caras=(((div/2-2)*2*div)+(2*div));
    this->caras.resize(this->num_caras);

    int i,j,k,k_=((div/2-2)*div)+div,verdad=0;

    this->vertices[0].x=0;
    this->vertices[0].y=r;
    this->vertices[0].z=0;
    this->vertices[this->vertices.size()-1].x=0;
    this->vertices[this->vertices.size()-1].y=-r;
    this->vertices[this->vertices.size()-1].z=0;
    for(i=0; i<this->divisiones/2; i++){
        int pos=(i*this->divisiones)+1;
        // Construimos PUNTOS:
        double altura=r*cos(((2*M_PI)/(this->divisiones))*(i+1));
        double r2=r*sin(((2*M_PI)/(this->divisiones))*(i+1));
        for(j=0,k=pos;j<this->divisiones;j++,k++){
            this->vertices[k].y=altura;
            this->vertices[k].x=r2*cos(((2*M_PI)/(this->divisiones))*j);
            this->vertices[k].z=r2*sin(((2*M_PI)/(this->divisiones))*j);
        }
        // Construimos CARAS:
        for(k=pos-1,j=0;j<this->divisiones;k++,j++){verdad++;
            // caso caras de 'boina' superior
            if(i==0){
                this->caras[k]._0=0;
                this->caras[k]._1=pos+j;
                ((pos+j-1)<1)?this->caras[k]._2=this->divisiones:this->caras[k]._2=pos+j-1;
            }
            // caso caras tronco
            else if((pos+this->divisiones)<(this->divisiones/2*this->divisiones)){verdad++;
                int pos=((i-1)*this->divisiones)+1;
                //Cara A
                this->caras[k]._0=pos+j;
                ((pos+this->divisiones+j+1)==(pos+this->divisiones*2))?this->caras[k]._1=pos+this->divisiones:this->caras[k]._1=pos+this->divisiones+j+1;
                this->caras[k]._2=pos+this->divisiones+j;
                //Cara B
                this->caras[k_]._0=pos+j;
                ((pos+j+1)==(pos+this->divisiones))?this->caras[k_]._1=pos:this->caras[k_]._1=pos+j+1;
                ((pos+this->divisiones+j+1)==(pos+this->divisiones*2))?this->caras[k_]._2=pos+this->divisiones:this->caras[k_]._2=pos+this->divisiones+j+1;
                k_++;
             }
            // caso caras de 'boina' inferior
            else{
                int pos=((i-1)*this->divisiones)+1;
                this->caras[k_]._0=pos+j;
                ((pos+j+1)==(pos+this->divisiones))?this->caras[k_]._1=pos:this->caras[k_]._1=pos+j+1;
                this->caras[k_]._2=this->divisiones/2*this->divisiones+1;
                k_++;
            }
        }
    }

    this->Normalizar();
}











































/*    this->color=c;
    this->luz=l;
    this->divisiones = div;
    this->radio = r;
    this->columnas=div/2;
    this->filas=div;
    this->vertices.resize(this->columnas*this->filas);
    this->num_caras=this->vertices.size();
    this->caras.resize(this->num_caras);
    int i,j,k;
    for(i=0;i<this->num_caras;i++)this->caras[i]._0=-1;
    for (i = 0; i < div; ++i) {
      //colour(PointF(1.0, (float)i / div, 0.0));
      for (k=0,j = 0; j < div/2; j+=4,k+=2) {
        // guardo vertices
        //arriba
        this->vertices[this->pos(i,j)].x=r*sin((2*M_PI/div)*j)*cos((2*M_PI/div)*i);
        this->vertices[this->pos(i,j)].y=r*cos((2*M_PI/div)*j);
        this->vertices[this->pos(i,j)].z=r*sin((2*M_PI/div)*j)*sin((2*M_PI/div)*i);
        if(j+1<div/2){
            this->vertices[this->pos(i,j+1)].x=r*sin((2*M_PI/div)*j)*cos((2*M_PI/div)*(i+1));
            this->vertices[this->pos(i,j+1)].y=r*cos((2*M_PI/div)*j);
            this->vertices[this->pos(i,j+1)].z=r*sin((2*M_PI/div)*j)*sin((2*M_PI/div)*(i+1));
            if(j+2<div/2){
                this->vertices[this->pos(i,j+2)].x=r*sin((2*M_PI/div)*(j+1))*cos((2*M_PI/div)*(i+1));
                this->vertices[this->pos(i,j+2)].y=r*cos((2*M_PI/div)*(j+1));
                this->vertices[this->pos(i,j+2)].z=r*sin((2*M_PI/div)*(j+1))*sin((2*M_PI/div)*(i+1));
                // guardo caras
                this->caras[this->pos(i,k)]._0=this->pos(i,j);
                this->caras[this->pos(i,k)]._1=this->pos(i,j+1);
                this->caras[this->pos(i,k)]._2=this->pos(i,j+2);
                if(j+3<div/2){
                    this->vertices[this->pos(i,j+3)].x=r*sin((2*M_PI/div)*(j+1))*cos((2*M_PI/div)*i);
                    this->vertices[this->pos(i,j+3)].y=r*cos((2*M_PI/div)*(j+1));
                    this->vertices[this->pos(i,j+3)].z=r*sin((2*M_PI/div)*(j+1))*sin((2*M_PI/div)*i);
                    //guardando caras
                    this->caras[this->pos(i,k+1)]._0=this->pos(i,j);
                    this->caras[this->pos(i,k+1)]._1=this->pos(i,j+2);
                    this->caras[this->pos(i,k+1)]._2=this->pos(i,j+3);
                }
            }
        }
    }
  }j=0;
        for(i=0;i<this->filas*this->columnas;i++)if(this->vertices[i].x==-1)j++;
        cout << j << endl;
        cout << this->num_caras << endl;
        cout << this->num_caras-j << endl;
  this->Normalizar();
*/
