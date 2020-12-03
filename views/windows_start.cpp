#pragma once
#include <iostream>

#include <unistd.h>

#include "./shop.cpp"
#include "./top.cpp"
#include "./mode.cpp"
#include "./game_over.cpp"
#include "./snakeprint.cpp"
#include "../tools/clear.cpp"
#include "../snake/play_game_snake.cpp"
#include "../snake/keyEvent.h"
#include "../tools/saveUser.h"
#include "../tools/gameStruct.h"

using namespace std;

int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );

/**
 * Function that shows the initial menu to a player who inserted the name
 */
void messageMarginStart(int opc, myGame<nodeuserinfouser>* game) { 
    CLEAR;
    messageMargin(w.ws_col);
    messageSteep(w.ws_col);
    string linea1 =  "WELLCOME " + game->user->info.name + "  TO ...";
    messageLineMAGENTA(w.ws_col,linea1);
    string linea2[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    messageSteep(w.ws_col);
    messageSnake(w.ws_col,linea2 , 5);
    messageSteep(w.ws_col);
    messageSteep(w.ws_col);
    print_user(game);
    messageSteep(w.ws_col);
    messageSteep(w.ws_col);
    (opc==1)? messageLineRED(w.ws_col,"*  START  *"): messageLine(w.ws_col,"   START   ");
    (opc==2)? messageLineRED(w.ws_col,"*  TIENDA * "): messageLine(w.ws_col,"   TIENDA   ");
    (opc==3)? messageLineRED(w.ws_col,"*  Ver TOPS  *"): messageLine(w.ws_col,"   Ver TOPS   ");
    (opc==4)? messageLineRED(w.ws_col,"*  INSTRUCCIONES * "): messageLine(w.ws_col,"   INSTRUCCIONES   ");
    (opc==5)? messageLineRED(w.ws_col,"*  EXIT * "): messageLine(w.ws_col,"   EXIT   ");
    messageSteep(w.ws_col);
    messageMargin(w.ws_col);

};

/**
 * Function that calls the initial screen or menu
 */
auto mensajeStart = [](int opc, myGame<nodeuserinfouser>* game, int size) { 
    messageMarginStart(opc,game);
};

/**
 * Function that implements the functionality of the main menu
 */
int startMenuOpc(myGame<nodeuserinfouser>* game, int flag){
    switch (flag) {
        case 1:
            //Loads the game mode selection menu
            modeMenu(game);
            break;
        case 2:
            //Loads the shop menu
            shopMenu(game);
            //Updates user's info
            saveincsv(game->list.front);
            break;
        case 3:
            //Loads the top menu
            TopMenu(game);
            break;
        case 4:
            //Shows the initial history and instructions
            history();
            break;
        case 5:
            //Sorts users name by name
            quickSort(game->list.front, 7,&game->user);
            //Saves the list in the external file
            saveincsv(game->list.front);
            messageLineMAGENTA(w.ws_col,"Se guardo tu progreso!");
            messageSteep(w.ws_col);
            messageMargin(w.ws_col);
            //Closes the program
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
    //Returns to the start menu
    startMenu(game);
    return 0;
}

/**
 * Function that calls the option selector sending a function to 'listen' from the keyboard
 */
int startMenu(myGame<nodeuserinfouser>* game){
    startMenuOpc(game,optionSelectionKey(game,mensajeStart,5));
    return 0;
}