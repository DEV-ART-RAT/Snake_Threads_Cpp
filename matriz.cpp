#include <iostream>
#include <unistd.h>
#include "list.cpp"
#include <stdlib.h>
//#include <stdio.h>

#include <thread>

//#include <termios.h>
#include <unistd.h>

//#include  "clear.cpp"
#include "keyEvent.h"
#include "matriz.h"
#include "snake.h"

//compile g++ -pthread  ...



//#pragma once

using namespace std;

int main(void){

    charMatriz M;
    int FILA = 11;
    int COLUMNA = 23;
    char key = '0';
    int dir = 3;
    bool flag = true;
    //cout<<OS_Windows;

    getMatrizChar(&M,FILA,COLUMNA);//tamaño 11x11
    

    doubleLinked <nodeinfo> list;
    list.pushBack(nodeinfo(5,5));
    list.pushBack(nodeinfo(5,6));
    list.pushBack(nodeinfo(5,7));
    list.pushBack(nodeinfo(5,8));
    thread th1(keyboardEvent,&key,&flag);
    //thread th2(myThreadTwo,4);
    //*

    defineSnake(list,M,FILA,COLUMNA);
    defineFood(M,&FILA,&COLUMNA);
    //int flag =0;
    while (flag)
    {
        printMatrizChar(M,FILA,COLUMNA);//-----
        switch (key)
        {
        case '\n':
            flag=false;
            break;
        case 65:
            dir = (dir!=2)? 1 : 2;
            break;
        case 66:
            dir = (dir!=1)? 2 : 1;
            break;
        case 67:
            dir = (dir!=4)? 3 : 4;
            break;
        case 68:
            dir = (dir!=3)? 4 : 3;
            break;
        default:
            break;
        }
        snakeDirection(&list,M,&FILA,&COLUMNA,1,&dir);
        //snakeRight(&list,M,FILA,COLUMNA,1);
        //flag++;
        usleep(500 * 1000);
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