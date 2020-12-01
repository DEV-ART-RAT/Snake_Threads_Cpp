#pragma once
#include <iostream>
#include <thread>

#include <stdlib.h>
#include <unistd.h>

#include "matriz.h"
#include "../tools/list.h"
#include "../views/colors.h"

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

void levelOne(char** , int , int);


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

    bool x2Boosted, x3Boosted;
    doubleLinked <nodeinfo>* list;

    mySnake() {}
    mySnake(int _i, int _c) : FILA(_i), COLUMNA(_c) {
        //key='0';
        //dir=3;
        //flag=true;
        //redirect=false;
        steep=1;
        //level=0;
        sizeSnake = 3;
        speedBost = 0;
        speed = 4;
        initialSpeed = speed + speedBost;
        points= 0;
        coins = 0;
        //lifes = 3;
        sizeMax = 30;
        
        getMatrizChar(&M,FILA,COLUMNA);
    }

    void inicialiceMySnake(int row, int col) {
        list = new doubleLinked <nodeinfo>();
        FILA = row;
        COLUMNA = col;
        sizeSnake = 3;

        //key='0';
        //dir=3;
        //flag=true;
        //redirect=false;
        steep=1;
        //level=0;
        speedBost = 0;
        speed = 4;
        initialSpeed = speed + speedBost;
        points= 0;
        coins = 0;
        //lifes = 3;
        velMax = 30;
        sizeMax = 30;
        x2Boosted = false;
        x3Boosted = false;
        getMatrizChar(&M,FILA,COLUMNA);
    }

    void defineScene(int i){
        switch (i)
        {
        case 1://ecenario libre
            break;
        case 2:
            levelOne(M,FILA,COLUMNA);//matriz full paredes
            break;
        case 3:
            break;
        
        default:
            break;
        }
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
        cout<<COLOR_BOLDWHITE
        <<"Largo: "<<sizeSnake
        <<"   Restante: "<<sizeMax - sizeSnake 
        << "     VIDAS :"
        <<COLOR_BOLDRED<<" \u2665 "<<RESET
        <<lifes << "   Dinero:"<<COLOR_BOLDYELLOW
        <<" \u0024 "<<RESET<<coins<<" Puntos:"<<points<<RESET<<endl;
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
                //luis creo que me pase de lanza . pd : Rubi
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
