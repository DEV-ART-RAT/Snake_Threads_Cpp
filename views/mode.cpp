#include <iostream>
#include <termios.h>
#include <unistd.h>

//#include "../snake/clear.cpp"
//#include "../snake/matriz.cpp"
#include "../snake/my_snake.h"
#include "../user/nodeuser.h"
#include "./difficulty.cpp"
using namespace std;

auto mensajeMode = [](int opc,node<nodeuserinfouser>* userdata) { 
    CLEAR;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<endl<<endl;

    cout<<"\t\t\t\t\t"<<((opc==1)?"*":" ")<<" CLASICO "<<((opc==1)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==2)?"*":" ")<<" ESPECIAL "<<((opc==2)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==3)?"*":" ")<<" REGRESAR "<<((opc==3)?"*":"");
    cout<<endl<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
};

int startMenuAux(node<nodeuserinfouser>* , auto ,int );
int startMenu(node<nodeuserinfouser>* ,doubleLinked<nodeuserinfouser>* );


int modeMenuAux(node<nodeuserinfouser>* userdata,int flag,doubleLinked<nodeuserinfouser>* userlist){

    //mySnake snake = mySnake();
    switch (flag) {
        case 1:
            difficultyMenu(userdata,userlist);
            break;
        case 2://especial
            //playmatrix(&snake,2,0);
            difficultyMenu(userdata,userlist);
            break;
        case 3:
            //playmatrix(&snake,3,0);
            startMenu(userdata,userlist);
            break;
        default:
            break;
    }

    return 0;
}

int modeMenu(node<nodeuserinfouser>* userdata,doubleLinked<nodeuserinfouser>* userlist){
    return modeMenuAux(userdata,startMenuAux(userdata,mensajeMode,3),userlist);
}






