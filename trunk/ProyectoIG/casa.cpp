#include "casa.h"


void casa::creaCasa()
{
    /*1º.-Estructura:*/
    // suelo
    construirSuelo();
    // paredes
    construirPared();
    // techo
    construirTecho();
    // juntas
    construirJuntas();

    /*2º.-Decoración:*/
    // puerta
    p.construir();
    // cocina
    c.construir();
    // entrada
    e.construir();
    // salon
    s.construir();
    // enchufe
    enchufe.construir();
    /*3º.-Accesorios*/
    _vertex4f pos,ambient,diffuse,specular,blanco;
    // pelota
    blanco.r=0.8;blanco.g=0.2;blanco.b=0;blanco.a=1;
    pos.x=200;pos.y=170;pos.z=-70;pos.w=1;
    pelota.Construir(24,17,blanco,pos);
    ambient.x=ambient.y=ambient.z=0.8;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.9;diffuse.w=1;
    specular.x=specular.y=specular.z=0;specular.w=1;
    pelota.CambiaLuz(pos,ambient,diffuse,specular);
    // lampara
    lamparita.construir();
    // maceta
    macetita.construir();
    // tetera
    tetera.LecturaPly("PLY/tetera.ply");
    tetera.setColor(1,1,1,1);
    pos.x=100;pos.y=-100;pos.z=100;pos.w=1;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=diffuse.y=diffuse.z=0.9;diffuse.w=1;
    specular.x=specular.y=specular.z=0.4;specular.w=1;
    tetera.CambiaLuz(pos,ambient,diffuse,specular);
    // muelle
    muelle.LecturaPly("PLY/muelle.ply");
    muelle.setColor(1,1,1,1);
    muelle.CambiaMaterial("plata");
    ambient.x=ambient.y=ambient.z=0.3;
    diffuse.x=diffuse.y=diffuse.z=0.1;
    specular.x=specular.y=specular.z=0.08;
    muelle.CambiaLuz(pos,ambient,diffuse,specular);
    // guitarra electrica
    guitarra.LecturaPly("PLY/guitarra_electrica.ply");
    guitarra.setColor(1,1,1,1);
    guitarra.CambiaMaterial("perla");
    guitarra.CambiaLuz(pos,ambient,diffuse,specular);
    // zapatillas
    zapatilla.LecturaPly("PLY/zapatillas_deporte.ply");
    zapatilla.setColor(1,1,1,1);
    ambient.x=ambient.y=ambient.z=1;
    diffuse.x=diffuse.y=diffuse.z=1;
    specular.x=specular.y=specular.z=0.9;
    zapatilla.CambiaMaterial("gomaBlanca");
    zapatilla.CambiaLuz(pos,ambient,diffuse,specular);
    // ketchup
    ketchup.LecturaPly("PLY/ketchup.ply");
    ketchup.setColor(1,1,1,1);
    pos.x=0;pos.y=200;pos.z=0;pos.w=0.75;
    ambient.x=ambient.y=ambient.z=0.4;ambient.w=1;
    diffuse.x=0.5;specular.x=0.8;
    diffuse.y=0.5;specular.y=0.8;
    diffuse.z=0.5;specular.z=0.8;
    diffuse.w=specular.w=1;
    ketchup.CambiaLuz(pos,ambient,diffuse,specular);
    // silla
    silla.LecturaPly("PLY/silla.ply");
    silla.setColor(1,1,1,1);
    silla.CambiaMaterial("cromo");
    pos.x=0;pos.y=0;pos.z=200;pos.w=0.75;
    ambient.x=ambient.y=ambient.z=0.5;ambient.w=1;
    diffuse.x=0.8;specular.x=0.5;
    diffuse.y=0.8;specular.y=0.5;
    diffuse.z=0.8;specular.z=0.5;
    silla.CambiaLuz(pos,ambient,diffuse,specular);
    // tijeras
    tijeras.LecturaPly("PLY/tijeras.ply");
    tijeras.setColor(1,1,1,1);
    tijeras.CambiaMaterial("plata");
    tijeras.CambiaLuz(pos,ambient,diffuse,specular);
    // sandalias
    sandalia.LecturaPly("PLY/sandalia.ply");
    sandalia.setColor(1,1,1,1);
    sandalia.CambiaMaterial("gomaAmarilla");
    sandalia.CambiaLuz(pos,ambient,diffuse,specular);
    // cuadro_1 (florero)
    cuadro[0].construir(50,46,"obsidiana","BMP/cuadro1.bmp");//alto * ancho + material + cuadro
    // cuadro_2 (abstracto)
    cuadro[1].construir(54,48,"plata","BMP/cuadro2.bmp");
    // cuadro_3 (habitacion van gogh)
    cuadro[2].construir(30,30,"bronce","BMP/cuadro3.bmp");
    // cuadro_4 (el guernica)
    cuadro[3].construir(40,100,"gomaAzul","BMP/cuadro4.bmp");
    // cuadro_5 (girasoles)
    cuadro[4].construir(30,30,"bronce","BMP/cuadro5.bmp");
    // cuadro_6 (gracioso)
    cuadro[5].construir(30,30,"esmeralda","BMP/simpson.bmp");
    //cubo basura
    pos.x=100;pos.y=60;pos.z=50;pos.w=1;
    ambient.x=ambient.y=ambient.z=0.6;
    diffuse.x=diffuse.y=diffuse.z=0.4;
    specular.x=specular.y=specular.z=0.3;

    cubo_basura.LecturaPly("PLY/cubo_basura.ply");
    cubo_basura.setColor(1,1,1,1);
    cubo_basura.CambiaMaterial("plasticoBlanco");
    cubo_basura.CambiaLuz(pos,ambient,diffuse,specular);
}

void casa :: construirSuelo(void){
    /*iluminacion y color*/
    _vertex4f luz, color;
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;
    color.r=1;color.g=1;color.b=1;color.a=1;
    /* construccion */
    //utilizamos 20 divisiones...(primer entero)
    suelo.resize(3);
    entrada_=new BMPClass;
    entrada_->BMPLoad("BMP/entrada.bmp",color);
    suelo[0].construir(20,320,180,color,luz,entrada_);//entrada
    cocina_=new BMPClass;
    cocina_->BMPLoad("BMP/cocina.bmp",color);
    suelo[2].construir(20,320,320,color,luz,cocina_);//cocina_
    luz.y=60;
    salon_=new BMPClass;
    salon_->BMPLoad("BMP/salon.bmp",color);
    suelo[1].construir(20,180,500,color,luz,salon_);//salon
}

void casa :: construirPared(void){
    /*iluminacion y color*/
    _vertex4f luz, cocina_color, salon_color,entrada_color,columna_entrada,columna_salon,columna_cocina;
    /*colores*/
    entrada_color.r=0.75;entrada_color.g=0.65;entrada_color.b=1;entrada_color.a=1;
    cocina_color.r=0.6;cocina_color.g=0.988235294;cocina_color.b=0.6;cocina_color.a=1;
    salon_color.r=0.815686274;salon_color.g=0.721568627;salon_color.b=0.529411764;salon_color.a=1;
    columna_entrada.r=0.55;columna_entrada.g=0.17;columna_entrada.b=0.89;columna_entrada.a=1;
    columna_salon.r=0.549019607;columna_salon.g=0.274509803;columna_salon.b=0.078431372;columna_salon.a=1;
    columna_cocina.r=0.423529411;columna_cocina.g=0.556862745;columna_cocina.b=0.35;columna_cocina.a=1;//6B-8E-23
    /* construccion */
    pared.resize(36);
    int divisiones=1;
    int altura=100;

    /*1º.-Paredes entrada:*/
    luz.x=0;luz.y=1000;luz.z=0;luz.w=1;
    pared[0].construir(divisiones,altura,160,entrada_color,luz,NULL);//arriba
    pared[1].construir(divisiones,166,altura,entrada_color,luz,NULL);//derecha (der-puerta)
    pared[24].construir(divisiones,70,altura,entrada_color,luz,NULL);//derecha (izq-puerta)

    pared[2].construir(divisiones,altura,60,entrada_color,luz,NULL);//abajo_dere.puerta_salon
    pared[3].construir(divisiones,altura,50,entrada_color,luz,NULL);//abajo_izq.puerta_salon

    pared[5].construir(divisiones,160,altura,entrada_color,luz,NULL);//izquierda
    pared[6].construir(divisiones,70,altura,entrada_color,luz,NULL);//izquierda

    //partes de arriba de las puertas:
    pared[4].construir(divisiones,20,50,entrada_color,luz,NULL);//arriba_izq.puerta_salon
    pared[25].construir(divisiones,50,20,entrada_color,luz,NULL);//derecha (encima-puerta)
    pared[7].construir(divisiones,50,20,entrada_color,luz,NULL);//izquierda cocina

        //columna de 25 - derecha
        luz.y=50;luz.w=1;
        pared[26].construir(divisiones,26,altura,columna_entrada,luz,NULL);
        luz.y=25;luz.w=1;
        pared[27].construir(divisiones,10,altura,columna_entrada,luz,NULL);
        //columna de 30 - izq
        luz.y=50;luz.w=1;
        pared[28].construir(divisiones,30,altura,columna_entrada,luz,NULL);
        luz.y=25;luz.w=1;
        pared[29].construir(divisiones,10,altura,columna_entrada,luz,NULL);

    /*2º.-Paredes cocina:*/
    luz.x=0;luz.y=500;luz.z=0;luz.w=1;
    pared[8].construir(divisiones,altura,300,cocina_color,luz,NULL);//arriba
    pared[9].construir(divisiones,274,altura,cocina_color,luz,NULL);//izquierda

    pared[10].construir(divisiones,altura,130,cocina_color,luz,NULL);//abajo izq-puerta
    pared[11].construir(divisiones,altura,120,cocina_color,luz,NULL);//abajo der-puerta
    pared[12].construir(divisiones,20,50,cocina_color,luz,NULL);//abajo  arriba-puerta

    pared[13].construir(divisiones,154,altura,cocina_color,luz,NULL);//derecha-der(puerta)
    pared[14].construir(divisiones,70,altura,cocina_color,luz,NULL);//derecha-izq(puerta)
    pared[15].construir(divisiones,50,20,cocina_color,luz,NULL);//derecha puerta entrada
    //columnas cocina
        pared[34].construir(divisiones,altura,36,columna_cocina,luz,NULL);
        luz.y=25;luz.w=0.75;
        pared[35].construir(divisiones,altura,10,columna_cocina,luz,NULL);
        luz.y=500;luz.w=1;

    /*3º.-Paredes salon*/
    pared[16].construir(divisiones,altura,270,salon_color,luz,NULL);//abajo-izquierda
    pared[30].construir(divisiones,altura,170,salon_color,luz,NULL);//abajo-derecha
    pared[17].construir(divisiones,134,altura,salon_color,luz,NULL);//izquierda
    pared[18].construir(divisiones,134,altura,salon_color,luz,NULL);//derecha
    pared[19].construir(divisiones,altura,130,salon_color,luz,NULL);//arriba puerta-izquierda
    pared[20].construir(divisiones,altura,200,salon_color,luz,NULL);//arriba puerta-centro
    pared[21].construir(divisiones,altura,50,salon_color,luz,NULL);//arriba puerta-derecha
    pared[22].construir(divisiones,20,50,salon_color,luz,NULL);//arriba puerta sobrante derecho
    pared[23].construir(divisiones,20,50,salon_color,luz,NULL);//arriba puerta sobrante izquierdo
    //columnas
     /*1º.-izquierda*/
     pared[31].construir(divisiones,altura,36,columna_salon,luz,NULL);
     luz.y=25;luz.w=0.75;
     pared[32].construir(divisiones,altura,10,columna_salon,luz,NULL);
     luz.y=500;luz.w=1;
     /*2º.-derecha*/
      //usamos la de la izquierda
     /*3º.-abajo*/
     pared[33].construir(divisiones,altura,40,columna_salon,luz,NULL);//centro
     //para los laterales de la columna usamos la de la izquierda
}

void casa :: construirTecho(void){
    /*iluminacion y color*/
    _vertex4f luz, color;
    techo.resize(3);
    int divisiones=2;
    /* construccion*/
    /*1º.-Entrada:*/
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;    
    color.r=0.55;color.g=0.17;color.b=0.89;color.a=1;
    techo[0].construir(divisiones,320,180,color,luz,NULL);//entrada
    /*2º.-Salon:*/
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;
    color.r=0.549019607;color.g=0.274509803;color.b=0.078431372;color.a=0.15;
    techo[1].construir(divisiones,180,500,color,luz,NULL);//salon
    /*3º.-Cocina:*/
    luz.x=0;luz.y=50;luz.z=0;luz.w=1;
    color.r=0.423529411;color.g=0.556862745;color.b=0.35;color.a=1;//6B-8E-23
    techo[2].construir(divisiones,320,320,color,luz,NULL);//cocina

}

void casa :: construirJuntas(void){//de las puertas
    /*iluminacion y color*/
    _vertex4f luz, color;
    luz.x=0;luz.y=25;luz.z=0;luz.w=1;
    color.r=0.392156862;color.g=0.196078431;color.b=0;color.a=1;//color marron
    juntas.resize(2);
    int divisiones=2;
    /*construcción de las juntas de las puertas*/
    juntas[0].construir(divisiones,10,80,color,luz,NULL);//laterales puerta
    juntas[1].construir(divisiones,10,50,color,luz,NULL);//arriba      "
}

void casa :: drawPared(void){
    /*================     ENTRADA     =====================*/
    /*1º . arriba (130)*/
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(155,0,0);//situamos en su posicion
    glTranslatef(0,0,-245);
    glRotatef(90,1,0,0);//giramos pared
        pared[0].draw(1,3);
    glPopMatrix();
    /*2º . derecha (310)*/
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(0,0,-17);//situamos en su posicion
    glTranslatef(245,0,0);
    glRotatef(90,0,0,1);//giramos pared
        pared[1].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(0,0,-185);//situamos en su posicion
    glTranslatef(245,0,0);
    glRotatef(90,0,0,1);//giramos pared
        pared[24].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,90,0);//subimos
    glTranslatef(0,0,-125);//situamos en su posicion
    glTranslatef(245,0,0);
    glRotatef(90,0,0,1);//giramos pared
        pared[25].draw(1,3);
    glPopMatrix();

    /*3º . abajo (2x60)*/
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(215,0,0);//situamos en su posicion
    glTranslatef(0,0,65);//situamos en su posicion
    glRotatef(90,1,0,0);//giramos pared
        pared[2].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(110,0,0);//situamos en su posicion
    glTranslatef(0,0,65);//situamos en su posicion
    glRotatef(90,1,0,0);//giramos pared
        pared[3].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(160,0,0);//(puerta 50)
    glTranslatef(0,90,0);// 10(parte.abajo)+80(tam_puerta)
    glTranslatef(0,0,65);
    glRotatef(90,1,0,0);//giramos pared
        pared[4].draw(1,3);
    glPopMatrix();
    /*4º . izquierda (190 y 70)*/
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(0,0,-45);//situamos en su posicion
    glTranslatef(75,0,0);
    glRotatef(90,0,0,1);//giramos pared
        pared[5].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(0,0,-210);//situamos en su posicion
    glTranslatef(75,0,0);
    glRotatef(90,0,0,1);//giramos pared
        pared[6].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-150);//situamos en su posicion
    glTranslatef(0,90,0);// 10(parte.abajo)+80(tam_puerta)
    glTranslatef(75,0,0);
    glRotatef(90,0,0,1);//giramos pared
        pared[7].draw(1,3);
    glPopMatrix();
    //Columnas:
      /*1º.-izquierda*/
      glPushMatrix();
      glTranslatef(0,50,0);
      glTranslatef(0,0,-233);
      glTranslatef(235,0,0);
      glRotatef(90,0,0,1);
        pared[26].draw(1,3);
      glPopMatrix();
      glPushMatrix();
      glTranslatef(0,50,0);
      glTranslatef(0,0,-220);
      glTranslatef(240,0,0);
      glRotatef(90,0,1,0);
      glRotatef(90,0,0,1);
        pared[27].draw(1,3);
      glPopMatrix();
      /*1º.-izquierda*/
      glPushMatrix();
      glTranslatef(0,50,0);
      glTranslatef(0,0,50);
      glTranslatef(85,0,0);
      glRotatef(90,0,0,1);
        pared[28].draw(1,3);
      glPopMatrix();
      glPushMatrix();
      glTranslatef(0,50,0);
      glTranslatef(0,0,35);
      glTranslatef(80,0,0);
      glRotatef(90,0,1,0);
      glRotatef(90,0,0,1);
        pared[29].draw(1,3);
      glPopMatrix();



    /*================     COCINA     =====================*/
    /*1º . arriba (300)*/
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(-85,0,0);//situamos en su posicion
    glTranslatef(0,0,-245);
    glRotatef(90,1,0,0);//giramos pared
        pared[8].draw(1,3);
    glPopMatrix();
    /*2º . izquierda (274)*/
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(-245,0,0);//situamos en su posicion
    glTranslatef(0,0,-72);
    glRotatef(90,0,0,1);//giramos pared
        pared[9].draw(1,3);
    glPopMatrix();
     //columna -arriba-izq
     glPushMatrix();
     glTranslatef(0,50,0);//subimos
     glTranslatef(-235,0,0);
     glTranslatef(0,0,-227);
     glRotatef(90,0,1,0);
     glRotatef(90,1,0,0);
         pared[34].draw(1,3);//columna
     glPopMatrix();
     glPushMatrix();
     glTranslatef(0,50,0);//subimos
     glTranslatef(-240,0,0);
     glTranslatef(0,0,-209);
     glRotatef(90,1,0,0);
         pared[35].draw(1,3);//lateral
     glPopMatrix();
    /*3º . abajo (2x130)*/
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(-180,0,0);//situamos en su posicion
    glTranslatef(0,0,65);//situamos en su posicion
    glRotatef(90,1,0,0);//giramos pared
        pared[10].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(-5,0,0);
    glTranslatef(0,0,65);//situamos en su posicion
    glRotatef(90,1,0,0);//giramos pared
        pared[11].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-90,0,0);//(puerta 50)
    glTranslatef(0,90,0);// 10(parte.abajo)+80(tam_puerta)
    glTranslatef(0,0,65);
    glRotatef(90,1,0,0);//giramos pared
        pared[12].draw(1,3);
    glPopMatrix();
    /*4º . derecha (154 y 70)*/
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(0,0,-48);//situamos en su posicion
    glTranslatef(65,0,0);
    glRotatef(90,0,0,1);//giramos pared
        pared[13].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(0,0,-210);//situamos en su posicion
    glTranslatef(65,0,0);
    glRotatef(90,0,0,1);//giramos pared
        pared[14].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-150);//situamos en su posicion
    glTranslatef(0,90,0);// 10(parte.abajo)+80(tam_puerta)
    glTranslatef(65,0,0);
    glRotatef(90,0,0,1);//giramos pared
        pared[15].draw(1,3);
    glPopMatrix();
    //columna- abajo derecha
    glPushMatrix();
    glTranslatef(0,50,0);
    glTranslatef(55,0,0);
    glTranslatef(0,0,47);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
        pared[34].draw(1,3);//columna
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,50,0);
    glTranslatef(60,0,0);
    glTranslatef(0,0,29);
    glRotatef(90,1,0,0);
        pared[35].draw(1,3);//liston
    glPopMatrix();

    /*================     SALON     =====================*/
    /*1º . abajo (500)*/
    glPushMatrix();//Abajo-izquierda
    glTranslatef(0,50,0);//subimos
    glTranslatef(-100,0,0);
    glTranslatef(0,0,245);//situamos en su posicion
    glRotatef(90,1,0,0);//giramos pared
        pared[16].draw(1,3);
    glPopMatrix();
    glPushMatrix();//abajo-derecha
    glTranslatef(0,50,0);//subimos
    glTranslatef(160,0,0);
    glTranslatef(0,0,245);//situamos en su posicion
    glRotatef(90,1,0,0);//giramos pared
        pared[30].draw(1,3);
    glPopMatrix();
     //columnas de abajo
     glPushMatrix();
     glTranslatef(0,50,0);
     glTranslatef(0,0,235);
     glTranslatef(55,0,0);
     glRotatef(90,1,0,0);
        pared[33].draw(1,3);//central
     glPopMatrix();
     glPushMatrix();
     glTranslatef(0,50,0);
     glTranslatef(0,0,240);
     glTranslatef(35,0,0);
     glRotatef(90,0,1,0);
     glRotatef(90,1,0,0);
        pared[32].draw(1,3);//lateral-izq
     glPopMatrix();
     glPushMatrix();
     glTranslatef(0,50,0);
     glTranslatef(0,0,240);
     glTranslatef(75,0,0);
     glRotatef(90,0,1,0);
     glRotatef(90,1,0,0);
        pared[32].draw(1,3);//lateral-der
     glPopMatrix();
    /*2º . izquierda (170)*/
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(-245,0,0);//situamos en su posicion
    glTranslatef(0,0,142);
    glRotatef(90,0,0,1);//giramos pared
        pared[17].draw(1,3);
    glPopMatrix();
    //columna izquierda
     glPushMatrix();
     glTranslatef(0,50,0);
     glTranslatef(-235,0,0);
     glTranslatef(0,0,227);
     glRotatef(90,0,1,0);
     glRotatef(90,1,0,0);
        pared[31].draw(1,3);//centro
     glPopMatrix();
     glPushMatrix();
     glTranslatef(0,50,0);
     glTranslatef(-240,0,0);
     glTranslatef(0,0,209);
     glRotatef(90,1,0,0);
        pared[32].draw(1,3);//lateral
     glPopMatrix();
    /*3º . derecha (170)*/
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(245,0,0);//situamos en su posicion
    glTranslatef(0,0,178);
    glRotatef(90,0,0,1);//giramos pared
        pared[18].draw(1,3);
    glPopMatrix();
     //columna derecha
     glPushMatrix();
     glTranslatef(0,50,0);
     glTranslatef(235,0,0);
     glTranslatef(0,0,93);
     glRotatef(90,0,1,0);
     glRotatef(90,1,0,0);
        pared[31].draw(1,3);//centro
     glPopMatrix();
     glPushMatrix();
     glTranslatef(0,50,0);
     glTranslatef(240,0,0);
     glTranslatef(0,0,111);
     glRotatef(90,1,0,0);
        pared[32].draw(1,3);//lateral
     glPopMatrix();
    /*4º . arriba */
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(0,0,75);//situamos en su posicion
    glTranslatef(-180,0,0);
    glRotatef(90,1,0,0);//giramos pared
        pared[19].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(0,0,75);//situamos en su posicion
    glTranslatef(35,0,0);
    glRotatef(90,1,0,0);//giramos pared
        pared[20].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,50,0);//subimos
    glTranslatef(0,0,75);//situamos en su posicion
    glTranslatef(210,0,0);
    glRotatef(90,1,0,0);//giramos pared
        pared[21].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,75);//situamos en su posicion
    glTranslatef(0,90,0);
    glTranslatef(-90,0,0);
    glRotatef(90,1,0,0);//giramos pared
        pared[22].draw(1,3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,75);//situamos en su posicion
    glTranslatef(0,90,0);
    glTranslatef(160,0,0);
    glRotatef(90,1,0,0);//giramos pared
        pared[23].draw(1,3);
    glPopMatrix();
}

void casa :: drawTecho(void){
    //1º techo:
    glPushMatrix();
    glTranslatef(0,100,0);
    glTranslatef(0,0,-90);//atlura
    glTranslatef(160,0,0);//anchura (situamos)
        techo[0].draw(1,3);
    glPopMatrix();
    //2º techo;
    glPushMatrix();
    glTranslatef(0,100,0);
    glTranslatef(0,0,160);//anchura (situamos)
        techo[1].draw(1,3);
    glPopMatrix();
    //3º techo:
    glPushMatrix();
     glTranslatef(0,100,0);
    glTranslatef(0,0,-90);//altura (situamos)
    glTranslatef(-90,0,0);//anchura (situamos)
        techo[2].draw(1,3);
    glPopMatrix();
}


void casa :: drawSuelo(void){
    //1º suelo: entrada (180-ancho,320-alto)
    glPushMatrix();
    glTranslatef(0,0,-90);//atlura
    glTranslatef(160,0,0);//anchura (situamos)
        suelo[0].draw(1,4);
    glPopMatrix();
    //2º suelo: entrada (500-ancho,180-alto)
    glPushMatrix();
    glTranslatef(0,0,160);//anchura (situamos)
        suelo[1].draw(1,4);
    glPopMatrix();
    //3º suelo: entrada (320-ancho,320-alto)
    glPushMatrix();
    glTranslatef(0,0,-90);//altura (situamos)
    glTranslatef(-90,0,0);//anchura (situamos)
        suelo[2].draw(1,4);
    glPopMatrix();
}

void casa::drawJuntas(void){
 /*1º puerta : salón-cocina*/
    //liston de la izquierda
    glPushMatrix();
    glTranslatef(0,40,0);//subimos (mide el listo 80 - 80/2)
    glTranslatef(0,0,70);
    glTranslatef(-65,0,0);
    glRotatef(90,0,0,1);//anchura (situamos)
        juntas[0].draw(1,3);
    glPopMatrix();
    //liston de la derecha
    glPushMatrix();
    glTranslatef(0,40,0);//subimos (mide el listo 80 - 80/2)
    glTranslatef(0,0,70);
    glTranslatef(-115,0,0);
    glRotatef(90,0,0,1);//anchura (situamos)
        juntas[0].draw(1,3);
    glPopMatrix();
    //arriba
    glPushMatrix();
    glTranslatef(0,80,0);//altura puerta
    glTranslatef(0,0,70);//baja mov eje z
    glTranslatef(-90,0,0);//desplaza mov eje x
        juntas[1].draw(1,3);
    glPopMatrix();
 /*2º puerta : cocina-entrada*/
    //liston de la izquierda
    glPushMatrix();
    glTranslatef(0,40,0);//subimos (mide el listo 80 - 80/2)
    glTranslatef(0,0,-175);//mov eje z (arriba)
    glTranslatef(70,0,0);//mov eje x (izquierda)
    glRotatef(90,0,0,1);
    glRotatef(90,1,0,0);
        juntas[0].draw(1,3);
    glPopMatrix();
    //liston de la derecha
    glPushMatrix();
    glTranslatef(0,40,0);//subimos (mide el listo 80 - 80/2)
    glTranslatef(0,0,-125);//mov eje z (arriba)
    glTranslatef(70,0,0);//mov eje x (izquierda)
    glRotatef(90,0,0,1);
    glRotatef(90,1,0,0);
        juntas[0].draw(1,3);
    glPopMatrix();
    //arriba
    glPushMatrix();
    glTranslatef(0,80,0);//subimos (mide el listo 80 - 80/2)
    glTranslatef(0,0,-150);//mov eje z (arriba)
    glTranslatef(70,0,0);//mov eje x (izquierda)
    glRotatef(90,0,1,0);
        juntas[1].draw(1,3);
    glPopMatrix();
 /*3º puerta : entrada-salon*/
    //liston de la izquierda
    glPushMatrix();
    glTranslatef(0,40,0);//subimos (mide el listo 80 - 80/2)
    glTranslatef(0,0,70);
    glTranslatef(135,0,0);
    glRotatef(90,0,0,1);//anchura (situamos)
        juntas[0].draw(1,3);
    glPopMatrix();
    //liston de la derecha
    glPushMatrix();
    glTranslatef(0,40,0);//subimos (mide el listo 80 - 80/2)
    glTranslatef(0,0,70);
    glTranslatef(185,0,0);
    glRotatef(90,0,0,1);//anchura (situamos)
        juntas[0].draw(1,3);
    glPopMatrix();
    //arriba
    glPushMatrix();
    glTranslatef(0,80,0);//altura puerta
    glTranslatef(0,0,70);//baja mov eje z
    glTranslatef(160,0,0);//desplaza mov eje x
        juntas[1].draw(1,3);
    glPopMatrix();

}

void casa :: drawPuerta(){
    /*1º.-Puerta: salon-cocina*/
    glPushMatrix();
    glTranslatef(0,40,0);//subimos la puerta
    glTranslatef(0,0,90);//bajamos (mov z)
    glTranslatef(-130,0,0);//desplazamos (mov x)
    glRotatef(50,0,1,0);
    glRotatef(90,1,0,0);
        p.draw();
    glPopMatrix();
    /*2º.-Puerta: entrada-salon*/
    glPushMatrix();
    glTranslatef(0,40,0);//subimos la puerta
    glTranslatef(0,0,50);//bajamos (mov z)
    glTranslatef(200,0,0);//desplazamos (mov x)
    glRotatef(50,0,1,0);
    glRotatef(90,1,0,0);
        p.draw();
    glPopMatrix();
    /*3º.-Puerta: cocina-entrada*/
    glPushMatrix();
    glTranslatef(0,40,0);//subimos la puerta
    glTranslatef(0,0,-190);//bajamos (mov z)
    glTranslatef(50,0,0);//desplazamos (mov x)
    glRotatef(50,0,1,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
        p.draw();
    glPopMatrix();
    /*4º.- Puerta: calle*/
    glPushMatrix();
    glTranslatef(0,40,0);//subimos la puerta
    glTranslatef(0,0,-125);//bajamos (mov z)
    glTranslatef(247,0,0);//desplazamos (mov x)
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
        p.draw();
    glPopMatrix();
}

void casa::drawCocina(){
    // cocina
    glPushMatrix();
    glTranslatef(0,0,-207);
    glTranslatef(-146,0,0);
        c.draw();
        // cubo de basrua
        glPushMatrix();
        glTranslatef(-46,16,0);
        glTranslatef(0,0,255);
        glRotatef(90,-1,0,0);
        glScalef(0.6,0.5,0.6);
            cubo_basura.draw(1,3);
        glPopMatrix();
        // tetera
        glPushMatrix();
        glTranslatef(0,50,0);
        glTranslatef(0,0,15);
        glTranslatef(30,0,0);
        glRotatef(90,-1,0,0);
        glScalef(3.5,3.5,3.5);
            tetera.CambiaMaterial("plata");
            tetera.draw(1,3);
        glPopMatrix();
        // ketchup
        glPushMatrix();
        glTranslatef(180,53,180);
        glRotatef(90,0,-1,0);
        glScalef(3,3,3);
            ketchup.CambiaMaterial("gomaRoja");
            ketchup.draw(1,3);
        glPopMatrix();
        // silla
        glPushMatrix();
        glTranslatef(160,33,240);
        glRotatef(90,0,-1,0);
        glRotatef(90,-1,0,0);
        glScalef(1.6,1.6,1.7);
            silla.draw(1,3);
        glPopMatrix();
    glPopMatrix();
    // cuadro cocina (caxondeo)
    glPushMatrix();
    glTranslatef(-30,70,65);
    glRotatef(180,0,1,0);
    glRotatef(90,1,0,0);
        cuadro[5].draw();
    glPopMatrix();
    //lamparita_cocina
    glPushMatrix();
    glTranslatef(-90,118,-90);
    glScalef(0.5,0.5,0.5);
        lamparita.draw("esmeralda","plasticoVerde");// lampara + borde
    glPopMatrix();
    // botellas
    glPushMatrix();
    glTranslatef(-185,49,-50);
    glRotatef(40,0,-1,0);
    glRotatef(90,-1,0,0);
    glScalef(3,3,3);
        ketchup.CambiaMaterial("gomaAzul");
        ketchup.draw(1,3);
    glTranslatef(-2,-5,0);
        ketchup.CambiaMaterial("gomaAmarilla");
        ketchup.draw(1,3);
    glPopMatrix();
}

void casa :: drawEntrada(){
    // comoda + espejo + florero + maceta
    glPushMatrix();
    glTranslatef(0,0,-46);
    glTranslatef(96,0,0);
    glRotatef(90,0,1,0);
        e.draw();
        // maceta
        glPushMatrix();
        glTranslatef(0,0,135);
        glTranslatef(-70,0,0);
        glRotatef(180,0,1,0);
        glScalef(1.1,1.1,1.1);
            macetita.draw();
        glPopMatrix();
    glPopMatrix();
    // cuadro (el guernica)
    glPushMatrix();
    glTranslatef(155,60,-245);
    glRotatef(90,1,0,0);
        cuadro[3].draw();
    glPopMatrix();
    //lamparita_entrada
    glPushMatrix();
    glTranslatef(160,110,-95);
    glScalef(0.5,0.5,0.5);
        lamparita.draw("plata","cromo");// lampara + borde
    glPopMatrix();
}

void casa::drawSalon(){
    // salon
    s.draw();
    // sandalia izq-evitar paso
    glPushMatrix();
    glTranslatef(189,2,120);
    glRotatef(180,0,1,0);
    glRotatef(90,-1,0,0);
    glScalef(1.5,1.5,1.5);
        sandalia.draw(1,3);
    glPopMatrix();
    // sandalia arriba-evitar paso
    glPushMatrix();
    glTranslatef(174,2,198);
    glRotatef(90,0,-1,0);
    glRotatef(90,-1,0,0);
    glScalef(1.5,1.5,1.5);
        sandalia.draw(1,3);
    glPopMatrix();
    // sillas izqu-mesa(contra pared-puerta)
    glPushMatrix();
    glTranslatef(189,33,120);
    glRotatef(90,-1,0,0);
    glScalef(1.6,1.6,1.7);
        silla.draw(1,3);
    glPopMatrix();
    // sillas arriba (junto sandalia)
    glPushMatrix();
    glTranslatef(199,33,198);
    glRotatef(180,0,-1,0);
    glRotatef(90,-1,0,0);
    glScalef(1.6,1.6,1.7);
        silla.draw(1,3);
    glPopMatrix();
    // sillas arriba (junto columna)
    glPushMatrix();
    glTranslatef(70,33,198);
    glRotatef(180,0,-1,0);
    glRotatef(90,-1,0,0);
    glScalef(1.6,1.6,1.7);
        silla.draw(1,3);
    glPopMatrix();
    // muelle arriba (junto columna)
    glPushMatrix();
    glTranslatef(72,3,196);
    glRotatef(90,-1,0,0);
    glScalef(0.08,0.14,0.08);
        muelle.draw(1,3);
    glPopMatrix();
    // maceta
    glPushMatrix();
    glTranslatef(-165,0,110);
    glRotatef(90,0,1,0);
    glScalef(1.1,1.1,1.1);
        macetita.draw();
    glPopMatrix();
    // tetera - mesa de tv
    glPushMatrix();
    glTranslatef(-120,15,170);
    glRotatef(80,0,1,0);
    glRotatef(90,-1,0,0);
    glScalef(3.5,3.5,3.5);
        tetera.CambiaMaterial("oro_2");
        tetera.draw(1,3);
    glPopMatrix();
    // cuadro flores (entrada salon)
    glPushMatrix();
    glTranslatef(154,65,245);
    glRotatef(180,0,1,0);
    glRotatef(90,1,0,0);
        cuadro[0].draw();
    glPopMatrix();
    // cuadro abstracto (cocina salon)
    glPushMatrix();
    glTranslatef(-245,65,152);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
        cuadro[1].draw();
    glPopMatrix();
    // cuadro (habitacion)
    glPushMatrix();
    glTranslatef(-145,70,245);
    glRotatef(180,0,1,0);
    glRotatef(90,1,0,0);
        cuadro[2].draw();
    glPopMatrix();
    // cuadro (girasoles)
    glPushMatrix();
    glTranslatef(-98,57,245);
    glRotatef(180,0,1,0);
    glRotatef(90,1,0,0);
        cuadro[4].draw();
    glPopMatrix();
    // zapatillas (evitar paso hacia asientos salon-maceta)
    glPushMatrix();
    glTranslatef(-136,3,120);
    glRotatef(90,0,1,0);
    glScalef(1.3,1.3,1.3);
        zapatilla.draw(1,3);
    glTranslatef(-15,-1,0);
    glRotatef(204,0,0,1);
        zapatilla.draw(1,3);
    glPopMatrix();
    //lamparita_salon (cobre->lamp, oro->borde)
    glPushMatrix();
    glTranslatef(-50,131,160);
    glScalef(0.5,0.5,0.5);
        lamparita.draw("cobre_1","oro_2");// lampara + borde
    glTranslatef(270,0,0);
        lamparita.draw("cobre_1","oro_2");
    glPopMatrix();
    //pelota (evitar paso mesa izq)
    glPushMatrix();
    glTranslatef(187,17,150);
        pelota.draw(1,3);
    glPopMatrix();
    // ESTANTERIA
    //coche cutre (primero que realicé con las primitivas)
    glPushMatrix();
    glTranslatef(-10,49.8,212);
    glRotatef(165,0,1,0);
        coche_cutre.draw(1,0);
    glPopMatrix();
    //tijeras
    glPushMatrix();
    glTranslatef(-5,46,210);
    glRotatef(70,0,1,0);
    glScalef(1.5,1.5,1.5);
        tijeras.draw(1,3);
    glPopMatrix();
    //guitarra (apoyada en el lateral izq)
    glPushMatrix();
    glTranslatef(38.5,16.3,215);
    glRotatef(8,0,0,1);
    glRotatef(90,0,1,0);
    glRotatef(90,0,0,1);
    glScalef(0.1,0.1,0.1);
        guitarra.draw(1,3);
    glPopMatrix();
}

void casa::drawEnchufe(int estado1,int estado2, int estado3){
    // entrada
    glPushMatrix();
    glTranslatef(0,3,0);//subimos el enchufe
    glTranslatef(244,10,-90);
    glRotatef(90,0,-1,0);
    glRotatef(90,1,0,0);
        enchufe.draw(estado1);
    glPopMatrix();
    // salon
    glPushMatrix();
    glTranslatef(0,3,0);//subimos
    glTranslatef(0,10,76);
    glRotatef(90,1,0,0);
        enchufe.draw(estado2);
    glPopMatrix();
    // cocina
    glPushMatrix();
    glTranslatef(0,3,0);
    glTranslatef(0,0,-140);
    glTranslatef(64,10,62);
    glRotatef(90,0,-1,0);
    glRotatef(90,1,0,0);
        enchufe.draw(estado3);
    glPopMatrix();
}

void casa::draw(int estado1,int estado2, int estado3){
    // salon
    drawSalon();
    // +coche_cutre (encima de la estantería)
    // cocina
    drawCocina();
    // entrada
    drawEntrada();
    // suelo
    drawSuelo();
    // paredes
    drawPared();
    // techo
    drawTecho();
    // juntas
    drawJuntas();
    // puerta
    drawPuerta();
    // enchufe
    drawEnchufe(estado1,estado2,estado3);
}

_vertex3f casa::recta(_vertex3f puntoA, _vertex3f puntoB){
    _vertex3f sol;
    sol._0=puntoB.z-puntoA.z;
    sol._1=-(puntoB.x-puntoA.x);
    sol._2=(puntoA.z*(puntoB.x-puntoA.x))+(-puntoA.x*(puntoB.z-puntoA.z));
    return sol;//_0-->X: _1-->Y: _2-->C
}

double casa::distancia(_vertex3f r, _vertex3f punto){
    double dist=((r._0*punto.x)+(r._1*punto.z)+r._2)/sqrt((r._0*r._0)+(r._1*r._1));
    return dist;
}


/* Comprobación de coordenadas */
/*      COLISIONES   CASA      */
bool casa::CompruebaColision(_vertex3f punto, double caja){
    _vertex3f r;
    _vertex3f p1,p2;
    /*
     */
    /* 1º.-Entrada */
    if((punto.x+caja>=70&&punto.x-caja<=245) && (punto.z+caja>=-245&&punto.z-caja<=65)){
        _vertex3f r_mueble_frente, r_mueble_abajo, r_mueble_arriba;
        _vertex3f r_columna_abajo_lateral, r_columna_abajo_superior;
        _vertex3f r_puerta, r_maceta;
        _vertex3f r_columna_arriba_base, r_columna_arriba_lateral;

        /*Paredes de la sala*/
        //recta der
        p1.x=245;p1.z=65;
        p2.x=245;p2.z=-245;
        r=recta(p1,p2);
        if(distancia(r,punto)<caja) return true;
        //recta arriba
        p1.x=245;p1.z=-245;
        p2.x=75;p2.z=-245;
        r=recta(p1,p2);
        if(distancia(r,punto)<caja) return true;
        //recta-izq
        if(punto.z-caja<=-175||(punto.z+caja>=-125&&punto.z-caja<=65)){
            p1.x=75;p1.z=-245;
            p2.x=75;p2.z=65;
            r=recta(p1,p2);
            if(distancia(r,punto)<caja) return true;
        }
        //recta-abajo
        if((punto.x+caja>=75&&punto.x-caja<=135)||(punto.x+caja>=185&&punto.x-caja<=245)){
            p1.x=75;p1.z=65;
            p2.x=245;p2.z=65;
            r=recta(p1,p2);
            if(distancia(r,punto)<caja)return true;
        }

        /*Objetos de la sala*/
        //MUEBLE
         if(punto.x>=115 && (punto.z>=-78&&punto.z<=-14)){//delante
             p1.x=115;p1.z=-78;
             p2.x=115;p2.z=-14;
             r_mueble_frente=recta(p1,p2);
             if(distancia(r_mueble_frente,punto)<caja)return true;
         }
         if(punto.z-caja<=-78 && (punto.x+caja>=75 && punto.x-caja<=115)){//arriba
             p1.x=75;p1.z=-78;
             p2.x=115;p2.z=-78;
             r_mueble_arriba=recta(p1,p2);
             if(distancia(r_mueble_arriba,punto)<caja)return true;
         }
         if(punto.z+caja>=-14 && (punto.x+caja>=75 && punto.x-caja<=115)){//abajo
             p1.x=115;p1.z=-14;
             p2.x=75;p2.z=-14;
             r_mueble_abajo=recta(p1,p2);
             if(distancia(r_mueble_abajo,punto)<caja)return true;
         }
         //COLUMNAS
         if(punto.x>=85 && (punto.z>=35&&punto.z<=65)){//abajo
             p1.x=85;p1.z=35;
             p2.x=85;p2.z=65;
             r_columna_abajo_lateral=recta(p1,p2);
             if(distancia(r_columna_abajo_lateral,punto)<caja)return true;
         }
         if(punto.z-caja<=35 && (punto.x+caja>=75&&punto.x-caja<=85)){
             p1.x=75;p1.z=35;
             p2.x=85;p2.z=35;
             r_columna_abajo_superior=recta(p1,p2);
             if(distancia(r_columna_abajo_superior,punto)<caja)return true;
         }
         if(punto.x<=235 && (punto.z>=-245&&punto.z<=-220)){//arriba
             p1.x=235;p1.z=-225;
             p2.x=235;p2.z=-240;
             r_columna_arriba_lateral=recta(p1,p2);
             if(distancia(r_columna_arriba_lateral,punto)<caja)return true;
         }
         if(punto.z+caja>=-220 && (punto.x+caja>=235&&punto.x-caja<=245)){
             p1.x=245;p1.z=-220;
             p2.x=235;p2.z=-220;
             r_columna_arriba_base=recta(p1,p2);
             if(distancia(r_columna_arriba_base,punto)<caja)return true;
         }
         //MACETA
         if(punto.z<=15 && (punto.x>=220&&punto.x<=245)){
             p1.x=220;p1.z=15;
             p2.x=245;p2.z=15;
             r_maceta=recta(p1,p2);
             if(distancia(r_maceta,punto)<caja)return true;
         }
         //PUERTA
         if((punto.x>=175&&punto.x<=220) && (punto.z>=20&&punto.z<=75)){//arriba
             p1.x=175;p1.z=75;
             p2.x=220;p2.z=20;
             r_puerta=recta(p1,p2);
             if(distancia(r_puerta,punto)<caja)return true;
         }
     }
    /*
     */
    /* 2º.-Salon */
    else if((punto.x+caja>=-245&&punto.x-caja<=245) && (punto.z+caja>=75&&punto.z-caja<=245)){
        _vertex3f r_mesa_izq, r_mesa_pata_1,r_mesa_pata_3,r_mesa_silla_lateral_1,r_mesa_silla_lateral_2,r_mesa_silla_frontal;
        _vertex3f r_estanteria_lateral;
        _vertex3f r_mesa_baja_lateral, r_mesa_baja_frontal;
        _vertex3f r_puerta;
        _vertex3f r_mesa_pata_4_abajo,r_mesa_pata_4_arriba;
        /*Paredes de la sala*/
        //recta arriba
        p1.x=-245;p1.z=245;
        p2.x=245;p2.z=245;
        r=recta(p1,p2);
        if(distancia(r,punto)<caja) return true;
        //recta abajo
        if(punto.z+caja>=75 && ((punto.x+caja>=-65&&punto.x-caja<=135)||punto.x<=-115)){
            p1.x=135;p1.z=75;
            p2.x=-65;p2.z=75;
            r=recta(p1,p2);
            if(distancia(r,punto)<caja) return true;
        }
        //recta izquierda
        p1.x=183;p1.z=245;
        p2.x=183;p2.z=75;
        r=recta(p1,p2);
        if(distancia(r,punto)<caja) return true;
        //recta derecha
        p1.x=-132;p1.z=75;
        p2.x=-132;p2.z=245;
        r=recta(p1,p2);
        if(distancia(r,punto)<caja) return true;


        /*Objetos de la sala*/
        //MESA PRINCIPAL (alta de la entrada)
        //mesa izquierda
        if(punto.z>=117 && punto.x-caja<=170){
            p1.x=170;p1.z=245;
            p2.x=170;p2.z=117;
            r_mesa_izq=recta(p1,p2);
            if(distancia(r_mesa_izq,punto)<caja) return true;
        }
        //silla enfrente mesa
        if(punto.z>=172 && punto.x>=76){//lateral del hueco entre las sillas
            p1.x=76;p1.z=172;
            p2.x=76;p2.z=245;
            r_mesa_silla_lateral_1=recta(p1,p2);
            if(distancia(r_mesa_silla_lateral_1,punto)<caja) return true;
        }
        //silla enfrente mesa
        if(punto.z>=172 && punto.x<=66){//lateral del hueco entre la mesa y la estanteria
            p1.x=66;p1.z=245;
            p2.x=66;p2.z=172;
            r_mesa_silla_lateral_2=recta(p1,p2);
            if(distancia(r_mesa_silla_lateral_2,punto)<caja) return true;
        }
        //PATAS
        //mesa_izqu pata abajo (mas a la izqu-entrando por puerta)
        if(punto.z<=117 && punto.x>=170){
            p1.x=170;p1.z=117;
            p2.x=245;p2.z=117;
            r_mesa_pata_1=recta(p1,p2);
            if(distancia(r_mesa_pata_1,punto)<caja) return true;
        }
        //pata_3 (pegando a las dos sillas
        if(punto.z<=177 && (punto.x>=65&punto.x<=76)){
            p1.x=65;p1.z=177;
            p2.x=76;p2.z=177;
            r_mesa_pata_3=recta(p1,p2);
            if(distancia(r_mesa_pata_3,punto)<caja) return true;
        }
        //pata4
        if(punto.z-caja<=122 && (punto.x+caja>=66&punto.x-caja<=73)){
            p1.x=66;p1.z=122;
            p2.x=73;p2.z=122;
            r_mesa_pata_4_abajo=recta(p1,p2);
            if(distancia(r_mesa_pata_4_abajo,punto)<caja) return true;
        }
        if(punto.z+caja>=130 && (punto.x+caja>=66&punto.x-caja<=73)){
            p1.x=73;p1.z=130;
            p2.x=66;p2.z=130;
            r_mesa_pata_4_arriba=recta(p1,p2);
            if(distancia(r_mesa_pata_4_arriba,punto)<caja) return true;
        }
        //ESTANTERIA
        //silla enfrente mesa + estanteria
        if(punto.z>=195 && (punto.x>=-26&&punto.x<=68)){//frontal
            p1.x=68;p1.z=195;
            p2.x=-26;p2.z=195;
            r_mesa_silla_frontal=recta(p1,p2);
            if(distancia(r_mesa_silla_frontal,punto)<caja) return true;
        }
        if(punto.z>=200 && punto.x<=-25){//lateral
            p1.x=-25;p1.z=245;
            p2.x=-25;p2.z=200;
            r_estanteria_lateral=recta(p1,p2);
            if(distancia(r_estanteria_lateral,punto)<caja) return true;
        }
        //MESA BAJA (televisor)
        if(punto.z>=152 && punto.x<=-70){
            p1.x=-70;p1.z=152;
            p2.x=-70;p2.z=245;
            r_mesa_baja_lateral=recta(p1,p2);
            if(distancia(r_mesa_baja_lateral,punto)<caja) return true;
        }
        if(punto.z<=152 && (punto.x>=-132&&punto.x<=-68)){
            p1.x=-132;p1.z=152;
            p2.x=-68;p2.z=152;
            r_mesa_baja_frontal=recta(p1,p2);
            if(distancia(r_mesa_baja_frontal,punto)<caja) return true;
        }
        //PUERTA
        if((punto.x<=-102&&punto.x>=-165) && (punto.z>=70&&punto.z<=120)){//arriba
            p1.x=-102;p1.z=70;
            p2.x=-165;p2.z=120;
            r_puerta=recta(p1,p2);
            if(distancia(r_puerta,punto)<caja)return true;
        }

    }
    /*
     */
    /* 3º.-Cocina */
    else if((punto.x+caja>=-245&&punto.x-caja<=65) && (punto.z+caja>=-245&&punto.z-caja<=65)){
        _vertex3f r_puerta,r_frigro, r_frigo_lateral;
        _vertex3f r_silla_frontal, r_silla_lateral;

        /*Paredes de la sala*/
        //recta der
        if(punto.z-caja<=-175||(punto.z+caja>=-125&&punto.z-caja<=65)){
            p1.x=65;p1.z=65;
            p2.x=65;p2.z=-245;
            r=recta(p1,p2);
            if(distancia(r,punto)<caja) return true;
        }
        //recta-abajo
        if((punto.x+caja>=-245&&punto.x-caja<=-115)||(punto.x+caja>=-65&&punto.x-caja<=65)){
            p1.x=-245;p1.z=65;
            p2.x=65;p2.z=65;
            r=recta(p1,p2);
            if(distancia(r,punto)<caja)return true;
        }
        //recta arriba
        if(punto.x-caja<=-47){
            p1.x=65;p1.z=-174;
            p2.x=-245;p2.z=-174;
            r=recta(p1,p2);
            if(distancia(r,punto)<caja) return true;
        }
        //recta-izq
        p1.x=-174;p1.z=-169;
        p2.x=-174;p2.z=65;
        r=recta(p1,p2);
        if(distancia(r,punto)<caja) return true;

        /*Objetos de la sala*/
        //SILLA
        if(punto.x<=14 && (punto.z>=28&&punto.z<=65)){//frontal
            p1.x=14;p1.z=65;
            p2.x=14;p2.z=25;
            r_silla_frontal=recta(p1,p2);
            if(distancia(r_silla_frontal,punto)<caja)return true;
        }
        if(punto.z<=25 && (punto.x>=14&&punto.x<=65)){//superior
            p1.x=12;p1.z=25;
            p2.x=65;p2.z=25;
            r_silla_lateral=recta(p1,p2);
            if(distancia(r_silla_lateral,punto)<caja)return true;
        }
        //FRIGO
        if(punto.z<=-175 && (punto.x>=-44&&punto.x<=10)){//frontal
            p1.x=10;p1.z=-175;
            p2.x=-44;p2.z=-175;
            r_frigro=recta(p1,p2);
            if(distancia(r_frigro,punto)<caja)return true;
        }
        if(punto.x>=8 && (punto.z>=-245&&punto.z<=-175)){//superior
            p1.x=8;p1.z=-245;
            p2.x=8;p2.z=-175;
            r_frigo_lateral=recta(p1,p2);
            if(distancia(r_frigo_lateral,punto)<caja)return true;
        }
        //PUERTA
        if((punto.x>=8&&punto.x<=70) && (punto.z>=-210&&punto.z<=-170)){//superior
            p1.x=70;p1.z=-170;
            p2.x=8;p2.z=-210;
            r_puerta=recta(p1,p2);
            if(distancia(r_puerta,punto)<caja)return true;
        }
    }
    /*
     */
    return false;//todo terminó sin ninguna colisión
}










