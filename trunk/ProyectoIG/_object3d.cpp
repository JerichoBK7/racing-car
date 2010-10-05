/**
 *
 *   This file is part of _object3d.h
 *
 *   _object3d.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   _object3d.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */



#include "_object3d.h"

/*Constructores*/
_object3D::_object3D(){
    img=NULL;
    material=false;
    Luz=false;
}

/*Destructor*/
_object3D::~_object3D(){
    this->vertices.clear();
    this->caras.clear();
    this->filas=this->columnas=this->num_caras=0;
}

/*Otros Metodos*/
void _object3D::draw(){
    glBegin(GL_TRIANGLES);
    for(int i=0; i<this->num_caras; i++){
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._0]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._1]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._2]);
    }
    glEnd();
}

void _object3D::drawAjedrez(){
    glBegin(GL_TRIANGLES);
    for(int i=0; i<this->num_caras; i++){
        (i%2==0)?glColor3f(1,0,0):glColor3f(0,1,0);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._0]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._1]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._2]);
    }
    glEnd();
}

void _object3D::drawPlano(){
    glBegin(GL_TRIANGLES);
    for(int i=0; i<this->num_caras; i++){
        glNormal3fv((GLfloat*)&this->normalf[i]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._0]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._1]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._2]);
    }
    glEnd();
}

void _object3D::drawGouraud(){
    glBegin(GL_TRIANGLES);
    for(int i=0; i<this->num_caras; i++){
        glNormal3fv((GLfloat*)&this->normalv[this->caras[i]._0]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._0]);

        glNormal3fv((GLfloat*)&this->normalv[this->caras[i]._1]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._1]);

        glNormal3fv((GLfloat*)&this->normalv[this->caras[i]._2]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._2]);
    }
    glEnd();
}

void _object3D::CambiaMaterial(string tipo){
    /*TIPOS DE MATERIAL*/
    if(tipo=="esmeralda"){
        material_ambient[0]=0.0215f;material_ambient[1]=0.1745f;material_ambient[2]=0.0215f;material_ambient[3]=0.55f;
        material_diffuse[0]=0.07568f;material_diffuse[1]=0.61424f;material_diffuse[2]=0.07568f;material_diffuse[3]=0.55f;
        material_specular[0]=0.633f;material_specular[1]=0.727811f;material_specular[2]=0.633f;material_specular[3]=0.55f;
        material_brillo=76.8f;
        material=true;
    }
    else if(tipo=="cromo"){
        material_ambient[0]=0.25f;material_ambient[1]=0.25f;material_ambient[2]=0.25f;material_ambient[3]=0.1f;
        material_diffuse[0]=0.4f;material_diffuse[1]=0.4f;material_diffuse[2]=0.4f;material_diffuse[3]=0.1f;
        material_specular[0]=0.774597f;material_specular[1]=0.774597f;material_specular[2]=0.774597f;material_specular[3]=0.1f;
        material_brillo=76.8f;
        material=true;
    }
    else if(tipo=="jade"){
        material_ambient[0]=0.135;material_ambient[1]=0.2225;material_ambient[2]=0.1575;material_ambient[3]=1.0f;
        material_diffuse[0]=0.54;material_diffuse[1]=0.89;material_diffuse[2]=0.63;material_diffuse[3]=1.0f;
        material_specular[0]=0.316228;material_specular[1]=0.316228;material_specular[2]=0.316228;material_specular[3]=1.0f;
        material_brillo=0.1f;
        material=true;
    }
    else if(tipo=="obsidiana"){
        material_ambient[0]=0.05375;material_ambient[1]=0.05;material_ambient[2]=0.06625;material_ambient[3]=1.0f;
        material_diffuse[0]=0.18275;material_diffuse[1]=0.17;material_diffuse[2]=0.22525;material_diffuse[3]=1.0f;
        material_specular[0]=0.332741;material_specular[1]=0.328634;material_specular[2]=0.346435;material_specular[3]=1.0f;
        material_brillo=0.3f;
        material=true;
    }
    else if(tipo=="perla"){
        material_ambient[0]=0.25;material_ambient[1]=0.20725;material_ambient[2]=0.20725;material_ambient[3]=1.0f;
        material_diffuse[0]=1;material_diffuse[1]=0.829;material_diffuse[2]=0.829;material_diffuse[3]=1.0f;
        material_specular[0]=0.296648;material_specular[1]=0.296648;material_specular[2]=0.296648;material_specular[3]=1.0f;
        material_brillo=0.088f;
         material=true;
    }
    else if(tipo=="rubi"){
        material_ambient[0]=0.1745;material_ambient[1]=0.01175;material_ambient[2]=0.01175;material_ambient[3]=1.0f;
        material_diffuse[0]=0.61424;material_diffuse[1]=0.04136;material_diffuse[2]=0.04136;material_diffuse[3]=1.0f;
        material_specular[0]=0.727811;material_specular[1]=0.626959;material_specular[2]=0.626959;material_specular[3]=1.0f;
        material_brillo=0.6f;
        material=true;
    }
    else if(tipo=="turquesa"){
        material_ambient[0]=0.1;material_ambient[1]=0.18725;material_ambient[2]=0.1745;material_ambient[3]=1.0f;
        material_diffuse[0]=0.396;material_diffuse[1]=0.74151;material_diffuse[2]=0.69102;material_diffuse[3]=1.0f;
        material_specular[0]=0.297254;material_specular[1]=0.30829;material_specular[2]=0.306678;material_specular[3]=1.0f;
        material_brillo=0.011f;
        material=true;
    }
    else if(tipo=="cobre_1"){
        material_ambient[0]=0.329412;material_ambient[1]=0.223529;material_ambient[2]=0.027451;material_ambient[3]=1.0f;
        material_diffuse[0]=0.780392;material_diffuse[1]=0.568627;material_diffuse[2]=0.113725;material_diffuse[3]=1.0f;
        material_specular[0]=0.992157;material_specular[2]=.941176;material_specular[1]=0.807843;material_specular[3]=1.0f;
        material_brillo=0.21794872f;
        material=true;
    }
    else if(tipo=="cobre_2"){
        material_ambient[0]=0.19125;material_ambient[1]=0.0735;material_ambient[2]=0.0225;material_ambient[3]=1.0f;
        material_diffuse[0]=0.7038;material_diffuse[1]=0.27048;material_diffuse[2]=0.0828;material_diffuse[3]=1.0f;
        material_specular[0]=0.256777;material_specular[1]=0.137622;material_specular[2]=0.086014;material_specular[3]=1.0f;
        material_brillo=0.1f;
        material=true;
    }
    else if(tipo=="bronce"){
        material_ambient[0]=0.2125;material_ambient[1]=0.1275;material_ambient[2]=0.054;material_ambient[3]=1.0f;
        material_diffuse[0]=0.714;material_diffuse[1]=0.4284;material_diffuse[2]=0.18144;material_diffuse[3]=1.0f;
        material_specular[0]=0.393548;material_specular[1]=0.271906;material_specular[2]=0.166721;material_specular[3]=1.0f;
        material_brillo=0.2f;
        material=true;
    }
    else if(tipo=="oro_1"){
        material_ambient[0]=0.24725f;material_ambient[1]=0.2245f;material_ambient[2]=0.0645f;material_ambient[3]=1.0f;
        material_diffuse[0]=0.34615f;material_diffuse[1]=0.3143f;material_diffuse[2]=0.0903f;material_diffuse[3]=1.0f;
        material_specular[0]=0.797357f;material_specular[1]=0.723991f;material_specular[2]=0.208006f;material_specular[3]=1.0f;
        material_brillo=128.0f;
        material=true;
    }
    else if(tipo=="oro_2"){
        material_ambient[0]=0.24725;material_ambient[1]=0.1995;material_ambient[2]=0.0745;material_ambient[3]=1.0f;
        material_diffuse[0]=0.75164;material_diffuse[1]=0.60648;material_diffuse[2]=0.22648;material_diffuse[3]=1.0f;
        material_specular[0]=0.628281;material_specular[1]=0.555802;material_specular[2]=0.366065;material_specular[3]=1.0f;
        material_brillo=0.4f;
        material=true;
    }
    else if(tipo=="plata"){
        material_ambient[0]=0.19225;material_ambient[1]=0.19225;material_ambient[2]=0.19225;material_ambient[3]=1.0f;
        material_diffuse[0]=0.50754;material_diffuse[1]=0.50754;material_diffuse[2]=0.50754;material_diffuse[3]=1.0f;
        material_specular[0]=0.508273;material_specular[1]=0.508273;material_specular[2]=0.508273;material_specular[3]=1.0f;
        material_brillo=0.4f;
        material=true;
    }
    else if(tipo=="plasticoNegro"){
        material_ambient[0]=0.0;material_ambient[1]=0.0;material_ambient[2]=0.0;material_ambient[3]=1.0f;
        material_diffuse[0]=0.01;material_diffuse[1]=0.01;material_diffuse[2]=0.01;material_diffuse[3]=1.0f;
        material_specular[0]=0.50;material_specular[1]=0.50;material_specular[2]=0.50;material_specular[3]=1.0f;
        material_brillo=0.25f;
        material=true;
    }
    else if(tipo=="plasticoAzul"){
        material_ambient[0]=0.0;material_ambient[1]=0.1;material_ambient[2]=0.06;material_ambient[3]=1.0f;
        material_diffuse[0]=0.0;material_diffuse[1]=0.50980392;material_diffuse[2]=0.50980392;material_diffuse[3]=1.0f;
        material_specular[0]=0.50196078;material_specular[1]=0.50196078;material_specular[2]=0.50196078;material_specular[3]=1.0f;
        material_brillo=0.25f;
        material=true;
    }
    else if(tipo=="plasticoVerde"){
        material_ambient[0]=0.0;material_ambient[1]=0.0;material_ambient[2]=0.0;material_ambient[3]=1.0f;
        material_diffuse[0]=0.1;material_diffuse[1]=0.35;material_diffuse[2]=0.1;material_diffuse[3]=1.0f;
        material_specular[0]=0.45;material_specular[1]=0.55;material_specular[2]=0.45;material_specular[3]=1.0f;
        material_brillo=0.25f;
        material=true;
    }
    else if(tipo=="plasticoRojo"){
        material_ambient[0]=0.0;material_ambient[1]=0.0;material_ambient[2]=0.0;material_ambient[3]=1.0f;
        material_diffuse[0]=0.5;material_diffuse[1]=0.0;material_diffuse[2]=0.0;material_diffuse[3]=1.0f;
        material_specular[0]=0.7;material_specular[1]=0.6;material_specular[2]=0.6;material_specular[3]=1.0f;
        material_brillo=0.25f;
        material=true;
    }
    else if(tipo=="plasticoBlanco"){
        material_ambient[0]=0.0;material_ambient[1]=0.0;material_ambient[2]=0.0;material_ambient[3]=1.0f;
        material_diffuse[0]=0.55;material_diffuse[1]=0.55;material_diffuse[2]=0.55;material_diffuse[3]=1.0f;
        material_specular[0]=0.70;material_specular[1]=0.70;material_specular[2]=0.70;material_specular[3]=1.0f;
        material_brillo=0.25f;
        material=true;
    }
    else if(tipo=="plasticoAmarillo"){
        material_ambient[0]=0.0;material_ambient[1]=0.0;material_ambient[2]=0.0;material_ambient[3]=1.0f;
        material_diffuse[0]=0.5;material_diffuse[1]=0.5;material_diffuse[2]=0.0;material_diffuse[3]=1.0f;
        material_specular[0]=0.60;material_specular[1]=0.60;material_specular[2]=0.50;material_specular[3]=1.0f;
        material_brillo=0.25f;
        material=true;
    }
    else if(tipo=="gomaNegra"){
        material_ambient[0]=0.02;material_ambient[1]=0.02;material_ambient[2]=0.02;material_ambient[3]=1.0f;
        material_diffuse[0]=0.01;material_diffuse[1]=0.01;material_diffuse[2]=0.01;material_diffuse[3]=1.0f;
        material_specular[0]=0.4;material_specular[1]=0.4;material_specular[2]=0.4;material_specular[3]=1.0f;
        material_brillo=0.078125f;
        material=true;
    }
    else if(tipo=="gomaAzul"){
        material_ambient[0]=0.0;material_ambient[1]=0.05;material_ambient[2]=0.05;material_ambient[3]=1.0f;
        material_diffuse[0]=0.4;material_diffuse[1]=0.5;material_diffuse[2]=0.5;material_diffuse[3]=1.0f;
        material_specular[0]=0.04;material_specular[1]=0.7;material_specular[2]=0.7;material_specular[3]=1.0f;
        material_brillo=0.078125f;
        material=true;
    }
    else if(tipo=="gomaVerde"){
        material_ambient[0]=0.0;material_ambient[1]=0.05;material_ambient[2]=0.0;material_ambient[3]=1.0f;
        material_diffuse[0]=0.4;material_diffuse[1]=0.5;material_diffuse[2]=0.4;material_diffuse[3]=1.0f;
        material_specular[0]=0.04;material_specular[1]=0.7;material_specular[2]=0.04;material_specular[3]=1.0f;
        material_brillo=0.078125f;
        material=true;
    }
    else if(tipo=="gomaRoja"){
        material_ambient[0]=0.05;material_ambient[1]=0.0;material_ambient[2]=0.0;material_ambient[3]=1.0f;
        material_diffuse[0]=0.5;material_diffuse[1]=0.4;material_diffuse[2]=0.4;material_diffuse[3]=1.0f;
        material_specular[0]=0.7;material_specular[1]=0.04;material_specular[2]=0.04;material_specular[3]=1.0f;
        material_brillo=0.078125f;
        material=true;
    }
    else if(tipo=="gomaBlanca"){
        material_ambient[0]=0.05;material_ambient[1]=0.05;material_ambient[2]=0.05;material_ambient[3]=1.0f;
        material_diffuse[0]=0.5;material_diffuse[1]=0.5;material_diffuse[2]=0.5;material_diffuse[3]=1.0f;
        material_specular[0]=0.7;material_specular[1]=0.7;material_specular[2]=0.7;material_specular[3]=1.0f;
        material_brillo=0.078125f;
        material=true;
    }
    else if(tipo=="gomaAmarilla"){
        material_ambient[0]=0.05;material_ambient[1]=0.05;material_ambient[2]=0.0;material_ambient[3]=1.0f;
        material_diffuse[0]=0.5;material_diffuse[1]=0.5;material_diffuse[2]=0.4;material_diffuse[3]=1.0f;
        material_specular[0]=0.7;material_specular[1]=0.7;material_specular[2]=0.04;material_specular[3]=1.0f;
        material_brillo=0.078125f;
        material=true;
    }
}

void _object3D::CambiaLuz(_vertex4f pos,_vertex4f ambient,_vertex4f diffuse,_vertex4f specular){
    _vertex4f ambientLight,diffuseLight,specularLight;
    ambientLight.x=ambientLight.y=ambientLight.z=0.3;ambientLight.w=1;
    diffuseLight.x=diffuseLight.y=diffuseLight.z=0.7;diffuseLight.w=1;
    specularLight.x=specularLight.y=specularLight.z=0.25;diffuseLight.w=1;
    luz=pos;
    (ambient.x==-1)?copia(luz_ambientLight,ambientLight):copia(luz_ambientLight,ambient);
    (diffuse.x==-1)?copia(luz_diffuseLight,diffuseLight):copia(luz_diffuseLight,diffuse);
    (specular.x==-1)?copia(luz_specular,specularLight):copia(luz_specular,specular);
    // nueva luz
    Luz=true;
}

void _object3D::copia(GLfloat* gl,_vertex4f punto){
    gl[0]=punto.x;
    gl[1]=punto.y;
    gl[2]=punto.z;
    gl[3]=punto.w;
}

void _object3D::draw(int modo, int tipo){
    if(tipo>=2){
        //Activamos iluminación:
        glEnable(GL_LIGHTING);
        GLfloat Luz0[]={luz.x,luz.y,luz.z,luz.w};//posicion de la luz (procedencia)
        glLightfv(GL_LIGHT0, GL_POSITION, Luz0);
        if(!Luz){
            //Valores y coordenadas de la luz
            GLfloat ambientLight[]={0.3f,0.3f,0.3f,1.0f};
            GLfloat diffuseLight[]={0.7f,0.7f,0.7f,1.0f};
            GLfloat specular[]={0.25f,0.25f,0.25f,1.0f};
            glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
            glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
        }
        else{
            glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambientLight);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_diffuseLight);
            glLightfv(GL_LIGHT0, GL_SPECULAR,luz_specular);
        }
        //Establecer y activar el 0 de luz:
        glEnable(GL_LIGHT0);

        /* Materiales del instrumento: */
        if(!material){//Todos los materiales tienen una reflectancia especular completa con un alto brillo
            GLfloat specref[]={1.0f,1.0f,1.0f,1.0f};
            glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
            glMateriali(GL_FRONT, GL_SHININESS, 128);
        }
        else{//damos matices del material elegido únicamente por el frontal
            glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
            glMaterialf(GL_FRONT, GL_SHININESS, material_brillo);
        }
    }
    // tipo (alambres , normal, puntos)
    if(modo==0)glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    else if(modo==1)glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    else glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);

    // definicion del color
    if(tipo>=2){
        if(!material){
            GLfloat color[]={this->color.r, this->color.g, this->color.b, this->color.a};
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        }
    }
    // modo de pintado ( normal, ajedrez, plano, gouraud o textura)
    if(tipo==0){glColor3f(color.r,color.g,color.b);draw();}
    else if(tipo==1)drawAjedrez();
    else if(tipo==2){glShadeModel(GL_FLAT);drawPlano();}
    else if(tipo==3){glShadeModel(GL_SMOOTH);drawGouraud();}
    else{drawTexture();}

    if(tipo>=2){glDisable(GL_LIGHTING);glDisable(GL_COLOR_MATERIAL);}
}

void _object3D::drawTexture(void){
    // cargamos textura, sino fue cargada
    if(!glIsTexture(texID))loadTexture();
    // dibujamos
    glBindTexture(GL_TEXTURE_2D, texID);
    /*activamos las texturas*/
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLES);
    for(int i=0; i<this->num_caras; i++){
        glNormal3fv((GLfloat*)&this->normalv[this->caras[i]._0]);
        glTexCoord2fv((GLfloat*)&img->textura[0]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._0]);

        glNormal3fv((GLfloat*)&this->normalv[this->caras[i]._1]);
        (i%2==0)?glTexCoord2fv((GLfloat*)&img->textura[3]):glTexCoord2fv((GLfloat*)&img->textura[2]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._1]);

        glNormal3fv((GLfloat*)&this->normalv[this->caras[i]._2]);
        (i%2==0)?glTexCoord2fv((GLfloat*)&img->textura[1]):glTexCoord2fv((GLfloat*)&img->textura[3]);
        glVertex3fv((GLfloat*)&this->vertices[this->caras[i]._2]);
    }
    glEnd();
    /*desactivamos texturas*/
    glDisable(GL_TEXTURE_2D);
}

void _object3D::loadTexture(void){
    glGenTextures(1,&texID);
    /*Se "bindea"/selecciona la textura para definir sus propiedades*/
    glBindTexture(GL_TEXTURE_2D, texID);
    /*pegado sobre el poligono*/
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    /*filtro de la textura*/
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    //glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
    /*cargamos la imagen*/
    glTexImage2D(GL_TEXTURE_2D,0,3,img->width,img->height,0, GL_RGB,GL_UNSIGNED_BYTE, &img->pixel[0]);
}

_vertex3f& _object3D::read(const int &fil, const int&col){
    int pos=this->columnas*fil+col;
    if((pos%this->columnas)==0)
        pos=this->columnas*fil;
    return(this->vertices[pos]);
}

int _object3D::pos(const int &fil, const int&col){
    int pos=this->columnas*fil+col;
    if((pos%this->columnas)==0)
        pos=this->columnas*fil;
    return(pos);
}

void _object3D::Construir(float){
}
void _object3D::Construir(float,int){
}
void _object3D::Construir(float,float,int){
}


void _object3D::Normalizar(void){
    //-->Normales de las caras
    this->normalf.resize(this->num_caras);
    _vertex3f A,B,v;
    int f_0,f_1,f_2;
    for(int i=0; i<this->num_caras; i++){
        //-->Vectores que conforman la cara:
        f_0=this->caras[i]._0;
        f_1=this->caras[i]._1;
        f_2=this->caras[i]._2;
        //-->Obtención de vectores del plano:
        A=this->vertices[f_1]-this->vertices[f_0];
        B=this->vertices[f_2]-this->vertices[f_0];
        //-->Plano Normal al plano y normalizado:
        v=A.cross_product(B);
        this->normalf[i]=v.normalize();
    }
    //-->Normales de los puntos
    this->normalv.resize(this->vertices.size());
    for(int i=0; i<this->vertices.size(); i++){
        this->normalv[i].x=0;
        this->normalv[i].y=0;
        this->normalv[i].z=0;

        for(int j=0; j<this->num_caras; j++)
            if(this->caras[j]._0==i||this->caras[j]._1==i||this->caras[j]._2==i)this->normalv[i]+=this->normalf[j];
        this->normalv[i].normalize();
    }
}













