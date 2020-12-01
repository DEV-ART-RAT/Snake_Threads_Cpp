#pragma once
#include "../tools/gameStruct.h"

void levelOne(char** , int , int);


void sceneChargininstructions(myGame<nodeuserinfouser>* game){
        cout<<"argando escenario extra"<<game->scene-2<<endl;
        cin.get();

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
            sceneChargininstructions(game);
            break;
        }
    }


    
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