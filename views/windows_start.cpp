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
    (opc==3)? mensageLine(w.ws_col,"*  TOP  *"): mensageLine(w.ws_col,"   TOP   ");
    (opc==4)? mensageLine(w.ws_col,"*  EXIT * "): mensageLine(w.ws_col,"   EXIT   ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);

};

auto mensajeStart = [](int opc, myGame<nodeuserinfouser>* game) { 
    mensageMarginStart(opc,game);
};

int startMenuAux(myGame<nodeuserinfouser>* game, auto wellcome,int sizeOption){
    char key; //contenedor de tecla
    int flag = 1;       //opcion actual del menu
    //int sizeOption=3;   //numero total de opciones en el menu
    bool loop = true;   //bandera para el while true
    sleep(0.1);//para corregir fallo de while
    wellcome(flag,game);  //invocacion del menu
    cin.ignore();
    sleep(0.1);//para corregir fallo de whiles
    while(loop){
        key=getchar();//up:65 down:66 o B left:68 rigth:67
        if(key==65 ){
            if(flag > 1){
                flag--;
            }
        }
        if(  key=='B'){
            if(flag < sizeOption){
                flag++;
            }
        }
        if( key=='\n'){
            return flag;
        }
        wellcome(flag,game);
        sleep(0.01);//para corregir fallo de while
    }
    cin.ignore();

    return 0;
}

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
            quickSort(game->list.front, 1);
            saveincsv(game->list.front);
            top_game(game);
            //startMenu(game);
            break;
        case 4:
            quickSort(game->list.front, 1);
            saveincsv(game->list.front);
            cout<<"Se guardo tu progreso!"<<endl;
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
    startMenu(game);
    return 0;
}

int startMenu(myGame<nodeuserinfouser>* game){
    startMenuOpc(game,startMenuAux(game,mensajeStart,4));
    return 0;
}