#pragma once

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include "./snakeprint.cpp"
#include "./windows_start.cpp"
using namespace std;
struct termios term_over;


//int startMenuAux(node<nodeuserinfouser>* , auto ,int );

auto mensajeGameOverContinued = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    mensageLine(w.ws_col,"Que desea hacer?");
    (opc==1)? mensageLineRED(w.ws_col,"*  Continuar(gastaras una vida) *"):  mensageLine(w.ws_col,"   Continuar(gastaras una vida)  ");
    (opc==2)? mensageLineRED(w.ws_col,"*  REGRESAR  *"):  mensageLine(w.ws_col,"   REGRESAR  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
};
auto mensajeGameOverFinish = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    mensageLine(w.ws_col,"Points: "+to_string(game->snake.points));
    mensageLine(w.ws_col,"Coins: "+to_string(game->user->info.coin));
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    mensageLine(w.ws_col,"Lo sentimos pero perdiste.");
    (opc==1)? mensageLineRED(w.ws_col,"*  REGRESAR *"):  mensageLine(w.ws_col,"   REGRESAR  ");
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
        return gameOverMenuAux(game,optionSelectionKey(game,mensajeGameOverContinued,2));
    }
    gameOverMenuAux(game,optionSelectionKey(game,mensajeGameOverFinish,1));
    return false;
    
}
