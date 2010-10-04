#include "puerta.h"

void puerta :: construir(){
    construirPuerta();//construir la puerta
    construirJuntas();//construir las juntas de la puerta
}

void puerta :: construirPuerta(){
    /*iluminacion y color*/
    _vertex4f luz, color;
    luz.x=0;luz.y=25;luz.z=0;luz.w=1;
    color.r=1;color.g=1;color.b=1;color.a=1;
    /* construccion */
    p_=new BMPClass;
    p_->BMPLoad("BMP/puerta.bmp",color);
    p.construir(1,80,50,color,luz,p_);
}

void puerta :: construirJuntas(){
    /*iluminacion y color*/
    _vertex4f luz, color;
    luz.x=0;luz.y=25;luz.z=0;luz.w=1;
    color.r=0.6;color.g=0.4;color.b=0.2;color.a=1;//marrón puerta
    /*construcción de las juntas de las puertas*/
    juntas.resize(2);
    int divisiones=1;
    juntas[0].construir(divisiones,4,80,color,luz,NULL);//laterales puerta
    juntas[1].construir(divisiones,4,50,color,luz,NULL);//arriba      "
}

void puerta :: draw(){
 /*1º. Tapa arriba Y abajo*/
    glPushMatrix();
    glTranslatef(0,-2,0);//grosor
        p.draw(1,4);
    glTranslatef(0,4,0);//grosor
        p.draw(1,4);
    glPopMatrix();

 /*2º. Juntas*/
     //izquierda
    glPushMatrix();
        glTranslatef(25,0,0);
        glRotatef(90,0,0,1);
        glRotatef(90,0,1,0);
        juntas[0].draw(1,3);
    glPopMatrix();
    //derecha
   glPushMatrix();
       glTranslatef(-25,0,0);
       glRotatef(90,0,0,1);
       glRotatef(90,0,1,0);
       juntas[0].draw(1,3);
   glPopMatrix();
    //abajo
   glPushMatrix();
       glTranslatef(0,0,40);
       glRotatef(90,1,0,0);
       juntas[1].draw(1,3);
   glPopMatrix();
   //arriba
  glPushMatrix();
      glTranslatef(0,0,-40);
      glRotatef(90,1,0,0);
      juntas[1].draw(1,3);
  glPopMatrix();
}
