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

    int difficulty;//dificultad de juego [facil, normal,dificil]
    int mode;//modo de juego: Clasic o escenario especial[world,Clasic,special]
    int scene;//esenario actual [libre,cerrado,extras...]

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
        pause = false;
        direccion = 3;
    }

    void mostrarCabeceraSnake(){
        CLEAR;
        (2!=mode)?
        cout<<COLOR_BOLDWHITE<<"Largo: "<<snake.sizeSnake<<"   Restante: "<<snake.sizeMax - snake.sizeSnake << "     Lifes :"<<RESET<<COLOR_BOLDRED<<" \u2665 "<<RESET<<COLOR_BOLDWHITE<<snake.lifes << "   Dinero:"<<RESET<<COLOR_BOLDYELLOW<<" \u0024 "<<RESET<<COLOR_BOLDWHITE<<user->info.coin<<" Puntos:"<<snake.points<<RESET<<COLOR_BOLDGREEN<<"\t Pulsa Enter para entrar en el menu de opciones."<<RESET<<endl:
        cout<<COLOR_BOLDWHITE<<"Largo: "<<snake.sizeSnake<<"     Lifes :"<<RESET<<COLOR_BOLDRED<<" \u2665 "<<RESET<<" 1 " << "   Dinero:"<<COLOR_BOLDYELLOW<<" \u0024 "<<RESET<<COLOR_BOLDWHITE<<user->info.coin<<" Puntos:"<<snake.points<<RESET<<COLOR_BOLDGREEN<<"\t Pulsa Enter para entrar en el menu de opciones."<<RESET<<endl;
        
    }
    
};
