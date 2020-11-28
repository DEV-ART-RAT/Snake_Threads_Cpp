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
#include "./top.cpp"


using namespace std;

int welcomemain(int &P,int&C,string user);

auto mensajeStart = [](int opc, node<nodeuserinfouser>* userdata) { 
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
    cout<<"\t\t\t\t\t"<<((opc==3)?"*":" ")<<"  TOP "<<((opc==3)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==4)?"*":" ")<<"  EXIT "<<((opc==4)?"*":"");
    cout<<endl<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
};


int startMenuAux(node<nodeuserinfouser>* userdata, auto wellcome,int sizeOption){
    char key; //contenedor de tecla
    int flag = 1;       //opcion actual del menu
    //int sizeOption=3;   //numero total de opciones en el menu
    bool loop = true;   //bandera para el while true

    sleep(0.1);//para corregir fallo de while
    wellcome(flag,userdata);  //invocacion del menu

    cin.ignore();
    //sleep(0.1);//para corregir fallo de whiles

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

        if( key=='\n'){
            return flag;
        }

        wellcome(flag,userdata);
        sleep(0.01);//para corregir fallo de while
    }
    cin.ignore();

    return 0;
}



int startMenuOpc(node<nodeuserinfouser>* userdata, int flag,doubleLinked<nodeuserinfouser>* userlist){
    switch (flag) {
        case 1:
            //cout<<"new game start :v"<<endl;
            //playmatrix(&snake);
            difficultyMenu(userdata,userlist);
            //playmatrix(&snake);
            gameOverMenu(userdata,userlist);
            // loop=false; //para que termine el juego sin que se regrese al menu :
            break;
        case 2:
            welcomeshop(userdata,userlist);
            break;
        case 3:
            top_game(userdata,userlist);
            break;
        case 4:
            cout<<"exit... :'v"<<endl;
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
    return 0;
}

int startMenu(node<nodeuserinfouser>* userdata,doubleLinked<nodeuserinfouser>* userlist){
    startMenuOpc(userdata,startMenuAux(userdata,mensajeStart,4),userlist);
    return 0;
}







