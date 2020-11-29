#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <ostream>
//#include "../user/nodeuser.h"
#include "../tools/list.h"
#include "../snake/clear.cpp"
#include "../user/readuser.cpp"
#include "./snakeprint.cpp"
#include <iomanip>

using namespace std;
void top_game(myGame<nodeuserinfouser>* game);
void welcometop();
void ordenarparametros(int colsize,int sobraparallegar);
template<class T>
void printtop(node<T>* front,int colsize,int sobraparallegar);
void printtopaux(doubleLinked<nodeuserinfouser>* userlist);

void top_game(myGame<nodeuserinfouser>* game){
    welcometop();
    //traverseBegin(userlist->front);
    printtopaux(&game->list);
    mensageLine(w.ws_col,"presiona ENTER para continuar");
    cin.ignore();
    cin.get();
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
    if(front) {
        mensageLineSeccionAux(colsize,front->info.name,0,sobraparallegar);
        mensageLineSeccionAux(colsize,to_string(front->info.coin),1,sobraparallegar);
        mensageLineSeccionAux(colsize,to_string(front->info.nivel),1,sobraparallegar);
        mensageLineSeccionAux(colsize,to_string(front->info.vidas),1,sobraparallegar);
        mensageLineSeccionAux(colsize,to_string(front->info.puntajeContinuar),1,sobraparallegar);
        mensageLineSeccionAux(colsize,to_string(front->info.puntaje),-1,sobraparallegar);
        mensageMargin(w.ws_col);
        printtop(front->next,colsize,sobraparallegar);
    }
}

void printtopaux(doubleLinked<nodeuserinfouser>* userlist){
    int colsize = 0;
     //numero de columnas de la tabla
    int columnas=6;
     //funcion para que el top sea responsive
    string espacios="";
    // tamanio de la pantalla (menos 2 porque se tiende a pasar al final)
    int tamaniotabla=w.ws_col-2;
    // calculamos cuantos elementos sobraran (no todas los tamanios de pantalla se pueden dividir exactos)
    int sobraparallegar=tamaniotabla%columnas;
    // tamanio de cada columna
    colsize=((tamaniotabla)/columnas);
    ordenarparametros(colsize,sobraparallegar);

    printtop(userlist->front,colsize,sobraparallegar);
}

void ordenarparametros(int colsize,int sobraparallegar){
    //cout<<": Tamanio de todo  : "<< tamaniotabla<<":| | Sobra al dividir las comunas :"<<sobraparallegar<<"| | COLSIZE :"<<colsize<<"| | tamanio tabla exacto : "<<colsize*columnas<<endl;
    // tamanio de la tabla entre sus columnas nos da el tamanio de cada columna 
    mensageMargin(w.ws_col);
    mensageLineSeccionAux(colsize,"Nombre",0,sobraparallegar);
    mensageLineSeccionAux(colsize,"Monedas",1,sobraparallegar);
    mensageLineSeccionAux(colsize,"Nivel",1,sobraparallegar);    
    mensageLineSeccionAux(colsize,"Vidas",1,sobraparallegar);
    mensageLineSeccionAux(colsize,"Puntaje Actual",1,sobraparallegar);
    mensageLineSeccionAux(colsize,"Puntaje Maximo",-1,sobraparallegar);
    mensageMargin(w.ws_col);
}