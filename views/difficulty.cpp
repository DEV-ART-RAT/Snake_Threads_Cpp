#pragma once

#include <iostream>

#include <unistd.h>
#include <termios.h>

#include "../snake/my_snake.h"
#include "../tools/nodeuser.h"
using namespace std;

/**
 * Function that shows the dificulty menu options
 */
auto mensajeDifficulty = [](int opc,myGame<nodeuserinfouser>* userdata,int size) { 
    CLEAR;
    snakeprint();
    (opc==1)? messageLineRED(w.ws_col,"*  FACIL  *"):    messageLine(w.ws_col,"   FACIL   ");
    (opc==2)? messageLineRED(w.ws_col,"*  MEDIO * "):    messageLine(w.ws_col,"   MEDIO   ");
    (opc==3)? messageLineRED(w.ws_col,"*  DIFICIL *"):   messageLine(w.ws_col,"   DIFICIL  ");
    (opc==4)? messageLineRED(w.ws_col,"*  REGRESAR *"):  messageLine(w.ws_col,"   REGRESAR  ");
    messageSteep(w.ws_col);
    messageMargin(w.ws_col);
};

int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* );
int playmatrix(myGame<nodeuserinfouser>* );
int difficultyMenu(myGame<nodeuserinfouser>* );

/**
 * Function that shows the dificulty menu options
 */
int difficultyMenuAuxOpc(myGame<nodeuserinfouser>* game,int flag){
    //Inits special difficulty
    game->difficulty = flag;

    //Inits special stage (3 level by difficulty)
    game->levelSpecial = 1;

    //Inits lifes in special mode (3 lifes)
    game->liveSpecial = 3;

    //Special stage points
    game->snake.points = 0;

    //Number of food
    game->food = 2;

    switch (flag) {
        /*case 1:
            playmatrix(game);
            break;
        case 2:
            playmatrix(game);
            break;
        case 3:
            playmatrix(game);
            break;*/
        case 4:
            return 1;
        default:
            playmatrix(game);
            break;
    }
    difficultyMenu(game);
    return 0;
}

/**
 * Function that calls function above
 */
int difficultyMenu(myGame<nodeuserinfouser>* game){
    return difficultyMenuAuxOpc(game,optionSelectionKey(game,mensajeDifficulty,4));
}






