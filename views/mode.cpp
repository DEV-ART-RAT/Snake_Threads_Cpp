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

/**
 * Function that shows the Game mode menu
 */
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

/**
 * Function that implements the mode menu functionality
 */
int modeMenuAux(myGame<nodeuserinfouser>* game,int flag){

    //Saves the game mode in a flag
    game->mode = flag;

    switch (flag) {
        //"World Party" Game mode
        case 1:
            //Inits necesary flags for this game mode
            //Especifies two foods
            game->food = 2;
            //Loads stage one by default
            game->scene = 1;
            //Starts the game
            playmatrix(game);
            saveincsv(game->list.front);
            break;
        //"Clasico 97" game mode
        case 2:
            //game->scene =  1;
            game->mode = 2;
            //Especifies one foor
            game->food = 1;
            //Stage one
            game->scene = 1;
            //Always begins with no points
            game->snake.points = 0;
            //Starts the game
            playmatrix(game);
            saveincsv(game->list.front);
            //gameOverMenu(game);
            break;
        //"Especial" Game mode
        case 3:
            //Inits flags needed for this game mode
            //Starts with no points
            game->snake.points = 0;
            //Loads the stages menu
            sceneMenu(game);
            break;
        case 4:
            //skips this menu
            return 1;
        default:
            break;
    }
    //If the player selects "Regresar" returns this menu
    modeMenu(game);
    return 0;
}

/**
 * Function that calls option selector sending the function to 'listen' from keyboard
 */
int modeMenu(myGame<nodeuserinfouser>* game){
    return modeMenuAux(game,optionSelectionKey(game,mensajeMode,4));
}






