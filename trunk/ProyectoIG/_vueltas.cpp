#include "_vueltas.h"


_vueltas::_vueltas()
{
    // variables
    int num_vuelta=7,divisiones=1;
    char cadena[10];
    _vertex4f blanco,luz,ambient,diffuse,specular;
    string ruta;
    blanco.r=blanco.g=blanco.b=blanco.a=1;

    /*1º.-Construccion de las texturas*/
    textura_vuelta.resize(num_vuelta);
    for(int i=0;i<num_vuelta;i++){
        textura_vuelta[i] = new BMPClass;
        //conversion del entero a cadena
        sprintf(cadena,"%d",i+1);
        ruta="INFORMACION/VUELTAS/"+(string)cadena+"-7.bmp";
        textura_vuelta[i]->BMPLoad(ruta,blanco);
    }
    /*2º.-Imagen-Vueltas del coche*/
    //Luces
    luz.x=0;luz.y=100;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.2;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.3;specular.w=1;
    //superficie
    vuelta.resize(num_vuelta);
    for(int i=0;i<num_vuelta;i++){
        vuelta[i].construir(divisiones,3,3,blanco,luz,textura_vuelta[i]);
        vuelta[i].CambiaLuz(luz,ambient,diffuse,specular);
    }
    /*3º.-Embellecedor*/
    luz.x=0;luz.y=4;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.5;diffuse.w=1;
    specular.x=specular.y=specular.z=0.45;specular.w=1;
    /*construir*/
    juntas = new Cube;
    juntas->Construir(1);
    juntas2 = new Cube;
    juntas2->Construir(1);
    /*luz*/
    juntas->setColor(1,1,1,1);
    juntas->CambiaLuz(luz,ambient,diffuse,specular);
    juntas->Normalizar();
    juntas->CambiaMaterial("plasticoRojo");

    luz.x=0;luz.y=4;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.3;specular.w=1;
    juntas2->setColor(1,1,1,1);
    juntas2->CambiaLuz(luz,ambient,diffuse,specular);
    juntas2->Normalizar();
    juntas2->CambiaMaterial("plasticoRojo");
}

_vueltas::~_vueltas(){
    //imagenes
    for(int i=0;i<textura_vuelta.size();i++)
        delete textura_vuelta[i];
    //cubo
    delete juntas;
    delete juntas2;
}

void _vueltas::draw(int num){
    int num_vueltas=vuelta.size();

    if(num>0){
        (num>num_vueltas)?num=0:num=num-num_vueltas;
        if(num<0)num*=-1;
        //1º.-Número de vueltas:
        glPushMatrix();
        glRotatef(180,0,0,1);
            vuelta[num].draw(1,4);
        glPopMatrix();
        //2º.-Juntas
        //abajo - arriba
        glPushMatrix();
        glTranslatef(-0.445,0,-1.03);
        glScalef(2.88,0.15,0.15);
            juntas->draw(1,3);
        glTranslatef(0,0,20.5);
            juntas->draw(1,3);
        glPopMatrix();
        //izq
        glPushMatrix();
        glTranslatef(-1.95,0,0.5);
        glRotatef(90,0,1,0);
        glScalef(3.22,0.15,0.15);
            juntas2->draw(1,3);
        glPopMatrix();
        //der
        glPushMatrix();
        glTranslatef(1.07,0,0.5);
        glRotatef(90,0,1,0);
        glScalef(3.22,0.15,0.15);
            juntas2->draw(1,3);
        glPopMatrix();
    }
}
