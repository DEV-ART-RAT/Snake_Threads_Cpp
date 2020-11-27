#pragma once
#include <iostream>
#include <termios.h>
#include <unistd.h>
// #ifdef _WIN32 /* Deberia estar definido en windows*/
//#include <windows.h>
//#include <winuser.h>
//#include <cstdlib>
//#include <conio.h>

//#include <thread>
#include "../snake/clear.cpp"
#include "../snake/matriz.cpp"
#include "../snake/keyEvent.h"
#include "./shop.cpp"
#include "./difficulty.cpp"
#include <termios.h>
#include <unistd.h>
#include "./game_over.cpp"


using namespace std;

int welcomemain(int &P,int&C,string user);
void wellcome(int,node<nodeuserinfouser>* );


int startMenu(node<nodeuserinfouser>* userdata){
    char key; //contenedor de tecla
    int flag = 1;       //opcion actual del menu
    int sizeOption=3;   //numero total de opciones en el menu
    bool loop = true;   //bandera para el while true

    sleep(0.1);//para corregir fallo de while
    wellcome(flag,userdata);  //invocacion del menu

    abrir_buffer();
    sleep(0.1);//para corregir fallo de whiles
    
    
    while(loop){
        key=getchar();//up:65 down:66 left:68 rigth:67

        if(key==65 ){
            if(flag > 1){
                flag--;
            }
        }
        if(  key=='B'){
            if(flag < sizeOption){
                flag++;
            }
        }
        wellcome(flag,userdata);
        if( key=='\n'){
            cerrar_buffer();
            return flag;
        }

        sleep(0.01);//para corregir fallo de while
    }

    cerrar_buffer();
    //*/

    return 0;
}

int startMenuOpc(node<nodeuserinfouser>* userdata, int flag){
    switch (flag) {
        case 1:
            cout<<"new game start :v"<<endl;
            //playmatrix(&snake);
            welcomedifficulty(userdata);
            //playmatrix(&snake);
            game_over(userdata);
            // loop=false; //para que termine el juego sin que se regrese al menu :
            break;
        case 2:
            welcomeshop(userdata);
            break;
        case 3:
            cout<<"exit... :'v"<<endl;
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
    return 0;
}

void wellcome(int opc, node<nodeuserinfouser>* userdata){
    CLEAR;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t\tWELLCOME !!  ¡¡¡"<<userdata->info.name<<"!!! TO ......!!!\n\n";
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t"<<((opc==1)?"*":" ")<<"  START "<<((opc==1)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==2)?"*":" ")<<" TIENDA "<<((opc==2)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==3)?"*":" ")<<"  EXIT "<<((opc==3)?"*":"");
    cout<<endl<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
}





