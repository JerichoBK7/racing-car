#include "entidad_game.h"

entidad_game::entidad_game(){}

void entidad_game::InicializaParticulas(void)
{
    //VUELTAS
    //
    //
    meta=-75;
    /*Vueltas particulas*/
    int vueltas=7;
    for(int i=0;i<particulas.size();i++){
        particulas[i].num_vueltas=vueltas;
        particulas[i].bandera[0]=true;
        particulas[i].bandera[1]=particulas[i].bandera[2]=false;
        particulas[i].posicion=-1;
        particulas[i].gasolina_ant=particulas[i].gasolina;
    }
    /*GASOLINERAS*/
    //
    //libres
    gasolinera[0]=gasolinera[1]=gasolinera[2]=0;
    time_0[0]=time_0[1]=time_0[2]=false;
    umbral=45;
    //electricidad
    nivel_electricidad=200;
    electricidad[0]=electricidad[2]=electricidad[1]=nivel_electricidad;
    //entrada
    pos_gasolinera[0].x=235;
    pos_gasolinera[0].z=-90;
    //salon
    pos_gasolinera[1].x=7;
    pos_gasolinera[1].z=95;
    //cocina
    pos_gasolinera[2].x=46;
    pos_gasolinera[2].z=-78;
    //
    //
    //
    /*COCHES RECORRIDOS*/
    //
    num_zonas=(4*16)+3; //5-Zonas por habitacion (18): [0-4]:Entrada; [5-9]:Salon; [10,14]:Cocina -- 15:EnchufeEntrada, 16:EnchufeSalon, 17:EnchufeCocina
    mover.resize(num_zonas);
    int POS;
    /*Gasolineras*/
    mover[4*16].x=222;mover[4*16].z=-95;//entrada
    mover[(4*16)+1].x=4;mover[(4*16)+1].z=95;//salon
    mover[(4*16)+2].x=44;mover[(4*16)+2].z=-68;//cocina
    /*1º.-CAMIONETA*/
    POS=0;
    /*
    1.-Entrada
    */
    mover[POS+0].x=91;mover[POS+0].z=-146;
    mover[POS+1].x=145;mover[POS+1].z=-100;
    mover[POS+2].x=151;mover[POS+2].z=-93;
    mover[POS+3].x=152;mover[POS+3].z=-16;
    mover[POS+4].x=160;mover[POS+4].z=80;//puerta
    /*
    2.-Salon
    */
    mover[POS+5].x=150;mover[POS+5].z=90;
    mover[POS+6].x=120;mover[POS+6].z=110;
    //pata arriba
    mover[POS+7].x=75;mover[POS+7].z=158;
    //pata abajo
    mover[POS+8].x=79;mover[POS+8].z=90;

    mover[POS+9].x=28;mover[POS+9].z=99;
    mover[POS+10].x=-82;mover[POS+10].z=115;
    mover[POS+11].x=-95;mover[POS+11].z=75;//puerta
    /*
    3.-Cocina
    */
    mover[POS+12].x=-80;mover[POS+12].z=10;
    mover[POS+13].x=20;mover[POS+13].z=-20;
    mover[POS+14].x=40;mover[POS+14].z=-145;
    mover[POS+15].x=63;mover[POS+15].z=-150;//puerta


    /*2º.-COCHE ANTIGUO*/
    POS+=16;
    /*
    1.-Entrada
    */
    mover[POS+0].x=154;mover[POS+0].z=-160;
    mover[POS+1].x=162;mover[POS+1].z=-120;
    mover[POS+2].x=168;mover[POS+2].z=-72;
    mover[POS+3].x=165;mover[POS+3].z=15;
    mover[POS+4].x=170;mover[POS+4].z=67;//puerta
    /*
    2.-Salon
    */
    mover[POS+5].x=157;mover[POS+5].z=85;
    mover[POS+6].x=150;mover[POS+6].z=100;
    //pata arriba
    mover[POS+7].x=82;mover[POS+7].z=156;
    //pata abajo
    mover[POS+8].x=73;mover[POS+8].z=98;
    mover[POS+9].x=11;mover[POS+9].z=102;
    mover[POS+10].x=-57;mover[POS+10].z=130;
    mover[POS+11].x=-94;mover[POS+11].z=86;//puerta
    /*
    3.-Cocina
    */
    mover[POS+12].x=-102;mover[POS+12].z=42;
    mover[POS+13].x=-62;mover[POS+13].z=-25;
    mover[POS+14].x=-17;mover[POS+14].z=-151;
    mover[POS+15].x=45;mover[POS+15].z=-155;//puerta


    /*3º.-ESCARABAJO*/
    POS+=16;
    /*
    1.-Entrada
    */
    mover[POS+0].x=92;mover[POS+0].z=-154;
    mover[POS+1].x=158;mover[POS+1].z=-157;
    mover[POS+2].x=201;mover[POS+2].z=-102;
    mover[POS+3].x=187;mover[POS+3].z=-24;
    mover[POS+4].x=174;mover[POS+4].z=49;//puerta
    /*
    2.-Salon
    */
    mover[POS+5].x=167;mover[POS+5].z=88;
    mover[POS+6].x=157;mover[POS+6].z=113;
    //pata arriba
    mover[POS+7].x=78;mover[POS+7].z=149;
    //pata abajo
    mover[POS+8].x=73;mover[POS+8].z=98;
    mover[POS+9].x=11;mover[POS+9].z=120;
    mover[POS+10].x=-43;mover[POS+10].z=135;
    mover[POS+11].x=-85;mover[POS+11].z=88;//puerta
    /*
    3.-Cocina
    */
    mover[POS+12].x=-78;mover[POS+12].z=60;
    mover[POS+13].x=-76;mover[POS+13].z=44;
    mover[POS+14].x=31;mover[POS+14].z=-84;
    mover[POS+15].x=45;mover[POS+15].z=-140;//puerta


    /*4º.-FORMULA1*/
    POS+=16;
    /*
    1.-Entrada
    */
    mover[POS+0].x=135;mover[POS+0].z=-158;
    mover[POS+1].x=139;mover[POS+1].z=-130;
    mover[POS+2].x=143;mover[POS+2].z=-70;
    mover[POS+3].x=147;mover[POS+3].z=-10;
    mover[POS+4].x=155;mover[POS+4].z=70;//puerta
    /*
    2.-Salon
    */
    mover[POS+5].x=156;mover[POS+5].z=93;
    mover[POS+6].x=135;mover[POS+6].z=116;
    //pata arriba
    mover[POS+7].x=53;mover[POS+7].z=167;
    //pata abajo
    mover[POS+8].x=73;mover[POS+8].z=90;
    mover[POS+9].x=11;mover[POS+9].z=102;
    mover[POS+10].x=-95;mover[POS+10].z=103;
    mover[POS+11].x=-90;mover[POS+11].z=70;//puerta
    /*
    3.-Cocina
    */
    mover[POS+12].x=-90;mover[POS+12].z=23;
    mover[POS+13].x=-48;mover[POS+13].z=-23;
    mover[POS+14].x=18;mover[POS+14].z=-128;
    mover[POS+15].x=70;mover[POS+15].z=-161;//puerta
}


void entidad_game::colision(int i){
    bool colision;
    // A.-COLISIONES ENTRE PARTICULAS
    colision=ColisionParticula(i);
    // B.-COLISIONES CON EL ESCENARIO
    if(!colision)
        colision=hogar->CompruebaColision(particulas[i].pos_act,particulas[i].obj->caja());
    //Actualizamos el estado de colision:
    if(!colision)
        for(int t=0;t<particulas.size();t++)particulas[i].colisiones[t]=false;
    else
        particulas[i].colisiones[i]=true;
}

void entidad_game::descolision(int numparticulas){
    if(particulas[numparticulas].colisiones[numparticulas]){//caso de particula colisionada
       particulas[numparticulas].pos_act=particulas[numparticulas].pos_ant; // posicion anterior
       if(particulas[numparticulas].humano){
           particulas[numparticulas].tecla="VACIO";
           particulas[numparticulas].Estado="PARADO";
           particulas[numparticulas].colisiones[numparticulas]=true;
       }
       else{
           particulas[numparticulas].gasolina=particulas[numparticulas].gasolina_ant;
           particulas[numparticulas].zona_mov=particulas[numparticulas].zona_mov_ant;
           particulas[numparticulas].Estado="EVITAR_COLISION";
       }
    }
}

bool entidad_game::ColisionParticula(int i){
    double R=particulas[i].obj->caja();
    bool salida=false;
    for(int j=0;j<particulas.size();j++){
        if(j!=i){// no es la misma particula
          double R_=particulas[j].obj->caja();
          double d=sqrt(pow(particulas[i].pos_act.x-particulas[j].pos_act.x,2)+pow(particulas[i].pos_act.z-particulas[j].pos_act.z,2));
          if(d<(R+R_)){
             particulas[i].colisiones[j]=true;
             salida=true;
          }
        }
    }
    if(salida)particulas[i].colisiones[i]=true;
    return salida;
}

/*
  Condicion: Estado - AVANZAR
             pos_f != pos_i (caso ordenador)
             ori_nueva (caso humano)
*/
bool entidad_game::ColisionTrayecto(int i,int cont){
    bool salir=false,colisiones;
    _vertex3f aux_i,aux;
    double inc=0;
    _vertex3f orientacion;
    //caso inicial)
    if(particulas[i].Estado=="AVANZAR"){
        if(particulas[i].humano){
            if(particulas[i].ori_nueva.x!=0||particulas[i].ori_nueva.z!=0)
                orientacion=particulas[i].ori_nueva;
        }
        else if(particulas[i].pos_f.x!=particulas[i].pos_i.x||particulas[i].pos_f.z!=particulas[i].pos_i.z){
            orientacion.x=particulas[i].pos_f.x-particulas[i].pos_i.x;
            orientacion.z=particulas[i].pos_f.z-particulas[i].pos_i.z;
            orientacion.normalize();
        }
    }
    else
        return errno;//error!

    //comprobamos el trayecto de colisiones)
    do{
        cont--;
        if(cont<=0)salir=true;
        aux_i.x=particulas[i].pos_i.x+(orientacion.x*inc);
        aux_i.z=particulas[i].pos_i.z+(orientacion.z*inc);
        inc+=0.25;
        if(particulas[i].pos_f.x<particulas[i].pos_i.x){
            if(particulas[i].pos_f.z<particulas[i].pos_i.z)
                {if(aux_i.x<=particulas[i].pos_f.x && aux_i.z<=particulas[i].pos_f.z)salir=true;}
            else
                {if(aux_i.x<=particulas[i].pos_f.x && aux_i.z>=particulas[i].pos_f.z)salir=true;}
        }
        else{
            if(particulas[i].pos_f.z<particulas[i].pos_i.z)
                {if(aux_i.x>=particulas[i].pos_f.x && aux_i.z<=particulas[i].pos_f.z)salir=true;}
            else
                {if(aux_i.x>=particulas[i].pos_f.x && aux_i.z>=particulas[i].pos_f.z)salir=true;}
        }
        if(!salir){
            aux=particulas[i].pos_act;
            particulas[i].pos_act.x=aux_i.x;
            particulas[i].pos_act.z=aux_i.z;
            colisiones=ColisionParticula(i);
            particulas[i].pos_act=aux;
            if(!colisiones)colisiones=hogar->CompruebaColision(aux_i,particulas[i].obj->caja());
            if(colisiones)salir=true;
        }
    }while(!salir);
    return colisiones;
}

int entidad_game::siguienteZona(int i){
   int zona=particulas[i].zona_mov;
   if(zona==((16*(i-1))+6)){
       if(particulas[i].gasolina<umbral && gasolinera[1]!=1){zona+=2;}//abajo
       else{
           if(gasolinera[1]==1){zona++;}//arriba
           else{_random sig(0,6);(sig.value()<3)?zona++:zona+=2;}
       }
   }
   else if(zona==((16*(i-1))+7)){zona+=3;}
   else {zona++;}

   if(zona>((16*i)-1))zona=16*(i-1);
   return zona;
}

bool entidad_game::MasAdelantada(int A, int B){
    string pos_casa_A=DeterminarSuperficie(A),pos_casa_B=DeterminarSuperficie(B);
    if(pos_casa_A==pos_casa_B){
        int cajaA=particulas[A].obj->caja();
        int cajaB=particulas[B].obj->caja();
        double dist_A;
        double dist_B;
        if(pos_casa_A=="entrada")
        {
            dist_A=sqrt(pow(particulas[A].pos_act.x+(particulas[A].ori_nueva.x*(cajaA))-145,2)+pow(particulas[A].pos_act.z+(particulas[A].ori_nueva.z*(cajaA))-70,2));
            dist_B=sqrt(pow(particulas[B].pos_act.x+(particulas[B].ori_nueva.x*(cajaB))-145,2)+pow(particulas[B].pos_act.z+(particulas[B].ori_nueva.z*(cajaB))-70,2));
            if(dist_A<dist_B)return true;
            else return false;
        }
        if(pos_casa_A=="cocina")
        {
            dist_A=sqrt(pow(particulas[A].pos_act.x+(particulas[A].ori_nueva.x*(cajaA))-70,2)+pow(particulas[A].pos_act.z+(particulas[A].ori_nueva.z*(cajaA))+160,2));
            dist_B=sqrt(pow(particulas[B].pos_act.x+(particulas[B].ori_nueva.x*(cajaB))-70,2)+pow(particulas[B].pos_act.z+(particulas[B].ori_nueva.z*(cajaB))+160,2));
            if(dist_A<dist_B)return true;
            else return false;
        }
        if(pos_casa_A=="salon")
        {
            dist_A=sqrt(pow(particulas[A].pos_act.x+(particulas[A].ori_nueva.x*(cajaA))+80,2)+pow(particulas[A].pos_act.z+(particulas[A].ori_nueva.z*(cajaA))-70,2));
            dist_B=sqrt(pow(particulas[B].pos_act.x+(particulas[B].ori_nueva.x*(cajaB))+80,2)+pow(particulas[B].pos_act.z+(particulas[B].ori_nueva.z*(cajaB))-70,2));
            if(dist_A<dist_B)return true;
            else return false;
        }
    }
    else{
        if(pos_casa_A=="entrada"){
            if(pos_casa_B=="salon")return false;
            else return true; }
        if(pos_casa_A=="salon"){
            if(pos_casa_B=="cocina")return false;
            else return true; }
        if(pos_casa_A=="cocina"){
            if(pos_casa_B=="entrada")return false;
            else return true; }
    }
}

string entidad_game::DeterminarSuperficie(int i){
    if(particulas[i].pos_act.x>=70){
        if(particulas[i].pos_act.z<=70) return "entrada";
        return "salon";
    }
    if(particulas[i].pos_act.z<70) return "cocina";
    return "salon";
}


/*-----  POSICION  +  VUELTAS  -------*/
void entidad_game::RefrescaPosicion(int i){
    int pos_nueva=1;

    // actualizamos la posición:
    for(int t=0;t<particulas.size();t++){
        if(particulas[t].Estado!="GAME_OVER" && t!=i){
            if(particulas[t].num_vueltas<particulas[i].num_vueltas)pos_nueva++;
            else if(particulas[t].num_vueltas==particulas[i].num_vueltas){
                int a,b;
                if(particulas[t].bandera[2])a=2;
                else if(particulas[t].bandera[1])a=1;
                else if(particulas[t].bandera[0])a=0;
                else a=-1;
                if(particulas[i].bandera[2])b=2;
                else if(particulas[i].bandera[1])b=1;
                else if(particulas[i].bandera[0])b=0;
                else b=-1;
                if(a>b)pos_nueva++;
                else if(a==b){if(MasAdelantada(t,i))pos_nueva++;}//mismas banderas activas
            }
        }
    }
    // mi posición nueva:
    particulas[i].posicion=pos_nueva;
}

void entidad_game::RefrescaVueltas(int i){
    string situacion=DeterminarSuperficie(i);
    if(particulas[i].bandera[2]==true){
        if(situacion=="salon")particulas[i].bandera[2]=false;
        else if(situacion=="entrada")
            if(particulas[i].pos_act.z > meta){
                particulas[i].bandera[0]=true;
                particulas[i].bandera[1]=particulas[i].bandera[2]=false;
                particulas[i].num_vueltas--;
            }
    }
    else if(particulas[i].bandera[1]==true){
        if(situacion=="entrada")particulas[i].bandera[1]=false;
        else if(situacion=="cocina")
            particulas[i].bandera[2]=true;
    }
    else if(particulas[i].bandera[0]==true){
        if(situacion=="cocina")particulas[i].bandera[0]=false;
        else if(situacion=="salon")
            particulas[i].bandera[1]=true;
    }
    else if(situacion=="entrada"){//si vamos para atrás
        if(particulas[i].pos_act.x<75&&particulas[i].pos_act.z<meta) particulas[i].num_vueltas--;
        else particulas[i].num_vueltas++;
        particulas[i].bandera[0]=true;
    }
}
/*-----------------------------------*/




/*----  MOVIMIENTO ----*/
void entidad_game::movimiento(int numparticulas){
    _vertex3f aux;
    aux.x=aux.y=aux.z=0;
    //
    if(particulas[numparticulas].Estado=="GAME_OVER" || particulas[numparticulas].Estado=="GANADOR")return;//salimos
    /*
        PARTE COMÚN (comprobación si hemos perdido)
    */
    for(int i=0;i<particulas.size();i++){
        if(i!=numparticulas)
            if(particulas[i].Estado=="GANADOR")
                particulas[numparticulas].Estado="GAME_OVER";
    }
    //
    //
    /*
       1º.- Controlado por HUMANO
    */
    if(particulas[numparticulas].humano){
        /*Maquina de estados*/
        //
        if(particulas[numparticulas].Estado=="PARADO"){//a la espera
            // reinicio turbo
            particulas[numparticulas].turbo_distancia=particulas[numparticulas].turbo_tick=0;
            // giro
            particulas[numparticulas].ticks_angulares=1;
            // movimiento
            particulas[numparticulas].avanza_dist=5;
            particulas[numparticulas].ticks=0.15;
        }
        //
        else if(particulas[numparticulas].Estado=="ACELERA" || particulas[numparticulas].Estado=="MARCHA_ATRAS"){// moviendose
            _vertex3f vector_orientacion=particulas[numparticulas].ori_nueva;
            //preparamos aumento:
            vector_orientacion.normalize();
            vector_orientacion.x*=(particulas[numparticulas].avanza_dist+particulas[numparticulas].turbo_distancia);
            vector_orientacion.z*=(particulas[numparticulas].avanza_dist+particulas[numparticulas].turbo_distancia);
            //guardamos aumento (punto_final)
            aux=particulas[numparticulas].pos_ant=particulas[numparticulas].pos_i=particulas[numparticulas].pos_act;
            if(particulas[numparticulas].Estado=="ACELERA"){
                aux.x+=vector_orientacion.x;
                aux.z+=vector_orientacion.z;
            }
            else{//MARCHA_ATRASarticulas[numparticulas].angulo_orientacion
                aux.x-=vector_orientacion.x;
                aux.z-=vector_orientacion.z;
            }
            particulas[numparticulas].pos_f=aux;
        }
        //
        else if(particulas[numparticulas].Estado=="GIRAR_LEFT" || particulas[numparticulas].Estado=="GIRAR_RIGHT"){// girando
            particulas[numparticulas].cont_angular++;
            particulas[numparticulas].num_angular=particulas[numparticulas].alfa/particulas[numparticulas].ticks_angulares;
            particulas[numparticulas].giro+=particulas[numparticulas].ticks_angulares;
            // nueva orientación:
            double angulo=particulas[numparticulas].angulo_orientacion;
            double angulo_bat=angulo-90;
            (particulas[numparticulas].Estado=="GIRAR_LEFT")?angulo+=particulas[numparticulas].alfa-particulas[numparticulas].giro:angulo+=-particulas[numparticulas].alfa+particulas[numparticulas].giro;
            (particulas[numparticulas].Estado=="GIRAR_LEFT")?angulo_bat+=particulas[numparticulas].alfa-particulas[numparticulas].giro:angulo_bat+=-particulas[numparticulas].alfa+particulas[numparticulas].giro;
            particulas[numparticulas].ori_nueva.x=cos(angulo*M_PI/180);
            particulas[numparticulas].ori_nueva.z=sin(angulo*M_PI/180);

            particulas[numparticulas].ori_bat.x=cos(angulo_bat*M_PI/180);
            particulas[numparticulas].ori_bat.z=sin(angulo_bat*M_PI/180);
        }
        //
        else if(particulas[numparticulas].Estado=="AVANZAR"){// mov.
            //gasolina
            particulas[numparticulas].gasolina-=((particulas[numparticulas].turbo_tick+particulas[numparticulas].ticks)*0.035);
            if(particulas[numparticulas].gasolina<=0)particulas[numparticulas].Estado="GAME_OVER";
            //movimiento
            particulas[numparticulas].cont_ticks++;
            particulas[numparticulas].num_ticks=particulas[numparticulas].distancia/particulas[numparticulas].ticks;
            float t=(float)particulas[numparticulas].cont_ticks/(float)particulas[numparticulas].num_ticks;

            aux.y=particulas[numparticulas].pos_i.y;
            aux.x=((1-t)*particulas[numparticulas].pos_i.x)+(t*particulas[numparticulas].pos_f.x);
            aux.z=((1-t)*particulas[numparticulas].pos_i.z)+(t*particulas[numparticulas].pos_f.z);

            particulas[numparticulas].pos_ant=particulas[numparticulas].pos_act;
            particulas[numparticulas].pos_act=aux;
        }
        //
        else if(particulas[numparticulas].Estado=="RECARGANDO"){//reponiendo gasolina
            double elec=0.25;
            if(electricidad[particulas[numparticulas].repostando]>0){
                if(electricidad[particulas[numparticulas].repostando]>elec){
                    electricidad[particulas[numparticulas].repostando]-=elec;
                }
                else{
                    elec=electricidad[particulas[numparticulas].repostando];
                    electricidad[particulas[numparticulas].repostando]=0;
                }
                particulas[numparticulas].gasolina+=elec;
            }
        }


        /*Cambio de estados*/
        //
        if(particulas[numparticulas].Estado=="PARADO"){
            if(particulas[numparticulas].gasolina>0){//si hay combustible
                if(particulas[numparticulas].tecla=="UP")
                    particulas[numparticulas].Estado="ACELERA";
                else if(particulas[numparticulas].tecla=="DOWN")
                    particulas[numparticulas].Estado="MARCHA_ATRAS";
                else if(particulas[numparticulas].tecla=="LEFT" || particulas[numparticulas].tecla=="RIGHT"){
                    /*
                     * 'alfa' es el angulo que buscamos girar
                     * 'giro', con 'giro_y'    --> son los giros para orientarnos (provisionales)
                     * 'beta', con 'giro_beta' --> son los giros definitivos (con la orientacion ganada al girar)
                     */
                    // giro alfa (lo que queremos girar)
                    particulas[numparticulas].alfa=10;//en grados
                    // direccion del giro alfa
                    (particulas[numparticulas].tecla=="LEFT")?particulas[numparticulas].giro_y=1:particulas[numparticulas].giro_y=-1;
                    // calculamos nueva orientacion
                    (particulas[numparticulas].tecla=="LEFT")?particulas[numparticulas].angulo_orientacion-=particulas[numparticulas].alfa:particulas[numparticulas].angulo_orientacion+=particulas[numparticulas].alfa;
                    if(particulas[numparticulas].angulo_orientacion>360)particulas[numparticulas].angulo_orientacion-=360;
                    if(particulas[numparticulas].angulo_orientacion<0)particulas[numparticulas].angulo_orientacion+=360;
                    // nuevos valores
                    particulas[numparticulas].cont_angular=0;
                    // siguiente estado
                    (particulas[numparticulas].tecla=="LEFT")?particulas[numparticulas].Estado="GIRAR_LEFT":particulas[numparticulas].Estado="GIRAR_RIGHT";
                }
                else if(particulas[numparticulas].tecla=="RECARGA"){
                    double dist;
                    int i=numparticulas;
                    dist=sqrt(pow(particulas[i].pos_act.x-pos_gasolinera[0].x,2)+pow(particulas[i].pos_act.z-pos_gasolinera[0].z,2));
                    if(particulas[i].gasolina<100){
                        //entrada
                        if(dist<=20){
                            if(gasolinera[0]==0)//libre
                            {gasolinera[0]=1;particulas[numparticulas].repostando=0;particulas[numparticulas].Estado="RECARGANDO";}
                        }
                        else{
                        //salon
                            dist=sqrt(pow(particulas[i].pos_act.x-pos_gasolinera[1].x,2)+pow(particulas[i].pos_act.z-pos_gasolinera[1].z,2));
                            if(dist<=20){
                                if(gasolinera[1]==0)//libre
                                {gasolinera[1]=1;particulas[numparticulas].repostando=1;particulas[numparticulas].Estado="RECARGANDO";}
                            }
                            else{
                        //cocina
                                dist=sqrt(pow(particulas[i].pos_act.x-pos_gasolinera[2].x,2)+pow(particulas[i].pos_act.z-pos_gasolinera[2].z,2));
                                if(dist<=20){
                                    if(gasolinera[2]==0)//libre
                                    {gasolinera[2]=1;particulas[numparticulas].repostando=2;particulas[numparticulas].Estado="RECARGANDO";}
                                }
                            }
                        }
                    }
                    //
                    particulas[numparticulas].tecla="VACIA";
                }
            }
        }
        //
        else if((particulas[numparticulas].Estado=="ACELERA" || particulas[numparticulas].Estado=="MARCHA_ATRAS")&& particulas[numparticulas].pos_f==aux){
            particulas[numparticulas].distancia=sqrt(pow(particulas[numparticulas].pos_f.x-particulas[numparticulas].pos_i.x,2)+pow(particulas[numparticulas].pos_f.y-particulas[numparticulas].pos_i.y,2)+pow(particulas[numparticulas].pos_f.z-particulas[numparticulas].pos_i.z,2));
            particulas[numparticulas].cont_ticks=0;
            particulas[numparticulas].Estado="AVANZAR";
        }
        //
        else if((particulas[numparticulas].Estado=="GIRAR_LEFT"||particulas[numparticulas].Estado=="GIRAR_RIGHT")){
            double dif_contador_ang=particulas[numparticulas].num_angular-particulas[numparticulas].cont_angular;
            if(dif_contador_ang<=0){
                // guardamos angulo anterior (beta)
                _vertex3f _B=particulas[numparticulas].ori_nueva,_A=particulas[numparticulas].orientacion;
                _A.normalize();
                _B.normalize();
                float angulo_anterior=_A.dot_product(_B);
                particulas[numparticulas].beta=(acos(angulo_anterior)*180)/M_PI;
                (_A.cross_product(_B).y<0)?particulas[numparticulas].giro_beta=-1:particulas[numparticulas].giro_beta=1;
                particulas[numparticulas].giro=particulas[numparticulas].giro_y=0;
                // estado siguiente
                particulas[numparticulas].Estado="PARADO";
            }
        }
        //
        else if(particulas[numparticulas].Estado=="AVANZAR"){
            double dif_contador=particulas[numparticulas].num_ticks-particulas[numparticulas].cont_ticks;
            if(particulas[numparticulas].colisiones[numparticulas]==true)particulas[numparticulas].colisiones[numparticulas]=false;//caso de encontrarse colisionada y salir
            if(dif_contador<=0){// caso terminar de recorrer
                if(particulas[numparticulas].tecla=="UP")particulas[numparticulas].Estado="ACELERA";
                else if(particulas[numparticulas].tecla=="UP_2"){
                    particulas[numparticulas].turbo_distancia=10;
                    if(particulas[numparticulas].turbo_tick==0)particulas[numparticulas].turbo_tick=1;
                    else if(particulas[numparticulas].turbo_tick<3)particulas[numparticulas].turbo_tick++;
                    else particulas[numparticulas].turbo_tick=3;
                    particulas[numparticulas].tecla="UP";
                    particulas[numparticulas].Estado="ACELERA";
                }
                else if(particulas[numparticulas].tecla=="DOWN")particulas[numparticulas].Estado="MARCHA_ATRAS";
                else particulas[numparticulas].Estado="PARADO";
            }
            else if(particulas[numparticulas].tecla=="UP" || particulas[numparticulas].tecla=="DOWN"){
                particulas[numparticulas].ticks+=0.15;
                if(particulas[numparticulas].ticks>0.6)particulas[numparticulas].ticks=0.6;
                particulas[numparticulas].ticks+=particulas[numparticulas].turbo_tick;
                if(dif_contador<=5){
                    particulas[numparticulas].avanza_dist=20;
                    if(particulas[numparticulas].tecla=="UP")particulas[numparticulas].Estado="ACELERA";
                    else{
                        // reiniciamos el turbo
                        particulas[numparticulas].turbo_tick--;
                        if(particulas[numparticulas].turbo_tick<0){
                            particulas[numparticulas].turbo_distancia=particulas[numparticulas].turbo_tick=0;
                            particulas[numparticulas].Estado="MARCHA_ATRAS";
                        }
                        else {particulas[numparticulas].tecla="UP";particulas[numparticulas].Estado="ACELERA";}
                    }
                }
            }
            //
            if(particulas[numparticulas].tecla=="PARAR")
                particulas[numparticulas].Estado="PARADO";
        }
        //
        else if(particulas[numparticulas].Estado=="RECARGANDO"){
            bool salir=false, vacia=false;
            //A tope de gasolina
            if(particulas[numparticulas].gasolina>=100){
                particulas[numparticulas].gasolina=100;
                salir=true;
            }
            //Si paramos de repostar
            if(particulas[numparticulas].tecla=="RECARGA")salir=true;
            //Si gasolinera vacia
            if(electricidad[particulas[numparticulas].repostando]<=0)vacia=true;
            //Op. siguientes
            if(vacia || salir){
                gasolinera[particulas[numparticulas].repostando]=0;
                particulas[numparticulas].Estado="PARADO";
                particulas[numparticulas].tecla="VACIA";
            }
            if(vacia){
                electricidad[particulas[numparticulas].repostando]=0;
                gasolinera[particulas[numparticulas].repostando]=-1;
            }
            if(vacia || salir)
                particulas[numparticulas].repostando=-1;
        }
        //
    }
    /*=================================================================================================================================================*/
    /*
       2º.- Controlado por ORDENADOR
    */
    else {
        //
        //
        if(particulas[numparticulas].colisiones[numparticulas]==false && particulas[numparticulas].Estado!="RECARGANDO"){//PRE-COLISION
            string estado=particulas[numparticulas].Estado;
            particulas[numparticulas].Estado="AVANZAR";
            if(ColisionTrayecto(numparticulas,10))particulas[numparticulas].Estado="EVITAR_COLISION";
            else particulas[numparticulas].Estado=estado;
        }
        //
        if(particulas[numparticulas].Estado=="EVITAR_COLISION"){
            particulas[numparticulas].pos_i=particulas[numparticulas].pos_ant=particulas[numparticulas].pos_act;
            particulas[numparticulas].Estado="AVANZAR";
            for(int i=0;i<particulas.size();i++)particulas[numparticulas].colisiones[i]=false;//limpiamos las posibles colisiones...
            if(ColisionTrayecto(numparticulas,20)==false){particulas[numparticulas].Estado="EVITAR_COLISION_";}
            else{
                bool salir=false;
                for(int i=0;i<particulas.size()&&!salir;i++){
                    if(i!=numparticulas && particulas[numparticulas].colisiones[i]){
                        if(particulas[i].Estado=="EVITAR_COLISION" || (particulas[i].humano&&particulas[i].Estado!="AVANZAR")){
                            if(!MasAdelantada(numparticulas,i))salir=true;
                        }
                        else salir=true;
                    }
                }
                if(!salir)particulas[numparticulas].Estado="EVITAR_COLISION_";
                else particulas[numparticulas].Estado="EVITAR_COLISION";
            }
        }
        //
        else if(particulas[numparticulas].Estado=="BUSCAR_OBJETIVO"){
            //Buscamos siguiente zona y asignamos al pos_f
            int zona=particulas[numparticulas].zona_mov;
            double x_=mover[zona].x,z_=mover[zona].z;
            if(zona>=0 && zona<(4*16)){
                zona=siguienteZona(numparticulas);
                particulas[numparticulas].zona_mov_ant=particulas[numparticulas].zona_mov;
                particulas[numparticulas].zona_mov=zona;}

            particulas[numparticulas].pos_ant=particulas[numparticulas].pos_i=particulas[numparticulas].pos_act;
            aux.x=x_;
            aux.y=particulas[numparticulas].subir;
            aux.z=z_;
            particulas[numparticulas].pos_f=aux;
        }
        //
        else if(particulas[numparticulas].Estado=="GIRAR"){
            particulas[numparticulas].cont_angular++;
            particulas[numparticulas].num_angular=particulas[numparticulas].alfa/particulas[numparticulas].ticks_angulares;
            particulas[numparticulas].giro+=particulas[numparticulas].ticks_angulares;
        }
        //
        else if(particulas[numparticulas].Estado=="AVANZAR"){
            //gasolina
            particulas[numparticulas].gasolina_ant=particulas[numparticulas].gasolina;
            particulas[numparticulas].gasolina-=(particulas[numparticulas].ticks*0.05);
            if(particulas[numparticulas].gasolina<=0)particulas[numparticulas].Estado="GAME_OVER";
            //avanzar
            particulas[numparticulas].cont_ticks++;
            particulas[numparticulas].num_ticks=particulas[numparticulas].distancia/particulas[numparticulas].ticks;
            float t=(float)particulas[numparticulas].cont_ticks/(float)particulas[numparticulas].num_ticks;
            aux.y=particulas[numparticulas].pos_i.y;
            if(!particulas[numparticulas].mov_lineal){
               aux.x=((1-sin(t))*particulas[numparticulas].pos_i.x)+(sin(t)*particulas[numparticulas].pos_f.x);
               aux.z=((1-sin(t))*particulas[numparticulas].pos_i.z)+(sin(t)*particulas[numparticulas].pos_f.z);
            }
            else{
               aux.x=((1-t)*particulas[numparticulas].pos_i.x)+(t*particulas[numparticulas].pos_f.x);
               aux.z=((1-t)*particulas[numparticulas].pos_i.z)+(t*particulas[numparticulas].pos_f.z);
            }
            particulas[numparticulas].pos_ant=particulas[numparticulas].pos_act;
            particulas[numparticulas].pos_act=aux;
        }
        else if(particulas[numparticulas].Estado=="RECARGANDO"){
            double elec=0.25;
            if(electricidad[particulas[numparticulas].repostando]>0){
                if(electricidad[particulas[numparticulas].repostando]>elec){
                    electricidad[particulas[numparticulas].repostando]-=elec;
                }
                else{
                    elec=electricidad[particulas[numparticulas].repostando];
                    electricidad[particulas[numparticulas].repostando]=0;
                }
                particulas[numparticulas].gasolina+=elec;
            }
        }
        //
        // Cambios de estado:
        if(particulas[numparticulas].Estado=="EVITAR_COLISION_")
        {
                particulas[numparticulas].zona_mov=particulas[numparticulas].zona_mov_ant;
                particulas[numparticulas].Estado="BUSCAR_OBJETIVO";
        }
        else if(particulas[numparticulas].Estado=="BUSCAR_OBJETIVO")
        {
            // angulo giro
            _vertex3f B;
            _vertex3f A=particulas[numparticulas].ori_nueva;
            B.x=particulas[numparticulas].pos_f.x-particulas[numparticulas].pos_i.x;
            B.z=particulas[numparticulas].pos_f.z-particulas[numparticulas].pos_i.z;
            B.normalize();
            A.normalize();
            float escalar=A.dot_product(B);
            (escalar>=1)?particulas[numparticulas].alfa=0:particulas[numparticulas].alfa=(acos(escalar)*180)/M_PI;
            (A.cross_product(B).y<0)?particulas[numparticulas].giro_y=-1:particulas[numparticulas].giro_y=1;
            // ticks angulares
            particulas[numparticulas].num_angular=particulas[numparticulas].alfa/particulas[numparticulas].ticks_angulares;
            particulas[numparticulas].cont_angular=0;
            particulas[numparticulas].ori_nueva=B;
            // siguiente estado
            (particulas[numparticulas].giro_y==-1)?particulas[numparticulas].angulo_orientacion-=particulas[numparticulas].alfa:particulas[numparticulas].angulo_orientacion+=particulas[numparticulas].alfa;
            if(particulas[numparticulas].angulo_orientacion>360)particulas[numparticulas].angulo_orientacion-=360;
            if(particulas[numparticulas].angulo_orientacion<0)particulas[numparticulas].angulo_orientacion+=360;
            particulas[numparticulas].Estado="GIRAR";
        }
        else if(particulas[numparticulas].Estado=="GIRAR" &&  ((particulas[numparticulas].num_angular<particulas[numparticulas].cont_angular) || particulas[numparticulas].alfa==0))
        {
            // guardamos angulo anterior (beta)
            _vertex3f _B=particulas[numparticulas].ori_nueva,_A=particulas[numparticulas].orientacion;
            _A.normalize();
            _B.normalize();
            float angulo_anterior=_A.dot_product(_B);
            particulas[numparticulas].beta=(acos(angulo_anterior)*180)/M_PI;
            (_A.cross_product(_B).y<0)?particulas[numparticulas].giro_beta=-1:particulas[numparticulas].giro_beta=1;
            particulas[numparticulas].giro=particulas[numparticulas].giro_y=0;
            // generamos ticks movimiento:
            particulas[numparticulas].distancia=sqrt(pow(particulas[numparticulas].pos_f.x-particulas[numparticulas].pos_i.x,2)+pow(particulas[numparticulas].pos_f.z-particulas[numparticulas].pos_i.z,2));
            particulas[numparticulas].num_ticks=particulas[numparticulas].distancia/particulas[numparticulas].ticks;
            particulas[numparticulas].cont_ticks=0;
            particulas[numparticulas].Estado="AVANZAR";
        }
        else if(particulas[numparticulas].Estado=="AVANZAR"){
            //estado repostar:
            if(particulas[numparticulas].repostando==-1){
                if(particulas[numparticulas].gasolina<umbral){
                    if(particulas[numparticulas].zona_mov == (((numparticulas-1)*16)+2)){//entrada
                        if(gasolinera[0]==0){
                            particulas[numparticulas].repostando=0;
                            particulas[numparticulas].zona_mov_ant=particulas[numparticulas].zona_mov=4*16;}
                    }
                    else if(particulas[numparticulas].zona_mov == (((numparticulas-1)*16)+9)){//salon
                        if(gasolinera[1]==0){
                            particulas[numparticulas].repostando=1;
                            particulas[numparticulas].zona_mov_ant=particulas[numparticulas].zona_mov=(4*16)+1;}
                    }
                    else if(particulas[numparticulas].zona_mov == (((numparticulas-1)*16)+14)){//cocina
                        if(gasolinera[2]==0){
                            particulas[numparticulas].repostando=2;
                            particulas[numparticulas].zona_mov_ant=particulas[numparticulas].zona_mov=(4*16)+2;}
                    }
                }
            }
            //siguiente estado:
            if(particulas[numparticulas].num_ticks<particulas[numparticulas].cont_ticks){
                if(particulas[numparticulas].zona_mov>=(4*16)){
                    if(particulas[numparticulas].pos_f.x==mover[particulas[numparticulas].zona_mov].x && particulas[numparticulas].pos_f.z==mover[particulas[numparticulas].zona_mov].z){
                        if(gasolinera[particulas[numparticulas].repostando]==0)
                            gasolinera[particulas[numparticulas].repostando]=1;
                        particulas[numparticulas].Estado="RECARGANDO";
                    }
                    else
                        particulas[numparticulas].Estado="BUSCAR_OBJETIVO";
                }
                else{
                    particulas[numparticulas].repostando=-1;
                    particulas[numparticulas].Estado="BUSCAR_OBJETIVO";
                }
            }
        }
        else if(particulas[numparticulas].Estado=="RECARGANDO"){
            bool salir=false, vacia=false;
            //A tope de gasolina
            if(particulas[numparticulas].gasolina>=100){
                particulas[numparticulas].gasolina=100;
                salir=true;
            }
            //Si gasolinera vacia
            if(electricidad[particulas[numparticulas].repostando]<=0)vacia=true;
            //Op. siguientes
            if(vacia || salir){
                gasolinera[particulas[numparticulas].repostando]=0;
                if(particulas[numparticulas].zona_mov==(4*16))particulas[numparticulas].zona_mov=particulas[numparticulas].zona_mov_ant=((numparticulas-1)*16)+3;
                else if(particulas[numparticulas].zona_mov==(4*16)+1)particulas[numparticulas].zona_mov=particulas[numparticulas].zona_mov_ant=((numparticulas-1)*16)+10;
                else if(particulas[numparticulas].zona_mov==(4*16)+2)particulas[numparticulas].zona_mov=particulas[numparticulas].zona_mov_ant=((numparticulas-1)*16)+14;
                particulas[numparticulas].Estado="BUSCAR_OBJETIVO";
            }
            if(vacia){
                electricidad[particulas[numparticulas].repostando]=0;
                gasolinera[particulas[numparticulas].repostando]=-1;
            }
            if(salir || vacia)particulas[numparticulas].repostando=-1;
        }
    }
    //
    //
    /*   PARTE COMÚN    */
    //
    //
    /*  ACTULIZAMOS LAS VUELTAS Y POSICION  */
    RefrescaPosicion(numparticulas);
    RefrescaVueltas(numparticulas);

    if(particulas[numparticulas].num_vueltas<=0 && particulas[numparticulas].Estado!="GAME_OVER"){
        particulas[numparticulas].Estado="GANADOR";
    }
    /*  CASO DE PERDER/GANAR  */
    if(particulas[numparticulas].Estado=="GAME_OVER"){
        /*1º.-Porche*/
        if(numparticulas==0){
            // posicion:
            particulas[numparticulas].pos_act.x=15;
            particulas[numparticulas].pos_act.y=72.5+particulas[numparticulas].obj->caja();
            particulas[numparticulas].pos_act.z=210;
            // giro beta (en el eje y)
            particulas[numparticulas].beta=160;
            particulas[numparticulas].giro_beta=1;
        }

        /*2º.-Camioneta*/
        else if(numparticulas==1){
            // posicion:
            particulas[numparticulas].pos_act.x=-8;
            particulas[numparticulas].pos_act.y=66.5+particulas[numparticulas].obj->caja();
            particulas[numparticulas].pos_act.z=213;
            // giro beta (en el eje y)
            particulas[numparticulas].beta=175;
            particulas[numparticulas].giro_beta=1;
        }

        /*3º.-Coche Antiguo*/
        else if(numparticulas==2){
            // posicion:
            particulas[numparticulas].pos_act.x=14;
            particulas[numparticulas].pos_act.y=54.6+particulas[numparticulas].obj->caja();
            particulas[numparticulas].pos_act.z=213;
            // giro beta (en el eje y)
            particulas[numparticulas].beta=180;
            particulas[numparticulas].giro_beta=1;
        }

        /*4º.-Escarabajo*/
        else if(numparticulas==3){
            // posicion:
            particulas[numparticulas].pos_act.x=-10;
            particulas[numparticulas].pos_act.y=57.45+particulas[numparticulas].obj->caja();
            particulas[numparticulas].pos_act.z=213;
            // giro beta (en el eje y)
            particulas[numparticulas].beta=150;
            particulas[numparticulas].giro_beta=1;
        }

        /*5º.-Formula1*/
        else if(numparticulas==4){
            // posicion:
            particulas[numparticulas].pos_act.x=13;
            particulas[numparticulas].pos_act.y=32+particulas[numparticulas].obj->caja();
            particulas[numparticulas].pos_act.z=208;
            // giro beta (en el eje y)
            particulas[numparticulas].beta=160;
            particulas[numparticulas].giro_beta=1;
        }
    }

    /*  COLISIONES  */
    else if((particulas[numparticulas].colisiones[numparticulas]==false&&particulas[numparticulas].Estado!="RECARGANDO") || (particulas[numparticulas].Estado=="AVANZAR"&&particulas[numparticulas].cont_ticks>1)){
            colision(numparticulas);
            descolision(numparticulas);
    }



}
//-----------------------------





//------------   GASOLINERAS - VACIAS   -----------------

void entidad_game::gasolineraTime(void){
    int num_gasolineras=3;
    for(int i=0;i<num_gasolineras;i++){
        if(gasolinera[i]==-1){
            if(time_0[i]==false){
                time_0[i]=true;
                time_ini[i]=clock();
            }
            time_f[i]=clock();
            float segundos=(time_f[i]-time_ini[i])/CLOCKS_PER_SEC;
            if(segundos>25){//25 segundos sin electricidad
                time_0[i]=false;
                gasolinera[i]=0;
                electricidad[i]=nivel_electricidad;
            }
        }
    }
}

//-------------------------------------------------------

