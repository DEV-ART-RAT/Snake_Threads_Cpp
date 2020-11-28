#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../snake/node.h"
#include "../snake/list.cpp"

using namespace std;


/*

template<class T>
void yy(node<T>* list){
    //auxiliamos el nodo
    node<T>* aux = list;
    ofstream data;
    remove("data.csv");
    //abrimos data
    data.open("data.csv",ios::app);
    while (aux)
    {
        //segun nuestra lista que llene el csv
        data<<aux->info.c<<","<<aux->info.i<<"\n";
        //saltamos 
        aux= aux->next;
    }
    data.close();
    
};

template<class T>
void xx(doubleLinked<T> *list) {
    //definimos la variable
    ifstream data;
    //abrimos el archivo
    data.open("./data/user.csv",ios::in);
    for(string line; getline(data,line);){
        stringstream data(line);
        string puntaje,name;
        int point;
        //damos los datos
        for (int col = 0;getline(data,puntaje,',');col++){
            if(col==0){
                name = puntaje;
            }else
            {
                point = stoi(puntaje);
                pushBack(T(point,name),list);
            }
        }

    }
    data.close();
}

*/