#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <ostream>
#include "../user/nodeuser.h"
#include "../snake/list.cpp"
#include "../snake/clear.cpp"
#include "../user/readuser.cpp"

using namespace std;
void top_game(node<nodeuserinfouser>* userdata,doubleLinked<nodeuserinfouser>* userlist);
void welcometop();

void top_game(node<nodeuserinfouser>* userdata,doubleLinked<nodeuserinfouser>* userlist){
    welcometop();
    traverseBegin(userlist->front);
    cout<<"presiona ENTER para continuar";
    cin.ignore();
    cin.get();
    startMenuOpc(userdata,startMenu(userdata,userlist),userlist);
};
void welcometop(){
    // borra esto porque hay nose que conflicto de pragma once
    CLEAR;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t TOP :  \n";

}