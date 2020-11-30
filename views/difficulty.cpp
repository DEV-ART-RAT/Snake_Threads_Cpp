#pragma once
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
int startMenu(myGame<nodeuserinfouser>* );
int playmatrix(myGame<nodeuserinfouser>* );
int difficultyMenu(myGame<nodeuserinfouser>* );


int difficultyMenuAuxOpc(myGame<nodeuserinfouser>* game,int flag){

    game->difficulty = flag;//inciando dificultad especial
    game->levelSpecial = 1;//inicando escenario especial
    game->liveSpecial = 3;//iniciando vidads especial

    switch (flag) {
        case 1:
            
            playmatrix(game);
            break;
        case 2:
            playmatrix(game);
            break;
        case 3:
            playmatrix(game);
            break;
        case 4:
            return 1;
        default:
            break;
    }
    difficultyMenu(game);
    return 0;
}

int difficultyMenu(myGame<nodeuserinfouser>* game){
    return difficultyMenuAuxOpc(game,startMenuAux(game->user,mensajeDifficulty,4));
}






