#include "funciones.h"

funciones::funciones()
{
}

void funciones::StoF(float &resultado,char *cad){
    resultado=atoi(cad);
    if(cad[0]=='-')resultado=0-resultado;
    int i, b=1, primero=0;
    for (i=0; i<strlen(cad); i++){
        if(primero==0&&cad[i]=='.')primero=-1;
        else if(primero==-1){//empezamos a crear flotante
            char *c;
            if(cad[i]=='e'){
                int resultado2=0,b2=0;
                for(int j=strlen(cad)-1;j>=i+2;j--){
                    c=(char*)malloc(sizeof(char));
                    sprintf(c,"%c",cad[j]);
                    resultado2+=(atoi(c)*1.0)*pow(10,b2);
                    b2++;
                    free(c);
                }
                if(cad[i+1]=='-')resultado2=0-resultado2;
                resultado*=pow(10,resultado2);
                i=strlen(cad);
            }
            else{
                c=(char*)malloc(sizeof(char));
                sprintf(c,"%c",cad[i]);
                resultado+=(atoi(c)*1.0)/pow(10,b);
                b++;
                free(c);
            }
        }
    }
    if(cad[0]=='-')resultado=0-resultado;
}
