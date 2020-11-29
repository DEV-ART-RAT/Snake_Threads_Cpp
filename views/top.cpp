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
void top_game(node<nodeuserinfouser>* userdata,doubleLinked<nodeuserinfouser>* userlist);
void welcometop();

template<class T>
void printtop(node<T>* front);
void printtopaux(doubleLinked<nodeuserinfouser>* userlist);

void top_game(node<nodeuserinfouser>* userdata,doubleLinked<nodeuserinfouser>* userlist){
    welcometop();
    //traverseBegin(userlist->front);
    printtopaux(userlist);
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
    winsize w = screenSize();
    //cout<<fwall;
    if(front) {

        mensageLineSeccionAux(((w.ws_col/3)%2==0)?w.ws_col/3:(w.ws_col/3)-1,front->info.name,0);
        // mensageLineSeccionAux(((w.ws_col/3)%2==0)?w.ws_col/3:(w.ws_col/3)-1,to_string(front->info.coin),1);
        // mensageLineSeccionAux(((w.ws_col/3)%2==0)?w.ws_col/3:(w.ws_col/3)-1,to_string(front->info.puntaje),2);
        cout<<endl;
        // mensageMargin(w.ws_col);
        printtop(front->next);
    }
    else    
        cout<<endl;
}

void printtopaux(doubleLinked<nodeuserinfouser>* userlist){

    mensageMargin(w.ws_col);
    int part=((w.ws_col/3)%2==0)?w.ws_col/3:(w.ws_col/3)+1;
    cout<<"Tamanio total : "<<w.ws_col<<endl;
    cout<<"Tamanio total/3 :"<<w.ws_col/3<<endl;
    cout<<"Tamanio part : "<<part<<endl;
    mensageLineSeccionAux(part,"Nombre",0);
    // mensageLineSeccionAux(((w.ws_col/3)%2==0)?w.ws_col/3:(w.ws_col/3)-1,"Monedas",1);
    // mensageLineSeccionAux(((w.ws_col/3)%2==0)?w.ws_col/3:(w.ws_col/3)-1,"Puntaje",1);
    // mensageMargin(w.ws_col);
    cout<<endl;

    printtop(userlist->front);
}