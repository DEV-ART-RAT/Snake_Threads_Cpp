#include <iostream>
#pragma once

using namespace std;


void getMatrizChar(char** array, int b){//solucion de J
    for(int i = 0; i < b; i++) {
        for(int j = 0; j < b; j++)
            array[i][j]=' ';
    }
}

char** newCharDoublePointer(int b){//inicializa la matriz... preparacion
    char** doublePointer;
    doublePointer = new char* [b];
    for(int i = 0; i < b; i++)
        doublePointer[i] = new char [b];
        return doublePointer;
}

void getMatrizChar(char*** array, int b){
    *array=newCharDoublePointer(b);
    getMatrizChar(*array,b);
}

void printMatrizChar(char** array, int b){
    for(int i = 0; i < b; i++) {
        for(int j = 0; j < b; j++)
            cout<<array[i][j]<<" ";
        cout<<endl;
    }  
}