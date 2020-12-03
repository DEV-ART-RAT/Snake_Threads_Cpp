#pragma once

#include "matriz.h"

#include "../tools/gameStruct.h"

using namespace std;


/** Function that calculates points increasing depending on game mode and (if has it) level
 */
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

/** Function that deletes the snake in the double list and matrix
 */
void snakeDel(myGame<nodeuserinfouser>* game){
    node<nodeinfo>* n = game->snake.list->removeFront();
    game->snake.M[n->info.i][n->info.j]=' ';
    delete(n);
}

/** Function that caluclates changes of snake's velocity depending on its size, difficulty, and level
 */
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

/** Function that increases snake's size, velocity 
 *  user's points and coins when  the snake eats
 *  Or just continue snake's direction
 */
void snakeNew(myGame<nodeuserinfouser>* game, int fil, int col){
    game->snake.list->pushBack(nodeinfo(fil,col));
    if(game->snake.M[fil][col]== FOOD ){
        changeVelocity(game);
        game->snake.sizeSnake++;
        //Increments coins according the difficuly
        game->user->info.coin+=10*game->difficulty;
        increasePoints(game);
        if(game->snake.sizeSnake == game->snake.sizeMax){
            game->playing = false;
        }
        game->snake.defineFood();
        game->snake.M[fil][col]=SNAKE;
    }else if(game->snake.M[fil][col]==SNAKE || game->snake.M[fil][col]==WALL){
        game->playing = false;
        game->snake.M[fil][col]=CRASH;
        game->mostrarCabeceraSnake();
        game->snake.show();
        game->snake.list->removeBack();
        game->snake.M[fil][col]=WALL;

    }else
    {
        snakeDel(game);
        game->snake.M[fil][col]=SNAKE;
    }    

}


/** Function that changes snake's direction or orientation to the right
 */
void snakeRight(myGame<nodeuserinfouser>* game){
    int prevF= game->snake.list->back->info.i;
    int prevC= game->snake.list->back->info.j;
    for(int k = 0; k< game->snake.steep;k++){
        prevC++;
        if(prevC>=game->snake.COLUMNA){
            prevC=0;
        }
        snakeNew(game,prevF,prevC);
    }
}

/** Function that changes snake's direction or orientation to the left
 */
void snakeLeft(myGame<nodeuserinfouser>* game){
    int prevF= game->snake.list->back->info.i;
    int prevC= game->snake.list->back->info.j;
    for(int k = 0; k< game->snake.steep;k++){
        prevC--;
        if(prevC < 0){
            prevC = game->snake.COLUMNA -1;
        }
        snakeNew(game,prevF,prevC);
    }
}

/** Function that changes snake's direction or orientation up
 */
void snakeUp(myGame<nodeuserinfouser>* game){
    int prevF= game->snake.list->back->info.i;
    int prevC= game->snake.list->back->info.j;
    for(int k = 0; k< game->snake.steep;k++){
        prevF--;
        if(prevF < 0){
            prevF = game->snake.FILA - 1;
        }
        snakeNew(game,prevF,prevC);
    }
}

/** Function that changes snake's direction or orientation above
 */
void snakeDown(myGame<nodeuserinfouser>* game){
    int prevF= game->snake.list->back->info.i;
    int prevC= game->snake.list->back->info.j;
    for(int k = 0; k< game->snake.steep;k++){
        prevF++;
        if(prevF >= game->snake.FILA){
            prevF = 0;
        }
        snakeNew(game,prevF,prevC);
    }
}

/** Function that determines snake's direction and calls one of the four functions above
 */
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