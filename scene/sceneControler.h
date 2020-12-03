#pragma once
#include <string>
#include <ostream>
#include <fstream>
#include <sstream>
#include <iostream>

#include "../tools/list.h"

using namespace std;

/**Function that reads files with instructions given
 * And modifies a double linked list used to storage the stages
*/

template<class T>
void chargeScenes(myGame<T>* game,string name){
    ifstream data;
    string recibo;
    int row,col,end;
    bool flag = true;
    doubleLinked<sceneInfo> scenesList;
    data.open("./data/scenes/" + name,ios::in);
    for(string line; getline(data,line);){
        stringstream data(line);
        //cout<<line<<endl;
        for (int colec = 0;getline(data,recibo,',');colec++){
            if(stoi(recibo) == -1){
                flag=false;
                //cout<<"f "<<recibo<<endl;
                break;
            }
            //cout<<recibo<<endl;
            if(colec==0){
                row = stoi(recibo);
            }
            else if(colec==1){
                col = stoi(recibo);
            }else
            {
                end = stoi(recibo);
                scenesList.pushBack(sceneInfo(row,col,end,flag));
                //cout<<"guardado"<<flag<<endl;
            }
            
        }
    }
    data.close();
    game->sceneList.pushBack(scenesList);
}

