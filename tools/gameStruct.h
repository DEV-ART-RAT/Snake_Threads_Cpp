#pragma once

#include "list.h"
#include "../snake/my_snake.h"

template<class T>
struct myGame{
    node<T>* user;
    doubleLinked<T> list;
    doubleLinked<doubleLinked<sceneInfo>> sceneList;
    //doubleLinked<doubleLinked<sceneInfo>> scenesListContainer;
    mySnake snake = mySnake();
    int difficulty;//dificultad de juego
    int mode;//modo de juego: clasico o escenario especial
    int scene;//esenario actual
    int levelSpecial;
    int liveSpecial;
    int food;
    
    bool pause = false;
    bool proxLevel = false;
    
    char key;
    bool playing;
    bool redirection;
    int direccion;
    
    myGame(){};
    
    void startGame(){
        key = '0';
        playing = true;
        redirection = false;
        direccion = 3;
    }
    
};
