#pragma once
#include <termios.h>
#include <unistd.h>


#include <stdio.h>//getChar()
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

void snakeEvent(myGame<nodeuserinfouser>* game){
    //snakeDirection(snake);
    //printMatrizChar(game->snake.M,game->snake.FILA,game->snake.COLUMNA);//-----
    //usleep(500 * 1000);
    game->snake.redirect =  true;
}

//template<class T>
void keyEventSnake(myGame<nodeuserinfouser>* game){
    cin.ignore();

    while (game->snake.flag)
    {   
        //fflush(stdin);
        
        //cin.ignore();
        game->snake.key=getchar();
        if(!game->snake.flag){
            return;
        }
        switch (game->snake.key)
        {
        case '\n':
            //game->snake.flag=false;
            
                shopMenu(game);
            break;//finalizando hilo
        case 65://up
            if(game->snake.dir!=2 && game->snake.dir!=1){
                game->snake.dir=1;
                snakeEvent(game);
            }
            break;
        case 66://down
            if(game->snake.dir!=2 && game->snake.dir!=1){
                game->snake.dir=2;
                snakeEvent(game);
            }
            break;
        case 67://right
            if(game->snake.dir!=3 && game->snake.dir!=4){
                game->snake.dir=3;
                snakeEvent(game);
            }
            break;
        case 68://left
            if(game->snake.dir!=3 && game->snake.dir!=4){
                game->snake.dir=4;
                snakeEvent(game);
            }
            break;
        default:
            break;
        }
        //cout<<"steep: "<<*steep<<endl;
        //sleep(2);

        
        //snakeRight(&list,M,FILA,COLUMNA,1);
        //flag++;
        //__fpurge(stdin);
        //usleep(500 * 1000);
        
        
    }
    


    cin.ignore();
}

/* Thread
void myThreadTwo(int b){
    for (int i = 0 ; i  < b; i++){
        cout<<"thread two "<<i<<endl;
        sleep(2);
    }
}
//*/