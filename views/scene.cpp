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
int startMenu(myGame<nodeuserinfouser>* );
int sceneMenu(myGame<nodeuserinfouser>* );


int sceneMenuAux(myGame<nodeuserinfouser>* game,int flag,int size){

    game->scene =  flag;
    
    if(flag != size){
        difficultyMenu(game);
    }
    if(flag == size){
        return 1;
    }
    sceneMenu(game);
    return 0;
}

int sceneMenu(myGame<nodeuserinfouser>* game){
    int opciones = 3;
    opciones += game->sceneList.size();
    return sceneMenuAux(game,optionSelectionKey(game,mensajeScene,opciones),opciones);
}






