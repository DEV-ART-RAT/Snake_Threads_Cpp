#pragma once
#include <iostream>
#include <unistd.h>
//#include "../tools/list.h"
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
//#include "../tools/gameStruct.h"

//compile g++ -pthread  ...



//#pragma once



using namespace std;

int playGame(myGame<nodeuserinfouser>* game){
    double timer = 0;
    while (game->snake.flag)
    {
                    
        if(game->snake.redirect || timer == 10 * game->snake.speed){
            timer = 0;
            game->snake.redirect = false;
            game->snake.show();
            //printMatrizChar(snake->M,snake->FILA,snake->COLUMNA);//-----
            snakeDirection(game);
            cout<<"cabeza: "<<game->list.back<<"  direccion: "<<game->snake.dir;
            cin.get();
        }
        
        
        usleep(10 * 1000);
        timer++;
        //sleep(2);
    }
}

void playingGame(myGame<nodeuserinfouser>* game){
    thread th1(keyEventSnake , game);
    game->snake.flag=true;
    game->snake.show();
    sleep(2);
    playGame(game);
    th1.detach();
    cout<<"murio el hilo"<<endl;
    cin.get();
}

void restartingGame(myGame<nodeuserinfouser>* game){
    game->snake.deleteSnake();
    for(int i = 0 ; i < game->snake.sizeSnake - 2;i++){
        game->snake.list->pushBack(nodeinfo(5,5));//cargando serpiente
    }
    game->snake.list->pushBack(nodeinfo(5,6));
    game->snake.list->pushBack(nodeinfo(5,7));
    game->snake.defineSnake();
}

int playmatrix(myGame<nodeuserinfouser>* game){
    srand(time(NULL));
    //int level = 11;//[1,5]facil,[6,10]normal,[11,15]dificil
    int row, col , obstaculos, snkMax, velocidad;

    
    if(game->mode){//juego clasico --continuo
        game->scene =  1;
        while (game->user->info.nivel * game->scene > 9){//eligiendo escenario clasico
            game->scene++;
        }
        sceneLevel(game->user->info.nivel, &row, &col, &obstaculos,&snkMax,&velocidad);
        game->difficulty = velocidad;//obteniendo ladificultad segun nivel actual
    }else//juego especial
    {
        sceneLevel(game->levelSpecial, &row, &col, &obstaculos,&snkMax,&velocidad);
    }
    
    game->snake.inicialiceMySnake(row,col);

    game->snake.list->pushBack(nodeinfo(5,5));//cargando serpiente
    game->snake.list->pushBack(nodeinfo(5,6));
    game->snake.list->pushBack(nodeinfo(5,7));
    game->snake.defineSnake();

    game->snake.defineScene(game->scene);
    game->snake.defineObst(obstaculos);
    game->snake.defineFood();
    game->snake.defineFood();
    
    game->snake.initialSpeed = game->snake.initialSpeed - game->difficulty;//nivel de velocidad
    game->snake.sizeMax = snkMax;
    
    //thread th2(myThreadTwo,4);
    //*

    playingGame(game);

    while (gameOverMenu(game))
    {
        restartingGame(game);
        playingGame(game);
        
    }

    
    
    //th1.join();
    //th2.join();

    return 0;
}