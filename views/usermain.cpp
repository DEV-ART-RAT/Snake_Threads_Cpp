#include <iostream>
#include <string>
#include <iostream>
#include <ostream>
#include "../user/nodeuser.h"
#include "../snake/list.cpp"
#include "../user/readuser.cpp"
using namespace std;
void welcomeuser();
template<class T>
void printUsers(doubleLinked<T>* dl,string user,node<T>*);

void usermain(node<nodeuserinfouser>* userdata,doubleLinked<nodeuserinfouser>* userlist) {
    string user;
    welcomeuser();//mostrando mensaje visual para pedir usuario
    cin>>user;

    printUsers(userlist,user,userdata);//cargando lista de usuarios de fuente externa
    if(userdata->info.name!=""){//revisando si el usuario ya estaba registrado
        cout<<"Bienvenido de nuevo! "<<userdata->info.name<<endl;
        cout<<"Tus monedas : "<<userdata->info.coin<<endl;
        cout<<"Tus puntajes : "<<userdata->info.puntaje<<endl;
    } else{
        userlist->pushBack(nodeuserinfouser(0,0,user));//creando nuevo usuario
        *userdata = *userlist->back;
        cout<<"Bienvenido! "<<userdata->info.name<<endl;
    }
    cout<<"presiona ENTER para continuar";
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
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t Digita tu  USUARIO \n";
    cout<<"\t\t\t (si ya tienes un usuario se recuperara tu progreso) \n";

}