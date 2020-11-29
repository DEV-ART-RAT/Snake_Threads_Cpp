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
void ordenarparametros(int &colsize);
template<class T>
void printtop(node<T>* front);
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
void printtop(node<T>* front){
    int size=6;
    int colsize=(w.ws_col)/size;
    int sobra=0;// nose si size o 6 
    
    string nombres="";
    //cout<<fwall;
    if(front) {
        // sobra+=mensageLineSeccionAux(colsize,front->info.name);
        // sobra+=mensageLineSeccionAux(colsize,to_string(front->info.coin));
        // sobra+=mensageLineSeccionAux(colsize,to_string(front->info.nivel));
        // sobra+=mensageLineSeccionAux(colsize,to_string(front->info.vidas));
        // sobra+=mensageLineSeccionAux(colsize,to_string(front->info.puntajeContinuar));
        // sobra+=mensageLineSeccionAux(colsize,to_string(front->info.puntaje));
        //cout <<endl<<sobra<<endl;
        sobra=w.ws_col-sobra;
        //if(sobra>0){nombres.insert(0,sobra,' ');}
        cout<<nombres<<"*"<<endl;
        mensageMargin(w.ws_col);
        //cout <<endl<<sobra<<endl;

        printtop(front->next);
    }
    else    
        cout<<endl;
}

void printtopaux(doubleLinked<nodeuserinfouser>* userlist){
    int colsize = 0;
    ordenarparametros(colsize);

    printtop(userlist->front);
}

void ordenarparametros(int &colsize){
    //funcion para que el top sea responsive
    string espacios="";
    int sobra=0;
    //numero de columnas de la tabla
    int columnas=6;
    // tamanio de la pantalla (menos 2 porque se tiende a pasar al final)
    int tamaniotabla=w.ws_col-2;
    // calculamos cuantos elementos sobraran (no todas los tamanios de pantalla se pueden dividir exactos)
    int sobraparallegar=tamaniotabla%columnas;
    // tamanio de cada columna
    colsize=((tamaniotabla)/columnas);
    //cout<<": Tamanio de todo  : "<< tamaniotabla<<":| | Sobra al dividir las comunas :"<<sobraparallegar<<"| | COLSIZE :"<<colsize<<"| | tamanio tabla exacto : "<<colsize*columnas<<endl;
    // tamanio de la tabla entre sus columnas nos da el tamanio de cada columna 
    mensageMargin(w.ws_col);
    sobra+=mensageLineSeccionAux(colsize,"Nombre",0,sobraparallegar);
    sobra+=mensageLineSeccionAux(colsize,"Monedas",1,sobraparallegar);
    sobra+=mensageLineSeccionAux(colsize,"Nivel",1,sobraparallegar);    
    sobra+=mensageLineSeccionAux(colsize,"Vidas",1,sobraparallegar);
    sobra+=mensageLineSeccionAux(colsize,"Puntaje Actual",1,sobraparallegar);
    sobra+=mensageLineSeccionAux(colsize,"Puntaje Maximo",-1,sobraparallegar);
    mensageMargin(w.ws_col);
}