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
    (opc==1)? mensageLine(w.ws_col,"*  SNAKE WORLD PARTY  *"):    mensageLine(w.ws_col,"   SNAKE WORLD PARTY   ");
    (opc==2)? mensageLine(w.ws_col,"*  CLASICO 97  *"):    mensageLine(w.ws_col,"   CLASICO 97   ");
    (opc==3)? mensageLine(w.ws_col,"*  ESPECIAL * "):   mensageLine(w.ws_col,"   ESPECIAL   ");
    (opc==4)? mensageLine(w.ws_col,"*  REGRESAR *"):    mensageLine(w.ws_col,"   REGRESAR  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
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
            game->user->info.vidas=game->snake.lifes;
            saveincsv(game->list.front);
            //gameOverMenu(game);
            break;
        case 2:
            //game->scene =  1;
            game->mode = 2;//clasico
            game->food = 1;
            game->scene = 1;
            game->snake.points = 0;
            //difficultyMenu(game);
            playmatrix(game);
            game->user->info.vidas=game->snake.lifes;
            saveincsv(game->list.front);
            //gameOverMenu(game);
            break;
        case 3://especial
            //playmatrix(&snake,2,0);
            game->mode = 3;//especial
            game->snake.points = 0;
            sceneMenu(game);
            game->user->info.vidas=game->snake.lifes;
            saveincsv(game->list.front);
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






