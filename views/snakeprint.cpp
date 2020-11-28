#include <iostream>
#include "../tools/screenControl.h"
#include <iomanip>
#include <string>

using namespace std;
void mensageSnake(int col){
    string str;
    string linea1[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    
    col = (col- linea1->size() -4 )/2;
    str.insert(0, col, ' ');
    for (int i=0; i < 5;i++){
        cout<<"*"<<str <<  linea1[i] << str <<"*" <<endl;
    }
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


int main(void) {
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    
    mensageMargin(w.ws_col);
    mensageSteep(w.ws_col);
    mensageSnake(w.ws_col);
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    
    
    return 0;
};