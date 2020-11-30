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

#include "clear.cpp"
#include "keyEvent.h"
#include "matriz.h"
#include "snake.h"
#include "my_snake.h"
#include "../scene/parameter_define.cpp"
//#include "../tools/gameStruct.h"

//compile g++ -pthread  ...

//#pragma once

using namespace std;
void close_buffer();
void open_buffer();

int redireccionando(myGame<nodeuserinfouser> *game)
{
    switch (game->key)
    {
    case '\n':
            //game->playing=false;
            //game->pause = true;
            //close_buffer();
            game->pause = true;
            shopMenu(game);
            game->snake.show();
            //open_buffer();
            game->pause = false;
            sleep(2);
            //game->pause=false;
            break;//finalizando hilo
    case 65: //up
        if (game->direccion != 2 && game->direccion != 1)
        {
            //game->redirection = true;
            game->direccion = 1;
        }
        break;
    case 66: //down
        if (game->direccion != 2 && game->direccion != 1)
        {
            //game->redirection = true;
            game->direccion = 2;
        }
        break;
    case 67: //right
        if (game->direccion != 3 && game->direccion != 4)
        {
            //game->redirection = true;
            game->direccion = 3;
        }
        break;
    case 68: //left
        if (game->direccion != 3 && game->direccion != 4)
        {
            //game->redirection = true;
            game->direccion = 4;
        }
        break;
    default:
        break;
    }
}

int playGame(myGame<nodeuserinfouser> *game)
{
    double timer = 0; // auxiliar para la velocidad
    while (game->playing)
    {
        //if (!game->pause)
        //{
            if (timer > 40 - game->snake.speed)
            {
                redireccionando(game);
                /*if (game->redirection)
                {
                    
                    game->redirection = false;
                }*/
                snakeDirection(game);
                game->snake.show();
                timer = 0;
            }
            timer++;
        //}
        
        usleep(10 * 1000);
    }
}

void playingGame(myGame<nodeuserinfouser> *game)
{
    thread th1(keyEventSnake, game);
    game->startGame();  // alzando banderas
    game->snake.show(); // mostrando serpiente
    sleep(2);           // tiempo de gracia (espera para iniciar)
    playGame(game);     //
    th1.detach();
    if (game->snake.sizeSnake == game->snake.sizeMax)
    {
        game->proxLevel = true;
    }
    //cout<<"murio el hilo"<<endl;
    //cin.get();
}

void restartingGame(myGame<nodeuserinfouser> *game)
{
    game->snake.deleteSnake();
    game->direccion = 3;
    for (int i = 0; i < game->snake.sizeSnake - 2; i++)
    {
        game->snake.list->pushBack(nodeinfo(5, 5)); //cargando serpiente
    }
    game->snake.list->pushBack(nodeinfo(5, 6));
    game->snake.list->pushBack(nodeinfo(5, 7));
    game->snake.defineSnake();
}

int playmatrix(myGame<nodeuserinfouser> *game)
{
    srand(time(NULL));
    //int level = 11;//[1,5]facil,[6,10]normal,[11,15]dificil
    int row, col, obstaculos, snkMax, velocidad;
    game->food = 1;

    if (game->mode == 1)
    { //juego clasico --continuo
        game->scene = 1;
        game->food++;
        if (game->user->info.vidas <= 0)
        {
            game->user->info.vidas = 5;
            game->user->info.nivel = 1;
        }
        //game->snake.lifes = game->user->info.vidas;
        while (game->user->info.nivel * game->scene > 9)
        { //eligiendo escenario clasico
            game->scene++;
            if (game->scene > 2)
            {
                CLEAR;
                snakeprint();
                mensageLine(w.ws_col, "Nuevo escenario");
                game->user->info.puntajeContinuar += game->snake.lifes * 100;
                cout << " se sumaron " << game->snake.lifes * 100 << " a tu puntaje actual por tus "
                     << game->snake.lifes << " restantes" << endl;
                mensageLine(w.ws_col, " presiona cualquier tecla para continuar");
                mensageSteep(w.ws_col);
                mensageMargin(w.ws_col);
                cin.ignore();
                getchar();
                return 1;
            }
        }
        sceneLevel(game->user->info.nivel, &row, &col, &obstaculos, &snkMax, &velocidad);
        game->difficulty = velocidad; //obteniendo ladificultad segun nivel actual
        game->snake.level = game->user->info.nivel;
        game->liveSpecial = game->user->info.vidas;
    }
    else if (game->mode == 2)
    {
        game->liveSpecial = 0;
        sceneLevel(game->levelSpecial, &row, &col, &obstaculos, &snkMax, &velocidad);
        obstaculos = 0;
        snkMax = 99999;
        game->snake.level = 1;
    }
    else //juego especial
    {
        game->food++;
        if (game->levelSpecial > 3)
        {

            CLEAR;
            snakeprint();
            mensageLine(w.ws_col, "Subiste de nivel");
            mensageLine(w.ws_col, " presiona cualquier tecla para continuar");
            mensageSteep(w.ws_col);
            mensageMargin(w.ws_col);
            cin.ignore();
            getchar();
            return 1;
        }
        sceneLevel(game->levelSpecial, &row, &col, &obstaculos, &snkMax, &velocidad);
        game->snake.level = game->liveSpecial;
    }
    game->snake.setLive(game->liveSpecial);
    game->snake.inicialiceMySnake(row, col);

    game->snake.list->pushBack(nodeinfo(5, 5)); //cargando serpiente
    game->snake.list->pushBack(nodeinfo(5, 6));
    game->snake.list->pushBack(nodeinfo(5, 7));
    game->snake.defineSnake();

    game->snake.defineScene(game->scene);
    game->snake.defineObst(obstaculos);
    for (int i = 0; i < game->food; i++)
    {
        game->snake.defineFood();
    }

    game->snake.initialSpeed = game->snake.initialSpeed - game->difficulty; //nivel de velocidad
    game->snake.sizeMax = snkMax;


    //thread th2(myThreadTwo,4);
    //*

    playingGame(game);

    while (!game->proxLevel && gameOverMenu(game))
    {
        restartingGame(game);
        playingGame(game);
        //game->liveSpecial++;
    }

    if (game->mode)
    {
        if (game->snake.lifes <= 0)
        {
            game->user->info.vidas = 5;
            game->user->info.nivel = 1;
        }
    }

    if (game->proxLevel)
    {
        CLEAR;
        snakeprint();
        mensageLine(w.ws_col, "Subiste de nivel");
        mensageLine(w.ws_col, " presiona cualquier tecla para continuar");
        mensageSteep(w.ws_col);
        mensageMargin(w.ws_col);
        cin.ignore();
        getchar();
        if (game->mode)
        {
            game->user->info.vidas = game->snake.lifes;
            game->user->info.nivel++;
        }
        else
        {
            game->levelSpecial++;
        }
        playmatrix(game);
        game->proxLevel = false;
    }

    //th1.join();
    //th2.join();

    return 0;
}