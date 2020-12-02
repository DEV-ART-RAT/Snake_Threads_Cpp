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
    mensageLine(w.ws_col,"Coins: "+to_string(game->user->info.coin));
    if(game->snake.x2Boosted || game->snake.x3Boosted){
        mensageLine(w.ws_col,"Potenciador Activo: x" + to_string((game->snake.x3Boosted)? 3:2) );
    }
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    (opc==1)? mensageLine(w.ws_col,"*  Vida Extra (200 monedas)  *"):              
        mensageLine(w.ws_col,"   Vida Extra (200 monedas)   ");
    (opc==2)? mensageLine(w.ws_col,"*  Potenciar puntaje x2 (500 monedas) * "):   
        mensageLine(w.ws_col,"   Potenciar puntaje x2 (500 monedas)   ");
    (opc==3)? mensageLine(w.ws_col,"*  Potenciar puntaje x3 (1000 monedas) *"):    
        mensageLine(w.ws_col,"   Potenciar puntaje x3 (1000 monedas)  ");
    (opc==4)? mensageLine(w.ws_col,"*  REGRESAR *"):    
        mensageLine(w.ws_col,"   REGRESAR  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
}; 

int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* game);
int shopMenu(myGame<nodeuserinfouser>* game);

void boostPointsx2(myGame<nodeuserinfouser>* game){
	if(!game->snake.x2Boosted && !game->snake.x3Boosted && game->user->info.coin >= 500){
		game->snake.x2Boosted = true;
        game->user->info.coin -= 500;
		cout<<"Puntaje potenciado x2"<<endl;
	}else if(game->snake.x2Boosted || game->snake.x3Boosted){
		cout<<"Un potenciador ya habia sido activado"<<endl;
	} else {
		cout<<"Monedas insuficientes"<<endl;
    }
}

void boostPointsx3(myGame<nodeuserinfouser>* game){
	if(!game->snake.x2Boosted && !game->snake.x3Boosted && game->user->info.coin >=1000){
		game->snake.x3Boosted = true;
        game->user->info.coin -= 1000;
		cout<<"Puntaje potenciado x3"<<endl;
	}else if(game->snake.x2Boosted || game->snake.x3Boosted){
		cout<<"Un potenciador ya habia sido activado"<<endl;
	} else {
		cout<<"Monedas insuficientes"<<endl;
    }
}

void buyLife(node<nodeuserinfouser>* userdata){
    if(userdata->info.coin >= 200){
        userdata->info.coin -= 200;
        userdata->info.vidas++;
        cout<<"Vida comprada"<<endl;
    } else {
        cout<<"Monedas insuficientes"<<endl;
    }
}



int shopMenuAux(myGame<nodeuserinfouser>* game,int flag){

    //mySnake snake = mySnake();

    //bool x2Boosted = false, x3Boosted = false; //Espero que temporalmente aqui
    switch (flag) {
        case 1:
            buyLife(game->user);
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








