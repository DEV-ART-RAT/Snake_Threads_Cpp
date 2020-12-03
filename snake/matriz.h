#pragma once
#include <iostream>

#include  "../tools/clear.cpp"

using namespace std;
typedef char** charMatriz;
void getMatrizChar(char** array, int b, int a){//solucion de J
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++)
            array[i][j]=' ';
    }
}
char** newCharDoublePointer(int b, int a){//inicializa la matriz... preparacion
    char** doublePointer;
    doublePointer = new char* [a];
    for(int i = 0; i < a; i++)
        doublePointer[i] = new char [b];
        return doublePointer;
}

void getMatrizChar(char*** array, int b, int a){
    *array=newCharDoublePointer(a,b);
    getMatrizChar(*array,a,b);
}