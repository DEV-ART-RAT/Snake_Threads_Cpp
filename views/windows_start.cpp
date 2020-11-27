#pragma once;
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
#include "./shop.cpp"
#include "./game_over.cpp"

//#define mySleep(x) Sleep(x);

// #elif defined __unix__ /* Creo que es esta macro, deberia estar definida en sistemas Unix-like*/
// #include <unistd.h>
// #define mySleep(x) sleep(x);
// #else  /* No sabemos donde estamos*/
// #warning Missing sleep function
// #endif
//#include <conio.h>

// COMPILAR:
/*
/usr/bin/i686-w64-mingw32-g++ -I w32api/include/ -L w32api/lib/ keyboarEvent.cpp
*/

using namespace std;

//void abrir_buffer();
//void cerrar_buffer();
int welcomemain(int &P,int&C,string user);


void wellcome(int);

/*
void __fastcall onKey::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
  // do something with Key
}
 //*/

int welcomemain(node<nodeuserinfouser>* userdata){

    mySnake snake = mySnake(15,32);
    char key;
    //bool key_up = false;
    int flag = 1;       //opcion actual del menu
    int sizeOption=3;   //numero total de opciones en el menu
    bool loop = true;   //bandera para el while true
    sleep(0.1);//para corregir fallo de while
    wellcome(   flag);  //invocacion del menu

    //cin.ignore();
    abrir_buffer();
    
    while(loop){
        key=getchar();//up:65 down:66 left:68 rigth:67
        //cout<<int(key);

        //evento de key Up
        if(  /*GetKeyState(VK_UP) & 0x8000*/ key==65 ){
            if(flag > 1){
                flag--;
                //wellcome(flag);
            }
            //sleep(0.1);//para corregir fallo de while
        }
        //*evento de key DOWN
        if( /*GetAsyncKeyState(VK_DOWN) & 0x8000*/ key=='B'){
            if(flag < sizeOption){
                flag++;
                 //wellcome(flag);
            }
            //Sleep(100);//para corregir fallo de while
        }
        wellcome(flag);
         //evento de ENTER seleccionando una opcion de menu
        if( /*GetAsyncKeyState(VK_RETURN) & 0x8000*/ key=='\n'){
            //Sleep(100);//para corregir fallo de while
            switch (flag) {
                case 1:
                    loop=false;
                    cout<<"new game start :v"<<endl;
                    playmatrix(&snake);
                    game_over(userdata);
                   // loop=false; //para que termine el juego sin que se regrese al menu :
                    break;
                case 2:
                    loop=false;
                    welcomeshop(userdata);
                    break;
                case 3:
                    loop=false;
                    cout<<"exit... :'v"<<endl;
                    break;
                default:
                    break;
            }

            //Sleep(100);//para corregir fallo de while
        }
         //*/

        sleep(0.01);//para corregir fallo de while
    }

    cerrar_buffer();
    //*/

    return 0;
}

void wellcome(int opc){
    //system("cls");//linux
    //cout<<flush;
    //system("clear");//windows
    CLEAR;
    //sleep(0.01);//para corregir fallo de while
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t\tWELLCOME !! TO ......!!!\n\n";
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t"<<((opc==1)?"*":" ")<<" START "<<((opc==1)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==2)?"*":" ")<<" TIENDA "<<((opc==2)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==3)?"*":" ")<<"  EXIT "<<((opc==3)?"*":"");
    cout<<endl<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
}




