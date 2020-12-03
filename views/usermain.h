#pragma once
#include <string>
#include <ostream>
#include <fstream>
#include <sstream>
#include <iostream>

#include "./colors.h"
#include "./historias.cpp"
#include "./snakeprint.cpp"
#include "../tools/clear.cpp"
#include "../tools/gameStruct.h"
#include "../tools/ordenar.h"

using namespace std;
void welcomeuser();
template<class T>
void printUsers(myGame<T>* ,string user);
template<class T>
void printUser(myGame<T>*);

/**
 * Function that asks for insert a name correctly and checks if the user exists or not
 */
template <class T>
void usermain(myGame<T>* game) {
    //Gets the terminal dimensions
    winsize w = screenSize();
    string user="";

    //Shows message to ask for a user name
    welcomeuser();
    int userIntents=0;
    do{ 
        //Forbidden name
        if(user=="enxel"){
            CLEAR;
            welcomeuser();
            messageLineRED(w.ws_col,"Lo sentimos ese nombre no esta disponible ");
        }else
        {
            //If the user name is left in blanck or has more than 12 characters
            if(userIntents>0){
                CLEAR
                welcomeuser();
                messageLineRED(w.ws_col,"El usuario no puede estar vacio o tener mas de 12 caracteres ");
            }
        }
        userIntents++;
        cin>>user;
    }while(user==""||user.size()>12||user=="enxel");

    //loads players from an external source
    printUsers(game,user);
    //Checks if user was already registered
    if(game->user){
        messageLine(w.ws_col,string("Bienvenido de nuevo!  "+game->user->info.name));cout<<RESET;
        messageLineMAGENTA(w.ws_col,"Presiona ENTER para continuar");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
        cin.ignore();
        cin.clear();
        cin.get();
        //print_user(game); 
    } 
    // Creates a new user
    else{
        game->list.pushBack(nodeuserinfouser(0,0,0,0,5,1,user));
        game->user = game->list.back;
        messageLine(w.ws_col,string("Bienvenido!   "+game->user->info.name));        cout<<RESET;
        messageLine(w.ws_col,"Esperamos Te guste!");        cout<<RESET;
        messageLineMAGENTA(w.ws_col,"Presiona ENTER para continuar");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
        cin.ignore();
        cin.clear();
        cin.get();
        history();
        //print_user(game); 
    }
   
};

/**
 * Function that shows the players registered saved in an external file
 */
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
                //ame->lista_ordenar.pushBack(T(point,pointContinue,pointClassic,coin,lifes,nivel,name));
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

/**
 * Function that asks for the users name
 */
void welcomeuser(void){
    CLEAR;
    // Gets terminal dimensions
    winsize w = screenSize();
    snakeprint();
    messageLine(w.ws_col,"Digita tu  USUARIO");
    messageLine(w.ws_col,"(Si ya tienes un usuario se recuperara tu progreso!)");

}

/**
 * Function that shows the info of an user
 */
template <class T>
void print_user(myGame<T>* game){
    messageLineMAGENTA(w.ws_col,string("Tus monedas : "+to_string(game->user->info.coin)));        cout<<RESET;
    messageLineMAGENTA(w.ws_col,string("Tu Puntos Snake World Party: "+to_string(game->user->info.Points)));        cout<<RESET;
    messageLineMAGENTA(w.ws_col,string("Tu Puntos Clasic: "+to_string(game->user->info.PointsClasic)));        cout<<RESET;
    messageLineMAGENTA(w.ws_col,string("Tus Vidas : "+to_string(game->user->info.Lifes)));        cout<<RESET;
    messageLineMAGENTA(w.ws_col,string("Tu Nivel : "+to_string(game->user->info.nivel)));        cout<<RESET;
}
