#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>

#include "./node.h"

template<class T>
void saveincsv(node<T>* list){
    //auxiliamos el nodo
    node<T>* aux = list;
    ofstream data;
    remove("data/user.csv");
    //abrimos data
    data.open("data/user.csv",ios::app);
    while (aux)
    {
        //segun nuestra lista que llene el csv
        data<<aux->info.name<<","<<
        aux->info.Points<<","<<
        aux->info.coin<<","<<
        aux->info.Lifes<<","<<
        aux->info.nivel<<","<<
        aux->info.Points_Save<<","<<
        aux->info.PointsClasic<<"\n";
        //saltamos 
        aux= aux->next;
    }
    data.close();
    
}