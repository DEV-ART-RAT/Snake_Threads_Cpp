#pragma once

#include <iostream>
#include <termios.h>
#include <unistd.h>
//#include "../snake/keyEvent.h"
#include "./windows_start.cpp"
//#include "../tools/gameStruct.h"

using namespace std;
struct termios term_over;


//int startMenuAux(node<nodeuserinfouser>* , auto ,int );

auto mensajeGameOverContinued = [](int opc,node<nodeuserinfouser>* userdata) { 
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
    cout<<"\t\t\t\t\t"<<((opc==1)?"*":" ")<<" Continuar "<<((opc==1)?"*":"");
    cout<<endl;
    cout<<"\t\t\t\t\t"<<((opc==2)?"*":" ")<<"  Regresar "<<((opc==2)?"*":"");
    cout<<endl<<endl;
};
auto mensajeGameOverFinish = [](int opc,node<nodeuserinfouser>* userdata) { 
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
    cout<<"\t\t\t\t\t"<<((opc==1)?"*":" ")<<" Regresar "<<((opc==1)?"*":"");
    cout<<endl<<endl;
};

int gameOverMenuAux(myGame<nodeuserinfouser>* game, int flag) {
    switch (flag) {
        case 1:
            game->snake.lifes--;
            return true;
        case 2:
            delete(game->snake.M);
            delete(game->snake.list);
            game->snake.sizeSnake = 3;
            return false;
        default:
            return false;
    }
};

bool gameOverMenu(myGame<nodeuserinfouser>* game){
    if(game->snake.lifes > 0){
        return gameOverMenuAux(game,startMenuAux(game->user,mensajeGameOverContinued,2));
    }
    gameOverMenuAux(game,startMenuAux(game->user,mensajeGameOverFinish,1));
    return false;
    
}
