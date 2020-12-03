#pragma once
#include <thread>
#include <iostream>

#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>

#include "../scene/scenaryCreator.h"
#include "snake.h"
#include "matriz.h"
#include "../tools/clear.cpp"
#include "keyEvent.h"
#include "my_snake.h"
#include "../scene/parameter_define.cpp"
#include "../views/pauseMenu.cpp"


using namespace std;
//Declarations
void loading();
void restartingGame(myGame<nodeuserinfouser> *game);
bool playingGame(myGame<nodeuserinfouser> *game);
const bool jugando=false;

/**
 * Function that redirects the orientation of the snake depending on the key pressed
 */
bool redireccionando(myGame<nodeuserinfouser> *game){
    bool exit = true;
    switch (game->key)
    {
    //enter => pause
    case '\n':
            //game->pause = true;
            exit = PauseMenu(game);
            game->key = '0';
            game->pause = false;
            //cin.clear();
            break;//finalizando hilo
    //up
    case 65: 
        if (game->direccion != 2 && game->direccion != 1)
            game->direccion = 1;
        break;
    //down
    case 66: 
        if (game->direccion != 2 && game->direccion != 1)
            game->direccion = 2;
        break;
    //right
    case 67: 
        if (game->direccion != 3 && game->direccion != 4)
            game->direccion = 3;
        break;
    //left
    case 68: 
        if (game->direccion != 3 && game->direccion != 4)
            game->direccion = 4;
        break;
    default:
        break;
    }
    return exit;
}

/** Funtion that checks if the game is been played
 */
bool playGame(myGame<nodeuserinfouser> *game){
    bool exit = true;
    double timer = 0; // auxiliar para la velocidad
    while (game->playing){
        if (timer > 10 * game->snake.speed)
        {
            if (!redireccionando(game)){
                exit =  false;
                break;
            }
            snakeDirection(game);
            game->mostrarCabeceraSnake();
            game->snake.show();
            timer = 0;
        }
        timer++;
        
        usleep(10 * 1000);
    }
    return exit;
}

/**Funtion that checks if the game pauses
 */
bool playingGame(myGame<nodeuserinfouser> *game)
{
    //loading();//Pantalla de carga
    //cin.clear();
    bool exit = true;
    thread th1(keyEventSnake, game);
    game->startGame();  // alzando banderas
    game->mostrarCabeceraSnake();
    game->snake.show(); // mostrando serpiente
    sleep(2);           // tiempo de gracia (espera para iniciar)
    exit = playGame(game);     //
    if (game->snake.sizeSnake == game->snake.sizeMax)
    {
        game->proxLevel = true;
    }
    //cin.clear();
    th1.detach();
    return exit;
}

/** Funtion that restarts game
 */
void restartingGame(myGame<nodeuserinfouser> *game)
{
    game->snake.deleteSnake();
    game->direccion = 3;
    for (int i = 0; i < game->snake.sizeSnake - 2; i++)
    {
        game->snake.list->pushBack(nodeinfo(5, 5)); //loading serpiente
    }
    game->snake.list->pushBack(nodeinfo(5, 6));
    game->snake.list->pushBack(nodeinfo(5, 7));
    game->snake.defineSnake();
}

/** Funtion that shows a screen when an Stage is completed
 */
void nextStage(myGame<nodeuserinfouser> *game){
    CLEAR;
    snakeprint();
    messageLine(w.ws_col, "Completaste el ....M-U-N-D-O... <|:v");
    game->user->info.Points_Save += game->snake.lifes * 100 + game->snake.points;
    cout << " se sumaron " << game->snake.lifes * 100 << " a tu Points actual por tus "
            << game->snake.lifes << " restantes" << endl;
    messageLine(w.ws_col, " presiona cualquier tecla para continuar");
    messageSteep(w.ws_col);
    messageMargin(w.ws_col);
    cin.clear();
    getchar();
}

/** Funtion that shows a screen when a level is completed
 */
void nextStageLevel(myGame<nodeuserinfouser> *game){
    CLEAR;
    snakeprint();
    messageLine(w.ws_col, "Completaste el escenario");
    messageLine(w.ws_col, " presiona cualquier tecla para continuar");
    messageSteep(w.ws_col);
    messageMargin(w.ws_col);
    cin.clear();
    getchar();
}

/** Funtion that loads World Party game mode
 */
void cargarModoWorldParty(myGame<nodeuserinfouser> *game, int* row, int* col, int* obstaculos,int* snkMax,int* velocidad){
    game->snake.points = game->user->info.Points_Save;
        if (game->user->info.Lifes <= 0){
            game->user->info.Lifes = 5;
            game->user->info.nivel = 1;
        }
        while (game->user->info.nivel * game->scene > 9)
        { //eligiendo escenario Clasic
            game->scene++;
            if (game->scene > 2){
                nextStage(game);
                if(game->user->info.Points_Save > game->user->info.Points){
                    game->user->info.Points = game->user->info.Points_Save;
                }
                game->user->info.Points_Save = 0;
                game->user->info.Lifes = 5;
                game->user->info.nivel = 1;
                return;
            }
        }
        sceneLevel(game->user->info.nivel, row, col, obstaculos, snkMax, velocidad);
        game->difficulty = *velocidad; //obteniendo ladificultad segun nivel actual
        game->snake.level = game->user->info.nivel;
        game->liveSpecial = game->user->info.Lifes;
}

/** Funtion that checks the option selected from user to determine game mode
 * and its difficulty if it has it
 * sets user parameters 
 * and saves the progress data in the .csv file
 */
int playmatrix(myGame<nodeuserinfouser> *game){
    //variables to storage key parameters
    int row, col, obstaculos, snkMax, velocidad;

    //Loads World Party game mode
    if (game->mode == 1){ 

        cargarModoWorldParty(game,&row,&col,&obstaculos,&snkMax,&velocidad);

    }
    //Loads classic 97 game mode
    else if (game->mode == 2)
    {
        game->liveSpecial = 0;

        sceneLevel(0, &row, &col, &obstaculos, &snkMax, &velocidad);
        obstaculos = 0;
        snkMax = 99999;
        game->snake.level = 1;
        game->difficulty = velocidad;
        
    }
    //Loads special game mode
    else { 
        if (game->levelSpecial > 3)
        {
            nextStageLevel(game);
            return 1;
        }
        sceneLevel(game->levelSpecial, &row, &col, &obstaculos, &snkMax, &velocidad);
        game->snake.level = game->levelSpecial;
    }
    
    //Gamer lifes of game to be played
    game->snake.setLive(game->liveSpecial);
    game->snake.inicialiceMySnake(row, col);

    //Loads initial snake with three nodes
    game->snake.list->pushBack(nodeinfo(5, 5)); 
    game->snake.list->pushBack(nodeinfo(5, 6));
    game->snake.list->pushBack(nodeinfo(5, 7));

    //Defines the scene to be showed
    defineScene(game);
    game->snake.defineSnake();
    game->snake.defineObst(obstaculos);
    for (int i = 0; i < game->food; i++)
    {
        game->snake.defineFood();
    }

    //Define velocity depending on levels
    game->snake.initialSpeed = game->snake.initialSpeed - game->difficulty;

    //Defines snake max size
    game->snake.sizeMax = snkMax;

    //Determines if the player looses or continues playing
    bool inExit = true;
    inExit = playingGame(game);
    while (inExit && !game->proxLevel)
    {
        if(!gameOverMenu(game)){
            break;
        }
        restartingGame(game);
        inExit = playingGame(game);
    }

    // Saving player lifes
    // by rubi
    if(game->mode!=2){
        if(game->snake.lifes>0){
            game->user->info.Lifes=game->snake.lifes;
        }else{
            game->user->info.Lifes=0;
        }            
    }

    //Saving progress at .csv file
    // by rubi
    saveincsv(game->list.front);

    // When 'Game over' restarts some values depending on game mode
    // and saves progress
    if (game->mode == 1){    
        game->snake.x2Boosted = false;
        game->snake.x3Boosted = false;

        game->user->info.Points_Save = game->snake.points;

        if(game->user->info.Points < game->user->info.Points_Save){
            game->user->info.Points = game->user->info.Points_Save;
        }

        if (game->snake.lifes <= 0){
            game->user->info.Lifes = 5;
            game->user->info.nivel = 1;
            game->user->info.Points_Save = 0;
        }
    }

    if (game->mode == 2){   
        game->snake.x2Boosted = false;
        game->snake.x3Boosted = false;
        if(game->user->info.PointsClasic < game->snake.points){
            game->user->info.PointsClasic = game->snake.points;
        }
    }

    //When Game is paused
    game->pause = true;
    game->playing = false;
    
    //Checks if player levels up
    if (game->proxLevel && inExit){
        CLEAR;
        //cin.clear();
        snakeprint();
        messageLine(w.ws_col, "Subiste de nivel");
        messageLine(w.ws_col, " presiona cualquier tecla para continuar");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
        cin.clear();
        getchar();
        //cin.get();

        if (game->mode == 1){
            game->user->info.Lifes = game->snake.lifes;
            game->user->info.nivel++;
        }
        else
        {
            game->levelSpecial++;
        }
        game->proxLevel = false;
        playmatrix(game);
    }
    return inExit;
}