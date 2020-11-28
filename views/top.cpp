#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <ostream>
#include "../user/nodeuser.h"
#include "../snake/list.cpp"
#include "../snake/clear.cpp"
#include "../user/readuser.cpp"
#include <iomanip>

using namespace std;
void top_game(node<nodeuserinfouser>* userdata,doubleLinked<nodeuserinfouser>* userlist);
void welcometop();

template<class T>
void printtop(node<T>* front);
void printtopaux(doubleLinked<nodeuserinfouser>* userlist);

void top_game(node<nodeuserinfouser>* userdata,doubleLinked<nodeuserinfouser>* userlist){
    welcometop();
    //traverseBegin(userlist->front);
    printtopaux(userlist);
    cout<<"presiona ENTER para continuar";
    cin.ignore();
    cin.get();
    //startMenuOpc(userdata,startMenu(userdata,userlist),userlist);
    return;
};
void welcometop(){
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

}
template<class T>
void printtop(node<T>* front){
    string line,lineone,wall,fwall,lwall;
    line="=================================================================================================================================";
    wall="\t|\t";
    fwall="|\t";
    lwall="\t|";
    //cout<<fwall;
    if(front) {
        cout<< fwall;
        cout<<setw(20)<< front->info.name;
        cout<<setw(20)<< wall;
        cout<<setw(20)<< front->info.coin;
        cout<<setw(20)<<wall;
        cout<<setw(20)<<front->info.puntaje;
        cout<<setw(20)<<lwall;
        cout<<endl ;
        printtop(front->next);
    }
    else    
        cout<<endl;
}

void printtopaux(doubleLinked<nodeuserinfouser>* userlist){
    string line,lineone,wall,fwall,lwall,all;int size;
    wall="\t|\t";
    fwall="|\t";
    lwall="\t|";
    cout<< fwall;
    cout<<setw(20)<< "Nombre ";
    cout<<setw(20)<<wall;
    cout<<setw(20)<< "Monedas";
    cout<<setw(20)<<wall;
    cout<<setw(20)<<"Puntaje";
    cout<<setw(20)<<lwall;
    cout<<endl ;
    printtop(userlist->front);
}