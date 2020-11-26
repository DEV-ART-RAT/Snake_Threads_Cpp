#include <iostream>
#include <unistd.h>
#include "list.cpp"
#include <stdlib.h>

//#pragma once

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

void printMatrizChar(charMatriz array, int a, int b){
    //cout<<flush;
    system("clear");//windows
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
}

template<class T>
void defineSnake(doubleLinked<T> list, charMatriz M, int fil, int col){
    for(node<T>* e = list.front; e!=NULL; e=e->next){
        if(e->info.i>=fil)
            e->info.i=0;
        if(e->info.j>=col)
        e->info.j=0;
        M[e->info.i][e->info.j]='*';
        //cout<<"e.i"<<e->info.i<<" e.j"<<e->info.j<<" ;";
    }

}

template<class T>
void snakeNew(doubleLinked<T>* list, charMatriz M, int fil, int col){
    list->pushBack(T(fil,col));
    //node<T>* n = list.removeFront;
    M[fil][col]='*';
    //delete(n);
}
template<class T>
void snakeDel(doubleLinked<T>* list, charMatriz M){
    node<T>* n = list->removeFront();
    M[n->info.i][n->info.j]=' ';
    delete(n);
}

template<class T>
void snakeRight(doubleLinked<T>* list, charMatriz M, int fil, int col,int step){
    int prevF= list->back->info.i;
    int prevC= list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< step;k++){
        prevC++;
        if(prevC>=col){
            prevC=0;
        }
        snakeNew(list,M,prevF,prevC);
        snakeDel(list,M);
    }
}

template<class T>
void snakeLeft(doubleLinked<T>* list, charMatriz M, int fil, int col,int step){
    int prevF= list->back->info.i;
    int prevC= list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< step;k++){
        prevC--;
        if(prevC < 0){
            prevC = col -1;
        }
        snakeNew(list,M,prevF,prevC);
        snakeDel(list,M);
    }
}

template<class T>
void snakeUp(doubleLinked<T>* list, charMatriz M, int fil, int col,int step){
    int prevF= list->back->info.i;
    int prevC= list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< step;k++){
        prevF--;
        if(prevF < 0){
            prevF = fil - 1;
        }
        snakeNew(list,M,prevF,prevC);
        snakeDel(list,M);
    }
}

template<class T>
void snakeDown(doubleLinked<T>* list, charMatriz M, int fil, int col,int step){
    int prevF= list->back->info.i;
    int prevC= list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< step;k++){
        prevF++;
        if(prevF >= fil){
            prevF = 0;
        }
        snakeNew(list,M,prevF,prevC);
        snakeDel(list,M);
    }
}






int main(void){

    charMatriz M;
    int FILA = 11;
    int COLUMNA = 23;

    getMatrizChar(&M,FILA,COLUMNA);//tamaño 11x11
    

    doubleLinked <nodeinfo> list;
    list.pushBack(nodeinfo(5,5));
    list.pushBack(nodeinfo(5,6));
    list.pushBack(nodeinfo(5,7));
    list.pushBack(nodeinfo(5,8));

    defineSnake(list,M,FILA,COLUMNA);
    int flag =0;
    while (flag<4)
    {
        printMatrizChar(M,FILA,COLUMNA);//-----
        snakeRight(&list,M,FILA,COLUMNA,1);
        flag++;
        usleep(500 * 1000);
    }

    flag =0;
    while (flag<3)
    {
        printMatrizChar(M,FILA,COLUMNA);//-----
        snakeUp(&list,M,FILA,COLUMNA,1);
        flag++;
        usleep(500 * 1000);
    }

    flag =0;
    while (flag<4)
    {
        printMatrizChar(M,FILA,COLUMNA);//-----
        snakeLeft(&list,M,FILA,COLUMNA,1);
        flag++;
        usleep(500 * 1000);
    }

    flag =0;
    while (flag<4)
    {
        printMatrizChar(M,FILA,COLUMNA);//-----
        snakeDown(&list,M,FILA,COLUMNA,1);
        flag++;
        usleep( 500 * 1000);
    }

    traverseBegin(list.front);
    
    


    return 0;
}