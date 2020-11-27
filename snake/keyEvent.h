#include <termios.h>
#include <unistd.h>


#include <stdio.h>//getChar()
#include <stdio_ext.h>

#include "snake.h"
#include "my_snake.h"
#pragma once

struct termios term;

void abrir_buffer(){
    //*
    cin.ignore();
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    //*/
}
void cerrar_buffer(){
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    cin.ignore();
}


void keyboardEvent(char* key, bool* flag){
    abrir_buffer();

    while (*flag)
    {
        *key=getchar();
    }

    cerrar_buffer();
}

void snakeEvent(mySnake* snake){
    //snakeDirection(snake);
    //printMatrizChar(snake->M,snake->FILA,snake->COLUMNA);//-----
    //usleep(500 * 1000);
    snake ->redirect=  true;
}

//template<class T>
void keyEventSnake(mySnake* snake){
    abrir_buffer();

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
    


    cerrar_buffer();
}

/* Thread
void myThreadTwo(int b){
    for (int i = 0 ; i  < b; i++){
        cout<<"thread two "<<i<<endl;
        sleep(2);
    }
}
//*/