#pragma once

#include "list.h"
#include "../snake/my_snake.h"

/**Structure used to define game
 * 
 */
template<class T>
struct myGame{
    // Properties
    node<T>* user = NULL;
    doubleLinked<T> list;
    //doubleLinked<T> lista_ordenar;
    doubleLinked<doubleLinked<sceneInfo>> sceneList;
    //doubleLinked<doubleLinked<sceneInfo>> scenesListContainer;
    mySnake snake = mySnake();

    //Game difficulty: easy, normal or hard
    int difficulty;

    //Game mode: World Party, Classic or Special
    int mode;

    //Current stage, free, closed or extras
    int scene;

    int levelSpecial;
    int liveSpecial;
    int food;
    
    bool pause = false;
    bool proxLevel = false;
    
    char key;
    bool playing;
    bool redirection;
    int direccion;
    
    //Constructor
    myGame(){};
    
    //Methods
    
    //Initial values when starting a new game
    void startGame(){
        key = '0';
        playing = true;
        redirection = false;
        pause = false;
        direccion = 3;
    }

    //Shows Game's header depending on game mode
    void mostrarCabeceraSnake(){
        CLEAR;
        (2!=mode)?
        cout<<COLOR_BOLDWHITE<<"Largo: "<<snake.sizeSnake<<"   Restante: "<<snake.sizeMax - snake.sizeSnake << "     Lifes :"<<RESET<<COLOR_BOLDRED<<" \u2665 "<<RESET<<COLOR_BOLDWHITE<<snake.lifes << "   Dinero:"<<RESET<<COLOR_BOLDYELLOW<<" \u0024 "<<RESET<<COLOR_BOLDWHITE<<user->info.coin<<" Puntos:"<<snake.points<<RESET<<COLOR_BOLDGREEN<<"\t Pulsa Enter para entrar en el menu de opciones."<<RESET<<"lvl: "<<user->info.nivel<<"/"<< ((3!=mode)? ((sceneList.size() + 2) * 9): 3)<<endl:
        cout<<COLOR_BOLDWHITE<<"Largo: "<<snake.sizeSnake<<"     Lifes :"<<RESET<<COLOR_BOLDRED<<" \u2665 "<<RESET<<" 1 " << "   Dinero:"<<COLOR_BOLDYELLOW<<" \u0024 "<<RESET<<COLOR_BOLDWHITE<<user->info.coin<<" Puntos:"<<snake.points<<RESET<<COLOR_BOLDGREEN<<"\t Pulsa Enter para entrar en el menu de opciones."<<RESET<<endl;
        
    }
    
};
