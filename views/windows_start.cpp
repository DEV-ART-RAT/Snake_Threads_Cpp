#pragma once
#include <iostream>

#include <unistd.h>

#include "./shop.cpp"
#include "./top.cpp"
#include "./mode.cpp"
#include "./game_over.cpp"
#include "./snakeprint.cpp"
#include "../snake/clear.cpp"
#include "../snake/matriz.cpp"
#include "../snake/keyEvent.h"
#include "../tools/saveUser.h"
#include "../tools/gameStruct.h"

using namespace std;

int welcomemain(int &P,int&C,string user);
int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );

void mensageMarginStart(int opc, myGame<nodeuserinfouser>* game) { 
    CLEAR;
    mensageMargin(w.ws_col);
    mensageSteep(w.ws_col);
    string linea1 =  "WELLCOME " + game->user->info.name + "  TO ...";
    mensageLineMAGENTA(w.ws_col,linea1);
    string linea2[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    mensageSteep(w.ws_col);
    mensageSnake(w.ws_col,linea2 , 5);
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    print_user(game);
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    (opc==1)? mensageLine(w.ws_col,"*  START  *"): mensageLine(w.ws_col,"   START   ");
    (opc==2)? mensageLine(w.ws_col,"*  TIENDA * "): mensageLine(w.ws_col,"   TIENDA   ");
    (opc==3)? mensageLine(w.ws_col,"*  TOP WORLD PARTY  *"): mensageLine(w.ws_col,"   TOP WORLD PARTY   ");
    (opc==4)? mensageLine(w.ws_col,"*  TOP CLASICO  *"): mensageLine(w.ws_col,"   TOP CLASICO   ");
    (opc==5)? mensageLine(w.ws_col,"*  INSTRUCCIONES * "): mensageLine(w.ws_col,"   INSTRUCCIONES   ");
    (opc==6)? mensageLine(w.ws_col,"*  EXIT * "): mensageLine(w.ws_col,"   EXIT   ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);

};

auto mensajeStart = [](int opc, myGame<nodeuserinfouser>* game, int size) { 
    mensageMarginStart(opc,game);
};

int startMenuOpc(myGame<nodeuserinfouser>* game, int flag){
    switch (flag) {
        case 1:
            //cout<<"new game start :v"<<endl;
            //playmatrix(&snake);
            modeMenu(game);
            saveincsv(game->list.front);
            //playmatrix(&snake);
            // loop=false; //para que termine el juego sin que se regrese al menu :
            break;
        case 2:
            shopMenu(game);
            saveincsv(game->list.front);
            break;
        case 3:
        //Puntuacion World party
            quickSort(game->list.front, 1);
            saveincsv(game->list.front);
            top_game(game);
            saveincsv(game->list.front);
            //startMenu(game);
            break;
        case 4:
        //Puntuacion Clasico
            quickSort(game->list.front, 3);
            saveincsv(game->list.front);
            top_game(game);
            saveincsv(game->list.front);
            //startMenu(game);
            break;
        case 5:
            history();
            //startMenu(game);
            break;
        case 6:
            quickSort(game->list.front, 0);
            saveincsv(game->list.front);
            mensageLineMAGENTA(w.ws_col,"Se guardo tu progreso!");
            mensageSteep(w.ws_col);
            mensageMargin(w.ws_col);
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
    startMenu(game);
    return 0;
}

int startMenu(myGame<nodeuserinfouser>* game){
    startMenuOpc(game,optionSelectionKey(game,mensajeStart,6));
    return 0;
}