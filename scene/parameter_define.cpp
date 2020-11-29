#include <iostream>
#include "../tools/screenControl.h"

using namespace std;

//tamaño de terminal
void sceneSize(int level, int* row, int* col){
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    *row = w.ws_row - 5;
    *col = w.ws_col / 2;

    //cout<<"leve: "<<level <<"  col: "<<*col<<"  row: "<<*row<<endl;
    //cin.get();
    //level=6;

    switch (level)
    {
    /*case 1: // pantalla 20%
        *col  *= 0.2;
        break;
    case 2: // pantalla 40%
        *col  *= 0.4;
        break;*/
    case 1: // pantalla 60%
        *col  *= 0.6;
        break;
    case 2: // pantalla 80%
        *col  *= 0.8;
        break;
    default:
        *col -= 5;
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
    *cel = (*row) * (*col);//obteniendo el numero total de *celdas
    *snk = *cel;
    switch (level)
    {
    case 1: // celdas 0%
        *cel  *= 0;
        *snk *= 0.3; //tamaño MAX de snake
        break;
    case 2: // celdas 5%
        *cel  *= 0.5;
        *snk *= 0.6; //tamaño MAX de snake
        break;
    case 3: // celdas 10%
        *cel  *= 0.1;
        *snk *= 0.9; //tamaño MAX de snake
        break;
    case 4: // celdas 15%
        *cel  *= 0.15;
        break;
    case 5: // celdas 20%
        *cel  *= 0.2;
        *snk *= 0.12; //tamaño MAX de snake
        break;
    default:
        break;
    }
}

void sceneLevel(int level, int* row, int* col, int* obstaculos,int* snkMax){
    int levelTwo = 1;//nivel base

    while(level > 3){
        levelTwo++;
        level -= 3;
    }
    sceneSize(level,row,col);
    sceneLevelDif(levelTwo,row,col,obstaculos,snkMax);
}

/*
int main(void){
    int level = 5, row, col, obst;
    sceneSize(level,&row,&col);
    sceneLevelDif(level,&row,&col,&obst);

    cout<<"sizeRow: "<<row<<" , sizeCol: "<<col<<" , numObst: "<<obst<<endl;



    return 0;
}

 //*/