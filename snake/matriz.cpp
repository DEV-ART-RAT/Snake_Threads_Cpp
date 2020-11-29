#include <iostream>
#include <unistd.h>
#include "../tools/list.h"
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
#include "../scene/parameter_define.cpp"

//compile g++ -pthread  ...



//#pragma once



using namespace std;



int playmatrix(mySnake* snake, int difficulty, int mode){
    srand(time(NULL));
    int level = 11;//[1,5]facil,[6,10]normal,[11,15]dificil
    int row, col , obstaculos, snkMax;

    sceneLevel(level, &row, &col, &obstaculos,&snkMax);
    snake->inicialiceMySnake(row,col);

    snake->list.pushBack(nodeinfo(5,5));
    snake->list.pushBack(nodeinfo(5,6));
    snake->list.pushBack(nodeinfo(5,7));
    snake->list.pushBack(nodeinfo(5,8));

    snake->defineSnake();
    snake->defineFood();
    snake->defineLevel(difficulty);
        
    snake->initialSpeed = snake->initialSpeed - difficulty;
    
    //thread th2(myThreadTwo,4);
    //*

    thread th1(keyEventSnake , snake);
    double timer = 0;
    
    snake->show();
    sleep(1);

    
    while (snake->flag)
    {
                    
        if(snake->redirect || timer == 10 * snake->speed){
            timer = 0;
            snake->redirect = false;
            snake->show();
            //printMatrizChar(snake->M,snake->FILA,snake->COLUMNA);//-----
            snakeDirection(snake);
        }
        
        
        usleep(10 * 1000);
        timer++;
        //sleep(2);
    }

    
    
    th1.join();
    //th2.join();

    return 0;
}