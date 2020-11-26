#include <termios.h>
#include <unistd.h>


#include <stdio.h>//getChar()
#include <stdio_ext.h>

#include "snake.h"
#include "my_snake.h"
#pragma once


void keyboardEvent(char* key, bool* flag){
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    while (*flag)
    {
        *key=getchar();
    }
    


    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void snakeEvent(mySnake* snake){
    //snakeDirection(snake);
    //printMatrizChar(snake->M,snake->FILA,snake->COLUMNA);//-----
    //usleep(500 * 1000);
    snake ->redirect=  true;
}

//template<class T>
void keyEventSnake(mySnake* snake){
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    while (snake->flag)
    {   
        //fflush(stdin);
        
        //cin.ignore();
        snake->key=getchar();
        switch (snake->key)
        {
        case '\n':
            snake->flag=false;
            return;//finalizando hilo
        case 65://up
            if(snake->dir!=2 && snake->dir!=1){
                snake->dir=1;
                snakeEvent(snake);
            }
            break;
        case 66://down
            if(snake->dir!=2 && snake->dir!=1){
                snake->dir=2;
                snakeEvent(snake);
            }
            break;
        case 67://right
            if(snake->dir!=3 && snake->dir!=4){
                snake->dir=3;
                snakeEvent(snake);
            }
            break;
        case 68://left
            if(snake->dir!=3 && snake->dir!=4){
                snake->dir=4;
                snakeEvent(snake);
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
    


    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

/* Thread
void myThreadTwo(int b){
    for (int i = 0 ; i  < b; i++){
        cout<<"thread two "<<i<<endl;
        sleep(2);
    }
}
//*/