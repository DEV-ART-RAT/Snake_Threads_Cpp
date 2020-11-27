#include "matriz.h"
#include "my_snake.h"

#pragma once





/*template<class T>
void defineSnake(doubleLinked<T> list, charMatriz M, int fil, int col){
    for(node<T>* e = list.front; e!=NULL; e=e->next){
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
void snakeDel(mySnake* snake){
    node<nodeinfo>* n = snake->list.removeFront();
    snake->M[n->info.i][n->info.j]=' ';
    delete(n);
}

//template<class T>
void snakeNew(mySnake* snake, int fil, int col){
    snake->list.pushBack(nodeinfo(fil,col));
    if(snake->M[fil][col]== FOOD ){
        //list.pushFront(T(fil,col));
        snake->sizeSnake = snake->sizeSnake + 1;
        //cout << snake->speed;
        int max = snake->sizeMax;
        if(snake->sizeSnake < max*0.2)
            snake->speed = snake->initialSpeed * 0.8;
        else if (snake->sizeSnake < max*0.4)
            snake->speed = snake->initialSpeed  * 0.6;
        else if (snake->sizeSnake < max*0.5)
            snake->speed = snake->initialSpeed  * 0.5;
        else if (snake->sizeSnake < max*0.60)
            snake->speed = snake->initialSpeed  * 0.4;
        else if (snake->sizeSnake < max*0.80)
            snake->speed = snake->initialSpeed  * 0.3;
        else if (snake->sizeSnake < max * 1.2)
            snake->speed = snake->initialSpeed  * 0.2;
        else
            snake->speed = snake->initialSpeed  * 0.1;
            
        snake->defineFood();
        //M[fil][col]='*';
    }else if(snake->M[fil][col]==SNAKE || snake->M[fil][col]==WALL){
        snake->flag = false;
        snake->M[fil][col]=CRASH;
        snake->show();
        //printMatrizChar(snake->M,snake->FILA,snake->COLUMNA);//-----
        cout<<"GAME OVER >:´v"<<endl;

    }else
    {
        snakeDel(snake);
    }    
    snake->M[fil][col]=SNAKE;
}


//template<class T>
void snakeRight(mySnake* snake){
    int prevF= snake->list.back->info.i;
    int prevC= snake->list.back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< snake->steep;k++){
        prevC++;
        if(prevC>=snake->COLUMNA){
            prevC=0;
        }
        snakeNew(snake,prevF,prevC);
        //snakeDel(list,M);
    }
}

/*
void speedBooster(mySnake* snake){
        int max = 30;
        if(snake->sizeSnake < max*0.2)
            snake->speed = snake->initialSpeed * 0.8;
        else if (snake->sizeSnake < max*0.4)
            snake->speed = snake->initialSpeed  * 0.6;
        else if (snake->sizeSnake < max*0.5)
            snake->speed = snake->initialSpeed * 0.5;
        else if (snake->sizeSnake < max*0.60)
            snake->speed = snake->initialSpeed  * 0.4;
        else if (snake->sizeSnake < max*0.80)
            snake->speed = snake->initialSpeed  * 0.3;
        else if (snake->sizeSnake < max * 1.2)
            snake->speed = snake->initialSpeed  * 0.2;
        else
            snake->speed = snake->initialSpeed  * 0.1;
}
*/

//template<class T>
void snakeLeft(mySnake* snake){
    int prevF= snake->list.back->info.i;
    int prevC= snake->list.back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< snake->steep;k++){
        prevC--;
        if(prevC < 0){
            prevC = snake->COLUMNA -1;
        }
        snakeNew(snake,prevF,prevC);
        //snakeDel(list,M);
    }
}

//template<class T>
void snakeUp(mySnake* snake){
    int prevF= snake->list.back->info.i;
    int prevC= snake->list.back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< snake->steep;k++){
        prevF--;
        if(prevF < 0){
            prevF = snake->FILA - 1;
        }
        snakeNew(snake,prevF,prevC);
        //snakeDel(list,M);
    }
}

//template<class T>
void snakeDown(mySnake* snake){
    int prevF= snake->list.back->info.i;
    int prevC= snake->list.back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< snake->steep;k++){
        prevF++;
        if(prevF >= snake->FILA){
            prevF = 0;
        }
        snakeNew(snake,prevF,prevC);
        //snakeDel(list,M);
    }
}

//template<class T>
void snakeDirection(mySnake* snake){
    switch (snake->dir)
        {
        case 1:
            snakeUp(snake);
            break;
        case 2:
            snakeDown(snake);
            break;
        case 3:
            snakeRight(snake);
            break;
        case 4:
            snakeLeft(snake);
            break;
        default:
            break;
        }
}