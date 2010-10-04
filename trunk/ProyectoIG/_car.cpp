#include "_car.h"

/*Constructores*/
_car::_car()
{
    int ancho=8,largo=12;
    //-->Declaraciones:
    this->rueda.ConstruirR(ancho,largo);
    this->chasis_=new Cube;
    this->cabina_=new Cube;
    this->chasis_->Construir(1);
    this->cabina_->Construir(1);
    this->faro=new Cono;
    this->faro->Construir(ancho/12.15,largo/15.15,20);
}
void _car::draw(int modo, int tipo){
    /*
        MODO
          0.-Aristas
          1.-Normal
          2.-Puntos
        TIPO
          0.-Normal
          1.-Ajedrez
    */
    int ancho=8,largo=12;
    /*Color*/
        modo%=3;
        if(modo==1){
            // Chasis
            this->chasis_->setColor(1,0,0,1);
            // Cabina
            this->cabina_->setColor(0,1,0,1);
            // Faro
            this->faro->setColor(0,1,1,1);
        }
        else{
            // Chasis
            this->chasis_->setColor(0,1,0,1);
            // Cabina
            this->cabina_->setColor(0,1,0,1);
            // Faro
            this->faro->setColor(0,1,0,1);
        }
    /*Dibujamos en Pantalla*/
        tipo%=2;
        // Chasis-cabina
        this->eje(ancho,largo,modo,tipo);
        // Chasis
        this->chasis(ancho,largo,modo,tipo);
        // Cabina
        this->cabina(ancho,largo,modo,tipo);
        // Faro
        this->faros(ancho,largo,modo,tipo);
}

/*Destructor*/
_car::~_car(){
    delete this->chasis_;
    delete this->cabina_;
    delete this->faro;
}

/*Otros Metodos*/
void _car::eje(int ancho, int largo, int modo, int tipo){
    this->rueda.drawEje(ancho,largo,modo,tipo);
}
void _car::chasis(int ancho, int largo, int modo, int tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(ancho,ancho/2,largo);
    this->chasis_->draw(modo,tipo);
    glPopMatrix();
}
void _car::cabina(int ancho, int largo, int modo, int tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,ancho/2,-largo/6);
    glScalef((ancho-ancho/4),ancho/2,largo/2);
    this->cabina_->draw(modo,tipo);
    glPopMatrix();
}
void _car::faros(int ancho, int largo, int modo, int tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(ancho/2-ancho/4.5,ancho/4-ancho/5,largo/2);
    glRotatef(-90,1,0,0);
    this->faro->draw(modo,tipo);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-ancho/2+ancho/4.5,ancho/4-ancho/5,largo/2);
    glRotatef(-90,1,0,0);
    this->faro->draw(modo,tipo);
    glPopMatrix();
}
