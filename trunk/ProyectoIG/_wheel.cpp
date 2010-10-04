#include "_wheel.h"

_wheel::_wheel(int ancho, int largo)
{
    this->ConstruirR(ancho,largo);
}
void _wheel::ConstruirR(int ancho,int largo){
    this->ruedas = new Cilindro;
    this->ruedas->setColor(0,0,1,1);
    this->ruedas->Construir(ancho/4.5,ancho/5.5,20);//r,h,div
}

_wheel::~_wheel(){
    delete this->ruedas;
}

void _wheel::drawEje(int ancho, int largo, int modo, int tipo){
    if(modo!=1)this->ruedas->setColor(0,1,0,1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(ancho/2,-ancho/4,largo/2-ancho/3);//Dd
    glRotatef(90,0,0,1);
    //(modo==2)?this->ruedas->drawAjedrez():this->ruedas->draw();
    this->ruedas->draw(modo,tipo);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-ancho/2,-ancho/4,largo/2-ancho/3);//Di
    glRotatef(-90,0,0,1);
    //(modo==2)?this->ruedas->drawAjedrez():this->ruedas->draw();
    this->ruedas->draw(modo,tipo);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(ancho/2,-ancho/4,-largo/2+ancho/3);//Td
    glRotatef(90,0,0,1);
    //(modo==2)?this->ruedas->drawAjedrez():this->ruedas->draw();
    this->ruedas->draw(modo,tipo);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-ancho/2,-ancho/4,-largo/2+ancho/3);//Ti
    glRotatef(-90,0,0,1);
    //(modo==2)?this->ruedas->drawAjedrez():this->ruedas->draw();
    this->ruedas->draw(modo,tipo);
    glPopMatrix();
}
