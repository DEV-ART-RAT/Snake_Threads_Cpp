#pragma once
#include <iostream>
#include "../tools/screenControl.h"
#include <iomanip>
#include <string>

using namespace std;
void mensageSnake(int col,string linea1[],int linea1size){
    string str;
    col = (col- linea1->size() - 4 )/2;
    str.insert(0, col, ' ');
    for (int i=0; i <linea1size ;i++){
    cout<<"*"<<str <<  linea1[i] << str <<"*" <<endl;

    }
    
}

void mensageLine(int col,string linea1){
    string str;
    col = (col- linea1.size() - 4 )/2;
    str.insert(0, col, ' ');
    (linea1.size()%2 != 0)? cout<<"*"<<str <<  linea1 << str <<" *" <<endl :
    cout<<"*"<<str <<  linea1 << str <<"*" <<endl;
}

void mensageLineSeccionAux(int col,string linea1,int pos){
    string str;
    col = (((col)/2)- (linea1.size())/2);
    (pos==0)?cout<<"*":cout<<"";
    str.insert(0, col, ' ');
    (linea1.size()%2 != 0)? cout<<str <<  linea1 << str <<" *":
    cout<<str <<  linea1 << str <<"*";chchc
}
void mensageSteep(int col){
    string strl;
    strl.insert(0, col - 4, ' ');
    cout<<"*"<<strl<<"*"<<endl;
}

void mensageMargin(int col){
    string strl;
    strl.insert(0, col - 2, '*');
    cout<<strl<<endl;
}


int snakeprint(void) {
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    
    string linea1[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    mensageMargin(w.ws_col);
    mensageSteep(w.ws_col);
    mensageSnake(w.ws_col,linea1 , 5);
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    
    
    return 0;
};