#pragma once
#include <iostream>
#include <termios.h>
#include <unistd.h>

//#include "../snake/clear.cpp"
//#include "../snake/matriz.cpp"
#include "../snake/my_snake.h"
#include "../tools/gameStruct.h"
#include "./difficulty.cpp"
using namespace std;

auto mensajeScene = [](int opc,node<nodeuserinfouser>* userdata) { 
    CLEAR;
 mensageMargin(w.ws_col);
    mensageSteep(w.ws_col);

    string linea1[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    mensageSteep(w.ws_col);
    mensageSnake(w.ws_col,linea1 , 5);
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
     (opc==1)? mensageLine(w.ws_col,"*  LIBRE  *"):    mensageLine(w.ws_col,"   LIBRE   ");
    (opc==2)? mensageLine(w.ws_col,"*  CERRADO * "):   mensageLine(w.ws_col,"   CERRADO   ");
    (opc==3)? mensageLine(w.ws_col,"*  REGRESAR *"):    mensageLine(w.ws_col,"   REGRESAR  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
};

int startMenuAux(node<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* );
int sceneMenu(myGame<nodeuserinfouser>* );


int sceneMenuAux(myGame<nodeuserinfouser>* game,int flag){

    //mySnake snake = mySnake();
    game->scene =  flag;
    //game->levelSpecial = 1;
    switch (flag) {
        case 1:
            difficultyMenu(game);
            break;
        case 2://especial
            //playmatrix(&snake,2,0);
            difficultyMenu(game);
            break;
        case 3:
            //playmatrix(&snake,3,0);
            return 1;
        default:
            break;
    }
    sceneMenu(game);
    return 0;
}

int sceneMenu(myGame<nodeuserinfouser>* game){
    return sceneMenuAux(game,startMenuAux(game->user,mensajeScene,3));
}






