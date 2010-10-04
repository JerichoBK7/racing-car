#include "cuadros.h"

void cuadros::construir(int alto, int ancho,char *material,char *File_name){
    this->alto=alto;
    this->ancho=ancho;
    // marco
    construirMarco(material);
    // cuadro
    construirCuadro(File_name);
}

void cuadros::construirMarco(char *material){
    int divisiones=1;
    /*color y luz*/
    _vertex4f blanco;
    _vertex4f luz,ambient,diffuse,specular;
    blanco.x=blanco.y=blanco.z=blanco.a=1;
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.3;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.6;diffuse.w=1;
    specular.x=specular.y=specular.z=0.1;specular.w=1;
    /*construccion*/
    marco.resize(5);
    marco[0].construir(divisiones,alto,4,blanco,luz,NULL);//largo
    marco[1].construir(divisiones,4,ancho+8,blanco,luz,NULL);//corto
    marco[2].construir(divisiones,alto+8,4,blanco,luz,NULL);//largo interior
    marco[3].construir(divisiones,4,ancho+8,blanco,luz,NULL);//corto interior
    marco[4].construir(divisiones,alto+8,ancho+8,blanco,luz,NULL);//superficie

    marco[0].CambiaLuz(luz,ambient,diffuse,specular);
    marco[0].CambiaMaterial(material);
    marco[1].CambiaLuz(luz,ambient,diffuse,specular);
    marco[1].CambiaMaterial(material);

    luz.x=0;luz.y=30;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.2;
    diffuse.x=diffuse.y=diffuse.z=0.3;
    specular.x=specular.y=specular.z=0.1;

    marco[2].CambiaLuz(luz,ambient,diffuse,specular);
    marco[2].CambiaMaterial(material);
    marco[3].CambiaLuz(luz,ambient,diffuse,specular);
    marco[3].CambiaMaterial(material);
    marco[4].CambiaLuz(luz,ambient,diffuse,specular);
    marco[4].CambiaMaterial(material);
}

void cuadros::construirCuadro(char *File_name){
    int divisiones=1;
    /*color y luz*/
    _vertex4f blanco;
    _vertex4f luz,ambient,diffuse,specular;
    blanco.x=blanco.y=blanco.z=blanco.a=1;
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.2;specular.w=1;
    /*construccion*/
    textura_cuadro=new BMPClass;
    textura_cuadro->BMPLoad(File_name,blanco);
    cuadro.construir(divisiones,alto,ancho,blanco,luz,textura_cuadro);
    cuadro.CambiaLuz(luz,ambient,diffuse,specular);
}

void cuadros::drawMarco(){
    /*listones largos*/
    glPushMatrix();
    glTranslatef(-ancho/2-2,2,0);
        marco[0].draw(1,3);
    glTranslatef(ancho+4,0,0);
        marco[0].draw(1,3);
    glPopMatrix();
    /*listones cortos*/
    glPushMatrix();
    glTranslatef(0,2,alto/2+2);
        marco[1].draw(1,3);
    glTranslatef(0,0,-alto-4);
        marco[1].draw(1,3);
    glPopMatrix();
    /*interiores largos*/
    glPushMatrix();
    glTranslatef(-ancho/2,0,0);
    glRotatef(90,0,0,1);
        marco[2].draw(1,3);//interior izq
    glTranslatef(0,4,0);
        marco[2].draw(1,3);//exterior izq
    glTranslatef(0,-ancho-4,0);
        marco[2].draw(1,3);//interior der
    glTranslatef(0,-4,0);
        marco[2].draw(1,3);//interior der
    glPopMatrix();
    /*interiores cortos*/
    glPushMatrix();
    glTranslatef(0,0,-alto/2);
    glRotatef(90,1,0,0);
        marco[3].draw(1,3);//interior izq
    glTranslatef(0,-4,0);
        marco[3].draw(1,3);//exterior izq
    glTranslatef(0,alto+4,0);
        marco[3].draw(1,3);//interior der
    glTranslatef(0,4,0);
        marco[3].draw(1,3);//interior der
    glPopMatrix();
    /*superficie*/
    glPushMatrix();
    glTranslatef(0,-2,0);
        marco[4].draw(1,3);
    glPopMatrix();

}

void cuadros::drawCuadro(){
    glPushMatrix();
    glRotatef(180,0,0,1);
        cuadro.draw(1,4);
    glPopMatrix();
}

void cuadros::draw(){
    glPushMatrix();
    glTranslatef(0,2,0);
        // marco
        drawMarco();
        // cuadro
        drawCuadro();
    glPopMatrix();
}


