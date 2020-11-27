#include <iostream>
#include <termios.h>
#include <unistd.h>

//#include "../snake/clear.cpp"
//#include "../snake/matriz.cpp"
#include "../snake/my_snake.h"
#include "../user/nodeuser.h"
using namespace std;

void keyEventDifficulty(char& key,bool& flag)
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    key=getchar();//up:65 down:66 left:68 rigth:67


}
void difficultywelcome(int, node<nodeuserinfouser>* userdata);
int welcomemain(node<nodeuserinfouser>* userdata);


int welcomedifficulty(node<nodeuserinfouser>* userdata){

    mySnake snake = mySnake(15,32);
    char key;
    //bool key_up = false;
    int flag = 1;       //opcion actual del menu
    int sizeOption=4;   //numero total de opciones en el menu
    bool loop = true;   //bandera para el while true
    sleep(0.1);//para corregir fallo de while
    difficultywelcome(flag, userdata);  //invocacion del menu

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
        difficultywelcome(flag, userdata);
         //evento de ENTER seleccionando una opcion de menu
        if( /*GetAsyncKeyState(VK_RETURN) & 0x8000*/ key=='\n'){
            //Sleep(100);//para corregir fallo de while
            switch (flag) {
                case 1:
                    playmatrix(&snake,1);
                    break;
                case 2:
                    playmatrix(&snake,2);
                    break;
                case 3:
                    playmatrix(&snake,3);
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

void difficultywelcome(int opc,node<nodeuserinfouser>* userdata){
    CLEAR;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<endl<<endl;

    cout<<"\t\t\t\t\t"<<((opc==1)?"*":" ")<<" FACIL "<<((opc==1)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==2)?"*":" ")<<" MEDIO "<<((opc==2)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==3)?"*":" ")<<" DIFICIL "<<((opc==3)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==4)?"*":" ")<<" REGRESAR "<<((opc==4)?"*":"");
    cout<<endl<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
}



