#pragma once
#include <iostream>

#include  "../tools/clear.cpp"

using namespace std;
typedef char** charMatriz;

/**Funtion that prints out a matriz made of characters
 */
void getMatrizChar(char** array, int b, int a){//solucion de J
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++)
            array[i][j]=' ';
    }
}

/** Function used to initialize a matrix
 * Returns a double pointer data structure with dimensions given 
 */
char** newCharDoublePointer(int b, int a){//inicializa la matriz... preparacion
    char** doublePointer;
    doublePointer = new char* [a];
    for(int i = 0; i < a; i++)
        doublePointer[i] = new char [b];
        return doublePointer;
}

/** Function that uses funtions above to initialize and print a matrix
 */
void getMatrizChar(char*** array, int b, int a){
    *array=newCharDoublePointer(a,b);
    getMatrizChar(*array,a,b);
}