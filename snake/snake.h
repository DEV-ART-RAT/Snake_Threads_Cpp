#pragma once

#include "matriz.h"

#include "../tools/gameStruct.h"

using namespace std;

void increasePoints(myGame<nodeuserinfouser>* game){
    switch (game->mode)
    {
    case 1:
        if(game->snake.x2Boosted){
            game->snake.points += (100 + (game->snake.sizeSnake-3)*5 + game->snake.level*10)*2;
        }else if(game->snake.x3Boosted){
            game->snake.points += (100 + (game->snake.sizeSnake-3)*5 + game->snake.level*10)*3;
        }else{
            game->snake.points += 100 + (game->snake.sizeSnake-3)*5 + game->snake.level*10;
        }
        break;
    case 2:
        if(game->snake.x2Boosted){
            game->snake.points += (100 + (game->snake.sizeSnake-3)*5)*2;
        }else if(game->snake.x3Boosted){
            game->snake.points += (100 + (game->snake.sizeSnake-3)*5)*3;
        }else{
            game->snake.points += 100 + (game->snake.sizeSnake-3)*5;
        }
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
    int level = game->difficulty;
    max = max-(level*level);
    double velocity = 0.15;
    if(game->snake.sizeSnake < max)
        game->snake.speed = ((max-(level*level) - game->snake.sizeSnake) * velocity) + 0.5;
    else if(max <= game->snake.sizeSnake > max * 2)
        game->snake.speed = velocity*2.5;
    else if(max*2 <= game->snake.sizeSnake > max * 3)
        game->snake.speed = velocity * 1.5;
    else
        game->snake.speed = velocity;
    
}

void snakeNew(myGame<nodeuserinfouser>* game, int fil, int col){
    game->snake.list->pushBack(nodeinfo(fil,col));
    if(game->snake.M[fil][col]== FOOD ){
        changeVelocity(game);
        game->snake.sizeSnake++;
        game->user->info.coin+=10*game->difficulty;// esta linea incrementa las monedas segun su dificultad;
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
        game->mostrarCabeceraSnake();
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