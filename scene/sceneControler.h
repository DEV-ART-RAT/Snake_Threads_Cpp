#pragma once
#include <string>
#include <ostream>
#include <fstream>
#include <sstream>
#include <iostream>

#include "../tools/list.h"

using namespace std;


template<class T>
void chargeScenes(myGame<T>* game){
    ifstream data;
    string recibo;
    int row,col,end;
    bool flag = true;
    data.open("./data/scenes/extra1.csv",ios::in);
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
                game->scenesList.pushBack(sceneInfo(row,col,end,flag));
                //cout<<"guardado"<<flag<<endl;
            }
            
        }
    }
    data.close();
}

