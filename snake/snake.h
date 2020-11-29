#pragma once

#include "../tools/gameStruct.h"
#include "matriz.h"
//#include "../tools/gameStruct.h"

using namespace std;





/*template<class T>
void defineSnake(doubleLinked<T> list, charMatriz M, int fil, int col){
    for(node<T>* e = list->front; e!=NULL; e=e->next){
        if(e->info.i>=fil)
            e->info.i=0;
        if(e->info.j>=col)
        e->info.j=0;
        M[e->info.i][e->info.j]=SNAKE;
        //cout<<"e.i"<<e->info.i<<" e.j"<<e->info.j<<" ;";
    }

}*/

/*void defineFood(charMatriz M, int* fil, int* col){
    int i , j;
    do{
        i = getIntRand( 0 , *fil - 1 );
        j = getIntRand( 0 , *col - 1 );
    }while (M[i][j]!=SCENE);
    M[i][j] = FOOD;
}*/

//template<class T>
void snakeDel(myGame<nodeuserinfouser>* game){
    node<nodeinfo>* n = game->snake.list->removeFront();
    game->snake.M[n->info.i][n->info.j]=' ';
    delete(n);
}

//template<class T>
void snakeNew(myGame<nodeuserinfouser>* game, int fil, int col){
    game->snake.list->pushBack(nodeinfo(fil,col));
    if(game->snake.M[fil][col]== FOOD ){
        //list->pushFront(T(fil,col));
        game->snake.sizeSnake = game->snake.sizeSnake + 1;
        //cout << game->snake.speed;
        int max = game->snake.sizeMax;
        if(game->snake.sizeSnake < max*0.2)
            game->snake.speed = game->snake.initialSpeed * 0.8;
        else if (game->snake.sizeSnake < max*0.4)
            game->snake.speed = game->snake.initialSpeed  * 0.6;
        else if (game->snake.sizeSnake < max*0.5)
            game->snake.speed = game->snake.initialSpeed  * 0.5;
        else if (game->snake.sizeSnake < max*0.60)
            game->snake.speed = game->snake.initialSpeed  * 0.4;
        else if (game->snake.sizeSnake < max*0.80)
            game->snake.speed = game->snake.initialSpeed  * 0.3;
        else if (game->snake.sizeSnake < max * 1.2)
            game->snake.speed = game->snake.initialSpeed  * 0.2;
        else
            game->snake.speed = game->snake.initialSpeed  * 0.1;
            
        game->snake.defineFood();
        //M[fil][col]='*';
    }else if(game->snake.M[fil][col]==SNAKE || game->snake.M[fil][col]==WALL){
        game->snake.flag = false;
        game->snake.M[fil][col]=CRASH;
        game->snake.show();
        //printMatrizChar(game->snake.M,game->snake.FILA,game->snake.COLUMNA);//-----
        cout<<"GAME OVER >:´v"<<endl;

    }else
    {
        snakeDel(game);
    }    
    game->snake.M[fil][col]=SNAKE;
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
    switch (game->snake.dir)
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