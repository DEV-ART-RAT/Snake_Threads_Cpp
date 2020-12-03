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



auto mensajeTOPS = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    mensageLine(w.ws_col,"Points: "+to_string(game->user->info.puntaje));
    mensageLine(w.ws_col,"Coins: "+to_string(game->user->info.coin));
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    (opc==1)? 
    mensageLineRED(w.ws_col,"* TOP Ordenado por World Party *"):   
    mensageLine(w.ws_col,"  TOP Ordenado por World Party  ");
    (opc==2)? 
    mensageLineRED(w.ws_col,"* TOP Ordenado por Clasico 97 *"):    
    mensageLine(w.ws_col,"  TOP Ordenado por Clasico 97  ");
    (opc==3)? 
    mensageLineRED(w.ws_col,"* Regresar *"):    
    mensageLine(w.ws_col,"  Regresar  ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
}; 
bool TopMenuAux(myGame<nodeuserinfouser>* game,int flag){
    switch (flag) {
            case 1:
                quickSort(game->list.front, 1);
                top_game(game);
                TopMenu(game);      
                return false; 
            case 2:
                quickSort(game->list.front, 3);
                top_game(game);
                TopMenu(game);
                return false;
            case 3:
                return true;
            default:
                return true;
    }

}

void top_game(myGame<nodeuserinfouser>* game){
    welcometop();
    //traverseBegin(userlist->front);
    printtopaux(&game->list);
    cin.clear();
    mensageLine(w.ws_col,"presiona una tecla para continuar");
    getchar();
    //startMenuOpc(userdata,startMenu(userdata,userlist),userlist);
    return;
};
void welcometop(){
    // borra esto porque hay nose que conflicto de pragma once
    CLEAR;
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    snakeprint();

}
template<class T>
void printtop(node<T>* front,int colsize,int sobraparallegar){
    int tamaniotabla=w.ws_col-2;
    if(tamaniotabla<120){
        tamaniotabla=120;
    }
    if(front) {
        mensageLineSeccionAux(colsize,front->info.name,0,sobraparallegar);
        mensageLineSeccionAux(colsize,to_string(front->info.nivel),1,sobraparallegar);
        mensageLineSeccionAux(colsize,to_string(front->info.puntaje),1,sobraparallegar);
        mensageLineSeccionAux(colsize,to_string(front->info.puntajeClasico),-1,sobraparallegar);
        mensageMargin(tamaniotabla+2);
        printtop(front->next,colsize,sobraparallegar);
    }
}

void printtopaux(doubleLinked<nodeuserinfouser>* userlist){
    int colsize = 0;
    //numero de columnas de la tabla
    int columnas=4;
    // tamanio de la pantalla (menos 2 porque se tiende a pasar al final)
    int tamaniotabla=w.ws_col-2;
    if(tamaniotabla<120){
        tamaniotabla=120;
    }
    // calculamos cuantos elementos sobraran (no todas los tamanios de pantalla se pueden dividir exactos)
    int sobraparallegar=tamaniotabla%columnas;
    // tamanio de cada columna
    colsize=((tamaniotabla)/columnas);
    // tamanio de la tabla entre sus columnas nos da el tamanio de cada columna 
    //cout<<": Tamanio de todo  : "<< tamaniotabla<<":| | Sobra al dividir las comunas :"<<sobraparallegar<<"| | COLSIZE :"<<colsize<<"| | tamanio tabla exacto : "<<colsize*columnas<<endl;
    mensageMargin(tamaniotabla+2);   
    ordenarparametros(colsize,sobraparallegar);
    mensageMargin(tamaniotabla+2);   
    printtop(userlist->front,colsize,sobraparallegar);
}

void ordenarparametros(int colsize,int sobraparallegar){
    mensageLineSeccionAux(colsize,"Nombre",0,sobraparallegar);
    mensageLineSeccionAux(colsize,"Nivel",1,sobraparallegar);  
    mensageLineSeccionAux(colsize,"Puntaje World Snake",1,sobraparallegar);
    mensageLineSeccionAux(colsize,"Puntaje Clasico",-1,sobraparallegar);
}

bool TopMenu(myGame<nodeuserinfouser>* game){
    return TopMenuAux(game,optionSelectionKey(game,mensajeTOPS,3));
}
