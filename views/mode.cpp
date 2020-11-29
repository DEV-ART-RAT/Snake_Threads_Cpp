#include <iostream>
#include <termios.h>
#include <unistd.h>

//#include "../snake/clear.cpp"
//#include "../snake/matriz.cpp"
#include "../snake/my_snake.h"
#include "../tools/list.h"
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
int startMenu(myGame<nodeuserinfouser>* );


int modeMenuAux(myGame<nodeuserinfouser>* game,int flag){

    //mySnake snake = mySnake();
    switch (flag) {
        case 1:
            difficultyMenu(game);
            break;
        case 2://especial
            //playmatrix(&snake,2,0);
            difficultyMenu(game);
            break;
        case 3:
            //playmatrix(&snake,3,0);
            startMenu(game);
            break;
        default:
            break;
    }

    return 0;
}

int modeMenu(myGame<nodeuserinfouser>* game){
    return modeMenuAux(game,startMenuAux(game->user,mensajeMode,3));
}






