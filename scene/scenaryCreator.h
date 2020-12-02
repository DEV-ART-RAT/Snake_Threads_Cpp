#pragma once
#include "../tools/gameStruct.h"

void levelOne(char** , int , int);

void sceneChargininstructionsRow(char** array, int a, int b, sceneInfo* info){
    //cout<<*info<<endl;
    int i = a * info->row * 0.1;
    int j = b * info->col * 0.1;
    int end = b * info->end * 0.1;
    if(i > a || j > b){
        return;
    }

    for(; j < b && j<end ; j++) {//filas
            array[i][j]=WALL;
    }

}

void sceneChargininstructionsCol(char** array, int a, int b,sceneInfo* info){
    int i = a * info->row * 0.1;
    int j = b * info->col * 0.1;
    int end = a * info->end * 0.1;
    if(i > a || j > b){
        return;
    }

    for(; i < a && i<end ; i++) {//filas
            array[i][j]=WALL;
    }
}

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


void sceneChargininstructions(myGame<nodeuserinfouser>* game){
        int discriminante = 2;
        int escenario = game->scene-discriminante;
        //cout<<"argando escenario extra"<<game->scene-discriminante<<endl;
        node<doubleLinked<sceneInfo>>* temp = game->sceneList.front;
        for (;escenario<1;escenario--){
            temp=temp->next;
        }
        //cout<<temp->info.front->info.col<<endl;
        ejecutarInstruccion(game->snake.M,game->snake.FILA,game->snake.COLUMNA,temp->info.front);
        //cin.get();

    }

    void defineScene(myGame<nodeuserinfouser>* game){
        switch (game->scene)
        {
        case 1://escenario libre
            break;
        case 2:
            levelOne(game->snake.M,game->snake.FILA,game->snake.COLUMNA);//matriz full paredes
            break;
        default:
            sceneChargininstructions(game);//escenarios extras ( externos )
            break;
        }
    }


    
void levelOne(char** array, int a, int b){//escenario FULL paredes
    for(int i = 0; i < a; i++) {//columnas
            array[i][0]=WALL;
            array[i][b-1]=WALL;
    }

    for(int j = 0; j < b; j++) {//filas
            array[0][j]=WALL;
            array[a-1][j]=WALL;
    }
}