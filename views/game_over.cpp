#include <iostream>
#include <termios.h>
#include <unistd.h>
#pragma once;
#include "./windows_start.cpp"


using namespace std;
struct termios term_over;
//void abrir_buffer();
//void cerrar_buffer();
void game_over_Print(int opc);

int game_over(node<nodeuserinfouser>* userdata) {
    char key_game_over;
    int flag_game_over = 1;       //opcion actual del menu
    int sizeOption_game_over=2;   //numero total de opciones en el menu
    bool loop_game_over = true;   //bandera para el while true
    sleep(0.1);//para corregir fallo de while
    game_over_Print(flag_game_over);
    cin.ignore();
    abrir_buffer();
     while(loop_game_over){
        key_game_over=getchar();//up:65 down:66 left:68 rigth:67
        if(  /*GetKey_game_overState(VK_UP) & 0x8000*/ key_game_over==65 ){
            if(flag_game_over > 1){
                flag_game_over--;
            }
        }
        if( /*GetAsyncKey_game_overState(VK_DOWN) & 0x8000*/ key_game_over=='B'){
            if(flag_game_over < sizeOption_game_over){
                flag_game_over++;
                 //wellcome(flag_game_over);
            }
        }
        game_over_Print(flag_game_over);
        if( /*GetAsyncKey_game_overState(VK_RETURN) & 0x8000*/ key_game_over=='\n'){
            //Sleep(100);//para corregir fallo de while
            switch (flag_game_over) {
                case 1:
                    loop_game_over=false;
                    welcomemain(userdata);
                    break;
                case 2:
                    loop_game_over=false;
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
    return 0;
};

void game_over_Print(int opc){
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t Que desea hacer? \n";
    cout<<"\t\t\t\t\t"<<((opc==1)?"*":" ")<<" Comenzar de nuevo "<<((opc==1)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==2)?"*":" ")<<"  EXIT "<<((opc==2)?"*":"");
    cout<<endl<<endl;
}

