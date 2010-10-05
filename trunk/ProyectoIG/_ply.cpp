/**
 *
 *   This file is part of _ply.h
 *
 *   _ply.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   _ply.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "_ply.h"

_ply::_ply()
{
}

void _ply::CajaFrontera(void){
    double _x,_y,_z,x,y,z,y_menor;
    _x=x=this->vertices[0].x;
    _y=y=this->vertices[0].x;
    _z=z=this->vertices[0].x;
    y_menor=this->vertices[0].y;
    for(int i=0;i<this->vertices.size();i++){
        if(y_menor>this->vertices[i].y)y_menor=this->vertices[i].y;
        if(_x>this->vertices[i].x)_x=this->vertices[i].x;
        else if(x<this->vertices[i].x)x=this->vertices[i].x;
        if(_y>this->vertices[i].x)_y=this->vertices[i].y;
        else if(y<this->vertices[i].x)y=this->vertices[i].y;
        if(_z>this->vertices[i].x)_z=this->vertices[i].z;
        else if(z<this->vertices[i].x)z=this->vertices[i].z;
    }
    double d=sqrt(pow((x-_x),2)+pow((y-_y),2)+pow((z-_z),2));
    this->r_cajafrontera=(int)(d/2)+1;
    this->subir=y_menor;
}

void _ply::LecturaPly(char *File_name){
    _file_ply ply;
    if(ply.open(File_name)<0){
        perror("\nError durante la apertura del fichero");
        printf("\nError: %d\n",errno);
    }
    else{
        vector<float> vert;
        vector<int> faces;
        ply.read(vert,faces);
        ply.close();
        this->num_caras=faces.size()/3;
        this->caras.resize(this->num_caras);
        this->vertices.resize(vert.size()/3);
        int i,j;
        //--Lectura de vertices del PLY
        for(i=0,j=0; i<this->vertices.size(); i++,j+=3){
            this->vertices[i].x=vert[j];
            this->vertices[i].y=vert[j+1];
            this->vertices[i].z=vert[j+2];
        }
        //--Lectura de caras del PLY
        for(i=0,j=0; i<this->num_caras; i++,j+=3){
            this->caras[i]._0=faces[j];
            this->caras[i]._1=faces[j+1];
            this->caras[i]._2=faces[j+2];
        }
    }
    this->Normalizar();
    this->CajaFrontera();
}


