#pragma once
#include <iostream>
#include "../tools/screenControl.h"

using namespace std;

//Here we make the game responsive

/**Terminal size
 * *row and *col gets the dimension of terminal
 */
void sceneSize(int level, int* row, int* col){
    winsize w = screenSize();
    *row = w.ws_row - 5;
    *col = w.ws_col / 2;

    switch (level)
    {
    //60% Screen 
    case 1: 
        *col  *= 0.4;
        break;
    //80% Screen 
    case 2:
        *col  *= 0.7;
        break;
    default:
        *col -= 4;
        break;
    }

    if (*col<30){
        *col=30;
    }
    if (*row<10){
        *row=10;
    }
}
/**Determines total of obstacles by dificulty and terminal size
 * *cel obtains total of obstacles using some parameters *obstaculos(cel)
 * *snk gets the max size of the snake
 */ 
void sceneLevelDif(int level, int* row, int* col, int* cel, int* snk){
    *cel = (*row) + (*col);
    *snk = *cel * 0.7;
    switch (level)
    {
    //cells 0%
    case 1: 
        *cel  *= 0.10;
        *snk = (*snk>10)? 10: *snk;
        break;
    //cells 5%
    case 2: 
        *cel  *= 0.20;
        *snk = (*snk>20)? 20: *snk;
        break;
    //cells 10%
    case 3:
        *cel  *= 0.30;
        *snk = (*snk>30)? 30: *snk;
        break;
    default:
        break;
    }
}

//Determines volocity according level
void sceneLevel(int level, int* row, int* col, int* obstaculos,int* snkMax,int* velocidad){
    //base level
    *velocidad = 1;
    while(level > 3){
        *velocidad++;
        if(*velocidad > 3){
            *velocidad=1;
        }
        level -= 3;
    }
    sceneSize(level,row,col);
    sceneLevelDif(level,row,col,obstaculos,snkMax);
}
