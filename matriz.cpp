#include <iostream>
#include <unistd.h>
#include "list.cpp"
#include <stdlib.h>
//#include <stdio.h>
/* 
g++ -pthread matriz.cpp -o matriz
./matriz
*/
#include <thread>

//#include <termios.h>
#include <unistd.h>

//#include  "clear.cpp"
#include "keyEvent.h"
#include "matriz.h"
#include "snake.h"
#include "my_snake.h"

//compile g++ -pthread  ...



//#pragma once



using namespace std;



int main(void){
    srand(time(NULL));

    mySnake snake = mySnake(11,23);
    //cout<<OS_Windows;
    snake.list.pushBack(nodeinfo(5,5));
    snake.list.pushBack(nodeinfo(5,6));
    snake.list.pushBack(nodeinfo(5,7));
    snake.list.pushBack(nodeinfo(5,8));

    snake.defineSnake();
    snake.defineFood();
    
    //thread th2(myThreadTwo,4);
    //*

    
    //int flag =0;
    thread th1(keyEventSnake , &snake);
    int timer = 0;
    int speed = 1;
    while (snake.flag)
    {
        if(snake.redirect || timer == 10*speed){
            timer = 0;
            snake.redirect = false;
            printMatrizChar(snake.M,snake.FILA,snake.COLUMNA);//-----
            snakeDirection(&snake);
        }
        
        
        usleep(10 * 1000);
        timer++;
        //sleep(2);
    }

    /*flag =0;
    while (flag<3)
    {
        printMatrizChar(M,FILA,COLUMNA);//-----
        snakeUp(&list,M,FILA,COLUMNA,1);
        flag++;
        usleep(500 * 1000);
    }

    flag =0;
    while (flag<4)
    {
        printMatrizChar(M,FILA,COLUMNA);//-----
        snakeLeft(&list,M,FILA,COLUMNA,1);
        flag++;
        usleep(500 * 1000);
    }

    flag =0;
    while (flag<4)
    {
        printMatrizChar(M,FILA,COLUMNA);//-----
        snakeDown(&list,M,FILA,COLUMNA,1);
        flag++;
        usleep( 500 * 1000);
    }

    //traverseBegin(list.front);
     //*/
    
    
    th1.join();
    //th2.join();

    return 0;
}