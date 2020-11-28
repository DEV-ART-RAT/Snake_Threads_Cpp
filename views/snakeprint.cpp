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
    cout<<"*"<<str <<  linea1 << str <<"*" <<endl;
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

void mensageMarginStart(int opc, node<nodeuserinfouser>* userdata) { 
    //CLEAR;
    //cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    mensageMargin(w.ws_col);
    mensageSteep(w.ws_col);
    string linea1[] = {
        "WELLCOME !!  ¡¡¡" + userdata->info.name + " !!! TO ......!!!"
    };
    mensageSnake(w.ws_col,linea1 , 1);
    string linea2[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    mensageSnake(w.ws_col,linea2 , 5);
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);

    (opc==1)? mensageLine(w.ws_col,"*  START *"): mensageLine(w.ws_col,"   START  ");
    mensageSteep(w.ws_col);
    (opc==2)? mensageLine(w.ws_col,"*  TIENDA *"): mensageLine(w.ws_col,"   TIENDA  ");
    mensageSteep(w.ws_col);
    (opc==3)? mensageLine(w.ws_col,"*  TOP *"): mensageLine(w.ws_col,"   TOP  ");
    mensageSteep(w.ws_col);
    (opc==4)? mensageLine(w.ws_col,"*  EXIT *"): mensageLine(w.ws_col,"   EXIT  ");
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);

};


int main(void) {
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