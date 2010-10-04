#include "primitivas.h"

/*************************************************************************/
/*                        T E T R A E D R O                              */
/*                                                                       */
/*************************************************************************/
/*Constructores*/
Tetraedro::Tetraedro(float r){
    this->Construir(r);
}
void Tetraedro::Construir(float r){
    this->radio=0;
    this->vertices.resize(4);
    this->num_caras=4*2;
    this->caras.resize(8);
    //-->Construyendo Vertices:
    for(int i=0; i<3; i++){
        this->vertices[i].y=0;
        this->vertices[i].x=r*cos(((2*3.1415)/3)*i);
        this->vertices[i].z=r*sin(((2*3.1415)/3)*i);
    }
    double distancia=sqrt(pow(this->vertices[1].x-this->vertices[0].x,2)+pow(this->vertices[1].z-this->vertices[0].z,2));
    double h=sqrt(6)/3*distancia;
    this->vertices[3].x=0;
    this->vertices[3].z=0;
    for(int i=0;i<3;i++)this->vertices[i].y=-h/2;
    this->vertices[3].y=h/2;
    //-->Construyendo Caras:
      int j=0,num_div=3;
      //Base:
        this->caras[j]._0=0;this->caras[j]._1=1;this->caras[j]._2=2;
      //Altura:
        for(int i=0;i<num_div;i++,j++){
            this->caras[j]._0=((i+1)%num_div);this->caras[j]._1=i;this->caras[j]._2=num_div;
        }
}
/*Destructor*/
Tetraedro::~Tetraedro(){
    this->radio=0;
}


/*************************************************************************/
/*                              C U B O                                  */
/*                                                                       */
/*************************************************************************/
/*Constructores*/
Cube::Cube(float l){
    this->Construir(l);
}
void Cube::Construir(float l){
    this->lado=l;
    this->vertices.resize(8);
    this->filas=2;
    this->columnas=4;
    this->caras.resize(6*2*2);//6CarasCubo*2TriangulosCara*2DelanteDetras
    this->num_caras=24;
//--> Construimos los vertices:
    this->vertices[0].x=l/2;this->vertices[0].y=-l/2;this->vertices[0].z=l/2;
    this->vertices[1].x=l/2;this->vertices[1].y=-l/2;this->vertices[1].z=-l/2;
    this->vertices[2].x=-l/2;this->vertices[2].y=-l/2;this->vertices[2].z=-l/2;
    this->vertices[3].x=-l/2;this->vertices[3].y=-l/2;this->vertices[3].z=l/2;

    this->vertices[4].x=l/2;this->vertices[4].y=l/2;this->vertices[4].z=l/2;
    this->vertices[5].x=l/2;this->vertices[5].y=l/2;this->vertices[5].z=-l/2;
    this->vertices[6].x=-l/2;this->vertices[6].y=l/2;this->vertices[6].z=-l/2;
    this->vertices[7].x=-l/2;this->vertices[7].y=l/2;this->vertices[7].z=l/2;
//--> Construimos las caras:
    int i=0,j,k=0;
    //-->CUERPO
    for(j=0; j<this->columnas; j++){
        //Cara baja
        this->caras[k]._0=this->pos(i,j);this->caras[k]._1=this->pos(i,j+1);this->caras[k]._2=this->pos(i+1,j);
        //Cara alta
        k++;this->caras[k]._0=this->pos(i+1,j);this->caras[k]._1=this->pos(i,j+1);this->caras[k]._2=this->pos(i+1,j+1);
        k++;
    }
    //-->TAPAS
    i=1;j=0;
    //TAPA SUPERIOR
        //Cara baja
        this->caras[k]._0=this->pos(i,j);this->caras[k]._1=this->pos(i,j+1);this->caras[k]._2=this->pos(i,j+3);
        //Cara alta
        k++;this->caras[k]._0=this->pos(i,j+3);this->caras[k]._1=this->pos(i,j+1);this->caras[k]._2=this->pos(i,j+2);
    //TAPA INFERIOR
        i=j=0;
        //Cara baja
        k++;this->caras[k]._0=this->pos(i,j+2);this->caras[k]._1=this->pos(i,j+1);this->caras[k]._2=this->pos(i,j+3);
        //Cara alta
        k++;this->caras[k]._0=this->pos(i,j+3);this->caras[k]._1=this->pos(i,j+1);this->caras[k]._2=this->pos(i,j);
}

/*Destructor*/
Cube::~Cube(){
    this->lado=0;
}


/*************************************************************************/
/*                              C O N O                                  */
/*                                                                       */
/*************************************************************************/
/*Constructores*/
Cono::Cono(float r, float h, int num_div){
    this->Construir(r,h,num_div);
}

void Cono::Construir(float r, float h, int num_div){
    this->radio=r;this->altura=h;this->divisiones=num_div;
    this->vertices.resize(num_div+2);
    this->num_caras=num_div*2;
    this->caras.resize(num_div*2);
//-->Construyendo Vertices:
    int i=0;
    for(; i<num_div; i++){
        this->vertices[i].y=-h/2;
        this->vertices[i].x=r*cos(((2*3.1415)/num_div)*i);
        this->vertices[i].z=r*sin(((2*3.1415)/num_div)*i);
    }
    this->vertices[i].x=0;this->vertices[i].y=-h/2;this->vertices[i].z=0;
    this->vertices[i+1].x=0;this->vertices[i+1].y=h/2;this->vertices[i+1].z=0;
//-->Construyendo Caras:caras
    int k=0;
    //Circunferencia:
    for(i=0;i<num_div;i++,k++){
        this->caras[k]._0=i;this->caras[k]._1=((i+1)%num_div);this->caras[k]._2=num_div;
    }
    //Altura:
    for(i=0;i<num_div;i++,k++){
       this->caras[k]._0=((i+1)%num_div);this->caras[k]._1=i;this->caras[k]._2=num_div+1;
    }
}
/*Destructor*/
Cono::~Cono(){
    this->altura=this->divisiones=this->radio=0;
}


/*************************************************************************/
/*                         C I L I N D R O                               */
/*                                                                       */
/*************************************************************************/
/*Constructores*/
Cilindro::Cilindro(float r, float h, int div){
    this->Construir(r,h,div);
}
void Cilindro::Construir(float r, float h, int div){
    this->altura=h;this->radio=r;this->divisiones=div;
    this->filas=2;
    this->columnas=div;
    this->vertices.resize(div*2+2);
    this->num_caras=div*4;
    this->caras.resize(div*4);

//-->Construir Vertices:
    int i;
    for(i=0; i<div; i++){
        //->circunferencia inferior
        this->vertices[i].y=-h/2;
        this->vertices[i].x=r*cos(((2*3.1415)/div)*i);
        this->vertices[i].z=r*sin(((2*3.1415)/div)*i);
        //->circunferencia superior
        this->vertices[i+div].y=h/2;
        this->vertices[i+div].x=this->vertices[i].x;
        this->vertices[i+div].z=this->vertices[i].z;
    }
    this->vertices[div*2].x=0;this->vertices[div*2].y=-h/2;this->vertices[div*2].z=0;//centro abajo
    this->vertices[div*2+1].x=0;this->vertices[div*2+1].y=h/2;this->vertices[div*2+1].z=0;//centro arriba
//-->Construir Caras:
    int k;
    //Circunferencia:
        //Abajo:
        for(i=0,k=0;i<div;i++,k++){
            this->caras[k]._0=i;this->caras[k]._1=((i+1)%div);this->caras[k]._2=div*2;
        }
        //Arriba:
        for(;i<div*2;i++){
            int w;
            if((w=((i+1)%(div*2)))==0)w=div;
            //exterior:
            this->caras[k]._0=i;this->caras[k]._1=w;this->caras[k]._2=div*2+1;
            k++;
        }
    //Cuerpo:
        i=0;
        for(int j=0; j<div; j++){
            //Cara baja
            this->caras[k]._0=this->pos(i,j);this->caras[k]._1=this->pos(i,j+1);this->caras[k]._2=this->pos(i+1,j);
            //Cara alta
            k++;this->caras[k]._0=this->pos(i+1,j);this->caras[k]._1=this->pos(i,j+1);this->caras[k]._2=this->pos(i+1,j+1);
            k++;
        }
}
/*Destructor*/
Cilindro::~Cilindro(){
    this->altura=this->radio=this->divisiones=0;
}
