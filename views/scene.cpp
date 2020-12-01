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
    (opc==1)? mensageLine(w.ws_col,"*  LIBRE  *"):    mensageLine(w.ws_col,"   LIBRE   ");
    (opc==2)? mensageLine(w.ws_col,"*  CERRADO * "):   mensageLine(w.ws_col,"   CERRADO   ");
    for(int i=3; i<size;i++){
        (opc==i)? mensageLine(w.ws_col,"*  EXTRA "+to_string(i-2)+"  *"):    mensageLine(w.ws_col,"   EXTRA "+to_string(i-2)+"   ");
    }
    (opc==size)? mensageLine(w.ws_col,"*  REGRESAR *"):    mensageLine(w.ws_col,"   REGRESAR  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
};

int startMenuAux(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* );
int sceneMenu(myGame<nodeuserinfouser>* );


int sceneMenuAux(myGame<nodeuserinfouser>* game,int flag){

    //mySnake snake = mySnake();
    game->scene =  flag;
    //game->levelSpecial = 1;
    difficultyMenu(game);
    sceneMenu(game);
    return 0;
}

int sceneMenu(myGame<nodeuserinfouser>* game){
    int opciones = 3;
    opciones += game->sceneList.size();
    return sceneMenuAux(game,startMenuAux(game,mensajeScene,opciones));
}






