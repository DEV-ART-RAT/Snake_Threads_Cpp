#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <ostream>
#include "../user/nodeuser.h"
#include "../snake/list.cpp"
#include "../snake/clear.cpp"
#include "../user/readuser.cpp"
#include "./snakeprint.cpp"
using namespace std;
void welcomeuser();
template<class T>
void printUsers(doubleLinked<T>* dl,string user,node<T>*);

void usermain(node<nodeuserinfouser>* userdata,doubleLinked<nodeuserinfouser>* userlist) {
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    string user;
    welcomeuser();//mostrando mensaje visual para pedir usuario
    cin>>user;

    printUsers(userlist,user,userdata);//cargando lista de usuarios de fuente externa
    if(userdata->info.name!=""){//revisando si el usuario ya estaba registrado
        string coin,punteje;
        
        mensageLine(w.ws_col,string("Bienvenido de nuevo! "+userdata->info.name));
        mensageLine(w.ws_col,string("Tus monedas : "+to_string(userdata->info.coin)));
        mensageLine(w.ws_col,string("Tus puntajes : "+to_string(userdata->info.puntaje)));
    } else{
        userlist->pushBack(nodeuserinfouser(0,0,user));//creando nuevo usuario
        *userdata = *userlist->back;
        mensageLine(w.ws_col,string("Bienvenido!"+userdata->info.name));
        mensageLine(w.ws_col,"Esperamos Te guste!");
    }
    mensageLine(w.ws_col,"presiona ENTER para continuar");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
    cin.ignore();
    cin.get();
};

template<class T>
void printUsers(doubleLinked<T>* dl,string user,node<T>* userInfo){
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
                dl->pushBack(T(point,coin,name));
                if(name==user){
                    *userInfo = *dl->back;
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