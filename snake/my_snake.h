#pragma once
#include <iostream>
#include <thread>

#include <stdlib.h>
#include <unistd.h>

#include "matriz.h"
#include "../tools/list.h"
#include "../views/colors.h"
#include "../tools/gameStruct.h"


#define FOOD 'O'
#define SNAKE '*'
#define CRASH '?'
#define SCENE ' '
#define WALL 'X'
#define Circulo ''
#define Pared ''
using namespace std;

int getIntRand(int a, int b){   
    return rand() % (b - a + 1) + a;
}



struct mySnake{
    charMatriz M;
    int FILA;
    int COLUMNA;
    //char key;
    //int dir;
    //bool flag;
    //bool redirect;
    int steep;
    int sizeSnake;
    int points;
    int coins;
    int lifes;
    int level;
    double speed;
    double initialSpeed;
    double speedBost;
    int sizeMax;
    int velMax;

    bool x2Boosted=false, x3Boosted=false;
    doubleLinked <nodeinfo>* list;

    mySnake() {}
    mySnake(int _i, int _c) : FILA(_i), COLUMNA(_c) {
        steep=1;
        sizeSnake = 3;
        speedBost = 0;
        speed = 4;
        initialSpeed = speed + speedBost;
        points= 0;
        coins = 0;
        sizeMax = 30;
        
        getMatrizChar(&M,FILA,COLUMNA);
    }

    void inicialiceMySnake(int row, int col) {
        list = new doubleLinked <nodeinfo>();
        FILA = row;
        COLUMNA = col;
        sizeSnake = 3;
        steep=1;
        speedBost = 0;
        speed = 4;
        initialSpeed = speed + speedBost;
        coins = 0;
        velMax = 30;
        sizeMax = 30;
        getMatrizChar(&M,FILA,COLUMNA);
    }

    void defineSnake(){
        for(node<nodeinfo>* e = list->front; e!=NULL; e=e->next){
            if(e->info.i>=FILA)
                e->info.i=0;
            if(e->info.j>=FILA)
            e->info.j=0;
            M[e->info.i][e->info.j]=SNAKE;
        }
    }

    void deleteSnake(){
        for(node<nodeinfo>* e = list->back; e!=NULL; e=e->prev){
            M[e->info.i][e->info.j]=SCENE;
        }
        list = new doubleLinked <nodeinfo>();
    }

    void defineFood(){
        int i , j;
        do{
            i = getIntRand( 0 , FILA - 1 );
            j = getIntRand( 0 , COLUMNA - 1 );
        }while (M[i][j]!=SCENE);
        M[i][j] = FOOD;
    }

    void defineObst(int obstaculos){
        for(int k=0 ; k<obstaculos;k++){
            int i , j;
        do{
            i = getIntRand( 0 , FILA - 1 );
            j = getIntRand( 0 , COLUMNA - 1 );
        }while (M[i][j]!=SCENE);
        M[i][j] = WALL;
        }
    }

    void show(){
        //cout<<flush;
        //system("clear");//windows
        CLEAR;
        ((sizeMax - sizeSnake)<999)?
        cout<<COLOR_BOLDWHITE<<"Largo: "<<sizeSnake<<"   Restante: "<<sizeMax - sizeSnake << "     VIDAS :"<<COLOR_BOLDRED<<" \u2665 "<<RESET<<lifes << "   Dinero:"<<COLOR_BOLDYELLOW<<" \u0024 "<<RESET<<coins<<" Puntos:"<<points<<RESET<<endl:
        cout<<COLOR_BOLDWHITE<<"Largo: "<<sizeSnake<<"     VIDAS :"<<COLOR_BOLDRED<<" \u2665 "<<RESET<<lifes << "   Dinero:"<<COLOR_BOLDYELLOW<<" \u0024 "<<RESET<<coins<<" Puntos:"<<points<<RESET<<endl;
        cout<<COLOR_BOLDBLUE;
        for(int i=0; i< COLUMNA; i++)cout<<"- ";
        cout<<"-"<<endl<<RESET;
        for(int i = 0; i < FILA; i++) {
            cout<<COLOR_BOLDBLUE;
            cout<<'|';
            cout<<RESET;
            for(int j = 0; j < COLUMNA; j++){
                switch (M[i][j])
                {
                //https://unicode-table.com/es/#miscellaneous-mathematical-symbols-b
                case SNAKE:
                    cout<<COLOR_BOLDGREEN<<"\u2B24"<<" "<<RESET;
                    break;
                case WALL:
                    cout<<COLOR_BOLDRED<<"\u2612"<<" "<<RESET;
                    break;
                case FOOD:
                    cout<<COLOR_BOLDYELLOW<<"\u2B24"<<" "<<RESET;
                    break;                
                default:
                    cout<<M[i][j]<<" "; 
                    break;
                }
            }
            cout<<COLOR_BOLDBLUE;
            cout<<'|'<<endl;
            cout<<RESET;
        }  
        //int c = 238;
        //char a = c;
        cout<<COLOR_BOLDBLUE;
        for(int i=0; i< COLUMNA; i++)cout<<"- ";
        cout<<"-"<<endl;
        cout<<RESET;
}

    void setLive(int live){
        lifes=live;
    }

    
};



