#pragma once

#include <iostream>
#include <unistd.h>
#include <termios.h>

#include "./snakeprint.cpp"
#include "../snake/my_snake.h"
#include "../tools/gameStruct.h"

using namespace std;
extern thread th1;

/**
 * Function that shows the pause menu depending on the game mode
 */
auto mensajePause = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    messageLine(w.ws_col,"Points: "+to_string(game->user->info.Points));
    messageLine(w.ws_col,"Coins: "+to_string(game->user->info.coin));
    messageSteep(w.ws_col);
    messageSteep(w.ws_col);
    switch (game->mode)
    {
    //"Clasico 97" game mode
    case 2:
            (opc==1)? 
            messageLineRED(w.ws_col,"* Regresar al juego *"):              
            messageLine(w.ws_col,"  Regresar al juego  ");
            (opc==2)? 
            messageLineRED(w.ws_col,"* Salir del juego *"):    
            messageLine(w.ws_col,"  Salir del juego  ");
            messageSteep(w.ws_col);
            messageMargin(w.ws_col);
            break;
    
    //Others game modes
    default:
            (opc==1)? 
            messageLineRED(w.ws_col,"* Regresar al juego *"):              
            messageLine(w.ws_col,"  Regresar al juego  ");
            (opc==2)? 
            messageLineRED(w.ws_col,"* Ir ala tienda *"):   
            messageLine(w.ws_col,"  Ir ala tienda  ");
            (opc==3)? 
            messageLineRED(w.ws_col,"* Salir del juego *"):    
            messageLine(w.ws_col,"  Salir del juego  ");
            messageSteep(w.ws_col);
            messageMargin(w.ws_col);
            break;
    }
    
  
}; 
int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* game);
int shopMenu(myGame<nodeuserinfouser>* game);
bool PauseMenu(myGame<nodeuserinfouser>* game);
bool gameOverMenu(myGame<nodeuserinfouser>* game);

/**
 * Function that implements the inner menu options functionality of the pause menu
 */
bool PauseMenuAux(myGame<nodeuserinfouser>* game,int flag){
    switch (game->mode)
    {
    //"Clasico 97" Game mode
    case 2:
            switch (flag) 
            {   
                //Continue playing
                case 1:
                    return true;
                //Exit
                case 2:
                    game->playing = false;
                    return false;  
                default:
                    return true;
            }  
            break;
    //Others Game modes
    default:
            switch (flag) 
            {   
                //Back to game
                case 1:
                    cin.clear();
                    return true;
                //Go to shop menu
                case 2:
                    shopMenu(game);
                    return PauseMenu(game);
                //Exit that game
                case 3:
                    game->playing = false;
                    return false;    
                default:
                    return true;
            };  
            break;
    };
}

/**
 * Function that implements the funtionality of the pause menu and checks the game mode
 */
bool PauseMenu(myGame<nodeuserinfouser>* game){
    switch (game->mode)
    {
    case 2:
            return PauseMenuAux(game,optionSelectionKey(game,mensajePause,2));
            break;
    default:
            return PauseMenuAux(game,optionSelectionKey(game,mensajePause,3));
            break;
    }
}








