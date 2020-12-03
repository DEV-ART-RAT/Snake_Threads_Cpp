#pragma once

#include <iostream>

#include <unistd.h>
#include <termios.h>

#include "./difficulty.cpp"
#include "../snake/my_snake.h"
#include "../tools/gameStruct.h"
using namespace std;

auto mensajeScene = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    (opc==1)? messageLineRED(w.ws_col,"*  LIBRE  *"):    messageLine(w.ws_col,"   LIBRE   ");
    (opc==2)? messageLineRED(w.ws_col,"*  CERRADO * "):   messageLine(w.ws_col,"   CERRADO   ");
    for(int i=3; i<size;i++){
        (opc==i)? messageLineRED(w.ws_col,"*  EXTRA "+to_string(i-2)+"  *"):    messageLine(w.ws_col,"   EXTRA "+to_string(i-2)+"   ");
    }
    (opc==size)? messageLineRED(w.ws_col,"*  REGRESAR *"):    messageLine(w.ws_col,"   REGRESAR  ");
    messageSteep(w.ws_col);
    messageMargin(w.ws_col);
};

int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );
//int startMenu(myGame<nodeuserinfouser>* );
int sceneMenu(myGame<nodeuserinfouser>* );

//menu para seleccionar el tipo de escenario
int sceneMenuAux(myGame<nodeuserinfouser>* game,int flag,int size){

    game->scene =  flag;//se guarda el numero de escenario a cargar
    
    if(flag != size){//se revisa si la opcion seleccionada no sea la de retroeceder
        difficultyMenu(game);//se carga el menu de seleccion de dificultad
    }
    if(flag == size){//si la opcion es de retroceder
        return 1;//se retorna a un menu previo
    }
    sceneMenu(game);//se vuelve a cargar este menu desde una seleccionposterior
    return 0;
}

//funcion que llama al selector de opciones mandando la funcion para escuchar el teclado
int sceneMenu(myGame<nodeuserinfouser>* game){
    int opciones = 3;//numero de opciones por default
    opciones += game->sceneList.size();//se suma el totaldeescenarios cargados externamente a las opciones
    return sceneMenuAux(game,optionSelectionKey(game,mensajeScene,opciones),opciones);
}






