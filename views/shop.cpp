#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "../snake/my_snake.h"
#include "../user/nodeuser.h"
using namespace std;

void keyEventshop(char& key,bool& flag)
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    key=getchar();//up:65 down:66 left:68 rigth:67


}
void shopwelcome(int, node<nodeuserinfouser>* userdata);
int welcomemain(node<nodeuserinfouser>* userdata);

void buyCoin(nodeuserinfouser* userdata){
    if(userdata->puntaje >= 100){
        userdata->puntaje -= 100;
        userdata->coin++;
        cout<<"Moneda comprada"<<endl;
    } else {
        cout<<"Puntos insuficientes"<<endl;
    }
}

void buyLife(nodeuserinfouser* userdata){
    if(userdata->coin >= 5){
        userdata->coin -= 5;
       // userdata->lifes++;
        cout<<"Vida comprada"<<endl;
    } else {
        cout<<"Monedas insuficientes"<<endl;
    }
}

int welcomeshop(node<nodeuserinfouser>* userdata){

    char key;
    //bool key_up = false;
    int flag = 1;       //opcion actual del menu
    int sizeOption=4;   //numero total de opciones en el menu
    bool loop = true;   //bandera para el while true
    sleep(0.1);//para corregir fallo de while
    shopwelcome(flag, userdata);  //invocacion del menu

    //*
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    //*/

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
        shopwelcome(flag, userdata);
         //evento de ENTER seleccionando una opcion de menu
        if( /*GetAsyncKeyState(VK_RETURN) & 0x8000*/ key=='\n'){
            //Sleep(100);//para corregir fallo de while
            switch (flag) {
                case 1:
                    buyLife(userdata);
                    sleep(1);
                    shopwelcome(flag, userdata);
                    break;
                case 2:
                    cout<<"Compraste Velocidad"<<endl;
                    break;
                case 3:
                    buyCoin(userdata);
                    sleep(1);
                    shopwelcome(flag, userdata);
                    break;
                case 4:
                    loop=false;
                    welcomemain(userdata);
                    break;
                default:
                    break;
            }

            //Sleep(100);//para corregir fallo de while
        }
         //*/

        sleep(0.01);//para corregir fallo de while
    }

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    //*/

    return 0;
}

void shopwelcome(int opc,node<nodeuserinfouser>* userdata){
    CLEAR;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<endl<<endl;

    cout<<"Points: "<<userdata->info.puntaje<<endl;
    cout<<"Coins: "<<userdata->info.coin<<endl;
    //cout<<"Lifes: "<<snake->lifes<<endl;
    cout<<"\t\t\t\t\t"<<((opc==1)?"*":" ")<<" Vida Extra (5 monedas) "<<((opc==1)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==2)?"*":" ")<<" Potenciar puntaje x2 (500 puntos) "<<((opc==2)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==3)?"*":" ")<<" 1 moneda (100 puntos)"<<((opc==3)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==4)?"*":" ")<<"  Regresar "<<((opc==4)?"*":"");
    cout<<endl<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
}



