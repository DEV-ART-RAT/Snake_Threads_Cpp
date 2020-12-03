#pragma once

#include <iostream>
#include <unistd.h>
#include <termios.h>

#include "./snakeprint.cpp"
#include "../snake/my_snake.h"
#include "../tools/gameStruct.h"

using namespace std;

auto mensajeShop = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    messageLine(w.ws_col,"Coins: "+to_string(game->user->info.coin));
    if(game->snake.x2Boosted || game->snake.x3Boosted){
        messageLine(w.ws_col,"Potenciador Activo: x" + to_string((game->snake.x3Boosted)? 3:2) );
    }
    messageSteep(w.ws_col);
    messageSteep(w.ws_col);
    (opc==1)? messageLineRED(w.ws_col,"*  Vida Extra (200 monedas)  *"):              
        messageLine(w.ws_col,"   Vida Extra (200 monedas)   ");
    (opc==2)? messageLineRED(w.ws_col,"*  Potenciar Points x2 (500 monedas) * "):   
        messageLine(w.ws_col,"   Potenciar Points x2 (500 monedas)   ");
    (opc==3)? messageLineRED(w.ws_col,"*  Potenciar Points x3 (1000 monedas) *"):    
        messageLine(w.ws_col,"   Potenciar Points x3 (1000 monedas)  ");
    (opc==4)? messageLineRED(w.ws_col,"*  REGRESAR *"):    
        messageLine(w.ws_col,"   REGRESAR  ");
    messageSteep(w.ws_col);
    messageMargin(w.ws_col);
}; 

int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* game);
int shopMenu(myGame<nodeuserinfouser>* game);

void boostPointsx2(myGame<nodeuserinfouser>* game){
	if(!game->snake.x2Boosted && !game->snake.x3Boosted && game->user->info.coin >= 500){
		game->snake.x2Boosted = true;
        game->user->info.coin -= 500;
		messageLine(w.ws_col,"Points potenciado x2");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
	}else if(game->snake.x2Boosted || game->snake.x3Boosted){
		messageLine(w.ws_col,"Un potenciador ya habia sido activado");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
	} else {
		messageLine(w.ws_col,"Monedas insuficientes");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
    }
}

void boostPointsx3(myGame<nodeuserinfouser>* game){
	if(!game->snake.x2Boosted && !game->snake.x3Boosted && game->user->info.coin >=1000){
		game->snake.x3Boosted = true;
        game->user->info.coin -= 1000;
		messageLine(w.ws_col,"Points potenciado x3");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
	}else if(game->snake.x2Boosted || game->snake.x3Boosted){
		messageLine(w.ws_col,"Un potenciador ya habia sido activado");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
	} else {
		messageLine(w.ws_col,"Monedas insuficientes");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
    }
}

void buyLife(myGame<nodeuserinfouser>* game){
    if(game->user->info.coin >= 200){
        game->user->info.coin -= 200;
        game->snake.lifes++;
        messageLine(w.ws_col,"Vida comprada");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
    } else {
        messageLine(w.ws_col,"Monedas insuficientes");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
    }
}



int shopMenuAux(myGame<nodeuserinfouser>* game,int flag){

    //mySnake snake = mySnake();

    //bool x2Boosted = false, x3Boosted = false; //Espero que temporalmente aqui
    switch (flag) {
        case 1:
            buyLife(game);
            //sleep(1);
            //shopMenu(userdata,userlist);
            break;
        case 2:
            boostPointsx2(game);
            break;
        case 3:
            boostPointsx3(game);
            //sleep(1);
            //shopMenu(flag, userdata);
            break;
        case 4:
            //welcomemain(userdata);
            //startMenuOpc(userdata,startMenu(userdata,userlist),userlist);
            return 0;
        default:
            break;
    }
    sleep(1);
    shopMenu(game);

    return 0;
}

int shopMenu(myGame<nodeuserinfouser>* game){
    return shopMenuAux(game,optionSelectionKey(game,mensajeShop,4));
}








