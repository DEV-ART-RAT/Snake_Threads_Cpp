#pragma once

#include <iostream>
#include <unistd.h>
#include <termios.h>

#include "./snakeprint.cpp"
#include "../snake/my_snake.h"
#include "../tools/gameStruct.h"

using namespace std;
extern thread th1;

auto mensajePause = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    mensageLine(w.ws_col,"Points: "+to_string(game->user->info.puntaje));
    mensageLine(w.ws_col,"Coins: "+to_string(game->user->info.coin));
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    (opc==1)? 
    mensageLine(w.ws_col,"* Regresar al juego *"):              
    mensageLine(w.ws_col,"  Regresar al juego  ");
    if(game->mode!=2){
        (opc==2)? 
        mensageLine(w.ws_col,"* Ir ala tienda *"):   
        mensageLine(w.ws_col,"  Ir ala tienda  ");
        (opc==3)? 
        mensageLine(w.ws_col,"* Salir del juego *"):    
        mensageLine(w.ws_col,"  Salir del juego  ");
        mensageSteep(w.ws_col);
        mensageMargin(w.ws_col);
    }else{
        (opc==2)? 
        mensageLine(w.ws_col,"* Salir del juego *"):    
        mensageLine(w.ws_col,"  Salir del juego  ");
        mensageSteep(w.ws_col);
        mensageMargin(w.ws_col);
    }
  
}; 
int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* game);
int shopMenu(myGame<nodeuserinfouser>* game);
bool PauseMenu(myGame<nodeuserinfouser>* game);
bool gameOverMenu(myGame<nodeuserinfouser>* game);

bool PauseMenuAux(myGame<nodeuserinfouser>* game,int flag){
    switch (flag) {
            case 1:
                return true;
            case 2:
                if(game->mode!=2)
                {
                    shopMenu(game);
                    return PauseMenu(game);
                }else{
                    game->playing = false;
                    return false;                   
                }
            case 3:
                game->playing = false;
                return false;
            default:
                return true;
    }

}

bool PauseMenu(myGame<nodeuserinfouser>* game){
    if(game->mode!=2)
        return PauseMenuAux(game,optionSelectionKey(game,mensajePause,3));
    else
        return PauseMenuAux(game,optionSelectionKey(game,mensajePause,2));
}








