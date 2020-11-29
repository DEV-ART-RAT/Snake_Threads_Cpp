#include <iostream>
#include <termios.h>
#include <unistd.h>

//#include "../snake/clear.cpp"
//#include "../snake/matriz.cpp"
#include "../snake/my_snake.h"
#include "../tools/nodeuser.h"
using namespace std;

auto mensajeDifficulty = [](int opc,node<nodeuserinfouser>* userdata) { 
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
};

int startMenuAux(node<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* game);
int playmatrix(mySnake*, int , int );


int difficultyMenuAuxOpc(myGame<nodeuserinfouser>* game,int flag){

    mySnake snake = mySnake();
    switch (flag) {
        case 1:
            playmatrix(&snake,0,0);
            break;
        case 2:
            playmatrix(&snake,2,0);
            break;
        case 3:
            playmatrix(&snake,3,0);
            break;
        case 4:
            startMenu(game);
            break;
        default:
            break;
    }

    return 0;
}

int difficultyMenu(myGame<nodeuserinfouser>* game){
    return difficultyMenuAuxOpc(game,startMenuAux(game->user,mensajeDifficulty,4));
}






