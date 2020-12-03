#pragma once

#include <iostream>

#include <unistd.h>
#include <termios.h>

#include "./difficulty.cpp"
#include "../snake/my_snake.h"
#include "../tools/gameStruct.h"
using namespace std;

/**
 * Function that shows the "Especial" game mode options
 */
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
int sceneMenu(myGame<nodeuserinfouser>* );

/**
 * Function that implements the stage selection menu
 */
int sceneMenuAux(myGame<nodeuserinfouser>* game,int flag,int size){

    //Saves the stage number to load
    game->scene =  flag;
    
    //Checks if options selected is not "Regresar"
    if(flag != size){
        //Loads the difficulty selection menu
        difficultyMenu(game);
    }
    //If the option selected is go back
    if(flag == size){
        //Returns previous menu
        return 1;
    }
    //Charges this menu again from a later menu
    sceneMenu(game);
    return 0;
}

/**
 * Function that calls options menu selector sending a function to 'listen' from keyboard
 */
int sceneMenu(myGame<nodeuserinfouser>* game){
    //Default options number
    int opciones = 3;
    //Adds total of stages loaded from files to the options
    opciones += game->sceneList.size();
    
    return sceneMenuAux(game,optionSelectionKey(game,mensajeScene,opciones),opciones);
}






