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
    int size=3;
    int colsize=w.ws_col/size;
    int sobra=0;
    string nombres="";
    //cout<<fwall;
    if(front) {
        sobra+=mensageLineSeccionAux(colsize,front->info.name);
        sobra+=mensageLineSeccionAux(colsize,to_string(front->info.coin));
        sobra+=mensageLineSeccionAux(colsize,to_string(front->info.puntaje));
        sobra=w.ws_col-sobra;
        if(sobra>0){nombres.insert(0,sobra,' ');}
        cout<<nombres<<"*"<<endl;
        mensageMargin(w.ws_col);

        printtop(front->next);
    }
    else    
        cout<<endl;
}

void printtopaux(doubleLinked<nodeuserinfouser>* userlist){

    mensageMargin(w.ws_col);
    int size=3;
    int colsize=w.ws_col/size;
    int sobra=0;
    string nombres="";
  

    // cout<<"Tamanio total : "<<w.ws_col<<endl;
    // cout<<"Tamanio total/3 :"<<w.ws_col/3<<endl;
    // cout<<"Tamanio part : "<<part<<endl;
    sobra+=mensageLineSeccionAux(colsize,"Nombre");
    sobra+=mensageLineSeccionAux(colsize,"Monedas");
    sobra+=mensageLineSeccionAux(colsize,"Puntaje");
    sobra=w.ws_col-sobra;
    //cout<< sobra<<endl;
    if(sobra>0){nombres.insert(0,sobra,' ');}
    cout<<nombres<<"*"<<endl;
    mensageMargin(w.ws_col);

    printtop(userlist->front);
}