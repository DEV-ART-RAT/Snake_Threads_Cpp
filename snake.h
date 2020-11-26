#include "matriz.h"

#define FOOD '+'
#define SNAKE '*'
#define CRASH 'F'

int getIntRand(int a, int b){   
    return rand() % (b - a + 1) + a;
}

template<class T>
void defineSnake(doubleLinked<T> list, charMatriz M, int fil, int col){
    for(node<T>* e = list.front; e!=NULL; e=e->next){
        if(e->info.i>=fil)
            e->info.i=0;
        if(e->info.j>=col)
        e->info.j=0;
        M[e->info.i][e->info.j]=SNAKE;
        //cout<<"e.i"<<e->info.i<<" e.j"<<e->info.j<<" ;";
    }

}

void defineFood(charMatriz M, int* fil, int* col){
    int i , j;
    do{
        i = getIntRand( 0 , *fil - 1 );
        j = getIntRand( 0 , *col - 1 );
    }while (M[i][j]!=' ');
    M[i][j] = FOOD;
}

template<class T>
void snakeDel(doubleLinked<T>* list, charMatriz M){
    node<T>* n = list->removeFront();
    M[n->info.i][n->info.j]=' ';
    delete(n);
}

template<class T>
void snakeNew(doubleLinked<T>* list, charMatriz M, int fil, int col,int* sizeFil, int* sizeCol, bool* flag){
    list->pushBack(T(fil,col));
    if(M[fil][col]==FOOD ){
        //list->pushFront(T(fil,col));
        defineFood(M,sizeFil,sizeCol);
        //M[fil][col]='*';
    }else if(M[fil][col]==SNAKE){
        *flag = false;
        M[fil][col]=CRASH;
        printMatrizChar(M,*sizeFil,*sizeCol);//-----
        cout<<"GAME OVER >:´v"<<endl;

    }else
    {
        snakeDel(list,M);
    }    
    M[fil][col]=SNAKE;
}


template<class T>
void snakeRight(doubleLinked<T>* list, charMatriz M, int* fil, int* col,int step, bool* flag){
    int prevF= list->back->info.i;
    int prevC= list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< step;k++){
        prevC++;
        if(prevC>=*col){
            prevC=0;
        }
        snakeNew(list,M,prevF,prevC,fil,col,flag);
        //snakeDel(list,M);
    }
}

template<class T>
void snakeLeft(doubleLinked<T>* list, charMatriz M, int* fil, int* col,int step, bool* flag){
    int prevF= list->back->info.i;
    int prevC= list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< step;k++){
        prevC--;
        if(prevC < 0){
            prevC = *col -1;
        }
        snakeNew(list,M,prevF,prevC,fil,col,flag);
        //snakeDel(list,M);
    }
}

template<class T>
void snakeUp(doubleLinked<T>* list, charMatriz M, int* fil, int* col,int step, bool* flag){
    int prevF= list->back->info.i;
    int prevC= list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< step;k++){
        prevF--;
        if(prevF < 0){
            prevF = *fil - 1;
        }
        snakeNew(list,M,prevF,prevC,fil,col,flag);
        //snakeDel(list,M);
    }
}

template<class T>
void snakeDown(doubleLinked<T>* list, charMatriz M, int* fil, int* col,int step, bool* flag){
    int prevF= list->back->info.i;
    int prevC= list->back->info.j;
    //cout<<"back.i "<<prevF<<" back.j "<<prevC<<endl;
    for(int k = 0; k< step;k++){
        prevF++;
        if(prevF >= *fil){
            prevF = 0;
        }
        snakeNew(list,M,prevF,prevC,fil,col,flag);
        //snakeDel(list,M);
    }
}

template<class T>
void snakeDirection(doubleLinked<T>* list, charMatriz M, int* fil, int* col,int step, int* dir, bool* flag){
    switch (*dir)
        {
        case 1:
            snakeUp(list,M,fil,col,step,flag);
            break;
        case 2:
            snakeDown(list,M,fil,col,step,flag);
            break;
        case 3:
            snakeRight(list,M,fil,col,step,flag);
            break;
        case 4:
            snakeLeft(list,M,fil,col,step,flag);
            break;
        default:
            break;
        }
}