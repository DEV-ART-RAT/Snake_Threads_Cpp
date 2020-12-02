#pragma once
#include <iostream>
#include "../tools/screenControl.h"

using namespace std;

//tamaño de terminal
void sceneSize(int level, int* row, int* col){
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    *row = w.ws_row - 5;
    *col = w.ws_col / 2;
    switch (level)
    {
    case 1: // pantalla 60%
        *col  *= 0.4;
        break;
    case 2: // pantalla 80%
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
//total de obstaculos segun dificulatad y tamaño de teminal
void sceneLevelDif(int level, int* row, int* col, int* cel, int* snk){
    *cel = (*row) + (*col);//obteniendo el numero total de *obstaculos(cel)
    *snk = *cel * 0.7;
    switch (level)
    {
    case 1: // celdas 0%
        *cel  *= 0.10;
        *snk = (*snk>15)? 15: *snk;
        //*snk *= 0.3; //tamaño MAX de snake
        break;
    case 2: // celdas 5%
        *cel  *= 0.20;
        *snk = (*snk>25)? 25: *snk;
        //*snk *= 0.6; //tamaño MAX de snake
        break;
    case 3: // celdas 10%
        *cel  *= 0.30;
        //*snk *= ; //tamaño MAX de snake
        *snk = (*snk>50)? 50: *snk;
        break;
    default:
        break;
    }
}
void sceneLevel(int level, int* row, int* col, int* obstaculos,int* snkMax,int* velocidad){
    *velocidad = 1;//nivel base
    while(level > 3){
        *velocidad++;
        if(*velocidad > 3){
            *velocidad=1;
        }
        level -= 3;
    }
    sceneSize(level,row,col);
    sceneLevelDif(level,row,col,obstaculos,snkMax);
    //*snkMax=5;
}
