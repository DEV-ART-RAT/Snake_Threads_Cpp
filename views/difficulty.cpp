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
    (opc==1)? mensageLineRED(w.ws_col,"*  FACIL  *"):    mensageLine(w.ws_col,"   FACIL   ");
    (opc==2)? mensageLineRED(w.ws_col,"*  MEDIO * "):    mensageLine(w.ws_col,"   MEDIO   ");
    (opc==3)? mensageLineRED(w.ws_col,"*  DIFICIL *"):   mensageLine(w.ws_col,"   DIFICIL  ");
    (opc==4)? mensageLineRED(w.ws_col,"*  REGRESAR *"):  mensageLine(w.ws_col,"   REGRESAR  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
};

int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* );
int playmatrix(myGame<nodeuserinfouser>* );
int difficultyMenu(myGame<nodeuserinfouser>* );


int difficultyMenuAuxOpc(myGame<nodeuserinfouser>* game,int flag){

    game->difficulty = flag;//inciando dificultad especial

    game->levelSpecial = 1;//inicando escenario especial (3 niveles por dificultad);
    game->liveSpecial = 3;//iniciando vidads especial (3 vidas);
    game->snake.points = 0;//escenario especial -> puntos -> monedas
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

int difficultyMenu(myGame<nodeuserinfouser>* game){
    return difficultyMenuAuxOpc(game,optionSelectionKey(game,mensajeDifficulty,4));
}






