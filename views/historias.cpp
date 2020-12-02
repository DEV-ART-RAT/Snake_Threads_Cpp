#include<iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits

#include "../snake/clear.cpp"
#include "./snakeprint.cpp"

//historia by .Drubi

using namespace std;

void mensajehistoria(int pos,int max,string histo[]);

int history(void) {
    string historia[]={
        "En el principio de la humanidad las personas vivian felizmente,",
        "Habian muchos trabajos y ocupaciones pero el que mas llamaba la atencion era ser mago,",
        "Por lo que muchos estudiaban magia negra",
        "En la universidad de los buhos,",
        "Eran felices hasta que un dia llego",
        "El Poderoso ENXEL,",
        "Que vino a convertir a toda la raza humana en Serpientes,",
        "Pero llegaste tu para combatirlo",
        "Asi que adelante Gana y vence a Enxel!!!"
    };
    CLEAR
    mensageMargin(w.ws_col);
    mensageLineMAGENTA(w.ws_col,"(Presiona Enter para avanzar en la historia)");
    mensageSteep(w.ws_col);
    int size =0;
    size=sizeof(historia)/sizeof(historia[0]);
    mensajehistoria(0,size,historia); 
    return 0;
};

void mensajehistoria(int pos,int max,string histo[]){
    char key=getchar();
    switch (key)
    {
    case '\n':
        if(pos<max){
            mensageLineCYAN(w.ws_col,histo[pos]);
            mensajehistoria(pos+1,max,histo);
        }else{
            mensageMargin(w.ws_col);
            sleep(0.5);
            return;
        }
        break;
    default:
        mensajehistoria(pos,max,histo);
        break;
    }
}