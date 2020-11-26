#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/*
xx) Hacer una función en C++ que dado un archivo de texto llamado “data.csv”, que por cada fila tiene
una cadena de caracteres un entero separados por coma, lea estos puntajes y los vaya colocando en
una lista como la descrita en tt)
*/


template<class T>
void xx(doubleLinked<T> *list) {
    //definimos la variable
    ifstream data;
    //abrimos el archivo
    data.open("../data/user.csv",ios::in);
    for(string line; getline(data,line);){
        stringstream data(line);
        string puntaje,name;
        int point;
        //damos los datos
        for (int col = 0;getline(data,puntaje,',');col++){
            if(col==0){
                name = puntaje;
            }else
            {
                point = stoi(puntaje);
                pushBack(T(point,name),list);
            }
        }

    }
    data.close();
}


/*
yy) Hacer una función en C++ que dada una lista como la descrita en tt) , escriba su contenido en un
archivo de texto llamado “data.csv” con el formato descrito en xx) .
*/

// elemento tipo template
template<class T>
void yy(node<T>* list){
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