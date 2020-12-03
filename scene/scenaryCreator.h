#pragma once
#include "../tools/gameStruct.h"

void levelOne(char** , int , int);

//Modifies the matrix tho load de stage
//If the parameter to be used is a row
void sceneChargininstructionsRow(char** array, int a, int b, sceneInfo* info){
    //cout<<*info<<endl;
    int i = (a * info->row * 0.1);
    int j = (b * info->col * 0.1);
    int end = b * info->end * 0.1;
    if(i >= a){
        i = a -1;
    }
    if(j >= b){
        i = b -1;
    }
    for(; j < b && j<end ; j++) {//filas
            array[i][j]=WALL;
    }

}

//Modifies the matrix tho load de stage 
//If the parameter to be used is a column
void sceneChargininstructionsCol(char** array, int a, int b,sceneInfo* info){
    int i = (a * info->row * 0.1);
    int j = (b * info->col * 0.1);
    int end = a * info->end * 0.1;
    //cout<<"a:"<<a <<"i:"<<i<<"j:"<<j<<"b:"<<b<<endl;
    //cin.get();
    
    if(i >= a){
        i = a - 1;
    }
    if(j >= b){
        j = b - 1;
    }

    for(; i < a && i<end ; i++) {//filas
            array[i][j]=WALL;
    }
}

//Recursive function that uses one or another of the funtions above depending on a flag given
void ejecutarInstruccion(char** array, int a, int b,node<sceneInfo>* temp){
    if(temp){
        if(temp->info.direction){
            sceneChargininstructionsRow(array,a,b,&temp->info);
        }else
        {
            sceneChargininstructionsCol(array,a,b,&temp->info);
        }
        
    ejecutarInstruccion(array,a,b,temp->next);
    }
}

//Loads the stage with instructions given in a file
void sceneChargininstructions(myGame<nodeuserinfouser>* game){
        int discriminante = 2;
        int escenario = game->scene-discriminante;
        //cout<<"argando escenario extra"<<game->scene-discriminante<<endl;
        node<doubleLinked<sceneInfo>>* temp = game->sceneList.front;
        for (;escenario>1;escenario--){
            temp=temp->next;
        }
        //cout<<temp->info.front->info.col<<endl;
        ejecutarInstruccion(game->snake.M,game->snake.FILA,game->snake.COLUMNA,temp->info.front);
        //cin.get();

    }

//Determines wich of the stages will be loaded
// - Free stage
// - With full walls in margin
// - Extra stages from a file
void defineScene(myGame<nodeuserinfouser>* game){
    switch (game->scene)
    {
    case 1:
        break;
    case 2:
        levelOne(game->snake.M,game->snake.FILA,game->snake.COLUMNA);
        break;
    default:
        sceneChargininstructions(game);
        break;
    }
}

// Creates an stage with walls in the margin     
void levelOne(char** array, int a, int b){
    for(int i = 0; i < a; i++) {
            array[i][0]=WALL;
            array[i][b-1]=WALL;
    }

    for(int j = 0; j < b; j++) {
            array[0][j]=WALL;
            array[a-1][j]=WALL;
    }
}