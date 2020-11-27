#include <iostream>
#include <string>
#include <iostream>
#include <ostream>
#include "../user/nodeuser.h"
#include "../snake/list.cpp"
#include "../user/readuser.cpp"
using namespace std;
void welcomeuser();

template<class T>
void printUsers(doubleLinked<T>* dl,int &P,int &C,string user);

int usermain(void) {
    doubleLinked<nodeuserinfouser> userlist;
    string user;
    int P,C;
    P=0,C=0;
    welcomeuser();
    cin>>user;
    printUsers(&userlist,P,C,user);
    if(C!=0&&P!=0){
        cout<<"Bienvenido de nuevo!"<<endl;
        cout<<"Tus monedas : "<<C<<endl;
        cout<<"Tus puntajes : "<<P<<endl;
    }
    getchar();
    //traverseBegin(userlist.front);
    return 0;
};

template<class T>
void printUsers(doubleLinked<T>* dl,int &P,int &C,string user){
    ifstream data;
    data.open("./data/user.csv",ios::in);
    for(string line; getline(data,line);){
        stringstream data(line);
        string puntaje,name;
        int point,coin;
        for (int col = 0;getline(data,puntaje,',');col++){
            if(col==0){
                name = puntaje;
                //cout<<name<<endl;
            }
            else if(col==1)
            {
                point = stoi(puntaje);
                //cout<<puntaje<<endl;

            }
            else if(col==2){
                coin = stoi(puntaje);
                //cout<<puntaje<<endl;
                // aqui es donde guardo los datos que se obtienen del csv
                if(name==user){
                    P=point;
                    C=coin;
                }
                dl->pushBack(T(point,coin,name));
            }

        }

    }
    data.close();


}

void welcomeuser(void){
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<"\t\t\t=====   ===    =="   <<"   =======   ==  =="  <<"   ====="   <<endl;
    cout<<"\t\t\t||      ||\\\\   ||" <<"   ||   ||   || // "  <<"   ||"      <<endl;
    cout<<"\t\t\t=====   || \\\\  ||" <<"   ||===||   |||   "  <<"   ====="   <<endl;
    cout<<"\t\t\t   ||   ||  \\\\ ||" <<"   ||   ||   || \\\\ "<<"   ||"      <<endl;
    cout<<"\t\t\t=====   ==   ===="   <<"   ==   ==   ==  =="  <<"   ====="   <<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t Digita tu  USUARIO \n";
    cout<<"\t\t\t (si ya tienes un usuario se recuperara tu progreso) \n";

}