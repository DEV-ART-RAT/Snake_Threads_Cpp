#pragma once

#include <stdio.h>//getChar()
#include <unistd.h>
#include <termios.h>
#include <stdio_ext.h> 

#include "snake.h"
#include "my_snake.h"
#include "../tools/gameStruct.h"

void keyboardEvent(char* key, bool* flag){
    cin.clear();
    while (*flag){
        *key=getchar();
    }
    cin.clear();
}

//funcion la cual se usa para escuchar el teclado en el momento de jugar...
//sera usada como un thread (hilo) separado
void keyEventSnake(myGame<nodeuserinfouser>* game){
    cin.clear();//limpia el buffer de entrada
    while (game->playing)//utiliza una bandera para indicar que el juego esta en proceso
    {   
        if(!game->pause){//utiliza una bandera para evitar que este hilo este ejecutandose con el menu de pausa
            game->key=getchar();//cactura un evento delteclado
            if(game->key == '\n'){//si durante el juego captura un ENTER procese a pausarlo
                game->pause = true;//se alza la badera que pausa el juego
            }
            if(!game->playing){//si se detecta que el juego termino termina esta funcion (entiendase: el thread)
                return;
            }
        }
    }
    cin.clear();
}

//funcion empleada por los diferentes menus para navegar entre opciones
int optionSelectionKey(myGame<nodeuserinfouser>* game, auto menssage,int sizeOption){
    char key; //contenedor de tecla
    int flag = 1;       //opcion actual del menu
    bool loop = true;   //bandera para el while true
    sleep(0.1);//para corregir fallo de while
    menssage(flag,game,sizeOption);  // muestra el mensaje del menu (a travez de una funcion lambda)
    cin.clear();//vaciamos el buffer por si hay "teclas" esperando a procesarse
    sleep(0.1);//para corregir fallo de whiles
    while(loop){
        key=getchar();//up:65 down:66 o B left:68 rigth:67
        if( key=='\n'){//revisa si se ha presionado la tecla ENTER
            return flag;
        }
        if(key==65 ){//revisa si se ha presionado la tecla UP (direccion)
            if(flag > 1){
                flag--;
            }
        }
        if(  key=='B'){//revisa si se ha presionado la tecla DOWN (dreccion)
            if(flag < sizeOption){
                flag++;
            }
        }
        menssage(flag,game,sizeOption); // muestra el mensaje del menu (a travez de una funcion lambda)
        sleep(0.01);//para corregir fallo de while
    }
    cin.clear();
    return 0;
}

bool enterSelection(myGame<nodeuserinfouser>* game,auto wellcome){
    char key; //contenedor de tecla
    bool loop = true;   //bandera para el while true
    wellcome(game);  //invocacion del menu
    while(loop){
        key=getchar();
        if( key=='\n'){
            return true;
        }
        else{
            return false;
        }
    }
}
