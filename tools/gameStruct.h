#pragma once
#include "list.h"
#include "../snake/my_snake.h"

template<class T>
struct myGame{
    node<T>* user;
    doubleLinked<T> list;
    mySnake snake = mySnake();
    int difficulty;//dificultad de juego
    bool mode;//modo de juego: clasico o escenario especial
    int scene;//esenario actual
    int levelSpecial;
    int liveSpecial;
    
    myGame(){};
};