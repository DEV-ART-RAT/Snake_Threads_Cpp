#pragma once
#include <stdio.h>//getChar()
#include <unistd.h>
#include <termios.h>
#include <stdio_ext.h> 
#include "snake.h"
#include "my_snake.h"
#include "../tools/gameStruct.h"

void keyboardEvent(char* key, bool* flag){
    cin.ignore();

    while (*flag)
    {
        *key=getchar();
    }

    cin.ignore();
}
//template<class T>
void keyEventSnake(myGame<nodeuserinfouser>* game){
    cin.ignore();
    while (game->playing)
    {   
        if(!game->pause){
            game->key=getchar();
            if(!game->playing){
                return;
            }
        }
    }
    cin.ignore();
}