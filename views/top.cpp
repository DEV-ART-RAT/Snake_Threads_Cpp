#pragma once

#include <string>
#include <ostream>
#include <iomanip>
#include <iostream>

#include "../tools/list.h"
#include "./snakeprint.cpp"
#include "../tools/clear.cpp"

using namespace std;
void top_game(myGame<nodeuserinfouser>* game);
void welcometop();
void ordenarparametros(int colsize,int sobraparallegar);
template<class T>
void printtop(node<T>* front,int colsize,int sobraparallegar);
void printtopaux(doubleLinked<nodeuserinfouser>* userlist);
bool TopMenuAux(myGame<nodeuserinfouser>* game,int flag);
bool TopMenu(myGame<nodeuserinfouser>* );


/**
 * Function that shows the top menu options
 */
auto mensajeTOPS = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    messageLine(w.ws_col,"Points: "+to_string(game->user->info.Points));
    messageLine(w.ws_col,"Coins: "+to_string(game->user->info.coin));
    messageSteep(w.ws_col);
    messageSteep(w.ws_col);
    (opc==1)? 
    messageLineRED(w.ws_col,"* TOP Ordenado por World Party *"):   
    messageLine(w.ws_col,"  TOP Ordenado por World Party  ");
    (opc==2)? 
    messageLineRED(w.ws_col,"* TOP Ordenado por Clasic 97 *"):    
    messageLine(w.ws_col,"  TOP Ordenado por Clasic 97  ");
    (opc==3)? 
    messageLineRED(w.ws_col,"* Regresar *"):    
    messageLine(w.ws_col,"  Regresar  ");
    messageSteep(w.ws_col);
    messageMargin(w.ws_col);
};

/**
 * Function that implements the top menu options functionality
 */
bool TopMenuAux(myGame<nodeuserinfouser>* game,int flag){
    switch (flag) {
            //Sort by "World party" game mode score
            case 1:
                quickSort(game->list.front, 1,&game->user);
                top_game(game);
                TopMenu(game);      
                return false; 
            //Sort by "Clasico 97" game mode score
            case 2:
                quickSort(game->list.front, 3,&game->user);
                top_game(game);
                TopMenu(game);
                return false;
            //GO back
            case 3:
                return true;
            default:
                return true;
    }

}

/**
 * Function that shows the top players
 */
void top_game(myGame<nodeuserinfouser>* game){
    welcometop();
    printtopaux(&game->list);
    cin.clear();
    messageLine(w.ws_col,"presiona una tecla para continuar");
    getchar();
    return;
};

/**
 * Function that calls the top menu
 */
void welcometop(){
    CLEAR;
    //gets terminal size
    winsize w = screenSize();
    snakeprint();

}

/**
 * Function that is used to print the top table
 */
template<class T>
void printtop(node<T>* front,int colsize,int sobraparallegar){
    int tamaniotabla=w.ws_col-2;
    if(tamaniotabla<120){
        tamaniotabla=120;
    }
    if(front) {
        messageLineSeccionAux(colsize,front->info.name,0,sobraparallegar);
        messageLineSeccionAux(colsize,to_string(front->info.nivel),1,sobraparallegar);
        messageLineSeccionAux(colsize,to_string(front->info.Points),1,sobraparallegar);
        messageLineSeccionAux(colsize,to_string(front->info.PointsClasic),-1,sobraparallegar);
        messageMargin(tamaniotabla+2);
        printtop(front->next,colsize,sobraparallegar);
    }
}

/**
 * Function that creates the table of the top
 */
void printtopaux(doubleLinked<nodeuserinfouser>* userlist){
    int colsize = 0;
    //Columns number
    int columnas=4;
    // Screen size
    int tamaniotabla=w.ws_col-2;
    if(tamaniotabla<120){
        tamaniotabla=120;
    }
    // calculates how many elements will be left
    int sobraparallegar=tamaniotabla%columnas;
    // Columns size
    colsize=((tamaniotabla)/columnas);
    // Table size betwwen columns gives us each column size
    messageMargin(tamaniotabla+2);   
    ordenarparametros(colsize,sobraparallegar);
    messageMargin(tamaniotabla+2);   
    printtop(userlist->front,colsize,sobraparallegar);
}

/**
 * Function that sorts the table parameters
 */
void ordenarparametros(int colsize,int sobraparallegar){
    messageLineSeccionAux(colsize,"Nombre",0,sobraparallegar);
    messageLineSeccionAux(colsize,"Nivel",1,sobraparallegar);  
    messageLineSeccionAux(colsize,"Points World Snake",1,sobraparallegar);
    messageLineSeccionAux(colsize,"Points Clasic",-1,sobraparallegar);
}

/**
 * Function that calls the top table
 */
bool TopMenu(myGame<nodeuserinfouser>* game){
    return TopMenuAux(game,optionSelectionKey(game,mensajeTOPS,3));
}
