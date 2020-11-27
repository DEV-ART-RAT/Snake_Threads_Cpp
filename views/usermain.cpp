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
void printUsers(doubleLinked<T>* dl,int &P,int &C,int &life,string user);

int usermain(nodeuserinfouser* userdata) {
    doubleLinked<nodeuserinfouser> userlist;
    int P,C,life;
    string user;
    P=0,C=0,life=3;
    welcomeuser();
    cin>>user;
    printUsers(&userlist,P,C,life,user);
    if(C!=0&&P!=0){
        cout<<"Bienvenido de nuevo!"<<endl;
        cout<<"Tus monedas : "<<C<<endl;
        cout<<"Tus puntajes : "<<P<<endl;
    }
     *userdata =  nodeuserinfouser(P,C,user)  ;

     // getchar(); borrar buffer
    //traverseBegin(userlist.front);
    return 0;
};

template<class T>
void printUsers(doubleLinked<T>* dl,int &P,int &C,int &life,string user){
    ifstream data;
    data.open("./data/user.csv",ios::in);
    for(string line; getline(data,line);){
        stringstream data(line);
        string puntaje,name;
        int point,coin,lifes;
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
                
            }else if(col==3){
                lifes = stoi(puntaje);
                if(name==user){
                    P=point;
                    C=coin;
                    life=lifes;
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