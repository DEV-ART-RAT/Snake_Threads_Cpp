#include <iostream>
#include <unistd.h>
#include "list.cpp"
#include <stdlib.h>
#include <stdio.h>

#include <thread>

#include <termios.h>
#include <unistd.h>

#include  "clear.cpp"

//compile g++ -pthread  ...



//#pragma once

using namespace std;

typedef char** charMatriz;



void keyboardEvent(char* key, bool* flag){
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    while (*flag)
    {
        *key=getchar();
    }
    


    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);


}
void myThreadTwo(int b){
    for (int i = 0 ; i  < b; i++){
        cout<<"thread two "<<i<<endl;
        sleep(2);
    }
}



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

template<class T>
void snakeDirection(doubleLinked<T>* list, charMatriz M, int fil, int col,int step, int* dir){
    switch (*dir)
        {
        case 1:
            snakeUp(list,M,fil,col,step);
            break;
        case 2:
            snakeDown(list,M,fil,col,step);
            break;
        case 3:
            snakeRight(list,M,fil,col,step);
            break;
        case 4:
            snakeLeft(list,M,fil,col,step);
            break;
        default:
            break;
        }
}





int main(void){

    charMatriz M;
    int FILA = 11;
    int COLUMNA = 23;
    char key = '0';
    int dir = 3;
    bool flag = true;
    //cout<<OS_Windows;

    getMatrizChar(&M,FILA,COLUMNA);//tamaño 11x11
    

    doubleLinked <nodeinfo> list;
    list.pushBack(nodeinfo(5,5));
    list.pushBack(nodeinfo(5,6));
    list.pushBack(nodeinfo(5,7));
    list.pushBack(nodeinfo(5,8));
    thread th1(keyboardEvent,&key,&flag);
    //thread th2(myThreadTwo,4);
    //*

    defineSnake(list,M,FILA,COLUMNA);
    //int flag =0;
    while (flag)
    {
        printMatrizChar(M,FILA,COLUMNA);//-----
        switch (key)
        {
        case '\n':
            flag=false;
            break;
        case 65:
            dir = (dir!=2)? 1 : 2;
            break;
        case 66:
            dir = (dir!=1)? 2 : 1;
            break;
        case 67:
            dir = (dir!=4)? 3 : 4;
            break;
        case 68:
            dir = (dir!=3)? 4 : 3;
            break;
        default:
            break;
        }
        snakeDirection(&list,M,FILA,COLUMNA,1,&dir);
        //snakeRight(&list,M,FILA,COLUMNA,1);
        //flag++;
        usleep(500 * 1000);
    }

    /*flag =0;
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

    //traverseBegin(list.front);
     //*/
    
    
    th1.join();
    //th2.join();

    return 0;
}