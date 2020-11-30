#pragma once
#include <iostream>
#include <termios.h>
#include <unistd.h>

//#include "../snake/clear.cpp"
//#include "../snake/matriz.cpp"
#include "../snake/my_snake.h"
#include "../tools/gameStruct.h"
#include "./difficulty.cpp"
#include "./scene.cpp"
using namespace std;

auto mensajeMode = [](int opc,myGame<nodeuserinfouser>* game) { 
    CLEAR;
    snakeprint();
    (opc==1)? mensageLine(w.ws_col,"*  CLASICO  *"):    mensageLine(w.ws_col,"   CLASICO   ");
    (opc==2)? mensageLine(w.ws_col,"*  ESPECIAL * "):   mensageLine(w.ws_col,"   ESPECIAL   ");
    (opc==3)? mensageLine(w.ws_col,"*  REGRESAR *"):    mensageLine(w.ws_col,"   REGRESAR  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
};

int startMenuAux(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* );
int sceneMenu(myGame<nodeuserinfouser>* );
int playmatrix(myGame<nodeuserinfouser>* );
int modeMenu(myGame<nodeuserinfouser>* );


int modeMenuAux(myGame<nodeuserinfouser>* game,int flag){

    switch (flag) {
        case 1:
            //game->scene =  1;
            game->mode = true;//clasico
            //difficultyMenu(game);
            playmatrix(game);
            //gameOverMenu(game);
            break;
        case 2://especial
            //playmatrix(&snake,2,0);
            game->mode = false;//especial
            sceneMenu(game);
            break;
        case 3:
            //playmatrix(&snake,3,0);
            //startMenu(game);
            return 1;
        default:
            break;
    }
    modeMenu(game);
    return 0;
}

int modeMenu(myGame<nodeuserinfouser>* game){
    return modeMenuAux(game,startMenuAux(game,mensajeMode,3));
}






