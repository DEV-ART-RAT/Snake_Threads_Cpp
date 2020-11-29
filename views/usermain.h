#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <ostream>
//#include "../user/nodeuser.h"
#include "../tools/gameStruct.h"
#include "../snake/clear.cpp"
#include "../user/readuser.cpp"
#include "./snakeprint.cpp"
using namespace std;
void welcomeuser();
template<class T>
void printUsers(myGame<T>* ,string user);

template <class T>
void usermain(myGame<T>* game) {
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    string user;
    welcomeuser();//mostrando mensaje visual para pedir usuario
    cin>>user;

    printUsers(game,user);//cargando lista de usuarios de fuente externa
    
    if(game->user){//revisando si el usuario ya estaba registrado
        string coin,punteje;
        
        mensageLine(w.ws_col,string("Bienvenido de nuevo! "+game->user->info.name));
        mensageLine(w.ws_col,string("Tus monedas : "+to_string(game->user->info.coin)));
        mensageLine(w.ws_col,string("Tus puntajes : "+to_string(game->user->info.puntaje)));
    } else{
        game->list.pushBack(nodeuserinfouser(0,0,user));//creando nuevo usuario
        
        game->user = game->list.back;
        mensageLine(w.ws_col,string("Bienvenido!"+game->user->info.name));
        mensageLine(w.ws_col,"Esperamos Te guste!");
    }
    mensageLine(w.ws_col,"presiona ENTER para continuar");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
    cin.ignore();
    cin.get();
};

template<class T>
void printUsers(myGame<T>* game,string user){
    ifstream data;
    data.open("./data/user.csv",ios::in);
    for(string line; getline(data,line);){
        stringstream data(line);
        string puntaje,name;
        int point,coin,lifes;
        for (int col = 0;getline(data,puntaje,',');col++){
            if(col==0){
                name = puntaje;
                //cout<<name<<endl;
            }
            else if(col==1)
            {
                point = stoi(puntaje);
                //cout<<puntaje<<endl;

            }
            else if(col==2){
                coin = stoi(puntaje);
                //cout<<puntaje<<endl;
                // aqui es donde guardo los datos que se obtienen del csv
                game->list.pushBack(T(point,coin,name));
                if(name==user){
                    game->user = game->list.back;
                    //cout<<"encontre: "<<name<<endl;
                }
                //cout<<"encontre no user: "<<name<<endl;
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
    mensageLine(w.ws_col,"(si ya tienes un usuario se recuperara tu progreso) ");

}