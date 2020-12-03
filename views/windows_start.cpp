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

auto mensajeStart = [](int opc, myGame<nodeuserinfouser>* game, int size) { 
    messageMarginStart(opc,game);
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
            quickSort(game->lista_ordenar.front, 0);//ordena la lista de jugadores segun su puntje
            saveincsv(game->list.front);//se guarda la lista ordenada en archivo externo
            messageLineMAGENTA(w.ws_col,"Se guardo tu progreso!");
            messageSteep(w.ws_col);
            messageMargin(w.ws_col);
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