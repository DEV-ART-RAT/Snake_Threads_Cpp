#pragma once
#include <string>
#include <ostream>
#include <fstream>
#include <sstream>
#include <iostream>

#include "./colors.h"
#include "./historias.cpp"
#include "./snakeprint.cpp"
#include "../snake/clear.cpp"
#include "../tools/gameStruct.h"
#include "../tools/ordenar.h"

using namespace std;
void welcomeuser();
template<class T>
void printUsers(myGame<T>* ,string user);
template<class T>
void printUser(myGame<T>*);

template <class T>
void usermain(myGame<T>* game) {
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    string user="";
    welcomeuser();//mostrando mensaje visual para pedir usuario
    int vecesdigitadas=0;
    do{
        if(vecesdigitadas>0){
                CLEAR
                welcomeuser();//mostrando mensaje visual para pedir usuario
                mensageLineRED(w.ws_col,"El usuario no puede estar vacio o tener mas de 12 caracteres ");
        }
        vecesdigitadas++;
        cin>>user;
    }while(user==""||user.size()>12);
    printUsers(game,user);//cargando lista de usuarios de fuente externa
    
    if(game->user){//revisando si el usuario ya estaba registrado        
        mensageLine(w.ws_col,string("Bienvenido de nuevo!  "+game->user->info.name));cout<<RESET;
        mensageLineMAGENTA(w.ws_col,"Presiona ENTER para continuar");
        mensageSteep(w.ws_col);
        mensageMargin(w.ws_col);
        cin.clear();
        cin.get();
        //print_user(game); 
    } else{
        game->list.pushBack(nodeuserinfouser(0,0,0,0,5,1,user));//creando nuevo usuario
        game->user = game->list.back;
        mensageLine(w.ws_col,string("Bienvenido!   "+game->user->info.name));        cout<<RESET;
        mensageLine(w.ws_col,"Esperamos Te guste!");        cout<<RESET;
        mensageLineMAGENTA(w.ws_col,"Presiona ENTER para continuar");
        mensageSteep(w.ws_col);
        mensageMargin(w.ws_col);
        cin.clear();
        cin.get();
        history();
        //print_user(game); 
    }
   
};

template<class T>
void printUsers(myGame<T>* game,string user){
    ifstream data;
    data.open("./data/user.csv",ios::in);
    for(string line; getline(data,line);){
        stringstream data(line);
        string recibo,name;
        int point,pointContinue,coin,lifes,nivel,pointClassic;
        for (int col = 0;getline(data,recibo,',');col++){
            switch (col)
            {
            case 0:
                name = recibo;
                break;
            case 1:
                point = stoi(recibo);
                break;
            case 2:
                coin = stoi(recibo);
                break;
            case 3:
                lifes = stoi(recibo);
                break;
            case 4:
                nivel = stoi(recibo);
                break;
            case 5:
                pointContinue = stoi(recibo);
                break;
            case 6:
                pointClassic = stoi(recibo);
                game->list.pushBack(T(point,pointContinue,pointClassic,coin,lifes,nivel,name));
                if(name==user){
                    game->user = game->list.back;
                }
                break;

            default:
                exit(EXIT_FAILURE);
                break;
            }
            
        }

    }
    data.close();

 
}

void welcomeuser(void){
    // borra esto porque hay nose que conflicto de pragma once
    CLEAR;
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    snakeprint();
    mensageLine(w.ws_col,"Digita tu  USUARIO");
    mensageLine(w.ws_col,"(Si ya tienes un usuario se recuperara tu progreso!)");

}
template <class T>
void print_user(myGame<T>* game){
    mensageLine(w.ws_col,string("Tus monedas : "+to_string(game->user->info.coin)));        cout<<RESET;
    mensageLine(w.ws_col,string("Tu Puntaje Snake World Party: "+to_string(game->user->info.puntaje)));        cout<<RESET;
    mensageLine(w.ws_col,string("Tu Puntaje Clasico: "+to_string(game->user->info.puntajeClasico)));        cout<<RESET;
    mensageLine(w.ws_col,string("Tus vidas : "+to_string(game->user->info.vidas)));        cout<<RESET;
    mensageLine(w.ws_col,string("Tu Nivel : "+to_string(game->user->info.nivel)));        cout<<RESET;
}
