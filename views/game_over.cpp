#pragma once

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include "./snakeprint.cpp"
#include "./windows_start.cpp"
using namespace std;
struct termios term_over;

/**
 * Function that shows the game over menu options
 */
auto mensajeGameOverContinued = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    messageLine(w.ws_col,"Que desea hacer?");
    (opc==1)? messageLineRED(w.ws_col,"*  Continuar(gastaras una vida) *"):  messageLine(w.ws_col,"   Continuar(gastaras una vida)  ");
    (opc==2)? messageLineRED(w.ws_col,"*  REGRESAR  *"):  messageLine(w.ws_col,"   REGRESAR  ");
    messageSteep(w.ws_col);
    messageMargin(w.ws_col);
};

/**
 * Function that shows the message when there are no more lifes
 */
auto mensajeGameOverFinish = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    messageLine(w.ws_col,"Points: "+to_string(game->snake.points));
    messageLine(w.ws_col,"Coins: "+to_string(game->user->info.coin));
    messageSteep(w.ws_col);
    messageSteep(w.ws_col);
    messageLine(w.ws_col,"Lo sentimos pero perdiste.");
    (opc==1)? messageLineRED(w.ws_col,"*  REGRESAR *"):  messageLine(w.ws_col,"   REGRESAR  ");
    messageSteep(w.ws_col);
    messageMargin(w.ws_col);
};

/**
 * Function that implements game over menu functionality
 */
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

/**
 * Function that checks if player's lifes are done
 */
bool gameOverMenu(myGame<nodeuserinfouser>* game){
    if(game->snake.lifes > 0){
        return gameOverMenuAux(game,optionSelectionKey(game,mensajeGameOverContinued,2));
    }
    gameOverMenuAux(game,optionSelectionKey(game,mensajeGameOverFinish,1));
    return false;
    
}
