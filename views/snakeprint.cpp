#include <iostream>
#include "../tools/screenControl.h"
#include <iomanip>
#include <string>

using namespace std;
void mensageSnake(int col){
    string str,strl;
    string linea1[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    strl.insert(0, col - 2, '*');
    cout<<strl<<endl;
    col = (col- linea1->size() -4 )/2;
    str.insert(0, col, ' ');
    for (int i=0; i < 5;i++){
        cout<<"*"<<str <<  linea1[i] << str <<"*" <<endl;
    }
}


int main(void) {
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    mensageSnake(w.ws_col);
    
    
    return 0;
};