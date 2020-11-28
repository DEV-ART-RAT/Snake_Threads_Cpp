#include <iostream>
#include "../tools/screenControl.h"
#include <iomanip>

using namespace std;
int main(void) {
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    int tamanio_alto=w.ws_row - 3;
    int tamanio_largo=w.ws_col /1 ;
    for (int i = 0; i < tamanio_alto; i++)
    {
        /* code */
        if(i>0 && i<6){
        cout<<"*"<<setw((tamanio_largo/2)-5)<<"=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;i-=-1;
        cout<<"*"<<setw((tamanio_largo/2)-5)<<"||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;i-=-1;
        cout<<"*"<<setw((tamanio_largo/2)-5)<<"=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;i-=-1;
        cout<<"*"<<setw((tamanio_largo/2)-5)<<"   ||   ||  \\\\ ||" <git pu<"   ||   ||   || \\\\ "<<"   ||"      <<endl;i-=-1;
        cout<<"*"<<setw((tamanio_largo/2)-5)<<"=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;i-=-1;
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
        
    }
    
    return 0;
};