#pragma once

#include <iostream>

#include <unistd.h>
#include <termios.h>

#include "../snake/my_snake.h"
#include "../tools/nodeuser.h"
using namespace std;

auto mensajeDifficulty = [](int opc,myGame<nodeuserinfouser>* userdata,int size) { 
    CLEAR;
    snakeprint();
    (opc==1)? mensageLine(w.ws_col,"*  FACIL  *"):    mensageLine(w.ws_col,"   FACIL   ");
    (opc==2)? mensageLine(w.ws_col,"*  MEDIO * "):    mensageLine(w.ws_col,"   MEDIO   ");
    (opc==3)? mensageLine(w.ws_col,"*  DIFICIL *"):   mensageLine(w.ws_col,"   DIFICIL  ");
    (opc==4)? mensageLine(w.ws_col,"*  REGRESAR *"):  mensageLine(w.ws_col,"   REGRESAR  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
};

int startMenuAux(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* );
int playmatrix(myGame<nodeuserinfouser>* );
int difficultyMenu(myGame<nodeuserinfouser>* );


int difficultyMenuAuxOpc(myGame<nodeuserinfouser>* game,int flag){

    game->difficulty = flag;//inciando dificultad especial
    game->levelSpecial = 1;//inicando escenario especial
    game->liveSpecial = 3;//iniciando vidads especial
    game->snake.points = 0;
    switch (flag) {
        case 1:
            
            playmatrix(game);
            break;
        case 2:
            playmatrix(game);
            break;
        case 3:
            playmatrix(game);
            break;
        case 4:
            return 1;
        default:
            break;
    }
    difficultyMenu(game);
    return 0;
}

int difficultyMenu(myGame<nodeuserinfouser>* game){
    return difficultyMenuAuxOpc(game,startMenuAux(game,mensajeDifficulty,4));
}






