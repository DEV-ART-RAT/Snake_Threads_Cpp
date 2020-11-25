#include <iostream>
// #ifdef _WIN32 /* Deberia estar definido en windows*/
#include <windows.h>
#include <winuser.h>
#include <cstdlib>
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
void wellcome(int);

/*
void __fastcall onKey::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
  // do something with Key
}
 //*/

int main(){

    //char key;
    //bool key_up = false;
    int flag = 1;       //opcion actual del menu
    int sizeOption=2;   //numero total de opciones en el menu
    bool loop = true;   //bandera para el while true
    wellcome(   flag);  //invocacion del menu
    while(loop){

        //evento de key Up
        if(  GetKeyState(VK_UP) & 0x8000 ){
            if(flag > 1){
                flag--;
                wellcome(flag);
            }
            Sleep(100);//para corregir fallo de while
        }
        //*evento de key DOWN
         if( GetAsyncKeyState(VK_DOWN) & 0x8000){
             if(flag < sizeOption){
                 flag++;
                 wellcome(flag);
             }
            Sleep(100);//para corregir fallo de while
        }

         //evento de ENTER seleccionando una opcion de menu
        if( GetAsyncKeyState(VK_RETURN) & 0x8000){
            switch (flag) {
                case 1:
                    cout<<"new game start :v"<<endl;
                    break;
                case 2:
                    loop=false;
                    cout<<"exit... :'v"<<endl;
                    break;
                default:
                    break;
            }

            Sleep(100);//para corregir fallo de while
        }
         //*/
         Sleep(10);//para corregir fallo de while
    }

    return 0;
}

void wellcome(int opc){
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"\t\t\t\t\t\tWELLCOME !! TO ......!!!\n";
    cout<<"\t\t\t=====\t===    =="   <<"\t=======\t  ==  =="  <<"\t====="   <<endl;
    cout<<"\t\t\t||   \t||\\\\   ||" <<"\t||   ||\t  || // "  <<"\t||"      <<endl;
    cout<<"\t\t\t=====\t|| \\\\  ||" <<"\t||===||\t  |||   "  <<"\t====="   <<endl;
    cout<<"\t\t\t   ||\t||  \\\\ ||" <<"\t||   ||\t  || \\\\ "<<"\t||"      <<endl;
    cout<<"\t\t\t=====\t==   ===="   <<"\t==   ==\t  ==  =="  <<"\t====="   <<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t\t"<<((opc==1)?"*":"")<<" START";
    cout<<endl;
    cout<<"\t\t\t\t\t\t"<<((opc==2)?"*":"")<<" EXIT";
    cout<<endl<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
}



