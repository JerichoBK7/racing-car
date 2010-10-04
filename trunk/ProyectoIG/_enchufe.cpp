#include "_enchufe.h"



void _enchufe::construir(){
    // enchufe
    construirEnchufe();
    // caja del enchufe
    construirJuntas();
}

void _enchufe::construirEnchufe(){
    int divisiones=1;
    /*luces y blanco*/
    _vertex4f blanco,luz,ambient,diffuse,specular;
    blanco.r=1;blanco.g=1;blanco.b=1;blanco.a=1;
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.3;specular.w=1;
    /*construccion*/
    textura=new BMPClass;
    textura->BMPLoad("BMP/enchufe.bmp",blanco);
    enchufe.construir(divisiones,6,6,blanco,luz,textura);
    enchufe.CambiaLuz(luz,ambient,diffuse,specular);
    enchufe.CambiaMaterial("perla");
}

void _enchufe::construirJuntas(){
    /*luces */
    _vertex4f luz,ambient,diffuse,specular;
    luz.x=-2;luz.y=2;luz.z=0;luz.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.7;diffuse.w=1;
    specular.x=specular.y=specular.z=0.3;specular.w=1;
    /*construir*/
    juntas = new Cube;
    juntas->Construir(1);
    /*luz*/
    juntas->setColor(1,1,1,1);
    juntas->CambiaLuz(luz,ambient,diffuse,specular);
    juntas->Normalizar();
    juntas->CambiaMaterial("perla");
}

void _enchufe::drawEnchufe(){
    glPushMatrix();
        enchufe.draw(1,4);
    glPopMatrix();
}

void _enchufe::drawJuntas(){
    glPushMatrix();
    glTranslatef(0,-0.51,0);
    glScalef(6,1,6);
        juntas->draw(1,3);
    glPopMatrix();
}

void _enchufe::draw(int estado){
    // estado del enchufe (color)
    if(estado==0){enchufe.CambiaMaterial("perla");juntas->CambiaMaterial("perla");}
    else if(estado==1){enchufe.CambiaMaterial("esmeralda");juntas->CambiaMaterial("esmeralda");}
    else {enchufe.CambiaMaterial("plasticoRojo");juntas->CambiaMaterial("plasticoRojo");}

    // enchufe
    drawEnchufe();
    // caja del enchufe
    drawJuntas();
}
