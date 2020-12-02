#pragma once

#include <stdio.h>//getChar()
#include <unistd.h>
#include <termios.h>
#include <stdio_ext.h> 

#include "snake.h"
#include "my_snake.h"
#include "../tools/gameStruct.h"

void keyboardEvent(char* key, bool* flag){
    cin.clear();

    while (*flag)
    {
        *key=getchar();
    }

    cin.clear();
}
//template<class T>
void keyEventSnake(myGame<nodeuserinfouser>* game){
    cin.clear();
    while (game->playing)
    {   
        if(!game->pause){
            game->key=getchar();
            if(!game->playing){
                return;
            }
        }
    }
    cin.clear();
}

int optionSelectionKey(myGame<nodeuserinfouser>* game, auto wellcome,int sizeOption){
    char key; //contenedor de tecla
    int flag = 1;       //opcion actual del menu
    //int sizeOption=3;   //numero total de opciones en el menu
    bool loop = true;   //bandera para el while true
    sleep(0.1);//para corregir fallo de while
    wellcome(flag,game,sizeOption);  //invocacion del menu
    cin.clear();
    sleep(0.1);//para corregir fallo de whiles
    while(loop){
        key=getchar();//up:65 down:66 o B left:68 rigth:67
        if( key=='\n'){
            return flag;
        }
        if(key==65 ){
            if(flag > 1){
                flag--;
            }
        }
        if(  key=='B'){
            if(flag < sizeOption){
                flag++;
            }
        }
        wellcome(flag,game,sizeOption);
        sleep(0.01);//para corregir fallo de while
    }
    cin.clear();
    return 0;
}

bool enterSelection(myGame<nodeuserinfouser>* game,auto wellcome){
    char key; //contenedor de tecla
    bool loop = true;   //bandera para el while true
    wellcome(game);  //invocacion del menu
    while(loop){
        key=getchar();
        if( key=='\n'){
            return true;
        }
        else{
            return false;
        }
    }
}
