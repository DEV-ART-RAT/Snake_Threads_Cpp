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