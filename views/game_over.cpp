#pragma once

#include <iostream>
#include <termios.h>
#include <unistd.h>
//#include "../snake/keyEvent.h"
#include "./windows_start.cpp"
//#include "../tools/gameStruct.h"
#include "./snakeprint.cpp"
using namespace std;
struct termios term_over;


//int startMenuAux(node<nodeuserinfouser>* , auto ,int );

auto mensajeGameOverContinued = [](int opc,myGame<nodeuserinfouser>* game) { 
    CLEAR;
    snakeprint();
    mensageLine(w.ws_col,"Que desea hacer?");
    (opc==1)? mensageLine(w.ws_col,"*  Continar(gastaras una vida) *"):  mensageLine(w.ws_col,"   Continar(gastaras una vida)  ");
    (opc==2)? mensageLine(w.ws_col,"*  REGRESAR *"):  mensageLine(w.ws_col,"   REGRESAR  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
};
auto mensajeGameOverFinish = [](int opc,myGame<nodeuserinfouser>* game) { 
    CLEAR;
    snakeprint();
    mensageLine(w.ws_col,"Points: "+to_string(game->user->info.puntaje));
    mensageLine(w.ws_col,"Coins: "+to_string(game->user->info.coin));
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    mensageLine(w.ws_col,"Lo sentimos pero perdiste.");
    (opc==1)? mensageLine(w.ws_col,"*  REGRESAR *"):  mensageLine(w.ws_col,"   REGRESAR  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
};

int gameOverMenuAux(myGame<nodeuserinfouser>* game, int flag) {
    switch (flag) {
        case 1:
            game->snake.lifes--;
            return true;
        case 2:
            delete(game->snake.M);
            delete(game->snake.list);
            game->snake.sizeSnake = 3;
            return false;
        default:
            return false;
    }
};

bool gameOverMenu(myGame<nodeuserinfouser>* game){
    if(game->snake.lifes > 0){
        return gameOverMenuAux(game,startMenuAux(game,mensajeGameOverContinued,2));
    }
    gameOverMenuAux(game,startMenuAux(game,mensajeGameOverFinish,1));
    return false;
    
}
