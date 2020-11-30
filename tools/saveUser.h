#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <sstream>

template<class T>
void saveincsv(node<T>* list){
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
    
}