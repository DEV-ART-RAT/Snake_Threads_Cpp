#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>

#include "./node.h"

/** Function that saves players progress
 */
template<class T>
void saveincsv(node<T>* list){
    //Node auxiliar
    node<T>* aux = list;
    ofstream data;
    remove("data/user.csv");

    //Open the file
    data.open("data/user.csv",ios::app);
    while (aux)
    {
        //Fills the file according the lines
        data<<aux->info.name<<","<<
        aux->info.Points<<","<<
        aux->info.coin<<","<<
        aux->info.Lifes<<","<<
        aux->info.nivel<<","<<
        aux->info.Points_Save<<","<<
        aux->info.PointsClasic<<"\n";
        //Jump to next 
        aux= aux->next;
    }
    data.close();
    
}