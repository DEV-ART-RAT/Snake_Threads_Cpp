#include  "clear.cpp"
#include <iostream>

//#include "my_snake.h"

#pragma once

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

/*
void printMatrizChar(charMatriz array, int a, int b){
    //cout<<flush;
    //system("clear");//windows
    CLEAR;
    for(int i=0; i< b; i++)cout<<"- ";
    cout<<"-"<<endl;
    for(int i = 0; i < a; i++) {
        cout<<'|';
        for(int j = 0; j < b; j++)
            cout<<array[i][j]<<" ";
        cout<<'|'<<endl;
    }  
    //int c = 238;
    //char a = c;
    for(int i=0; i< b; i++)cout<<"- ";
    cout<<"-"<<endl;
}//*/