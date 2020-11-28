#include <iostream>
#include "../tools/screenControl.h"
#include <iomanip>
#include <string>

using namespace std;
int main(void) {
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    int tamanio_alto=w.ws_row - 4;
    int tamanio_largo=w.ws_col -4 ;
    string linea1[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    int space = tamanio_largo/2 - linea1->size();
    string str;//("lolcat");
    str.insert(0, space, ' ');

    for (int i=0; i<5;i++){
        cout<<"*"<<str <<  linea1[i] << str <<"*" <<endl;
    }
    //cout<<linea1.size()<<endl;
    /*for (int i = 0; i < tamanio_alto; i++)
    {
        
        if(i>0 && i<6){
        cout<<"*"<<setw((tamanio_largo/2)-5)<<  linea1 << setw((tamanio_largo/2)-5) <<"*" <<endl;i-=-1;
        cout<<"*"<<setw((tamanio_largo/2)-5)<<      <<endl;i-=-1;
        cout<<"*"<<setw((tamanio_largo/2)-5)<<   <<endl;i-=-1;
        cout<<"*"<<setw((tamanio_largo/2)-5)<<     <<endl;i-=-1;
        cout<<"*"<<setw((tamanio_largo/2)-5)<<  <<endl;i-=-1;
        }
        if (i==0||i==tamanio_alto-1)
        {
            
            for (int i = 0; i <tamanio_largo; i++)
            {
                cout<<"*";

            }
            cout<<endl;
        }
        else
        {
            cout<<endl;
        }
        if(i==tamanio_alto-1){
                
        }
        
    }*/
    
    return 0;
};