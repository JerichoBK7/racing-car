/**
 *
 *   This file is part of _wheel.h
 *
 *   _wheel.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   _wheel.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


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
