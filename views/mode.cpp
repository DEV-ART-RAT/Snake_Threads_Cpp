#pragma once

#include <iostream>

#include <unistd.h>
#include <termios.h>

#include "./scene.cpp"
#include "./difficulty.cpp"
#include "../tools/saveUser.h"
#include "../snake/my_snake.h"
#include "../tools/gameStruct.h"

using namespace std;

auto mensajeMode = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    (opc==1)? mensageLineRED(w.ws_col,"*  SNAKE WORLD PARTY  *"):    mensageLine(w.ws_col,"   SNAKE WORLD PARTY   ");
    (opc==2)? mensageLineRED(w.ws_col,"*  CLASICO 97  *"):    mensageLine(w.ws_col,"   CLASICO 97   ");
    (opc==3)? mensageLineRED(w.ws_col,"*  ESPECIAL * "):   mensageLine(w.ws_col,"   ESPECIAL   ");
    (opc==4)? mensageLineRED(w.ws_col,"*  REGRESAR *"):    mensageLine(w.ws_col,"   REGRESAR  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
};

int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* );
int sceneMenu(myGame<nodeuserinfouser>* );
int playmatrix(myGame<nodeuserinfouser>* );
int modeMenu(myGame<nodeuserinfouser>* );


int modeMenuAux(myGame<nodeuserinfouser>* game,int flag){

    game->mode = flag;//se guarda el modo de juego en una bandera escencial

    switch (flag) {
        case 1://modo de juego "WORLD"
            //se inicializan banderas necesarias para este modo
            game->food = 2;//considerando un escenario muy especifico se decide en este juego enplear 2 "comidas"
            game->scene = 1;//se carga por defecto el escenario 1
            playmatrix(game);//inicia el juego
            break;
        case 2://modo de juego "CLASICO"
            //se inicializan banderas necesarias para este modo
            game->food = 1;//en este modo solo existira una comida a la vez
            game->scene = 1;//se jugara son en el esenario 1
            game->snake.points = 0;//siempre se inicia con una puntuacion de cero
            playmatrix(game);//inicia el juego
            break;
        case 3://modo de juego "ESPECIAL"
            //se inicializan banderas necesarias para este modo
            game->snake.points = 0;//siempre se inicia con una puntuacion de cero
            sceneMenu(game);//se carga el menu de escenarios
            break;
        case 4:
            return 1;//se escapa de este menu
        default:
            break;
    }
    modeMenu(game);//si se regresa de una opcion posterior se vuelve a cargar este menu
    return 0;
}

//funcion que llama al selector de opciones mandando la funcion para escuchar el teclado
int modeMenu(myGame<nodeuserinfouser>* game){
    return modeMenuAux(game,optionSelectionKey(game,mensajeMode,4));
}






