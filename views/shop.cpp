#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

void keyEventshop(char& key,bool& flag)
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    key=getchar();//up:65 down:66 left:68 rigth:67


}
void shopwelcome(int);
int welcomemain();
int welcomeshop(){

    char key;
    //bool key_up = false;
    int flag = 1;       //opcion actual del menu
    int sizeOption=3;   //numero total de opciones en el menu
    bool loop = true;   //bandera para el while true
    sleep(0.1);//para corregir fallo de while
    shopwelcome(flag);  //invocacion del menu

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
        shopwelcome(flag);
         //evento de ENTER seleccionando una opcion de menu
        if( /*GetAsyncKeyState(VK_RETURN) & 0x8000*/ key=='\n'){
            //Sleep(100);//para corregir fallo de while
            switch (flag) {
                case 1:
                    cout<<"Compraste Vidas"<<endl;
                    break;
                case 2:
                    cout<<"Compraste Velocidad"<<endl;
                    break;
                case 3:
                    loop=false;
                    welcomemain();
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

void shopwelcome(int opc){
    CLEAR;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t"<<((opc==1)?"*":" ")<<" Vidas Extra "<<((opc==1)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==2)?"*":" ")<<" Velocidad "<<((opc==2)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==3)?"*":" ")<<"  EXIT "<<((opc==3)?"*":"");
    cout<<endl<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
}



