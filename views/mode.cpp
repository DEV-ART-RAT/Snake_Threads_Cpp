#pragma once

#include <iostream>

#include <unistd.h>
#include <termios.h>

#include "./scene.cpp"
#include "./difficulty.cpp"
#include "../tools/saveUser.h"
#include "../snake/my_snake.h"
#include "../tools/gameStruct.h"

using namespace std;

auto mensajeMode = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    (opc==1)? messageLineRED(w.ws_col,"*  SNAKE WORLD PARTY  *"):    messageLine(w.ws_col,"   SNAKE WORLD PARTY   ");
    (opc==2)? messageLineRED(w.ws_col,"*  Clasic 97  *"):    messageLine(w.ws_col,"   Clasic 97   ");
    (opc==3)? messageLineRED(w.ws_col,"*  ESPECIAL * "):   messageLine(w.ws_col,"   ESPECIAL   ");
    (opc==4)? messageLineRED(w.ws_col,"*  REGRESAR *"):    messageLine(w.ws_col,"   REGRESAR  ");
    messageSteep(w.ws_col);
    messageMargin(w.ws_col);
};

int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* );
int sceneMenu(myGame<nodeuserinfouser>* );
int playmatrix(myGame<nodeuserinfouser>* );
int modeMenu(myGame<nodeuserinfouser>* );


int modeMenuAux(myGame<nodeuserinfouser>* game,int flag){

    switch (flag) {
        case 1:
            //game->scene =  1;
            game->mode = 1;//world
            game->food = 2;
            game->scene = 1;
            //difficultyMenu(game);
            playmatrix(game);
            //gameOverMenu(game);
            break;
        case 2:
            //game->scene =  1;
            game->mode = 2;//Clasic
            game->food = 1;
            game->scene = 1;
            game->snake.points = 0;
            //difficultyMenu(game);
            playmatrix(game);
            //gameOverMenu(game);
            break;
        case 3://especial
            //playmatrix(&snake,2,0);
            game->mode = 3;//especial
            game->snake.points = 0;
            sceneMenu(game);
            break;
        case 4:
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
    return modeMenuAux(game,optionSelectionKey(game,mensajeMode,4));
}






