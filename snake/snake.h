#pragma once

#include "matriz.h"
#include "../tools/gameStruct.h"

using namespace std;


void increasePoints(myGame<nodeuserinfouser>* game){
    switch (game->mode)
    {
    case 1:
        game->snake.points += 10;
        break;
    case 2:
        game->snake.points += 50;
        break;
    case 3:
        game->snake.points += 100;
        break;
    default:
        break;
    }
}

//template<class T>
void snakeDel(myGame<nodeuserinfouser>* game){
    node<nodeinfo>* n = game->snake.list->removeFront();
    game->snake.M[n->info.i][n->info.j]=' ';
    delete(n);
}

//template<class T>

void changeVelocity(myGame<nodeuserinfouser>* game){
    int max = game->snake.velMax;
    if(game->snake.sizeSnake < max)
        game->snake.speed = ((max - game->snake.sizeSnake) * 0.15) + 0.5;
    else if(game->snake.sizeSnake > max *2)
        game->snake.speed = 0.3;
    else
        game->snake.speed = 0.5;
    
}

void snakeNew(myGame<nodeuserinfouser>* game, int fil, int col){
    game->snake.list->pushBack(nodeinfo(fil,col));
    if(game->snake.M[fil][col]== FOOD ){
        changeVelocity(game);
        game->snake.sizeSnake++;
        increasePoints(game);
        if(game->snake.sizeSnake == game->snake.sizeMax){
            game->playing = false;
        }
        game->snake.defineFood();
        game->snake.M[fil][col]=SNAKE;
        //M[fil][col]='*';
    }else if(game->snake.M[fil][col]==SNAKE || game->snake.M[fil][col]==WALL){
        game->playing = false;
        game->snake.M[fil][col]=CRASH;
        game->snake.show();
        game->snake.list->removeBack();
        game->snake.M[fil][col]=WALL;
        //printMatrizChar(game->snake.M,game->snake.FILA,game->snake.COLUMNA);//-----
        //cout<<"GAME OVER >:´v"<<endl;

    }else
    {
        snakeDel(game);
        game->snake.M[fil][col]=SNAKE;
    }    
    
    //cout<<"voy en:"<<game->snake.list->back->info;
    //cin.get();
}


//template<class T>
void snakeRight(myGame<nodeuserinfouser>* game){
    int prevF= game->snake.list->back->info.i;
    int prevC= game->snake.list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< game->snake.steep;k++){
        prevC++;
        if(prevC>=game->snake.COLUMNA){
            prevC=0;
        }
        snakeNew(game,prevF,prevC);
        //snakeDel(list,M);
    }
}

/*
void speedBooster(myGame<nodeuserinfouser>* game){
        int max = 30;
        if(game->snake.sizeSnake < max*0.2)
            game->snake.speed = game->snake.initialSpeed * 0.8;
        else if (game->snake.sizeSnake < max*0.4)
            game->snake.speed = game->snake.initialSpeed  * 0.6;
        else if (game->snake.sizeSnake < max*0.5)
            game->snake.speed = game->snake.initialSpeed * 0.5;
        else if (game->snake.sizeSnake < max*0.60)
            game->snake.speed = game->snake.initialSpeed  * 0.4;
        else if (game->snake.sizeSnake < max*0.80)
            game->snake.speed = game->snake.initialSpeed  * 0.3;
        else if (game->snake.sizeSnake < max * 1.2)
            game->snake.speed = game->snake.initialSpeed  * 0.2;
        else
            game->snake.speed = game->snake.initialSpeed  * 0.1;
}
*/

//template<class T>
void snakeLeft(myGame<nodeuserinfouser>* game){
    int prevF= game->snake.list->back->info.i;
    int prevC= game->snake.list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< game->snake.steep;k++){
        prevC--;
        if(prevC < 0){
            prevC = game->snake.COLUMNA -1;
        }
        snakeNew(game,prevF,prevC);
        //snakeDel(list,M);
    }
}

//template<class T>
void snakeUp(myGame<nodeuserinfouser>* game){
    int prevF= game->snake.list->back->info.i;
    int prevC= game->snake.list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< game->snake.steep;k++){
        prevF--;
        if(prevF < 0){
            prevF = game->snake.FILA - 1;
        }
        snakeNew(game,prevF,prevC);
        //snakeDel(list,M);
    }
}

//template<class T>
void snakeDown(myGame<nodeuserinfouser>* game){
    int prevF= game->snake.list->back->info.i;
    int prevC= game->snake.list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< game->snake.steep;k++){
        prevF++;
        if(prevF >= game->snake.FILA){
            prevF = 0;
        }
        snakeNew(game,prevF,prevC);
        //snakeDel(list,M);
    }
}

//template<class T>
void snakeDirection(myGame<nodeuserinfouser>* game){
    switch (game->direccion)
        {
        case 1:
            snakeUp(game);
            break;
        case 2:
            snakeDown(game);
            break;
        case 3:
            snakeRight(game);
            break;
        case 4:
            snakeLeft(game);
            break;
        default:
            break;
        }
}