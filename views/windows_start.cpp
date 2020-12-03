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
    (opc==1)? mensageLineRED(w.ws_col,"*  START  *"): mensageLine(w.ws_col,"   START   ");
    (opc==2)? mensageLineRED(w.ws_col,"*  TIENDA * "): mensageLine(w.ws_col,"   TIENDA   ");
    (opc==3)? mensageLineRED(w.ws_col,"*  Ver TOPS  *"): mensageLine(w.ws_col,"   Ver TOPS   ");
    (opc==4)? mensageLineRED(w.ws_col,"*  INSTRUCCIONES * "): mensageLine(w.ws_col,"   INSTRUCCIONES   ");
    (opc==5)? mensageLineRED(w.ws_col,"*  EXIT * "): mensageLine(w.ws_col,"   EXIT   ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);

};

auto mensajeStart = [](int opc, myGame<nodeuserinfouser>* game, int size) { 
    mensageMarginStart(opc,game);
};

//opciones en el menu principal
int startMenuOpc(myGame<nodeuserinfouser>* game, int flag){
    switch (flag) {
        case 1:
            modeMenu(game);//carga el menu de seleccion de tipo de juego
            break;
        case 2:
            shopMenu(game);//carga el menu de tienda
            saveincsv(game->list.front);//actualiza lainformacion del usuario
            break;
        case 3:
            TopMenu(game);//carga el menu de TOP
            break;
        case 4:
            history();//menu que muestra instrucciones de los tipos de juegos
            break;
        case 5:
            quickSort(game->list.front, 0);//ordena la lista de jugadores segun su puntje
            saveincsv(game->list.front);//se guarda la lista ordenada en archivo externo
            mensageLineMAGENTA(w.ws_col,"Se guardo tu progreso!");
            mensageSteep(w.ws_col);
            mensageMargin(w.ws_col);
            exit(EXIT_SUCCESS);//cierra la aplicacion
            break;
        default:
            break;
    }
    startMenu(game);
    return 0;
}

//funcion que llama al selector de opciones mandando la funcion para escuchar el teclado
int startMenu(myGame<nodeuserinfouser>* game){
    startMenuOpc(game,optionSelectionKey(game,mensajeStart,5));
    return 0;
}