#pragma once

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "../snake/keyEvent.h"
#include "./windows_start.cpp"
#include "../tools/gameStruct.h"

using namespace std;
struct termios term_over;

int startMenuAux(node<nodeuserinfouser>* , auto ,int );

auto mensajeGameOver = [](int opc,node<nodeuserinfouser>* userdata) { 
    CLEAR;
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
};

int gameOverMenuAux(myGame<nodeuserinfouser>* game, int flag) {
    switch (flag) {
        case 1:
            startMenu(game);
            break;
        case 2:
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
};

int gameOverMenu(myGame<nodeuserinfouser>* game){
    gameOverMenuAux(game,startMenuAux(game->user,mensajeGameOver,2));
    return 0;
}
