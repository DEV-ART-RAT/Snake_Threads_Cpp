#pragma once
#include <iostream>
#include <unistd.h>
#include "../tools/list.h"
#include <stdlib.h>
//#include <stdio.h>

#include <thread>

//#include <termios.h>
#include <unistd.h>

//#include  "clear.cpp"
//#include "keyEvent.h"
#include "matriz.h"
//#include "snake.h"

//compile g++ -pthread  ...

#define FOOD '+'
#define SNAKE '*'
#define CRASH '?'
#define SCENE ' '
#define WALL 'X'



#pragma once



using namespace std;

int getIntRand(int a, int b){   
    return rand() % (b - a + 1) + a;
}

void levelOne(char** , int , int);


struct mySnake{
    charMatriz M;
    int FILA;
    int COLUMNA;
    char key;
    int dir;
    bool flag;
    bool redirect;
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
    doubleLinked <nodeinfo> list;

    mySnake() {}
    mySnake(int _i, int _c) : FILA(_i), COLUMNA(_c) {
        key='0';
        dir=3;
        flag=true;
        redirect=false;
        steep=1;
        level=0;
        sizeSnake = 4;
        speedBost = 0;
        speed = 4;
        initialSpeed = speed + speedBost;
        points= 1000;
        coins = 0;
        lifes = 3;
        sizeMax = 30;
        
        getMatrizChar(&M,FILA,COLUMNA);
    }

    void inicialiceMySnake(int _i, int _c) {
        FILA = _i;
        COLUMNA = _c;
        key='0';
        dir=3;
        flag=true;
        redirect=false;
        steep=1;
        level=0;
        sizeSnake = 4;
        speedBost = 0;
        speed = 4;
        initialSpeed = speed + speedBost;
        points= 1000;
        coins = 0;
        lifes = 3;
        sizeMax = 30;
        
        getMatrizChar(&M,FILA,COLUMNA);
    }

    void defineLevel(int i){
        switch (i)
        {
        case 1:
            //levelOne(M,FILA,COLUMNA);//inicando matriz
            //difficulty = 1;
            break;
        case 2:
            //levelOne(M,FILA,COLUMNA);//inicando matriz
            //difficulty = 2;
            break;
        case 3:
            levelOne(M,FILA,COLUMNA);//inicando matriz
            //difficulty = 3;
            break;
        
        default:
            break;
        }
    }

    void defineSnake(){
        for(node<nodeinfo>* e = list.front; e!=NULL; e=e->next){
            if(e->info.i>=FILA)
                e->info.i=0;
            if(e->info.j>=FILA)
            e->info.j=0;
            M[e->info.i][e->info.j]=SNAKE;
            //cout<<"e.i"<<e->info.i<<" e.j"<<e->info.j<<" ;";
        }
    }

    void defineFood(){
        int i , j;
        do{
            i = getIntRand( 0 , FILA - 1 );
            j = getIntRand( 0 , COLUMNA - 1 );
        }while (M[i][j]!=SCENE);
        M[i][j] = FOOD;
    }

    void show(){
        //cout<<flush;
        //system("clear");//windows
        CLEAR;
        for(int i=0; i< COLUMNA; i++)cout<<"- ";
        cout<<"-"<<endl;
        for(int i = 0; i < FILA; i++) {
            cout<<'|';
            for(int j = 0; j < COLUMNA; j++)
                cout<<M[i][j]<<" ";
            cout<<'|'<<endl;
        }  
        //int c = 238;
        //char a = c;
        for(int i=0; i< COLUMNA; i++)cout<<"- ";
        cout<<"-"<<endl;
}

    
};

void levelOne(char** array, int a, int b){//escenario FULL paredes
    for(int i = 0; i < a; i++) {
            array[i][0]=WALL;
            array[i][b-1]=WALL;
    }

    for(int j = 0; j < b; j++) {
            array[0][j]=WALL;
            array[a-1][j]=WALL;
    }
}
