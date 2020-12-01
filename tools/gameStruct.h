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
    int mode;//modo de juego: clasico o escenario especial[world,clasico,special]
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
        direccion = 3;
    }

    void mostrarCabeceraSnake(){
        CLEAR;
        (2!=mode)?
        cout<<COLOR_BOLDWHITE<<"Largo: "<<snake.sizeSnake<<"   Restante: "<<snake.sizeMax - snake.sizeSnake << "     VIDAS :"<<COLOR_BOLDRED<<" \u2665 "<<RESET<<snake.lifes << "   Dinero:"<<COLOR_BOLDYELLOW<<" \u0024 "<<RESET<<user->info.coin<<" Puntos:"<<snake.points<<RESET<<COLOR_BOLDGREEN<<"\t Pulsa enter para em menu de pausa"<<RESET<<endl:
        cout<<COLOR_BOLDWHITE<<"Largo: "<<snake.sizeSnake<<"     VIDAS :"<<COLOR_BOLDRED<<" \u2665 "<<RESET<<snake.lifes << "   Dinero:"<<COLOR_BOLDYELLOW<<" \u0024 "<<RESET<<user->info.coin<<" Puntos:"<<snake.points<<RESET<<COLOR_BOLDGREEN<<"\t Pulsa enter para em menu de pausa"<<RESET<<endl;
        
    }
    
};
