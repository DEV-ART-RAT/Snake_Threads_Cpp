#pragma once
#include <thread>
#include <iostream>

#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>

#include "../scene/scenaryCreator.h"
#include "snake.h"
#include "matriz.h"
#include "clear.cpp"
#include "keyEvent.h"
#include "my_snake.h"
#include "../scene/parameter_define.cpp"



using namespace std;
void close_buffer();
void open_buffer();

int redireccionando(myGame<nodeuserinfouser> *game)
{
    switch (game->key)
    {
    case '\n':
            game->pause = true;
            shopMenu(game);
            game->snake.show();
            game->pause = false;
            sleep(2);
            game->key = '0';
            break;//finalizando hilo
    case 65: //up
        if (game->direccion != 2 && game->direccion != 1)
            game->direccion = 1;
        break;
    case 66: //down
        if (game->direccion != 2 && game->direccion != 1)
            game->direccion = 2;
        break;
    case 67: //right
        if (game->direccion != 3 && game->direccion != 4)
            game->direccion = 3;
        break;
    case 68: //left
        if (game->direccion != 3 && game->direccion != 4)
            game->direccion = 4;
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
        if (timer > 10 * game->snake.speed)
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

void nextStage(myGame<nodeuserinfouser> *game){
    CLEAR;
    snakeprint();
    mensageLine(w.ws_col, "Completaste el escenario");
    game->user->info.puntajeContinuar += game->snake.lifes * 100 + game->snake.points;
    cout << " se sumaron " << game->snake.lifes * 100 << " a tu puntaje actual por tus "
            << game->snake.lifes << " restantes" << endl;
    mensageLine(w.ws_col, " presiona cualquier tecla para continuar");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
    cin.clear();
    getchar();
}

void nextStageLevel(myGame<nodeuserinfouser> *game){
    CLEAR;
    snakeprint();
    mensageLine(w.ws_col, "Completaste el escenario");
    mensageLine(w.ws_col, " presiona cualquier tecla para continuar");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
    cin.clear();
    getchar();
}

int playmatrix(myGame<nodeuserinfouser> *game)
{
    srand(time(NULL));
    int row, col, obstaculos, snkMax, velocidad;
    game->food = 1;
    if (game->mode == 1)
    { //juego clasico --continuo
        game->scene = 1;
        game->food++;
        game->snake.points = game->user->info.puntajeContinuar;
        if (game->user->info.vidas <= 0)
        {
            game->user->info.vidas = 5;
            game->user->info.nivel = 1;
        }
        while (game->user->info.nivel * game->scene > 9)
        { //eligiendo escenario clasico
            game->scene++;
            if (game->scene > 2)
            {
                nextStage(game);
                game->user->info.puntajeContinuar = 0;
                game->user->info.vidas = 5;
                game->user->info.nivel = 1;
                if(game->user->info.puntajeContinuar > game->user->info.puntaje){
                    game->user->info.puntaje = game->user->info.puntajeContinuar;
                }
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
            nextStageLevel(game);
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

    defineScene(game);
    game->snake.defineSnake();
    game->snake.defineObst(obstaculos);
    for (int i = 0; i < game->food; i++)
    {
        game->snake.defineFood();
    }
    game->snake.initialSpeed = game->snake.initialSpeed - game->difficulty; //nivel de velocidad
    game->snake.sizeMax = snkMax;
    playingGame(game);
    while (!game->proxLevel && gameOverMenu(game))
    {
        restartingGame(game);
        playingGame(game);
        //game->liveSpecial++;
    }
    if (game->mode == 1)
    {    
        game->snake.x2Boosted = false;
        game->snake.x3Boosted = false;
        if(game->user->info.puntaje < game->snake.points){
            game->user->info.puntaje = game->snake.points;
        }

        if (game->snake.lifes <= 0)
        {
            game->user->info.vidas = 5;
            game->user->info.nivel = 1;
            game->snake.points = 0;
        }
        game->user->info.puntajeContinuar = game->snake.points;
    }

    if (game->mode == 2)
    {   
        game->snake.x2Boosted = false;
        game->snake.x3Boosted = false;

        //Cambiar este if por puntaje clasico
        if(game->user->info.puntaje < game->snake.points){
            game->user->info.puntaje = game->snake.points;
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
        cin.clear();
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
        game->proxLevel = false;
        playmatrix(game);
    }
    return 0;
}