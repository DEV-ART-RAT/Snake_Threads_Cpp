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
        "Bienvenido Snakero, estas apunto de entrar a una fantastica aventura",
        "para evitar facilitarte tu viaje te explicaremos los controles basicos:",
        "Muevete usanso las direccionales dentro del menu y del campo de juego",
        "presiona ENTER para seleccionar y poner pausa dentro del juego",
        "Tendras 3 diferentes modos de juego:",
        "1- World Party Snake: disfruta de diferentes mundos cada uno mas dificil.",
        "2- Clasic 97: El snake Clasic, la velocidad aumenta mientras mas comas!",
        "3- Especial: Difruta de diferentes mapas creados por los dioses, no sera nada facil.",
        "No olvides reunir el maximo de monedas que puedas para comprar potenciadores en la tienda",
        "Y por ultimo ... domina la cima de todos los tops de los modos de juego",
        "Divierte!!!"
    };
    CLEAR
    messageMargin(w.ws_col);
    messageLineMAGENTA(w.ws_col,"(Presiona Enter para continuar)");
    messageSteep(w.ws_col);
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
            messageLineCYAN(w.ws_col,histo[pos]);
            mensajehistoria(pos+1,max,histo);
        }else{
            messageMargin(w.ws_col);
            sleep(0.5);
            return;
        }
        break;
    default:
        mensajehistoria(pos,max,histo);
        break;
    }
}